#ifndef StarCoolingConfiguration_H
#define StarCoolingConfiguration_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "CUEProperties/coolingconfigurationproperty_proxy.h"
#include "coolingconfigurationbase.h"

class StarCoolingConfiguration : public CoolingConfigurationBase
{
public:
    StarCoolingConfiguration()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created StarCoolingConfiguration" << std::endl;
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
CEREAL_CLASS_VERSION(StarCoolingConfiguration, 300)
CEREAL_REGISTER_TYPE(StarCoolingConfiguration)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CoolingConfigurationBase, StarCoolingConfiguration)

#endif // StarCoolingConfiguration_H
