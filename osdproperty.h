#ifndef OSDProperty_H
#define OSDProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class OSDProperty : public BaseProperty
{
public:
    OSDProperty() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(OSDProperty, 200)
CEREAL_REGISTER_TYPE(OSDProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, OSDProperty)
#endif // OSDProperty_H
