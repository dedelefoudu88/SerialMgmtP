#ifndef SERIALCONNECTWINDOW_H
#define SERIALCONNECTWINDOW_H

#include <QDialog>

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
    //on_exit();
private:
    Ui::SerialConnectWindow *ui;
};

#endif // SERIALCONNECTWINDOW_H
