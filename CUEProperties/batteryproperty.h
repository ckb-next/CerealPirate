#ifndef BatteryProperty_H
#define BatteryProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class BatteryProperty : public BaseProperty
{
public:
    BatteryProperty() {}
    int lowBatteryIntervalIndex;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(lowBatteryIntervalIndex));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(BatteryProperty, 200)
CEREAL_REGISTER_TYPE(BatteryProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, BatteryProperty)
#endif // BatteryProperty_H
