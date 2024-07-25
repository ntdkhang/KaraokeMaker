#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QtCore>
#include <QtWidgets>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void durationChanged(qint64 duration);

    void positionChanged(qint64 progress);

    void on_actionOpen_triggered();

    void on_pushButton_play_pause_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_mute_clicked();

    void on_horizontalSlider_volume_valueChanged(int value);

    void on_pushButton_seek_backward_clicked();

    void on_pushButton_seek_forward_clicked();

    void on_pushButton_test_clicked();

    void on_pushButton_save_subtitles_clicked();

    void on_pushButton_insert_time_start_clicked();

    void on_pushButton_insert_time_end_clicked();

    void on_pushButton_insert_subtitle_line_clicked();

    void on_actionOpen_original_audio_triggered();

private:
    Ui::MainWindow *player;
    QMediaPlayer *m_player;

    QVideoWidget *video;


    QAudioOutput *audioOutput;
    qint64 m_duration;
    bool is_paused = true;
    bool is_muted = false;
    qint32 subtitleIndex = 1;

    void updateDurationInfo(qint64 currentInfo);
};
#endif // MAINWINDOW_H
