#ifndef PlatinumCoolersConfigurationStorage_H
#define PlatinumCoolersConfigurationStorage_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "coolingconfigurationstoragebase.h"

class PlatinumCoolersConfigurationStorage : public CoolingConfigurationStorageBase
{
public:
    PlatinumCoolersConfigurationStorage()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created PlatinumCoolersConfigurationStorage" << std::endl;
#endif
    }
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CoolingConfigurationStorageBase>(this)));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(PlatinumCoolersConfigurationStorage, 300)
CEREAL_REGISTER_TYPE(PlatinumCoolersConfigurationStorage)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CoolingConfigurationStorageBase, PlatinumCoolersConfigurationStorage)

#endif // PlatinumCoolersConfigurationStorage_H
