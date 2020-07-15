#ifndef LIFTHEIGHTPROPERTY_H
#define LIFTHEIGHTPROPERTY_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class LiftHeightProperty : public BaseProperty
{
public:
    LiftHeightProperty() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(value));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(LiftHeightProperty, 200)
CEREAL_REGISTER_TYPE(LiftHeightProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, LiftHeightProperty)
#endif // LIFTHEIGHTPROPERTY_H
