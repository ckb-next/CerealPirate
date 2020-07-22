#ifndef SystemPointerProperty_H
#define SystemPointerProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class SystemPointerProperty : public BaseProperty
{
public:
    SystemPointerProperty()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created SystemPointerProperty" << std::endl;
#endif
    }
    QString enhancePointerPrecision;
    int pointerMotionSpeed;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(enhancePointerPrecision),
           CEREAL_NVP(pointerMotionSpeed));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(SystemPointerProperty, 200)
CEREAL_REGISTER_TYPE(SystemPointerProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, SystemPointerProperty)
#endif // SystemPointerProperty_H
