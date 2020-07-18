#ifndef GRADIENTLIGHTING_H
#define GRADIENTLIGHTING_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "cueanimationwithtransitions.h"

class GradientLighting : public CUEAnimationWithTransitions
{
public:
    GradientLighting() {}
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationWithTransitions>(this)));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(GradientLighting, 300)
CEREAL_REGISTER_TYPE(GradientLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, GradientLighting)

#endif // GRADIENTLIGHTING_H
