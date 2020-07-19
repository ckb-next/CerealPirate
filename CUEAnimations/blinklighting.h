#ifndef BlinkLighting_H
#define BlinkLighting_H
#include "cueanimationbase.h"

class BlinkLighting : public CUEAnimationBase
{
public:
    BlinkLighting() {}
    QString color1;
    QString color2;
    QString type;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationBase>(this)),
           CEREAL_NVP(color1), CEREAL_NVP(color2), CEREAL_NVP(type));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(BlinkLighting, 300)
CEREAL_REGISTER_TYPE(BlinkLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, BlinkLighting)
#endif // BlinkLighting_H
