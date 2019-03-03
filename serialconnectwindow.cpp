#include <QStringListModel>


#include "serialconnectwindow.h"
#include "serialmgmt.h"
#include "ui_serialconnectwindow.h"

SerialConnectWindow::SerialConnectWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialConnectWindow)
{
    ui->setupUi(this);
    serialSelect = "COM5";
    serialListModel = new QStringListModel(this);
    serialMgmt = new SerialMgmt();
    serialList = serialMgmt->getSerialConnected();
    serialListModel->setStringList(serialList);


    ui->listSerial->setModel(serialListModel);

    connect(ui->listSerial,SIGNAL(doubleClicked(QModelIndex)), this,SLOT(returnConection(QModelIndex)));
    //ui->verticalScrollBar;
    //ui->plainTextEdit

}

void SerialConnectWindow::returnConection(QModelIndex modelIdx)
{
    serialSelect = serialList[modelIdx.row()];
    this->accept();
}

SerialConnectWindow::~SerialConnectWindow()
{
    delete serialMgmt;
    delete serialListModel;

    delete ui;
}
