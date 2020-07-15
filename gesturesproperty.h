#ifndef GesturesProperty_H
#define GesturesProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class GesturesProperty : public BaseProperty
{
public:
    GesturesProperty() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(GesturesProperty, 301)
CEREAL_REGISTER_TYPE(GesturesProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, GesturesProperty)
#endif // GesturesProperty_H
