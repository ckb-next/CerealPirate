#ifndef MarqueeLighting_H
#define MarqueeLighting_H
#include <cereal/types/polymorphic.hpp>
#include "cueanimationbase.h"
#include "cuecolourclass.h"
#include <cereal/archives/xml.hpp>

class MarqueeLighting : public CUEAnimationBase
{
public:
    MarqueeLighting()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created MarqueeLighting" << std::endl;
#endif
    }
    uint32_t color;
    int speed;
    int direction;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationBase>(this)),
           CEREAL_NVP(color), CEREAL_NVP(speed), CEREAL_NVP(direction));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(MarqueeLighting, 301)
CEREAL_REGISTER_TYPE(MarqueeLighting)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEAnimationBase, MarqueeLighting)

#endif // MarqueeLighting_H
