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
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(AllDevicesCoolingProperty, 300)
CEREAL_REGISTER_TYPE(AllDevicesCoolingProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, AllDevicesCoolingProperty)
#endif // AllDevicesCoolingProperty_H
