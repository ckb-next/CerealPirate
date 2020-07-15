#ifndef ProfileIndicatorProperty_H
#define ProfileIndicatorProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class ProfileIndicatorProperty : public BaseProperty
{
public:
    ProfileIndicatorProperty() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(ProfileIndicatorProperty, 201)
CEREAL_REGISTER_TYPE(ProfileIndicatorProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, ProfileIndicatorProperty)
#endif // ProfileIndicatorProperty_H
