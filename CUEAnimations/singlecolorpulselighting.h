#ifndef SingleColorPulseLighting_H
#define SingleColorPulseLighting_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "cueanimationbase.h"
#include "cuecolourclass.h"
#include <cstdint>

class SingleColorPulseLighting : public CUEAnimationBase
{
public:
    SingleColorPulseLighting()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created SingleColorPulseLighting" << std::endl;
#endif
    }
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
CEREAL_CLASS_VERSION(SingleColorPulseLighting, 300)
CEREAL_REGISTER_TYPE(SingleColorPulseLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, SingleColorPulseLighting)

#endif // SingleColorPulseLighting_H
