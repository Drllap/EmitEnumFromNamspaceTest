#include "Sender.h"

#include "Receiver.h"

MyNamespace::Sender* MyNamespace::Connect()
{
        auto s = new Sender();
        auto r = new Receiver();

        QObject::connect(s, &Sender::EmitEnum,  r, &Receiver::OnGettingEnum);
        QObject::connect(s, &Sender::EmitEnum2, r, &Receiver::OnGettingEnum2);
        QObject::connect(s, &Sender::EmitStruct, r, &Receiver::OnGettingStruct);
        QObject::connect(s, &Sender::EmitStruct2, r, &Receiver::OnGettingStruct2);
        return s;
}
