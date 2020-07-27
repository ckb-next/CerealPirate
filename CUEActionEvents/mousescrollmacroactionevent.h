#ifndef MouseScrollMacroActionEvent_H
#define MouseScrollMacroActionEvent_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "actioneventbase.h"
#include <QString>

class MouseScrollMacroActionEvent : public ActionEventBase
{
public:
    MouseScrollMacroActionEvent()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created MouseScrollMacroActionEvent" << std::endl;
#endif
    }
    int x;
    int y;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<ActionEventBase>(this)), CEREAL_NVP(x),
           CEREAL_NVP(y));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(MouseScrollMacroActionEvent, 200)
CEREAL_REGISTER_TYPE(MouseScrollMacroActionEvent)
CEREAL_REGISTER_POLYMORPHIC_RELATION(ActionEventBase, MouseScrollMacroActionEvent)

#endif // MouseScrollMacroActionEvent_H
