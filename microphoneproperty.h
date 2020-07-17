#ifndef MicrophoneProperty_H
#define MicrophoneProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class MicrophoneProperty : public BaseProperty
{
public:
    MicrophoneProperty() {}
    QString value;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
#warning "FIXME"
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(MicrophoneProperty, 200)
CEREAL_REGISTER_TYPE(MicrophoneProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, MicrophoneProperty)
#endif // MicrophoneProperty_H
