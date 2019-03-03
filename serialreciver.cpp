#include "serialreciver.h"

SerialReciver::SerialReciver(QWidget *parent) : QWidget(parent)
{
    //zoneCentrale = new QMdiArea;
    //setCentralWidget(zoneCentrale);

    mainLayout = new QVBoxLayout();

    outputText = new QPlainTextEdit();
    outputText->setPlainText("test2");
    outputText->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    mainLayout->addWidget(outputText);
    this->setLayout(mainLayout);
}

SerialReciver::~SerialReciver()
{

}
