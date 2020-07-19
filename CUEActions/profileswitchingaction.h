#ifndef ProfileSwitchingAction_H
#define ProfileSwitchingAction_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "baseaction.h"

class ProfileSwitchingAction : public BaseAction
{
public:
    ProfileSwitchingAction() {}
    QString switchType;
    bool loop;
#warning "what's the vector type?"
    std::vector<int> profiles;
    QString direction;
    bool folderOnlyVisible;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseAction>(this)), CEREAL_NVP(switchType),
           CEREAL_NVP(loop), CEREAL_NVP(profiles), CEREAL_NVP(direction), CEREAL_NVP(folderOnlyVisible));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(ProfileSwitchingAction, 300)
CEREAL_REGISTER_TYPE(ProfileSwitchingAction)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseAction, ProfileSwitchingAction)
#endif // ProfileSwitchingAction_H
