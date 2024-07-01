#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <OpenGL/OpenGL.h>
#include <QtCore/qlogging.h>
#include <QtMultimedia/qaudio.h>
#include <QtWidgets/qfiledialog.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , player(new Ui::MainWindow)
{
    player->setupUi(this);

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


    connect(m_player, &QMediaPlayer::durationChanged, this, &MainWindow::durationChanged);
    connect(m_player, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);
}

MainWindow::~MainWindow()
{
    delete player;
}

void MainWindow::durationChanged(qint64 duration) {
    qInfo() << duration;
    player->horizontalSlider_progress->setMaximum(duration);
}

void MainWindow::positionChanged(qint64 progress) {
    qInfo() << "progress: " << progress;
    player->horizontalSlider_progress->setValue(progress);
}

void MainWindow::updateDurationInfo(qint64 currentInfo) {
    if (currentInfo || m_duration) {
        QTime currentTime((currentInfo / 3600) % 60, (currentInfo / 60) % 60, (currentInfo % 60));
        QTime totalTime((m_duration / 3600) % 60, (m_duration / 60) % 60, (m_duration % 60));
    }
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select Video File"), "", tr("MP4 Files (*.mp4)"));

    video = new QVideoWidget();
    video->setGeometry(5, 5, player->groupBox_Video->width() - 10, player->groupBox_Video->height() - 10);
    video->setParent(player->groupBox_Video);

    m_player->setVideoOutput(video);
    m_player->setSource(QUrl(fileName));

    video->setVisible(true);
    video->show();
}

void MainWindow::on_horizontalSlider_progress_valueChanged(int value)
{
    // TODO: changing slider value doesn't change video progress

    // m_player->setPosition(value);
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
    player->horizontalSlider_progress->setValue(player->horizontalSlider_progress->value() - 10000);
    m_player->setPosition(player->horizontalSlider_progress->value());
}


void MainWindow::on_pushButton_seek_forward_clicked()
{
    player->horizontalSlider_progress->setValue(player->horizontalSlider_progress->value() + 10000);
    m_player->setPosition(player->horizontalSlider_progress->value());
}

