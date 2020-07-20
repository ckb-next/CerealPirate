#ifndef LightingNodeConfigurationStorage_H
#define LightingNodeConfigurationStorage_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "coolingconfigurationstoragebase.h"

class LightingNodeConfigurationStorage : public CoolingConfigurationStorageBase
{
public:
    LightingNodeConfigurationStorage() {}
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CoolingConfigurationStorageBase>(this)));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(LightingNodeConfigurationStorage, 300)
CEREAL_REGISTER_TYPE(LightingNodeConfigurationStorage)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CoolingConfigurationStorageBase, LightingNodeConfigurationStorage)

#endif // LightingNodeConfigurationStorage_H
