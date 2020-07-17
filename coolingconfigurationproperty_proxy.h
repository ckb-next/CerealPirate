#ifndef CoolingConfigurationProperty_Proxy_H
#define CoolingConfigurationProperty_Proxy_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class CoolingConfigurationProperty_Proxy : public BaseProperty
{
public:
    CoolingConfigurationProperty_Proxy() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(CoolingConfigurationProperty_Proxy, 300)
CEREAL_REGISTER_TYPE_WITH_NAME(CoolingConfigurationProperty_Proxy, "CoolingConfigurationProperty::Proxy")
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, CoolingConfigurationProperty_Proxy)
#endif // CoolingConfigurationProperty_Proxy_H
