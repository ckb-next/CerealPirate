#ifndef MicMuteAction_H
#define MicMuteAction_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "baseaction.h"
#include "../CUEBehaviours/basebehaviour.h"

class MicMuteAction : public BaseAction
{
public:
    MicMuteAction() {}
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseAction>(this)));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(MicMuteAction, 200)
CEREAL_REGISTER_TYPE(MicMuteAction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseAction, MicMuteAction)
#endif // MicMuteAction_H
