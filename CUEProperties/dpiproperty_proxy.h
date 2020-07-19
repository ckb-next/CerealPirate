#ifndef DPIProperty_Proxy_H
#define DPIProperty_Proxy_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class DPIProperty_Proxy : public BaseProperty
{
public:
    DPIProperty_Proxy() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(DPIProperty_Proxy, 200)
CEREAL_REGISTER_TYPE_WITH_NAME(DPIProperty_Proxy, "DPIProperty::Proxy")
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, DPIProperty_Proxy)
#endif // DPIProperty_Proxy_H
