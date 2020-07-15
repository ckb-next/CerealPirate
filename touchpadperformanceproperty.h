#ifndef TouchpadPerformanceProperty_H
#define TouchpadPerformanceProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class TouchpadPerformanceProperty : public BaseProperty
{
public:
    TouchpadPerformanceProperty() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(TouchpadPerformanceProperty, 301)
CEREAL_REGISTER_TYPE(TouchpadPerformanceProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, TouchpadPerformanceProperty)
#endif // TouchpadPerformanceProperty_H
