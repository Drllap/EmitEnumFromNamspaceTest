
#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include <QThread>

#include "MetaRegister.h"
#include "Sender.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MetaRegister::RegisterAllOfTheThings();

    auto sender = MyNamespace::Connect();
    qDebug() << "test";
    qDebug() << "Main thread: " << QThread::currentThread();
    QThread senderThread;
    senderThread.start();
    sender->moveToThread(&senderThread);

    QTimer::singleShot(5'000, sender, [sender](){
        qDebug() << "Sender thread: " << QThread::currentThread();
        qDebug() << "5 sec passed, emitting MyEnum";
        sender->EmitEnum(MyNamespace::MyEnum::one);
    });

    QTimer::singleShot(10'000, sender, [sender](){
        qDebug() << "Sender thread: " << QThread::currentThread();
        qDebug() << "10 sec passed, emitting MyEnum2";
        sender->EmitEnum2(MyNamespace::MyEnum2::two);
    });

    QTimer::singleShot(15'000, sender, [sender](){
        qDebug() << "Sender thread: " << QThread::currentThread();
        qDebug() << "15 sec passed, emitting MyStruct";
        sender->EmitStruct(MyNamespace::MyStruct{});
    });

    QTimer::singleShot(20'000, sender, [sender](){
        qDebug() << "Sender thread: " << QThread::currentThread();
        qDebug() << "20 sec passed, emitting MyStruct2";
        sender->EmitStruct2(MyNamespace::MyStruct2{});
    });

    return a.exec();
}