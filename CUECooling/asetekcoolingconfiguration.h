#ifndef ASETEKCOOLINGCONFIGURATION_H
#define ASETEKCOOLINGCONFIGURATION_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "CUEProperties/coolingconfigurationproperty_proxy.h"
#include "coolingconfigurationbase.h"

class AsetekCoolingConfiguration : public CoolingConfigurationBase
{
public:
    AsetekCoolingConfiguration()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created AsetekCoolingConfiguration" << std::endl;
#endif
    }
    void Dummy() {}
    int pumpMode;
    int fanMode;
    int fixedPercents;
    CustomModePoint customModePoints[6];
    QString sensorId;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CoolingConfigurationBase>(this)), CEREAL_NVP(pumpMode),
           CEREAL_NVP(fanMode), CEREAL_NVP(fixedPercents), CEREAL_NVP(customModePoints), CEREAL_NVP(sensorId));
    }
};
CEREAL_CLASS_VERSION(AsetekCoolingConfiguration, 300)
CEREAL_REGISTER_TYPE(AsetekCoolingConfiguration)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CoolingConfigurationBase, AsetekCoolingConfiguration)

#endif // ASETEKCOOLINGCONFIGURATION_H
