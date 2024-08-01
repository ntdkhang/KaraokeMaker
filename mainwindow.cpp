#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "arggenerator.h"
#include <OpenGL/OpenGL.h>
#include <QtCore/qlogging.h>
#include <QtCore/qoverload.h>
#include <QtCore/qprocess.h>
#include <QtMultimedia/qaudio.h>
#include <QtWidgets/qfiledialog.h>
#include <ctime>
#include <fstream>
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , player(new Ui::MainWindow)
    , arggenerator("")
{
    player->setupUi(this);

    // media player
    m_player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    m_player->setAudioOutput(audioOutput);

    player->horizontalSlider_volume->setMinimum(0);
    player->horizontalSlider_volume->setMaximum(100);
    player->horizontalSlider_volume->setValue(50);
    audioOutput->setVolume(player->horizontalSlider_volume->value());

    player->horizontalSlider_progress->setRange(0, m_player->duration());

    player->pushButton_play_pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    player->pushButton_stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    player->pushButton_seek_forward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
    player->pushButton_seek_backward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    player->pushButton_mute->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));


    player->pushButton_test->setDisabled(true);


    // Subtitles
    player->plainTextEdit_subtitle->setReadOnly(true);


    connect(m_player, &QMediaPlayer::durationChanged, this, &MainWindow::durationChanged);
    connect(m_player, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);
    connect(player->horizontalSlider_progress, &QSlider::sliderMoved, m_player, &QMediaPlayer::setPosition);

    // audioSeparationProcess = new QProcess();
    // connect(audioSeparationProcess, &QProcess::finished, this, &MainWindow::separateVocal);
    // connect(vocalSeparationProcess, &QProcess::finished, this, &MainWindow::vocalSeparated);

    // connect(audioSeparationProcess, &QProcess::finished, this, &MainWindow::vocalSeparated);
}

MainWindow::~MainWindow()
{
    delete player;
}

void MainWindow::durationChanged(qint64 duration) {
    player->horizontalSlider_progress->setMaximum(duration);
    m_duration = duration;
}

void MainWindow::positionChanged(qint64 progress) {
    player->horizontalSlider_progress->setValue(progress);
    updateDurationInfo(progress);
}

void MainWindow::updateDurationInfo(qint64 currentInfo) {
    // currentInfo is the progress in milliseconds

    if (currentInfo || m_duration) {
        QTime currentTime((currentInfo / 3600000) % 60, (currentInfo / 60000) % 60, ((currentInfo / 1000) % 60), (currentInfo % 1000));
        QTime totalTime((m_duration / 3600000) % 60, (m_duration / 60000) % 60, (m_duration / 1000 % 60), (m_duration % 1000));
        QString format = "mm:ss,zzz";
        QString currentLabel, totalLabel;
        currentLabel = currentTime.toString(format);
        totalLabel = totalTime.toString(format);

        player->label_current_time->setText(currentLabel);
        player->label_total_time->setText(totalLabel);
    }
}


void MainWindow::on_actionOpen_triggered()
{
    QObject *parent;
    videoInputFileName = QFileDialog::getOpenFileName(this, tr("Select Video File"), "", tr("MP4 Files (*.mp4)"));
    arggenerator.setVideoInputFileName(videoInputFileName);

    video = new QVideoWidget();
    video->setGeometry(5, 5, player->groupBox_Video->width() - 10, player->groupBox_Video->height() - 10);
    video->setParent(player->groupBox_Video);

    m_player->setVideoOutput(video);
    m_player->setSource(QUrl(videoInputFileName));

    video->setVisible(true);
    video->show();


    // Separate audio in background
    QStringList arguments = arggenerator.SeparateAudioAndVideo();

    audioSeparationProcess = new QProcess(parent);
    // connect(audioSeparationProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
    //         [=](int exitCode, QProcess::ExitStatus exitStatus){
    //         qDebug()<<"finished";
    //         });
    // connect(audioSeparationProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, &MainWindow::separateVocal);
    connect(audioSeparationProcess, &QProcess::finished, this, &MainWindow::separateVocal);

    audioSeparationProcess->start(arggenerator.ffmpeg, arguments);

    // audioSeparationProcess->waitForFinished();
    // QString stdOut(audioSeparationProcess->readAllStandardOutput());
    // QString stdErr(audioSeparationProcess->readAllStandardError());
    // qInfo() << stdOut;
    // qInfo() << stdErr;

}

void MainWindow::on_horizontalSlider_volume_valueChanged(int value)
{
    qreal logVolume = QtAudio::convertVolume(value / qreal(100.0), QtAudio::LinearVolumeScale, QtAudio::LogarithmicVolumeScale);
    audioOutput->setVolume(logVolume);
}

void MainWindow::on_pushButton_play_pause_clicked()
{
    if (is_paused) {
        m_player->play();
        player->pushButton_play_pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        is_paused = false;
    } else {
        m_player->pause();
        player->pushButton_play_pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        is_paused = true;
    }
}


void MainWindow::on_pushButton_stop_clicked()
{
    m_player->stop();
}


void MainWindow::on_pushButton_mute_clicked()
{
    if (is_muted) {
        is_muted = false;
        player->pushButton_mute->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
        audioOutput->setMuted(is_muted);
    } else {
        is_muted = true;
        player->pushButton_mute->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
        audioOutput->setMuted(is_muted);
    }
}


void MainWindow::on_pushButton_seek_backward_clicked()
{
    player->horizontalSlider_progress->setValue(player->horizontalSlider_progress->value() - 5000);
    m_player->setPosition(player->horizontalSlider_progress->value());
}


void MainWindow::on_pushButton_seek_forward_clicked()
{
    player->horizontalSlider_progress->setValue(player->horizontalSlider_progress->value() + 5000);
    m_player->setPosition(player->horizontalSlider_progress->value());
}



void MainWindow::on_pushButton_test_clicked()
{
    QObject *parent;

    // Render video with subtitle
    QString outputFileName = QFileDialog::getSaveFileName(this, tr("Save video as"), "", tr("Videos (*.mp4)"));
    QStringList arguments = arggenerator.BurnSubtitle("./sub.srt", outputFileName);

    subtitleBurnProcess = new QProcess(parent);
    subtitleBurnProcess->start(arggenerator.ffmpeg, arguments);
    subtitleBurnProcess->waitForFinished();

    QString stdOut(subtitleBurnProcess->readAllStandardOutput());
    QString stdErr(subtitleBurnProcess->readAllStandardError());
    qInfo() << stdOut;
    qInfo() << stdErr;
}


void MainWindow::on_pushButton_save_subtitles_clicked()
{
    // get text from editor
    QString text = player->plainTextEdit_subtitle->toPlainText();

    // save to srt
    std::ofstream srtFile;
    srtFile.open("sub.srt");
    srtFile << text.toStdString();
    srtFile.close();
}


void MainWindow::on_pushButton_insert_time_start_clicked()
{
    player->plainTextEdit_create_sub->moveCursor(QTextCursor::End);
    player->plainTextEdit_create_sub->insertPlainText(QString::number(subtitleIndex));
    player->plainTextEdit_create_sub->insertPlainText("\n");

    QString timeStart = "00:" + player->label_current_time->text();
    // timeStart.append(",000");
    player->plainTextEdit_create_sub->insertPlainText(timeStart);
    player->plainTextEdit_create_sub->insertPlainText(" --> ");
}


void MainWindow::on_pushButton_insert_time_end_clicked()
{
    QString timeEnd = "00:" + player->label_current_time->text();
    // timeEnd.append(",000");

    player->plainTextEdit_create_sub->moveCursor(QTextCursor::End);
    player->plainTextEdit_create_sub->insertPlainText(timeEnd);
    player->plainTextEdit_create_sub->insertPlainText("\n");

    subtitleIndex++;
}


void MainWindow::on_pushButton_insert_subtitle_line_clicked()
{
    QString line = player->plainTextEdit_create_sub->toPlainText();
    if (!line.isEmpty()) {
        player->plainTextEdit_subtitle->moveCursor(QTextCursor::End);
        player->plainTextEdit_subtitle->insertPlainText(line);
        player->plainTextEdit_subtitle->insertPlainText("\n\n");
        player->plainTextEdit_create_sub->clear();
    }
}


void MainWindow::on_actionOpen_original_audio_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select Original Audio File For Separation"), "", tr("MP3 Files (*.mp3)"));
    qInfo() << fileName;

    QObject *parent;
    QString python = "/usr/local/Cellar/python@3.11/3.11.7_1/Frameworks/Python.framework/Versions/3.11/Resources/Python.app/Contents/MacOS/Python";

    QStringList arguments;

    arguments   << "-m" << "demucs.separate"
                << "-n" << "htdemucs"
                << "--mp3" << "--mp3-bitrate=320"
                << "--two-stems=vocals"
                << fileName;

    vocalSeparationProcess = new QProcess(parent);

    vocalSeparationProcess->start(python, arguments);
    vocalSeparationProcess->waitForFinished();
    QString stdOut(vocalSeparationProcess->readAllStandardOutput());
    qInfo() << stdOut;
    QString stdErr(vocalSeparationProcess->readAllStandardError());
    qInfo() << stdErr;

}

void MainWindow::separateVocal() {
    QObject *parent;
    qInfo() << "Separating vocal from music";
    QStringList arguments = arggenerator.SeparateVocal();

    vocalSeparationProcess = new QProcess(parent);
    connect(vocalSeparationProcess, &QProcess::finished, this, &MainWindow::vocalSeparated);
    vocalSeparationProcess->start(arggenerator.python, arguments);
}


void MainWindow::vocalSeparated() {
    // create a new video with beat as audio.

    QObject *parent;
    qInfo() << "Vocal separated, now putting non-vocal music back to video";

    QStringList arguments = arggenerator.AddNewAudio();

    addNewAudioProcess = new QProcess(parent);
    connect(addNewAudioProcess, &QProcess::finished, this, &MainWindow::newAudioAdded);
    addNewAudioProcess->start(arggenerator.ffmpeg, arguments);
}


void MainWindow::newAudioAdded() {
    qInfo() << "Non-vocal music added back to video";
    player->pushButton_test->setEnabled(true);
}
