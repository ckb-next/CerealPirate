#ifndef BasicLightingsProperty_Proxy_H
#define BasicLightingsProperty_Proxy_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/types/unordered_map.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"
#include "../cuedevice.h"
#include "channelpropertiesbase.h"

#warning "FIXME: Split this off when we find out what it is"
// it might already exist as another class
class UnknownLightingProperty : public ChannelPropertiesBase
{
public:
    UnknownLightingProperty() {}
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<ChannelPropertiesBase>(this)));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(UnknownLightingProperty, 300)
CEREAL_REGISTER_TYPE(UnknownLightingProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, UnknownLightingProperty)

// FIXME: This isn't the right base property
// ChannelPropertiesBase doesn't work for some reason
class BasicLightingsProperty_Proxy : public BaseProperty
{
public:
    BasicLightingsProperty_Proxy() {}
    std::map<CUEDeviceNoCaps, std::unique_ptr<UnknownLightingProperty>, CUEDeviceNoCapsComparator> properties;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(properties));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(BasicLightingsProperty_Proxy, 301)
CEREAL_REGISTER_TYPE_WITH_NAME(BasicLightingsProperty_Proxy, "BasicLightingsProperty::Proxy")
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, BasicLightingsProperty_Proxy)
#endif // BasicLightingsProperty_Proxy_H
