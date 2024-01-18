#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "videoplayerdialog.h"
#include <QRegularExpression>

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
    // Called on any digit button event, connected in QT designer.
    void digitClicked();
    // Verifies password on click.
    void on_b_enter_clicked();
    // Used to prevent permissions errors on windows, my C: is encrypted and is a mess to access.
    // To avoid extrenous code, I'm handling it this way.
    void selectPasswordFile();
    // Verify first line of password file is in correct format.
    void verifyPasswordFormat(QByteArray password);

private:
    Ui::MainWindow *ui;
    VideoPlayerDialog *videoPlayerDialog;
    QFile passwordFile;
    QString password;
};
#endif // MAINWINDOW_H
