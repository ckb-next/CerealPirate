#ifndef BasicLightingsProperty_Proxy_H
#define BasicLightingsProperty_Proxy_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class BasicLightingsProperty_Proxy : public BaseProperty
{
public:
    BasicLightingsProperty_Proxy() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(BasicLightingsProperty_Proxy, 301)
CEREAL_REGISTER_TYPE_WITH_NAME(BasicLightingsProperty_Proxy, "BasicLightingsProperty::Proxy")
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, BasicLightingsProperty_Proxy)
#endif // BasicLightingsProperty_Proxy_H
