#ifndef JoystickPerformanceProperty_H
#define JoystickPerformanceProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class JoystickPerformanceProperty : public BaseProperty
{
public:
    JoystickPerformanceProperty()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created JoystickPerformanceProperty" << std::endl;
#endif
    }
    QString modeFLockOff;
    QString modeFLockOn;
    int deadZone;
    int maxOutput;
    int sensitivity;
    QString xDirection;
    QString yDirection;
    QString leftButtonRemapFLockOff;
    QString rightButtonRemapFLockOff;
    QString joystickPressRemapFLockOff;
    QString leftButtonRemapFLockOn;
    QString rightButtonRemapFLockOn;
    QString joystickPressRemapFLockOn;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(modeFLockOff),
           CEREAL_NVP(modeFLockOn), CEREAL_NVP(deadZone), CEREAL_NVP(maxOutput), CEREAL_NVP(sensitivity),
           CEREAL_NVP(xDirection), CEREAL_NVP(yDirection), CEREAL_NVP(leftButtonRemapFLockOff),
           CEREAL_NVP(rightButtonRemapFLockOff), CEREAL_NVP(joystickPressRemapFLockOff),
           CEREAL_NVP(leftButtonRemapFLockOn), CEREAL_NVP(rightButtonRemapFLockOn),
           CEREAL_NVP(joystickPressRemapFLockOn));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(JoystickPerformanceProperty, 301)
CEREAL_REGISTER_TYPE(JoystickPerformanceProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, JoystickPerformanceProperty)
#endif // JoystickPerformanceProperty_H
