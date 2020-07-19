#ifndef XDLProfileProperty_H
#define XDLProfileProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class XDLProfileProperty : public BaseProperty
{
public:
    XDLProfileProperty() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(XDLProfileProperty, 200)
CEREAL_REGISTER_TYPE(XDLProfileProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, XDLProfileProperty)
#endif // XDLProfileProperty_H
