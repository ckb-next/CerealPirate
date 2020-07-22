#ifndef TemperatureAlertProperty_H
#define TemperatureAlertProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class TemperatureAlertProperty : public BaseProperty
{
public:
    TemperatureAlertProperty()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created TemperatureAlertProperty" << std::endl;
#endif
    }
#warning "FIXME: these are definitely not ints"
    std::vector<int> assignments;
    std::vector<int> alerts;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(assignments),
           CEREAL_NVP(alerts));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(TemperatureAlertProperty, 300)
CEREAL_REGISTER_TYPE(TemperatureAlertProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, TemperatureAlertProperty)
#endif // TemperatureAlertProperty_H
