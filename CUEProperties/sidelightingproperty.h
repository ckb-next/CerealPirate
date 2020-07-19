#ifndef SideLightingProperty_H
#define SideLightingProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class SideLightingProperty : public BaseProperty
{
public:
    SideLightingProperty() {}
    bool enabled;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(enabled));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(SideLightingProperty, 200)
CEREAL_REGISTER_TYPE(SideLightingProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, SideLightingProperty)
#endif // SideLightingProperty_H
