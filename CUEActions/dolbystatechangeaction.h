#ifndef DolbyStateChangeAction_H
#define DolbyStateChangeAction_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "baseaction.h"
#include "../CUEBehaviours/basebehaviour.h"

class DolbyStateChangeAction : public BaseAction
{
public:
    DolbyStateChangeAction() {}
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseAction>(this)));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(DolbyStateChangeAction, 200)
CEREAL_REGISTER_TYPE(DolbyStateChangeAction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseAction, DolbyStateChangeAction)
#endif // DolbyStateChangeAction_H
