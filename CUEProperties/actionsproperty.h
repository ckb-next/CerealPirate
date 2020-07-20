#ifndef ACTIONSPROPERTY_H
#define ACTIONSPROPERTY_H
#include <cereal/types/utility.hpp>
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"
#include "CUEActions/baseaction.h"

typedef std::pair<std::shared_ptr<BaseAction>, std::pair<QString, QString>> action_t;

class ActionsProperty : public BaseProperty
{
public:
    ActionsProperty() {}
    std::vector<action_t> actions;
    std::vector<action_t> default_actions;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(actions),
           CEREAL_NVP(default_actions));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(ActionsProperty, 202)
CEREAL_REGISTER_TYPE(ActionsProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, ActionsProperty)
#endif // ACTIONSPROPERTY_H
