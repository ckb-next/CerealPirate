#ifndef DPIProperty_Proxy_H
#define DPIProperty_Proxy_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class DPIProperty : public BaseProperty
{
public:
    DPIProperty() {}
    QString id;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(id));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(DPIProperty, 200)
CEREAL_REGISTER_TYPE(DPIProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, DPIProperty)

class DPIProperty_Proxy : public BaseProperty
{
public:
    DPIProperty_Proxy() {}
    std::map<int, std::unique_ptr<DPIProperty>> properties;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(properties));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(DPIProperty_Proxy, 200)
CEREAL_REGISTER_TYPE_WITH_NAME(DPIProperty_Proxy, "DPIProperty::Proxy")
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, DPIProperty_Proxy)
#endif // DPIProperty_Proxy_H
