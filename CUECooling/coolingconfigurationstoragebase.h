#ifndef COOLINGCONFIGURATIONSTORAGEBASE_H
#define COOLINGCONFIGURATIONSTORAGEBASE_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "coolingconfigurationstoragebasebase.h"
#include "asetekcoolingconfiguration.h"

class CoolingConfigurationStorageBase : public CoolingConfigurationStorageBaseBase
{
public:
    CoolingConfigurationStorageBase()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created CoolingConfigurationStorageBase" << std::endl;
#endif
    }
    std::vector<std::shared_ptr<CoolingConfigurationBase>> configurations;
    bool supportExternalSensor;
    bool supportsCreateCoolingConfigurations;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CoolingConfigurationStorageBaseBase>(this)),
           CEREAL_NVP(configurations), CEREAL_NVP(supportExternalSensor), CEREAL_NVP(supportsCreateCoolingConfigurations));
    }
    virtual void Dummy() = 0;
};
CEREAL_CLASS_VERSION(CoolingConfigurationStorageBase, 301)

#endif // COOLINGCONFIGURATIONSTORAGEBASE_H
