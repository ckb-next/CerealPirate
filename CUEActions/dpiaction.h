#ifndef DPIACTION_H
#define DPIACTION_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "baseaction.h"
#include "../CUEBehaviours/basebehaviour.h"

class DpiAction : public BaseAction
{
public:
    DpiAction() {}
    std::unique_ptr<BaseBehaviour> behavior;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseAction>(this)), CEREAL_NVP(behavior));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(DpiAction, 200)
CEREAL_REGISTER_TYPE(DpiAction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseAction, DpiAction)
#endif // DPIACTION_H
