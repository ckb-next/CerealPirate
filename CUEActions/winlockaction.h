#ifndef WinLockAction_H
#define WinLockAction_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "baseaction.h"
#include "../CUEBehaviours/basebehaviour.h"

class WinLockAction : public BaseAction
{
public:
    WinLockAction()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created WinLockAction" << std::endl;
#endif
    }
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseAction>(this)));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(WinLockAction, 200)
CEREAL_REGISTER_TYPE(WinLockAction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseAction, WinLockAction)
#endif // WinLockAction_H
