#ifndef BrightnessAction_H
#define BrightnessAction_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "baseaction.h"
#include "../CUEBehaviours/basebehaviour.h"

class BrightnessAction : public BaseAction
{
public:
    BrightnessAction() {}
    QString direction;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseAction>(this)), CEREAL_NVP(direction));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(BrightnessAction, 200)
CEREAL_REGISTER_TYPE(BrightnessAction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseAction, BrightnessAction)
#endif // BrightnessAction_H
