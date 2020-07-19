#ifndef IndicatorBrightnessProperty_H
#define IndicatorBrightnessProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class IndicatorBrightnessProperty : public BaseProperty
{
public:
    IndicatorBrightnessProperty() {}
    int IndicatorBrightness;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(IndicatorBrightness));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(IndicatorBrightnessProperty, 200)
CEREAL_REGISTER_TYPE(IndicatorBrightnessProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, IndicatorBrightnessProperty)
#endif // IndicatorBrightnessProperty_H
