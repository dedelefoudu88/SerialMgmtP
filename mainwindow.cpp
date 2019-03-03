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

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    zoneCentrale = new QMdiArea;
    setCentralWidget(zoneCentrale);

    zoneCentraleSubWin = new QMdiArea;

    mainLayout = new QVBoxLayout(zoneCentrale);                                 // area where the serial windows will be put

    debugText = new QPlainTextEdit();                                           // area for log & debug
    // debugText->setPlainText("test");
    debugText->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    mainLayout->addWidget(zoneCentraleSubWin);
    mainLayout->addWidget(debugText);
    createMenus();
}

/**
 * @brief MainWindow::createMenus
 */
void MainWindow::createMenus()
{
    menuSetting = menuBar()->addMenu("Setting");
    menuSerial = menuBar()->addMenu("Serial");
    QAction *actionSerial = new QAction("Connect", this);
    menuSerial->addAction(actionSerial);
    connect(actionSerial, SIGNAL(triggered()), this, SLOT(openSerialConnect()));

}

/**
 * @brief MainWindow::openSerialConnect
 *
 * open popup window to set serial conection
 */
void MainWindow::openSerialConnect()
{
    SerialConnectWindow serialConnectWindow(this);
    serialConnectWindow.setModal(true);
    if(serialConnectWindow.exec() == QDialog::Accepted)
    {
        log("Accepted "+ serialConnectWindow.serialSelect,1);
        creatSubWindows();
    }
    else
    {
        logWarning("reject");
    }
}

/**
 * @brief MainWindow::creatSubWindows
 *
 * creat serial window reciver
 */
void MainWindow::creatSubWindows()
{
    log("creat sub win",0);
    serialReciver = new SerialReciver;

    serialSubWindows = zoneCentraleSubWin->addSubWindow(serialReciver);
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

void MainWindow::log(QString str, int debugLevel)
{
    for(int tabLevel=0; tabLevel<debugLevel; tabLevel++)
    {
        str = "\t"+str+"\n";
    }
    debugText->insertPlainText(str);
    debugText->moveCursor(QTextCursor::End);
}

void MainWindow::logWarning(QString str)
{
    log("<warning> " + str, 0);
}

void MainWindow::logError(QString str)
{
    log("!!! ERROR !!! < " + str + " > !!! ERROR !!!", 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
