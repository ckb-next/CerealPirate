#ifndef STATICLIGHTING_H
#define STATICLIGHTING_H
#include "cueanimationwithtransitions.h"
#include "cueanimationbase.h"
#include <cstdint>

class StaticLighting : public CUEAnimationWithTransitions
{
public:
    StaticLighting() {}
    uint8_t opacity;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationWithTransitions>(this)), CEREAL_NVP(opacity));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(StaticLighting, 201)
CEREAL_REGISTER_TYPE(StaticLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, StaticLighting)
#endif // STATICLIGHTING_H
