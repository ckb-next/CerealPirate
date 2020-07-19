#ifndef RippleLighting_H
#define RippleLighting_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "cueanimationwithtransitions.h"
#include "cuecolourclass.h"

class RippleLighting : public CUEAnimationWithTransitions
{
public:
    RippleLighting() {}
    unsigned int velocity;
    unsigned int tailLength;
    bool autoDuration;
    QString waveSpread;
    CUEColourClass colors;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationWithTransitions>(this)),
           CEREAL_NVP(velocity), CEREAL_NVP(tailLength), CEREAL_NVP(autoDuration), CEREAL_NVP(waveSpread),
           CEREAL_NVP(colors));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(RippleLighting, 201)
CEREAL_REGISTER_TYPE(RippleLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, RippleLighting)

#endif // RippleLighting_H
