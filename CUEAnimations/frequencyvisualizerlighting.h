#ifndef FrequencyVisualizerLighting_H
#define FrequencyVisualizerLighting_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "cueanimationbase.h"
#include "cuecolourclass.h"

class FrequencyVisualizerLighting : public CUEAnimationBase
{
public:
    FrequencyVisualizerLighting() {}
    QString presentation;
    QString visualization;
    CUEColourClass colors;
    bool useRandomColors;
    int direction;
    int frequencyLightingType; // FIXME: This is most likely an enum
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationBase>(this)), CEREAL_NVP(presentation),
           CEREAL_NVP(visualization), CEREAL_NVP(colors), CEREAL_NVP(useRandomColors), CEREAL_NVP(direction),
           CEREAL_NVP(frequencyLightingType));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(FrequencyVisualizerLighting, 301)
CEREAL_REGISTER_TYPE(FrequencyVisualizerLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, FrequencyVisualizerLighting)

#endif // FrequencyVisualizerLighting_H
