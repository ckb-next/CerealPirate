#ifndef ProfileIndicatorProperty_H
#define ProfileIndicatorProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class ProfileIndicatorProperty : public BaseProperty
{
public:
    ProfileIndicatorProperty()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created ProfileIndicatorProperty" << std::endl;
#endif
    }
    QString m1Color;
    QString m2Color;
    QString m3Color;
    QString profileIndicatorColor;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(m1Color),
           CEREAL_NVP(m2Color), CEREAL_NVP(m3Color), CEREAL_NVP(profileIndicatorColor));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(ProfileIndicatorProperty, 201)
CEREAL_REGISTER_TYPE(ProfileIndicatorProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, ProfileIndicatorProperty)
#endif // ProfileIndicatorProperty_H
