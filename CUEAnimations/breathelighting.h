#ifndef BreatheLighting_H
#define BreatheLighting_H
#include "cueanimationbase.h"

class BreatheLighting : public CUEAnimationBase
{
public:
    BreatheLighting()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created BreatheLighting" << std::endl;
#endif
    }
    QString color;
    QString type;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationBase>(this)),
           CEREAL_NVP(color), CEREAL_NVP(type));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(BreatheLighting, 300)
CEREAL_REGISTER_TYPE(BreatheLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, BreatheLighting)
#endif // BreatheLighting_H
