#ifndef RainbowLighting_H
#define RainbowLighting_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "cueanimationbase.h"
#include "cuecolourclass.h"

class RainbowLighting : public CUEAnimationBase
{
public:
    RainbowLighting() {}
    int speed;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationBase>(this)), CEREAL_NVP(speed));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(RainbowLighting, 300)
CEREAL_REGISTER_TYPE(RainbowLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, RainbowLighting)

#endif // RainbowLighting_H
