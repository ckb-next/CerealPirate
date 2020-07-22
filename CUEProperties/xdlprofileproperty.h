#ifndef XDLProfileProperty_H
#define XDLProfileProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "baseproperty.h"
#include "basiclightinglayer.h"

class XDLProfileBase : public BaseProperty
{
public:
    XDLProfileBase()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created XDLProfileBase" << std::endl;
#endif
    }
    bool enabled;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(enabled));
    }
};
CEREAL_CLASS_VERSION(XDLProfileBase, 200)
CEREAL_REGISTER_TYPE(XDLProfileBase)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, XDLProfileBase)

class XDLProfileProperty : public XDLProfileBase
{
public:
    XDLProfileProperty()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created XDLProfileProperty" << std::endl;
#endif
    }
    std::shared_ptr<BasicLightingLayer> layer;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<XDLProfileBase>(this)), CEREAL_NVP(layer));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(XDLProfileProperty, 200)
CEREAL_REGISTER_TYPE(XDLProfileProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(XDLProfileBase, XDLProfileProperty)
#endif // XDLProfileProperty_H
