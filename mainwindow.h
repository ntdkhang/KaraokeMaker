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

    void on_actionOpen_triggered();

    void on_horizontalSlider_progress_valueChanged(int value);

    void on_pushButton_seek_backward_toggled(bool checked);

    void on_pushButton_seek_forward_toggled(bool checked);

    void on_pushButton_play_pause_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_mute_clicked();

    void on_horizontalSlider_volume_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QVideoWidget *video;
    QAudioOutput *audioOutput;
    qint64 mDuration;
    bool is_paused = true;
    bool is_muted = false;
};
#endif // MAINWINDOW_H
