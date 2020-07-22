#ifndef MacroRecordingAction_H
#define MacroRecordingAction_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "baseaction.h"
#include "../CUEBehaviours/basebehaviour.h"

class MacroRecordingAction : public BaseAction
{
public:
    MacroRecordingAction()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created MacroRecordingAction" << std::endl;
#endif
    }
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseAction>(this)));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(MacroRecordingAction, 200)
CEREAL_REGISTER_TYPE(MacroRecordingAction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseAction, MacroRecordingAction)
#endif // MacroRecordingAction_H
