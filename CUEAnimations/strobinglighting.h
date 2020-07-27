#ifndef StrobingLighting_H
#define StrobingLighting_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "cueanimationbase.h"
#include "cuecolourclass.h"

class StrobingLighting : public CUEAnimationBase
{
public:
    StrobingLighting()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created StrobingLighting" << std::endl;
#endif
    }
    bool isRandom;
    CUEColourClass colors;
    int speed;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationBase>(this)), CEREAL_NVP(isRandom),
           CEREAL_NVP(colors), CEREAL_NVP(speed));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(StrobingLighting, 300)
CEREAL_REGISTER_TYPE(StrobingLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, StrobingLighting)

#endif // StrobingLighting_H
