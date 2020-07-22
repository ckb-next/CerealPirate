#ifndef SidetoneProperty_H
#define SidetoneProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "baseproperty.h"

class SidetoneProperty : public BaseProperty
{
public:
    SidetoneProperty()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created SidetoneProperty" << std::endl;
#endif
    }
    bool muted;
    int level;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(muted),
           CEREAL_NVP(level));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(SidetoneProperty, 200)
CEREAL_REGISTER_TYPE(SidetoneProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, SidetoneProperty)
#endif // SidetoneProperty_H
