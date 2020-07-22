#ifndef BUTTONRESPONSEOPTIMIZATIONPROPERTY_H
#define BUTTONRESPONSEOPTIMIZATIONPROPERTY_H
#include <cereal/types/polymorphic.hpp>
#include "baseproperty.h"
#include <QString>
#include <cereal/archives/xml.hpp>
class ButtonResponseOptimizationProperty : public BaseProperty
{
public:
    ButtonResponseOptimizationProperty()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created ButtonResponseOptimizationProperty" << std::endl;
#endif
    }
    QString value;
    bool enabled;

    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(value), CEREAL_NVP(enabled));
    }
    void Dummy(){}
};
CEREAL_CLASS_VERSION(ButtonResponseOptimizationProperty, 200)
CEREAL_REGISTER_TYPE(ButtonResponseOptimizationProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, ButtonResponseOptimizationProperty)

#endif // BUTTONRESPONSEOPTIMIZATIONPROPERTY_H
