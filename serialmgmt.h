#ifndef SERIALMGMT_H
#define SERIALMGMT_H

#include <QStringList>

class SerialMgmt
{
public:
    SerialMgmt();
    ~SerialMgmt();
    QStringList getSerialConnected();
};

#endif // SERIALMGMT_H
