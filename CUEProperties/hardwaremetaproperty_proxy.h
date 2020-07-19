#ifndef HardwareMetaProperty_Proxy_H
#define HardwareMetaProperty_Proxy_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class HardwareMetaProperty_Proxy : public BaseProperty
{
public:
    HardwareMetaProperty_Proxy() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(HardwareMetaProperty_Proxy, 200)
CEREAL_REGISTER_TYPE_WITH_NAME(HardwareMetaProperty_Proxy, "HardwareMetaProperty::Proxy")
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, HardwareMetaProperty_Proxy)
#endif // HardwareMetaProperty_Proxy_H
