#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QSlider>
#include <QString>
#include <iostream>
#include <QProgressBar>
#include <QVideoWidget>

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_actionOpen_triggered();

    void on_actionStop_triggered();

    void on_actionPause_triggered();

    void on_actionPlay_triggered();

    void on_actionFullscreen_triggered();


    void on_actionExit_fullscreen_triggered();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QSlider *slider;
    QProgressBar *bar;
    QVideoWidget *videos;
};

#endif // MAINWINDOW_H
