#ifndef PSUCoolingConfigurationStorage_H
#define PSUCoolingConfigurationStorage_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "coolingconfigurationstoragebase.h"

class PSUCoolingConfigurationStorage : public CoolingConfigurationStorageBase
{
public:
    PSUCoolingConfigurationStorage() {}
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CoolingConfigurationStorageBase>(this)));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(PSUCoolingConfigurationStorage, 300)
CEREAL_REGISTER_TYPE(PSUCoolingConfigurationStorage)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CoolingConfigurationStorageBase, PSUCoolingConfigurationStorage)

#endif // PSUCoolingConfigurationStorage_H
