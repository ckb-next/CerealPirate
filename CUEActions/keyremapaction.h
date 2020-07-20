#ifndef KeyRemapAction_H
#define KeyRemapAction_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "baseaction.h"
#include "../CUEBehaviours/basebehaviour.h"

class KeyRemapAction : public BaseAction
{
public:
    KeyRemapAction() {}
    QString keyName;
#warning "What type is the vector?"
    std::vector<int> keyStroke;
    bool holdingKeyEnabled;
    QString holdingKeyType;
    int holdingKeyOnPressInterval;
    QString sniperSwitchMode;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseAction>(this)), CEREAL_NVP(keyName),
           CEREAL_NVP(keyStroke), CEREAL_NVP(holdingKeyEnabled), CEREAL_NVP(holdingKeyType),
           CEREAL_NVP(holdingKeyOnPressInterval), CEREAL_NVP(sniperSwitchMode));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(KeyRemapAction, 204)
CEREAL_REGISTER_TYPE(KeyRemapAction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseAction, KeyRemapAction)
#endif // KeyRemapAction_H
