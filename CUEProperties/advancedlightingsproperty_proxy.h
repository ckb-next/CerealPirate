#ifndef AdvancedLightingsProperty_Proxy_H
#define AdvancedLightingsProperty_Proxy_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class AdvancedLightingsProperty_Proxy : public BaseProperty
{
public:
    AdvancedLightingsProperty_Proxy() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(AdvancedLightingsProperty_Proxy, 200)
CEREAL_REGISTER_TYPE_WITH_NAME(AdvancedLightingsProperty_Proxy, "AdvancedLightingsProperty::Proxy")
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, AdvancedLightingsProperty_Proxy)
#endif // AdvancedLightingsProperty_Proxy_H
