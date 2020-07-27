#ifndef DelayMacroActionEvent_H
#define DelayMacroActionEvent_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "actioneventbase.h"
#include <QString>

class DelayMacroActionEvent : public ActionEventBase
{
public:
    DelayMacroActionEvent()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created DelayMacroActionEvent" << std::endl;
#endif
    }
    bool useRandom;
    int32_t delay;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<ActionEventBase>(this)), CEREAL_NVP(useRandom),
           CEREAL_NVP(delay));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(DelayMacroActionEvent, 200)
CEREAL_REGISTER_TYPE(DelayMacroActionEvent)
CEREAL_REGISTER_POLYMORPHIC_RELATION(ActionEventBase, DelayMacroActionEvent)

#endif // DelayMacroActionEvent_H
