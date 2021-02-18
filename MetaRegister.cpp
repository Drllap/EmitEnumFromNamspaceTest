#include "MetaRegister.h"

#include <QMetaType>
#include <QDebug>

#include "Sender.h"

namespace MyNamespace {
    Q_DECLARE_METATYPE(MyEnum)
    Q_DECLARE_METATYPE(MyStruct)
}

Q_DECLARE_METATYPE(MyNamespace::MyEnum2)
Q_DECLARE_METATYPE(MyNamespace::MyStruct2)

void MetaRegister::RegisterAllOfTheThings()
{
    qDebug() << "Registering meta type: " << qRegisterMetaType<MyNamespace::MyEnum>();
    qDebug() << "Registering meta type: " << qRegisterMetaType<MyNamespace::MyEnum2>();
    qDebug() << "Registering meta type: " << qRegisterMetaType<MyNamespace::MyStruct>();
    qDebug() << "Registering meta type: " << qRegisterMetaType<MyNamespace::MyStruct2>();
}
