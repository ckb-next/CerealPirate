#ifndef CoolingConfigurationStorageBaseBase_H
#define CoolingConfigurationStorageBaseBase_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "coolingconfigurationbase.h"
#include "asetekcoolingconfiguration.h"

class CoolingConfigurationStorageBaseBase
{
public:
    CoolingConfigurationStorageBaseBase() {}
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
    }
};
CEREAL_CLASS_VERSION(CoolingConfigurationStorageBaseBase, 300)

#endif // CoolingConfigurationStorageBaseBase_H
