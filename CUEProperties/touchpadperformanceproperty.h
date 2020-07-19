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
    QString modeFLockOff;
    QString modeFLockOn;
    int pointerSpeed;
    int tappingSpeed;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(modeFLockOff),
           CEREAL_NVP(modeFLockOn), CEREAL_NVP(pointerSpeed), CEREAL_NVP(tappingSpeed));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(TouchpadPerformanceProperty, 301)
CEREAL_REGISTER_TYPE(TouchpadPerformanceProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, TouchpadPerformanceProperty)
#endif // TouchpadPerformanceProperty_H
