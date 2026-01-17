#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Qt 6: QMediaPlayer uses a separate QAudioOutput for sound.
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    videos = new QVideoWidget(this);
    player->setVideoOutput(videos);
    this->setCentralWidget(videos);

    // Ensure we receive Esc even when the video widget is fullscreen/focused.
    videos->installEventFilter(this);

    slider= new QSlider(this);
    slider->setOrientation(Qt::Horizontal);

    ui->statusBar->addPermanentWidget(slider);


    connect(player, &QMediaPlayer::durationChanged, slider, &QSlider::setMaximum);
    connect(player, &QMediaPlayer::positionChanged, slider, &QSlider::setValue);
    connect(slider, &QSlider::sliderMoved, player, &QMediaPlayer::setPosition);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    // QVideoWidget grabs focus in fullscreen, so handle Esc here.
    if (obj == videos && event->type() == QEvent::KeyPress) {
        auto *ke = static_cast<QKeyEvent*>(event);
        if (ke->key() == Qt::Key_Escape && videos->isFullScreen()) {
            videos->setFullScreen(false);
            return true; // handled
        }
    }
    return QMainWindow::eventFilter(obj, event);
}



void MainWindow::on_actionOpen_triggered()
{
    const QString filename = QFileDialog::getOpenFileName(this, "Select movie file");
    if (filename.isEmpty())
        return;

    ui->statusBar->showMessage("Select a file.");

    // Qt 6: setMedia() was replaced by setSource().
    player->setSource(QUrl::fromLocalFile(filename));

    QFileInfo fileInfo(filename);
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


void MainWindow::on_actionExit_fullscreen_triggered()

{
    videos->setFullScreen(false);
}

void MainWindow::on_actionFullscreen_triggered()
{
    videos->setFullScreen(true);

}
