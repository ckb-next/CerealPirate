#ifndef VisorLighting_H
#define VisorLighting_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "cueanimationbase.h"
#include "cuecolourclass.h"

class VisorLighting : public CUEAnimationBase
{
public:
    VisorLighting()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created VisorLighting" << std::endl;
#endif
    }
    CUEColourClass colors;
    bool random;
    int speed;
    int direction;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationBase>(this)), CEREAL_NVP(colors),
           CEREAL_NVP(random), CEREAL_NVP(speed), CEREAL_NVP(direction));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(VisorLighting, 301)
CEREAL_REGISTER_TYPE(VisorLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, VisorLighting)

#endif // VisorLighting_H
