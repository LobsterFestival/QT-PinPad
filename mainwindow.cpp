#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    int digitValue = clickedButton->text().toInt();
    ui->lineEdit->setText(ui->lineEdit->text() + QString::number(digitValue));
}

void MainWindow::on_b_enter_clicked()
{
    QString enteredDigits = ui->lineEdit->text();
    if(password == enteredDigits && password != ""){
        QMessageBox::information(this,"Login","Password Correct");
        hide();
        videoPlayerDialog = new VideoPlayerDialog(this);
        videoPlayerDialog->show();
    } else {
        QMessageBox::information(this,"Login", "Password is incorrect!");
    }
}

void MainWindow::selectPasswordFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select Password File", "", "Text Files (*.txt)");
    QFile temp(fileName);
    // Verify password file format, single line of numbers, 10 chars long
    if (!temp.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(this,"Password File Error","Could Not Open " + fileName);
    }

    QByteArray firstLine = temp.readLine();
    verifyPasswordFormat(firstLine);
}

void MainWindow::verifyPasswordFormat(QByteArray firstLine)
{
    static QRegularExpression re("^\\d+$");
    QRegularExpressionMatch match = re.match(firstLine);
    if (match.hasMatch()) {
        password = match.captured(0);
        ui->b_enter->setEnabled(true);
    } else {
        QMessageBox::information(this, "Password File Error", "Password File not formatted correctly, please use a single line of 0-9 characters only.");
    }
}

