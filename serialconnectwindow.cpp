#include "serialconnectwindow.h"
#include "ui_serialconnectwindow.h"

SerialConnectWindow::SerialConnectWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialConnectWindow)
{
    ui->setupUi(this);
    serialSelect = "COM5";
    //ui->listSerial;
    //ui->verticalScrollBar;
    //ui->plainTextEdit

}

SerialConnectWindow::~SerialConnectWindow()
{
    delete ui;
}
