#include "arduino.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include "arduino.h"
#include <algorithm>
#include <iostream>

Arduino::Arduino()
{

}
int Arduino :: connect(){
    foreach(const QSerialPortInfo & sp, QSerialPortInfo::availablePorts()){
        if(sp.hasVendorIdentifier() && sp.hasProductIdentifier()){
            if((sp.vendorIdentifier() == ard_vendor_id) && sp.productIdentifier() == ard_product_id){
                isAvailable = true;
                ard_portName = sp.portName();
            }
        }
    }
    std::cout << "Arduino name is: " << ard_portName.toStdString() << std::endl;
    if(isAvailable == true){
        port->setPortName(ard_portName);
        if(port->open(QSerialPort::ReadWrite)){
            port->setBaudRate(QSerialPort::Baud9600);
            port->setDataBits(QSerialPort::Data8);
            port->setParity(QSerialPort::NoParity);
            port->setStopBits(QSerialPort::OneStop);
            port->setFlowControl(QSerialPort::NoFlowControl);
            return 0;
        }
    }
    return 1;
}
int Arduino :: close(){
    if(port->isOpen()){
        port->close();
        return 0;
    }
    return 1;
}
int Arduino :: write(QByteArray arr){
    if(port->isWritable()){
        port->write(arr);
    }else{
        std::cout << "Could not write to arduino" << std::endl;
     }
    return 0;
}
QByteArray Arduino :: read(){
    if(port->isReadable()){
        data = port->readAll();
        return data;
    }
}
QSerialPort * Arduino :: getSerial(){
    return port;
}
QString Arduino :: getName(){
    return ard_portName;
}
