#pragma once

#include <QDebug>
#include <QThread>

#include "Sender.h"

class Receiver : public QObject
{
    Q_OBJECT

    public slots:
        void OnGettingEnum(MyNamespace::MyEnum e) {
            qDebug() << "Received on thread: " << QThread::currentThread();
            qDebug() << "Got the MyEnum: " << static_cast<int>(e);
        }
        void OnGettingEnum2(MyNamespace::MyEnum2 e) {
            qDebug() << "Received on thread: " << QThread::currentThread();
            qDebug() << "Got the MyEnum2: " << static_cast<int>(e);
        }
        void OnGettingStruct(MyNamespace::MyStruct s) {
            qDebug() << "Received on thread: " << QThread::currentThread();
            qDebug() << "Got the MyStruct";
        }
        void OnGettingStruct2(MyNamespace::MyStruct2 s) {
            qDebug() << "Received on thread: " << QThread::currentThread();
            qDebug() << "Got the MyStruct2";
        }
};