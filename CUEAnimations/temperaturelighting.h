#ifndef TemperatureLighting_H
#define TemperatureLighting_H
#include <cereal/types/polymorphic.hpp>
#include "cueanimationbase.h"
#include "cuecolourclass.h"
#include "cueanimationwithtransitions.h"
#include <cereal/archives/xml.hpp>

#warning "FIXME: find a better name for the properties class. It might even be a duplicate"
class TemperatureLightingProperties : public CUEAnimationBase
{
public:
    TemperatureLightingProperties()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created TemperatureLightingProperties" << std::endl;
#endif
    }
    QString sensorId;
    std::vector<CUEAnimationTransition> transitions;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationBase>(this)), CEREAL_NVP(sensorId),
           CEREAL_NVP(transitions));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(TemperatureLightingProperties, 300)
CEREAL_REGISTER_TYPE(TemperatureLightingProperties)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, TemperatureLightingProperties)

class TemperatureLighting : public CUEAnimationBase
{
public:
    TemperatureLighting()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created TemperatureLighting" << std::endl;
#endif
    }
    std::unique_ptr<TemperatureLightingProperties> impl;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationBase>(this)), CEREAL_NVP(impl));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(TemperatureLighting, 301)
CEREAL_REGISTER_TYPE(TemperatureLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, TemperatureLighting)

#endif // TemperatureLighting_H
