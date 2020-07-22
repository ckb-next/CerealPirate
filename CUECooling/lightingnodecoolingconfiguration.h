#ifndef LightingNodeCoolingConfiguration_H
#define LightingNodeCoolingConfiguration_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "CUEProperties/coolingconfigurationproperty_proxy.h"
#include "coolingconfigurationbase.h"

class CustomLightingNodeModePoint
{
public:
    CustomLightingNodeModePoint()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created CustomLightingNodeModePoint" << std::endl;
#endif
    }
    bool enabled;
    int temperature;
    int rpm;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(enabled), CEREAL_NVP(temperature), CEREAL_NVP(rpm));
    }
};
CEREAL_CLASS_VERSION(CustomLightingNodeModePoint, 300)


class LightingNodeCoolingConfiguration : public CoolingConfigurationBase
{
public:
    LightingNodeCoolingConfiguration()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created LightingNodeCoolingConfiguration" << std::endl;
#endif
    }
    void Dummy() {}
    int fanMode;
    int fixedPercents;
    int fixedRpm;
    CustomLightingNodeModePoint customModePoints[6];
    QString sensorId;
    bool isHydroXExclusive;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CoolingConfigurationBase>(this)), CEREAL_NVP(fanMode),
           CEREAL_NVP(fixedPercents), CEREAL_NVP(fixedRpm), CEREAL_NVP(customModePoints), CEREAL_NVP(sensorId),
           CEREAL_NVP(isHydroXExclusive));
    }
};
CEREAL_CLASS_VERSION(LightingNodeCoolingConfiguration, 301)
CEREAL_REGISTER_TYPE(LightingNodeCoolingConfiguration)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CoolingConfigurationBase, LightingNodeCoolingConfiguration)

#endif // LightingNodeCoolingConfiguration_H
