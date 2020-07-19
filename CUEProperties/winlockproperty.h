#ifndef WinlockProperty_H
#define WinlockProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class WinlockProperty : public BaseProperty
{
public:
    WinlockProperty() {}
    bool disableAltTab;
    bool disableAltF4;
    bool disableWinKey;
    bool disableShiftTab;
    bool disableEncryption;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(disableAltTab),
           CEREAL_NVP(disableAltF4), CEREAL_NVP(disableWinKey), CEREAL_NVP(disableShiftTab),
           CEREAL_NVP(disableEncryption));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(WinlockProperty, 201)
CEREAL_REGISTER_TYPE(WinlockProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, WinlockProperty)
#endif // WinlockProperty_H
