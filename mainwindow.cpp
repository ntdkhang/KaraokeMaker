#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <OpenGL/OpenGL.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);


    ui->pushButton_play_pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    ui->pushButton_seek_forward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
    ui->pushButton_seek_backward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->pushButton_mute->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
}

void MainWindow::on_horizontalSlider_progress_valueChanged(int value)
{

}


void MainWindow::on_pushButton_seek_backward_toggled(bool checked)
{

}


void MainWindow::on_pushButton_seek_forward_toggled(bool checked)
{

}


void MainWindow::on_pushButton_play_pause_clicked()
{

}


void MainWindow::on_pushButton_stop_clicked()
{

}


void MainWindow::on_pushButton_mute_clicked()
{
    if (is_muted) {
        is_muted = false;
        ui->pushButton_mute->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
        audioOutput->setMuted(is_muted);
    } else {
        is_muted = true;
        ui->pushButton_mute->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
        audioOutput->setMuted(is_muted);
    }
}


void MainWindow::on_horizontalSlider_volume_valueChanged(int value)
{

}

