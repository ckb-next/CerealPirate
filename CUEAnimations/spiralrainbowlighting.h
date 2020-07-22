#ifndef SpiralRainbowLighting_H
#define SpiralRainbowLighting_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "cueanimationbase.h"
#include "cuecolourclass.h"

class SpiralRainbowLighting : public CUEAnimationBase
{
public:
    SpiralRainbowLighting()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created SpiralRainbowLighting" << std::endl;
#endif
    }
    bool clockwise;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationBase>(this)), CEREAL_NVP(clockwise));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(SpiralRainbowLighting, 300)
CEREAL_REGISTER_TYPE(SpiralRainbowLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, SpiralRainbowLighting)

#endif // SpiralRainbowLighting_H
