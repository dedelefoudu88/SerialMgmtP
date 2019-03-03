#include "serialmgmt.h"

SerialMgmt::SerialMgmt()
{

}

QStringList SerialMgmt::getSerialConnected()
{
    QStringList comConnect;
    comConnect << "COM1" << "COM2";
    return comConnect;
}

SerialMgmt::~SerialMgmt()
{

}

