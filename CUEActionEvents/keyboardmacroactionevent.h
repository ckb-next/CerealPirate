#ifndef KeyboardMacroActionEvent_H
#define KeyboardMacroActionEvent_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "actioneventbase.h"
#include <QString>

class KeyboardMacroActionEvent : public ActionEventBase
{
public:
    KeyboardMacroActionEvent()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created KeyboardMacroActionEvent" << std::endl;
#endif
    }
    std::vector<QString> keys;
    QString sub;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<ActionEventBase>(this)), CEREAL_NVP(keys),
           CEREAL_NVP(sub));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(KeyboardMacroActionEvent, 200)
CEREAL_REGISTER_TYPE(KeyboardMacroActionEvent)
CEREAL_REGISTER_POLYMORPHIC_RELATION(ActionEventBase, KeyboardMacroActionEvent)

#endif // KeyboardMacroActionEvent_H
