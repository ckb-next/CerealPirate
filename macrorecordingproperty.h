#ifndef MacroRecordingProperty_H
#define MacroRecordingProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class MacroRecordingProperty : public BaseProperty
{
public:
    MacroRecordingProperty() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(MacroRecordingProperty, 200)
CEREAL_REGISTER_TYPE(MacroRecordingProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, MacroRecordingProperty)
#endif // MacroRecordingProperty_H
