#ifndef MicrophoneProperty_H
#define MicrophoneProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class MicrophoneProperty : public BaseProperty
{
public:
    MicrophoneProperty()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created MicrophoneProperty" << std::endl;
#endif
    }
    bool muted;
    int level;
    int intervalIndex;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(muted),
           CEREAL_NVP(level), CEREAL_NVP(intervalIndex));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(MicrophoneProperty, 200)
CEREAL_REGISTER_TYPE(MicrophoneProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, MicrophoneProperty)
#endif // MicrophoneProperty_H
