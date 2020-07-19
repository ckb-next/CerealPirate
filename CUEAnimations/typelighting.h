#ifndef TypeLighting_H
#define TypeLighting_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "cueanimationbase.h"
#include "cuecolourclass.h"
#include <cstdint>

class TypeLighting : public CUEAnimationBase
{
public:
    TypeLighting() {}
    CUEColourClass colors;
    bool random;
    uint8_t opacity;
    int speed;
    unsigned int duration;
    int typeLightingBehavior; // FIXME: This is most likely an enum
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationBase>(this)), CEREAL_NVP(colors),
           CEREAL_NVP(random), CEREAL_NVP(opacity), CEREAL_NVP(speed), CEREAL_NVP(duration),
           CEREAL_NVP(typeLightingBehavior));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(TypeLighting, 300)
CEREAL_REGISTER_TYPE(TypeLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, TypeLighting)

#endif // TypeLighting_H
