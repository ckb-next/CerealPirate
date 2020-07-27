#ifndef ColorWarpLighting_H
#define ColorWarpLighting_H
#include <cereal/types/polymorphic.hpp>
#include "cueanimationbase.h"
#include "cuecolourclass.h"
#include <cereal/archives/xml.hpp>

class ColorWarpLighting : public CUEAnimationBase
{
public:
    ColorWarpLighting()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created ColorWarpLighting" << std::endl;
#endif
    }
    int speed;
    int direction;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationBase>(this)),
           CEREAL_NVP(speed), CEREAL_NVP(direction));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(ColorWarpLighting, 300)
CEREAL_REGISTER_TYPE(ColorWarpLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, ColorWarpLighting)

#endif // ColorWarpLighting_H
