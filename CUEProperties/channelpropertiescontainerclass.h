#ifndef ChannelPropertiesContainerClass_H
#define ChannelPropertiesContainerClass_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"
#include "channelpropertiesclass.h"

class ChannelPropertiesContainerClass : public BaseProperty
{
public:
    ChannelPropertiesContainerClass()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created ChannelPropertiesContainerClass" << std::endl;
#endif
    }
    std::vector<std::unique_ptr<ChannelPropertiesClass>> channelProperties;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(channelProperties));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(ChannelPropertiesContainerClass, 300)
CEREAL_REGISTER_TYPE(ChannelPropertiesContainerClass)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, ChannelPropertiesContainerClass)
#endif // ChannelPropertiesContainerClass_H
