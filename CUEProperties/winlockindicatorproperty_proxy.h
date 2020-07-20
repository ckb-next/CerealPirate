#ifndef WinlockIndicatorProperty_Proxy_H
#define WinlockIndicatorProperty_Proxy_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "baseproperty.h"
#include <QString>

class WinlockIndicatorProperty : public BaseProperty
{
public:
    WinlockIndicatorProperty() {}
    QString enabledIndicatorColor;
    QString disabledIndicatorColor;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(enabledIndicatorColor),
           CEREAL_NVP(disabledIndicatorColor));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(WinlockIndicatorProperty, 200)
CEREAL_REGISTER_TYPE(WinlockIndicatorProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, WinlockIndicatorProperty)

class WinlockIndicatorProperty_Proxy : public BaseProperty
{
public:
    WinlockIndicatorProperty_Proxy() {}
    std::unordered_map<bool, std::unique_ptr<WinlockIndicatorProperty>> properties;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(properties));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(WinlockIndicatorProperty_Proxy, 200)
CEREAL_REGISTER_TYPE_WITH_NAME(WinlockIndicatorProperty_Proxy, "WinlockIndicatorProperty::Proxy")
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, WinlockIndicatorProperty_Proxy)
#endif // WinlockIndicatorProperty_Proxy_H
