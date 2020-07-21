#ifndef SingleColorVisorLighting_H
#define SingleColorVisorLighting_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "cueanimationbase.h"
#include "cuecolourclass.h"
#include <cstdint>

class SingleColorVisorLighting : public CUEAnimationBase
{
public:
    SingleColorVisorLighting() {}
    uint8_t opacity;
    int speed;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationBase>(this)),
           CEREAL_NVP(opacity), CEREAL_NVP(speed));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(SingleColorVisorLighting, 300)
CEREAL_REGISTER_TYPE(SingleColorVisorLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, SingleColorVisorLighting)

#endif // SingleColorVisorLighting_H
