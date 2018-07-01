#include "mainwindow.h"
#include "ui_mainwindow.h"
int i;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player= new QMediaPlayer(this);

    videos = new QVideoWidget(this);
    player->setVideoOutput(videos);
    this->setCentralWidget(videos);

    slider= new QSlider(this);
    slider->setOrientation(Qt::Horizontal);

    ui->statusBar->addPermanentWidget(slider);


    connect(player, &QMediaPlayer::durationChanged, slider, &QSlider::setMaximum);
    connect(player, &QMediaPlayer::positionChanged, slider, &QSlider::setValue);
    connect(slider, &QSlider::sliderMoved, player, &QMediaPlayer::setPosition);}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    QStringList filename=QFileDialog::getOpenFileNames(this, "Select movie file");
    ui->statusBar->showMessage("Select a file.");
    player->setMedia(QUrl::fromLocalFile(filename.at(0)));
    QFileInfo fileInfo(filename.at(0));
    QString info(fileInfo.fileName());
    string show = info.toStdString();
    cout << show  << endl;
    player->play();
    ui->statusBar->showMessage(info);
}

void MainWindow::on_actionStop_triggered()
{
    player->stop();
    ui->statusBar->showMessage("Playback stopped.");

}

void MainWindow::on_actionPause_triggered()
{
    player->pause();
    ui->statusBar->showMessage("Playback paused.");

}

void MainWindow::on_actionPlay_triggered()
{
    player->play();
    ui->statusBar->showMessage("Playback resumes.");

}
