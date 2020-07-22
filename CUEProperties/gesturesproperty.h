#ifndef GesturesProperty_H
#define GesturesProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"
#include "../CUEActions/gestureaction.h"

class GesturesProperty : public BaseProperty
{
public:
    GesturesProperty()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created GesturesProperty" << std::endl;
#endif
    }
    std::map<int, std::pair<QString, std::shared_ptr<BaseAction>>> gestures;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(gestures));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(GesturesProperty, 301)
CEREAL_REGISTER_TYPE(GesturesProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, GesturesProperty)
#endif // GesturesProperty_H
