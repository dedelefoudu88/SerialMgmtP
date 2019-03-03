#ifndef SERIALRECIVER_H
#define SERIALRECIVER_H

#include <QWidget>
#include <QMdiArea>
#include <QVBoxLayout>
#include <QPlainTextEdit>

class SerialReciver : public QWidget
{
    Q_OBJECT
public:
    explicit SerialReciver(QWidget *parent = 0);
    ~SerialReciver();
signals:

public slots:

private:
    // layout
    QVBoxLayout *mainLayout;

    // debug
    QPlainTextEdit *outputText;
};

#endif // SERIALRECIVER_H
