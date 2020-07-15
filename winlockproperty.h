#ifndef WinlockProperty_H
#define WinlockProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class WinlockProperty : public BaseProperty
{
public:
    WinlockProperty() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(WinlockProperty, 200)
CEREAL_REGISTER_TYPE(WinlockProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, WinlockProperty)
#endif // WinlockProperty_H
