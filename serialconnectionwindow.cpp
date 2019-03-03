#include <QDialog>

#include "serialconnectionwindow.h"
#include "ui_serialconnectionwindow.h"

SerialConnectionWindow::SerialConnectionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialConnectionWindow)
{
    ui->setupUi(this);
}

SerialConnectionWindow::~SerialConnectionWindow()
{
    delete ui;
}
