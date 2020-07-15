#ifndef BrightnessIndicatorProperty_Proxy_H
#define BrightnessIndicatorProperty_Proxy_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class BrightnessIndicatorProperty_Proxy : public BaseProperty
{
public:
    BrightnessIndicatorProperty_Proxy() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(BrightnessIndicatorProperty_Proxy, 200)
CEREAL_REGISTER_TYPE_WITH_NAME(BrightnessIndicatorProperty_Proxy, "BrightnessIndicatorProperty::Proxy")
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, BrightnessIndicatorProperty_Proxy)
#endif // BrightnessIndicatorProperty_Proxy_H
