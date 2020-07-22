#ifndef BrightnessIndicatorProperty_Proxy_H
#define BrightnessIndicatorProperty_Proxy_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class BrightnessIndicatorProperty : public BaseProperty
{
public:
    BrightnessIndicatorProperty()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created BrightnessIndicatorProperty" << std::endl;
#endif
    }
    QString indicatorColor;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(indicatorColor));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(BrightnessIndicatorProperty, 200)
CEREAL_REGISTER_TYPE(BrightnessIndicatorProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, BrightnessIndicatorProperty)

class BrightnessIndicatorProperty_Proxy : public BaseProperty
{
public:
    BrightnessIndicatorProperty_Proxy()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created Proxy" << std::endl;
#endif
    }
    std::unordered_map<bool, std::unique_ptr<BrightnessIndicatorProperty>> properties;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(properties));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(BrightnessIndicatorProperty_Proxy, 200)
CEREAL_REGISTER_TYPE_WITH_NAME(BrightnessIndicatorProperty_Proxy, "BrightnessIndicatorProperty::Proxy")
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, BrightnessIndicatorProperty_Proxy)
#endif // BrightnessIndicatorProperty_Proxy_H
