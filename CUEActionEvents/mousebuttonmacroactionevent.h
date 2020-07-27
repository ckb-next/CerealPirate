#ifndef MouseButtonMacroActionEvent_H
#define MouseButtonMacroActionEvent_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "actioneventbase.h"
#include <QString>

class MouseButtonMacroActionEvent : public ActionEventBase
{
public:
    MouseButtonMacroActionEvent()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created MouseButtonMacroActionEvent" << std::endl;
#endif
    }
    int button;
    QString sub;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<ActionEventBase>(this)), CEREAL_NVP(button),
           CEREAL_NVP(sub));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(MouseButtonMacroActionEvent, 200)
CEREAL_REGISTER_TYPE(MouseButtonMacroActionEvent)
CEREAL_REGISTER_POLYMORPHIC_RELATION(ActionEventBase, MouseButtonMacroActionEvent)

#endif // MouseButtonMacroActionEvent_H
