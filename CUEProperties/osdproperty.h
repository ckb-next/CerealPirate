#ifndef OSDProperty_H
#define OSDProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class OSDProperty : public BaseProperty
{
public:
    OSDProperty() {}
#warning "FIXME: Find the right data types for all the values"
    int profile;
    int dpi;
    int timer;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(profile),
           CEREAL_NVP(dpi), CEREAL_NVP(timer));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(OSDProperty, 200)
CEREAL_REGISTER_TYPE(OSDProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, OSDProperty)
#endif // OSDProperty_H
