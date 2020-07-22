#ifndef ColorWaveLighting_H
#define ColorWaveLighting_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "cueanimationbase.h"
#include "cuecolourclass.h"

class ColorWaveLighting : public CUEAnimationBase
{
public:
    ColorWaveLighting()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created ColorWaveLighting" << std::endl;
#endif
    }
    int speed;
    bool random;
    CUEColourClass colors;
    int direction;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        // The class isn't called "base" here for some reason, so no NVP...
        ar(cereal::virtual_base_class<CUEAnimationBase>(this), CEREAL_NVP(speed),
           CEREAL_NVP(random), CEREAL_NVP(colors), CEREAL_NVP(direction));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(ColorWaveLighting, 300)
CEREAL_REGISTER_TYPE(ColorWaveLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, ColorWaveLighting)

#endif // ColorWaveLighting_H
