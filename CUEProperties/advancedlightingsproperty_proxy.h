#ifndef AdvancedLightingsProperty_Proxy_H
#define AdvancedLightingsProperty_Proxy_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/types/unordered_map.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"
#include "channelpropertiesclass.h"

class AdvancedLightingsProperty_Proxy : public BaseProperty
{
public:
    AdvancedLightingsProperty_Proxy()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created Proxy" << std::endl;
#endif
    }
    QString value;
    std::unordered_map<bool, std::unique_ptr<ChannelPropertiesClass>> properties;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(properties));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(AdvancedLightingsProperty_Proxy, 200)
CEREAL_REGISTER_TYPE_WITH_NAME(AdvancedLightingsProperty_Proxy, "AdvancedLightingsProperty::Proxy")
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, AdvancedLightingsProperty_Proxy)
#endif // AdvancedLightingsProperty_Proxy_H
