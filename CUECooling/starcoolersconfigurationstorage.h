#ifndef StarCoolersConfigurationStorage_H
#define StarCoolersConfigurationStorage_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "coolingconfigurationstoragebase.h"

class StarCoolersConfigurationStorage : public CoolingConfigurationStorageBase
{
public:
    StarCoolersConfigurationStorage()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created StarCoolersConfigurationStorage" << std::endl;
#endif
    }
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CoolingConfigurationStorageBase>(this)));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(StarCoolersConfigurationStorage, 300)
CEREAL_REGISTER_TYPE(StarCoolersConfigurationStorage)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CoolingConfigurationStorageBase, StarCoolersConfigurationStorage)

#endif // StarCoolersConfigurationStorage_H
