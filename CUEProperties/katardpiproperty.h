#ifndef KatarDPIProperty_H
#define KatarDPIProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "dpiproperty_proxy.h"

class KatarDPIProperty : public DPIProperty
{
public:
    KatarDPIProperty()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created KatarDPIProperty" << std::endl;
#endif
    }
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<DPIProperty>(this)));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(KatarDPIProperty, 200)
CEREAL_REGISTER_TYPE(KatarDPIProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, KatarDPIProperty)
#endif // KatarDPIProperty_H
