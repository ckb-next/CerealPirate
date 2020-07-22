#ifndef HardwareMetaProperty_Proxy_H
#define HardwareMetaProperty_Proxy_H
#include <cereal/types/unordered_map.hpp>
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "baseproperty.h"

class HardwareMetaProperty : public BaseProperty
{
public:
    int cookie;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(cookie));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(HardwareMetaProperty, 300)
CEREAL_REGISTER_TYPE(HardwareMetaProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, HardwareMetaProperty)

class HardwareMetaProperty_Proxy : public BaseProperty
{
public:
    HardwareMetaProperty_Proxy()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created Proxy" << std::endl;
#endif
    }
    std::unordered_map<bool, std::unique_ptr<HardwareMetaProperty>> properties;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(properties));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(HardwareMetaProperty_Proxy, 200)
CEREAL_REGISTER_TYPE_WITH_NAME(HardwareMetaProperty_Proxy, "HardwareMetaProperty::Proxy")
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, HardwareMetaProperty_Proxy)
#endif // HardwareMetaProperty_Proxy_H
