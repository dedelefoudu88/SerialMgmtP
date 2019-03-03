#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "serialconnectwindow.h"
#include "serialreciver.h"

#include <QMdiArea>
#include <QTextEdit>
#include <QMenuBar>
#include <QApplication>
#include <QToolBar>
#include <QFontComboBox>

#include <QPlainTextEdit>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    zoneCentrale = new QMdiArea;
    setCentralWidget(zoneCentrale);

    zoneCentraleSubWin = new QMdiArea;

    mainLayout = new QVBoxLayout(zoneCentrale);

    debugText = new QPlainTextEdit();
    debugText->setPlainText("test");
    debugText->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    //spacesubWindow = new QSpacerItem(10,200);//(int w, int h, QSizePolicy::Policy hPolicy = QSizePolicy::Minimum, QSizePolicy::Policy vPolicy = QSizePolicy::Minimum);
    mainLayout->addWidget(zoneCentraleSubWin);
    mainLayout->addWidget(debugText);
    createMenus();
}

void MainWindow::createMenus()
{
    menuSetting = menuBar()->addMenu("Setting");
    menuSerial = menuBar()->addMenu("Serial");
    QAction *actionSerial = new QAction("Connect", this);
    menuSerial->addAction(actionSerial);
    connect(actionSerial, SIGNAL(triggered()), this, SLOT(openSerialConnect()));

}

void MainWindow::openSerialConnect()
{
    SerialConnectWindow serialConnectWindow(this);
    serialConnectWindow.setModal(true);
    if(serialConnectWindow.exec() == QDialog::Accepted)
    {
        debugText->moveCursor(QTextCursor::End);
        debugText->insertPlainText("Accepted "+ serialConnectWindow.serialSelect);
        creatSubWindows();
    }
    else
    {
        debugText->moveCursor(QTextCursor::End);
        debugText->insertPlainText("reject");
    }
}

void MainWindow::creatSubWindows()
{
    debugText->moveCursor(QTextCursor::End);
    debugText->insertPlainText("creat sub win");
    serialReciver = new SerialReciver;
    //QTextEdit *zoneTexte1 = new QTextEdit;
    serialSubWindows = zoneCentraleSubWin->addSubWindow(serialReciver);
    //zoneCentrale->setActiveSubWindow(serialSubWindows);
    //zoneTexte1->setFrameStyle(Qt::FramelessWindowHint);
    serialReciver->show();
}

void MainWindow::deleteMenus()
{
    delete debugText;
    delete zoneCentraleSubWin;

    delete menuSerial;
    delete menuSetting;

    delete mainLayout;
    delete zoneCentrale;
}

MainWindow::~MainWindow()
{


    delete ui;
}
