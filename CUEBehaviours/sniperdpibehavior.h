#ifndef SniperDpiBehavior_H
#define SniperDpiBehavior_H
#include "basebehaviour.h"
class SniperDpiBehavior : public BaseBehaviour
{
public:
    SniperDpiBehavior() {}
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseBehaviour>(this)));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(SniperDpiBehavior, 200)
CEREAL_REGISTER_TYPE(SniperDpiBehavior)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseBehaviour, SniperDpiBehavior)

#endif // SniperDpiBehavior_H
