#ifndef SERIALCONNECTWINDOW_H
#define SERIALCONNECTWINDOW_H

#include <QDialog>
#include <QStringListModel>

#include "serialmgmt.h"

namespace Ui {
class SerialConnectWindow;
}

class SerialConnectWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SerialConnectWindow(QWidget *parent = 0);
    ~SerialConnectWindow();
    QString serialSelect;

public slots:

private slots:
    void returnConection(QModelIndex modelIdx);
    //on_exit();
private:
    QStringListModel *serialListModel;
    SerialMgmt *serialMgmt;
    QStringList serialList;
    Ui::SerialConnectWindow *ui;
};

#endif // SERIALCONNECTWINDOW_H
