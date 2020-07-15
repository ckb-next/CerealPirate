#ifndef JoystickPerformanceProperty_H
#define JoystickPerformanceProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class JoystickPerformanceProperty : public BaseProperty
{
public:
    JoystickPerformanceProperty() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(JoystickPerformanceProperty, 301)
CEREAL_REGISTER_TYPE(JoystickPerformanceProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, JoystickPerformanceProperty)
#endif // JoystickPerformanceProperty_H
