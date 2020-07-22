#ifndef AGGREGATEDLIGHTINGSPROPERTY_PROXY_H
#define AGGREGATEDLIGHTINGSPROPERTY_PROXY_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/types/map.hpp>
#include <QString>
#include "baseproperty.h"
#include "../cuedevice.h"
#include "channelpropertiescontainerclass.h"

class AggregatedLightingsProperty_Proxy : public BaseProperty
{
public:
    AggregatedLightingsProperty_Proxy()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created Proxy" << std::endl;
#endif
    }
    std::map<CUEDevice, std::unique_ptr<ChannelPropertiesContainerClass>, CUEDeviceComparator> properties;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(properties));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(AggregatedLightingsProperty_Proxy, 300)
CEREAL_REGISTER_TYPE_WITH_NAME(AggregatedLightingsProperty_Proxy, "AggregatedLightingsProperty::Proxy")
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, AggregatedLightingsProperty_Proxy)

#endif // AGGREGATEDLIGHTINGSPROPERTY_PROXY_H
