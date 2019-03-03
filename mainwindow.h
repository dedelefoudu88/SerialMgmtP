#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QPlainTextEdit>
#include <QMdiArea>
#include <QVBoxLayout>
#include <QMdiSubWindow>
#include <QSpacerItem>
#include <QString>

#include "serialreciver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void openSerialConnect();

private:
    Ui::MainWindow *ui;

    // layout
    QMdiArea *zoneCentrale;
    QMdiArea *zoneCentraleSubWin;
    QVBoxLayout *mainLayout;
    // menu
    QMenu *menuSetting;
    QMenu *menuSerial;

    // debug
    QPlainTextEdit *debugText;

    // serial sub windows
    SerialReciver *serialReciver;
    QMdiSubWindow *serialSubWindows;

    // func menu
    void createMenus();
    void deleteMenus();

    void creatSubWindows();

    // func log
    void log(QString str, int debugLevel=0);
    void logWarning(QString str);
    void logError(QString str);


};

#endif // MAINWINDOW_H
