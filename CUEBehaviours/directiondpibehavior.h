#ifndef DIRECTIONDPIBEHAVIOR_H
#define DIRECTIONDPIBEHAVIOR_H
#include "basebehaviour.h"
class DirectionDpiBehavior : public BaseBehaviour
{
public:
    DirectionDpiBehavior() {}
    bool forward;
    bool loob;
    bool applyToAllModes;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseBehaviour>(this)), CEREAL_NVP(forward),
           CEREAL_NVP(loob), CEREAL_NVP(applyToAllModes));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(DirectionDpiBehavior, 200)
CEREAL_REGISTER_TYPE(DirectionDpiBehavior)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseBehaviour, DirectionDpiBehavior)

#endif // DIRECTIONDPIBEHAVIOR_H
