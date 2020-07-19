#ifndef SidetoneProperty_H
#define SidetoneProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class SidetoneProperty : public BaseProperty
{
public:
    SidetoneProperty() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(SidetoneProperty, 200)
CEREAL_REGISTER_TYPE(SidetoneProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, SidetoneProperty)
#endif // SidetoneProperty_H
