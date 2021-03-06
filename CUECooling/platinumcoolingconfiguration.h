#ifndef PlatinumCoolingConfiguration_H
#define PlatinumCoolingConfiguration_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "CUEProperties/coolingconfigurationproperty_proxy.h"
#include "coolingconfigurationbase.h"

class PlatinumCoolingConfiguration : public CoolingConfigurationBase
{
public:
    PlatinumCoolingConfiguration()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created PlatinumCoolingConfiguration" << std::endl;
#endif
    }
    void Dummy() {}
    int pumpMode;
    int fanMode;
    int fixedPercents;
    int fixedRpm;
    CustomModePoint customModePoints[7];
    QString sensorId;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CoolingConfigurationBase>(this)), CEREAL_NVP(pumpMode),
           CEREAL_NVP(fanMode), CEREAL_NVP(fixedPercents), CEREAL_NVP(fixedRpm), CEREAL_NVP(customModePoints),
           CEREAL_NVP(sensorId));
    }
};
CEREAL_CLASS_VERSION(PlatinumCoolingConfiguration, 300)
CEREAL_REGISTER_TYPE(PlatinumCoolingConfiguration)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CoolingConfigurationBase, PlatinumCoolingConfiguration)

#endif // PlatinumCoolingConfiguration_H
