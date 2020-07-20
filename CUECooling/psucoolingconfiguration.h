#ifndef PSUCoolingConfiguration_H
#define PSUCoolingConfiguration_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "CUEProperties/coolingconfigurationproperty_proxy.h"
#include "coolingconfigurationbase.h"

class PSUCoolingConfiguration : public CoolingConfigurationBase
{
public:
    PSUCoolingConfiguration() {}
    void Dummy() {}
    int fanMode;
    int fixedPercents;
    CustomModePoint customModePoints[6];
    QString sensorId;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CoolingConfigurationBase>(this)), CEREAL_NVP(fanMode),
           CEREAL_NVP(fixedPercents), CEREAL_NVP(customModePoints), CEREAL_NVP(sensorId));
    }
};
CEREAL_CLASS_VERSION(PSUCoolingConfiguration, 300)
CEREAL_REGISTER_TYPE(PSUCoolingConfiguration)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CoolingConfigurationBase, PSUCoolingConfiguration)

#endif // PSUCoolingConfiguration_H
