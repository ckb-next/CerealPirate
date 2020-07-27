#ifndef MacroAction_H
#define MacroAction_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "baseaction.h"
#include "../CUEBehaviours/basebehaviour.h"
#include "../CUEActionEvents/actioneventbase.h"

class MacroAction : public BaseAction
{
public:
    MacroAction()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created MacroAction" << std::endl;
#endif
    }
    QString terminationMethod;
    bool highPriority;
    std::vector<std::shared_ptr<ActionEventBase>> events;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseAction>(this)), CEREAL_NVP(terminationMethod),
           CEREAL_NVP(highPriority), CEREAL_NVP(events));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(MacroAction, 201)
CEREAL_REGISTER_TYPE(MacroAction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseAction, MacroAction)
#endif // MacroAction_H
