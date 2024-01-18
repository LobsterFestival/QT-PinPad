#ifndef VIDEOPLAYERDIALOG_H
#define VIDEOPLAYERDIALOG_H

#include <QDialog>
#include <QtMultimedia>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets>
#include <QMediaPlayer>
#include <QVideoWidget>

namespace Ui {
class VideoPlayerDialog;
}

class VideoPlayerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VideoPlayerDialog(QWidget *parent = nullptr);
    ~VideoPlayerDialog();
    void loadVideo(QString fileName);

private slots:
    void on_b_play_clicked();

    void on_b_stop_clicked();

    void on_volumeSlider_valueChanged(int value);

    void on_openFileButton_clicked();

private:
    Ui::VideoPlayerDialog *ui;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    QVideoWidget *video;
    bool IS_PAUSED = true;
};

#endif // VIDEOPLAYERDIALOG_H
