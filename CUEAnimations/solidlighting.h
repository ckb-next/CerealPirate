#ifndef SolidLighting_H
#define SolidLighting_H
#include "cueanimationwithtransitions.h"
#include "cueanimationbase.h"

class SolidLighting : public CUEAnimationWithTransitions
{
public:
    SolidLighting() {}
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationWithTransitions>(this)));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(SolidLighting, 201)
CEREAL_REGISTER_TYPE(SolidLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, SolidLighting)
#endif // SolidLighting_H
