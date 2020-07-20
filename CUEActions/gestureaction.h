#ifndef GestureAction_H
#define GestureAction_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "baseaction.h"

class GestureAction : public BaseAction
{
public:
    GestureAction() {}
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseAction>(this)));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(GestureAction, 301)
CEREAL_REGISTER_TYPE(GestureAction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseAction, GestureAction)
#endif // GestureAction_H
