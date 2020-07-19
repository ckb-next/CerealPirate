#ifndef TemperatureAlertProperty_H
#define TemperatureAlertProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class TemperatureAlertProperty : public BaseProperty
{
public:
    TemperatureAlertProperty() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(TemperatureAlertProperty, 300)
CEREAL_REGISTER_TYPE(TemperatureAlertProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, TemperatureAlertProperty)
#endif // TemperatureAlertProperty_H
