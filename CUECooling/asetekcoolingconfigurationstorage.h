#ifndef ASETEKCOOLINGCONFIGURATIONSTORAGE_H
#define ASETEKCOOLINGCONFIGURATIONSTORAGE_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "coolingconfigurationstoragebase.h"

class AsetekCoolingConfigurationStorage : public CoolingConfigurationStorageBase
{
public:
    AsetekCoolingConfigurationStorage()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created AsetekCoolingConfigurationStorage" << std::endl;
#endif
    }
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CoolingConfigurationStorageBase>(this)));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(AsetekCoolingConfigurationStorage, 300)
CEREAL_REGISTER_TYPE(AsetekCoolingConfigurationStorage)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CoolingConfigurationStorageBase, AsetekCoolingConfigurationStorage)

#endif // ASETEKCOOLINGCONFIGURATIONSTORAGE_H
