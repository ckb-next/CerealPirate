#ifndef ADVANCEDLIGHTINGLAYER_H
#define ADVANCEDLIGHTINGLAYER_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "cuekeybase.h"
#include "CUEAnimations/cueanimationbase.h"

class AdvancedLightingLayer : public CUEKeyBase
{
public:
    AdvancedLightingLayer() {}
    std::shared_ptr<CUEAnimationBase> lighting;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEKeyBase>(this)), CEREAL_NVP(lighting));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(AdvancedLightingLayer, 200)
CEREAL_REGISTER_TYPE(AdvancedLightingLayer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEKeyBase, AdvancedLightingLayer)

#endif // ADVANCEDLIGHTINGLAYER_H
