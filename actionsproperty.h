#ifndef ACTIONSPROPERTY_H
#define ACTIONSPROPERTY_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class ActionsProperty : public BaseProperty
{
public:
    ActionsProperty() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(ActionsProperty, 202)
CEREAL_REGISTER_TYPE(ActionsProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, ActionsProperty)
#endif // ACTIONSPROPERTY_H
