#ifndef ChannelPropertiesBase_H
#define ChannelPropertiesBase_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class ChannelPropertiesBase : public BaseProperty
{
public:
    ChannelPropertiesBase() {}
#warning "FIXME random type here"
    std::vector<std::unique_ptr<int>> layers;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(layers));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(ChannelPropertiesBase, 200)
CEREAL_REGISTER_TYPE(ChannelPropertiesBase)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, ChannelPropertiesBase)
#endif // ChannelPropertiesBase_H
