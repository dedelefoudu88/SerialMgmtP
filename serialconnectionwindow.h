#ifndef SERIALCONNECTIONWINDOW_H
#define SERIALCONNECTIONWINDOW_H

#include <QDialog>

namespace Ui {
class SerialConnectionWindow;
}

class SerialConnectionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SerialConnectionWindow(QWidget *parent = 0);
    ~SerialConnectionWindow();

private:
    Ui::SerialConnectionWindow *ui;
};

#endif // SERIALCONNECTIONWINDOW_H
