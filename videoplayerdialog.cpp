#include "videoplayerdialog.h"
#include "ui_videoplayerdialog.h"

VideoPlayerDialog::VideoPlayerDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VideoPlayerDialog)
{
    ui->setupUi(this);

    player = new QMediaPlayer();
    audioOutput = new QAudioOutput();
    player->setAudioOutput(audioOutput);
}

void VideoPlayerDialog::loadVideo(QString fileName)
{
    video = new QVideoWidget();
    video->setGeometry(5,5,ui->gb_video->width() - 10, ui->gb_video->height() - 10);
    video->setParent(ui->gb_video);
    player->setVideoOutput(video);
    player->setSource(QUrl::fromLocalFile(fileName));
    video->setVisible(true);
    video->show();
    ui->volumeSlider->setSliderPosition(30);

}

VideoPlayerDialog::~VideoPlayerDialog()
{
    delete ui;
}

void VideoPlayerDialog::on_b_play_clicked()
{
    if(IS_PAUSED)
    {
        IS_PAUSED = false;
        player->play();
        ui->b_play->setText("Pause");
    } else {
        player->pause();
        IS_PAUSED = true;
        ui->b_play->setText("Play");
    }
}


void VideoPlayerDialog::on_b_stop_clicked()
{
    player->stop();
    if(!IS_PAUSED){
        IS_PAUSED = true;
        ui->b_play->setText("Play");
    }

}

void VideoPlayerDialog::on_volumeSlider_valueChanged(int value)
{
    float normalizedValue = value / 100.0;
    qDebug() << "Volume Level: " << value << " Normalized: " << normalizedValue;
    audioOutput->setVolume(normalizedValue);
}


void VideoPlayerDialog::on_openFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select Video File", "", "MP4 files (*.mp4)");
    loadVideo(fileName);
}

