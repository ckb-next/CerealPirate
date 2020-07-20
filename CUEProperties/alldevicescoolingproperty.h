#ifndef AllDevicesCoolingProperty_H
#define AllDevicesCoolingProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class AllDevicesCoolingProperty : public BaseProperty
{
public:
    AllDevicesCoolingProperty() {}
    bool enabled;
    int fixedPercents;
    int activeMode;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(enabled),
           CEREAL_NVP(fixedPercents), CEREAL_NVP(activeMode));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(AllDevicesCoolingProperty, 300)
CEREAL_REGISTER_TYPE(AllDevicesCoolingProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, AllDevicesCoolingProperty)
#endif // AllDevicesCoolingProperty_H
