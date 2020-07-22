#ifndef MacroRecordingProperty_H
#define MacroRecordingProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class MacroRecordingProperty : public BaseProperty
{
public:
    MacroRecordingProperty()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created MacroRecordingProperty" << std::endl;
#endif
    }
    QString enabledIndicatorColor;
    QString disabledIndicatorColor;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(enabledIndicatorColor),
           CEREAL_NVP(disabledIndicatorColor));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(MacroRecordingProperty, 200)
CEREAL_REGISTER_TYPE(MacroRecordingProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, MacroRecordingProperty)
#endif // MacroRecordingProperty_H
