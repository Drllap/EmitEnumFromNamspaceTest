#pragma once

#include <QObject>

namespace MyNamespace {
    enum class MyEnum : uint64_t { one, two, three, };
    enum class MyEnum2 : uint64_t { one, two, three, };

    struct MyStruct
    {
        int i{};
        double d{};
    };

    struct MyStruct2
    {
        int i{};
        double d{};
    };

    class Sender : public QObject
    {
        Q_OBJECT
    signals:
        void EmitEnum(MyEnum);
        void EmitEnum2(MyEnum2);
        void EmitStruct(MyStruct);
        void EmitStruct2(MyStruct2);
    };

    Sender* Connect();
}
