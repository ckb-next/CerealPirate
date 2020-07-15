#ifndef SystemPointerProperty_H
#define SystemPointerProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class SystemPointerProperty : public BaseProperty
{
public:
    SystemPointerProperty() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(SystemPointerProperty, 200)
CEREAL_REGISTER_TYPE(SystemPointerProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, SystemPointerProperty)
#endif // SystemPointerProperty_H
