#ifndef LightingLinkProperty_H
#define LightingLinkProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class LightingLinkProperty : public BaseProperty
{
public:
    LightingLinkProperty() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(LightingLinkProperty, 300)
CEREAL_REGISTER_TYPE(LightingLinkProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, LightingLinkProperty)
#endif // LightingLinkProperty_H
