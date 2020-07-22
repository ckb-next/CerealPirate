#ifndef EqPresetSwitchingAction_H
#define EqPresetSwitchingAction_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "baseaction.h"
#include "../CUEBehaviours/basebehaviour.h"

class EqPresetSwitchingAction : public BaseAction
{
public:
    EqPresetSwitchingAction()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created EqPresetSwitchingAction" << std::endl;
#endif
    }
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseAction>(this)));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(EqPresetSwitchingAction, 200)
CEREAL_REGISTER_TYPE(EqPresetSwitchingAction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseAction, EqPresetSwitchingAction)
#endif // EqPresetSwitchingAction_H
