#ifndef ARDUINO_H
#define ARDUINO_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>

class Arduino
{
    QSerialPort * port;
    QString ard_portName;
    bool isAvailable;
    QByteArray data;
    static const quint64 ard_vendor_id = 9025;
    static const quint64 ard_product_id = 67;
public:
    Arduino();
    int connect();
    int close();
    int write(QByteArray);
    QByteArray read();
    QSerialPort * getSerial();
    QString getName();
};

#endif // ARDUINO_H
