#ifndef ChannelPropertiesClass_H
#define ChannelPropertiesClass_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "channelpropertiesbase.h"
#include "advancedlightinglayer.h"

class ChannelPropertiesClass : public ChannelPropertiesBase
{
public:
    ChannelPropertiesClass() {}
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<ChannelPropertiesBase>(this)));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(ChannelPropertiesClass, 200)
CEREAL_REGISTER_TYPE(ChannelPropertiesClass)
CEREAL_REGISTER_POLYMORPHIC_RELATION(ChannelPropertiesBase, ChannelPropertiesClass)
#endif // ChannelPropertiesClass_H
