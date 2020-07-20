#ifndef DolbyProperty_H
#define DolbyProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "baseproperty.h"

class DolbyProperty : public BaseProperty
{
public:
    DolbyProperty() {}
    bool enabled;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(enabled));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(DolbyProperty, 200)
CEREAL_REGISTER_TYPE(DolbyProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, DolbyProperty)
#endif // DolbyProperty_H
