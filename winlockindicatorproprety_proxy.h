#ifndef WinlockIndicatorProperty_Proxy_H
#define WinlockIndicatorProperty_Proxy_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class WinlockIndicatorProperty_Proxy : public BaseProperty
{
public:
    WinlockIndicatorProperty_Proxy() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(WinlockIndicatorProperty_Proxy, 200)
CEREAL_REGISTER_TYPE_WITH_NAME(WinlockIndicatorProperty_Proxy, "WinlockIndicatorProperty::Proxy")
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, WinlockIndicatorProperty_Proxy)
#endif // WinlockIndicatorProperty_Proxy_H
