#ifndef WaveLighting_H
#define WaveLighting_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "cueanimationwithtransitions.h"

class WaveLighting : public CUEAnimationWithTransitions
{
public:
    WaveLighting() {}
    unsigned int velocity;
    unsigned int tailLength;
    bool isDoublesided;
    int angle;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationWithTransitions>(this)),
           CEREAL_NVP(velocity), CEREAL_NVP(tailLength), CEREAL_NVP(isDoublesided), CEREAL_NVP(angle));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(WaveLighting, 300)
CEREAL_REGISTER_TYPE(WaveLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, WaveLighting)

#endif // WaveLighting_H
