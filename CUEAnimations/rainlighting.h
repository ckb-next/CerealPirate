#ifndef RainLighting_H
#define RainLighting_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "cueanimationbase.h"
#include "cuecolourclass.h"
#include <cstdint>

class RainLighting : public CUEAnimationBase
{
public:
    RainLighting()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created RainLighting" << std::endl;
#endif
    }
    CUEColourClass colors;
    bool random;
    uint8_t opacity;
    int speed;
    int direction;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationBase>(this)), CEREAL_NVP(colors),
           CEREAL_NVP(random), CEREAL_NVP(opacity), CEREAL_NVP(speed), CEREAL_NVP(direction));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(RainLighting, 301)
CEREAL_REGISTER_TYPE(RainLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, RainLighting)

#endif // RainLighting_H
