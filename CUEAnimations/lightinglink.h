#ifndef LightingLink_H
#define LightingLink_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "cueanimationbase.h"
#include "cuecolourclass.h"
#include "../basiclightinglayer.h"

// This parent class might be wrong, but we don't serialise it...
class LightingLinkLayer : public BasicLightingLayer
{
public:
    LightingLinkLayer()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created LightingLinkLayer" << std::endl;
#endif
    }
    std::shared_ptr<CUEAnimationBase> lighting;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(lighting));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(LightingLinkLayer, 300)
CEREAL_REGISTER_TYPE(LightingLinkLayer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BasicLightingLayer, LightingLinkLayer)


class LightingLink : public CUEAnimationBase
{
public:
    LightingLink()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created LightingLink" << std::endl;
#endif
    }
    std::shared_ptr<LightingLinkLayer> layer;

    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationBase>(this)), CEREAL_NVP(layer));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(LightingLink, 300)
CEREAL_REGISTER_TYPE(LightingLink)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, LightingLink)

#endif // LightingLink_H
