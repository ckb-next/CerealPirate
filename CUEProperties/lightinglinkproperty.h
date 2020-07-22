#ifndef LightingLinkProperty_H
#define LightingLinkProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"
#include "cuekeybase.h"

class LightingLinkProperty : public BaseProperty
{
public:
    LightingLinkProperty()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created LightingLinkProperty" << std::endl;
#endif
    }
    std::vector<std::shared_ptr<CUEKeyBase>> layers;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(layers));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(LightingLinkProperty, 300)
CEREAL_REGISTER_TYPE(LightingLinkProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, LightingLinkProperty)
#endif // LightingLinkProperty_H
