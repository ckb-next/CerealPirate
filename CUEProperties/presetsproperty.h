#ifndef PresetsProperty_H
#define PresetsProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class PresetsProperty : public BaseProperty
{
public:
    PresetsProperty() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(PresetsProperty, 200)
CEREAL_REGISTER_TYPE(PresetsProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, PresetsProperty)
#endif // PresetsProperty_H
