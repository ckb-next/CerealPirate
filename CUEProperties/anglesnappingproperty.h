#ifndef ANGLESNAPPINGPROPERTY_H
#define ANGLESNAPPINGPROPERTY_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class AngleSnappingProperty : public BaseProperty
{
public:
    AngleSnappingProperty()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created AngleSnappingProperty" << std::endl;
#endif
    }
    bool enabled;
    int value; // This is also most likely an enum
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(enabled), CEREAL_NVP(value));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(AngleSnappingProperty, 200)
CEREAL_REGISTER_TYPE(AngleSnappingProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, AngleSnappingProperty)
#endif // ANGLESNAPPINGPROPERTY_H
