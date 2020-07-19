#ifndef RainbowWaveLighting_H
#define RainbowWaveLighting_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "cueanimationbase.h"
#include "cuecolourclass.h"

class RainbowWaveLighting : public CUEAnimationBase
{
public:
    RainbowWaveLighting() {}
    int speed;
    int direction;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationBase>(this)), CEREAL_NVP(speed),
           CEREAL_NVP(direction));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(RainbowWaveLighting, 301)
CEREAL_REGISTER_TYPE(RainbowWaveLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, RainbowWaveLighting)

#endif // RainbowWaveLighting_H
