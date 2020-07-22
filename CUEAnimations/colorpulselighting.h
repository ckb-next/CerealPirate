#ifndef ColorPulseLighting_H
#define ColorPulseLighting_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "cueanimationbase.h"
#include "cuecolourclass.h"

class ColorPulseLighting : public CUEAnimationBase
{
public:
    ColorPulseLighting()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created ColorPulseLighting" << std::endl;
#endif
    }
    CUEColourClass colors;
    bool random;
    int speed;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationBase>(this)), CEREAL_NVP(colors),
           CEREAL_NVP(random), CEREAL_NVP(speed));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(ColorPulseLighting, 300)
CEREAL_REGISTER_TYPE(ColorPulseLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, ColorPulseLighting)

#endif // ColorPulseLighting_H
