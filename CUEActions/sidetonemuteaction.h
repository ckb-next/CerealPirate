#ifndef SidetoneMuteAction_H
#define SidetoneMuteAction_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "baseaction.h"
#include "../CUEBehaviours/basebehaviour.h"

class SidetoneMuteAction : public BaseAction
{
public:
    SidetoneMuteAction() {}
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseAction>(this)));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(SidetoneMuteAction, 200)
CEREAL_REGISTER_TYPE(SidetoneMuteAction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseAction, SidetoneMuteAction)
#endif // SidetoneMuteAction_H
