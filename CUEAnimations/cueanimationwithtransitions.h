#ifndef CUEANIMATIONWITHTRANSITIONS_H
#define CUEANIMATIONWITHTRANSITIONS_H
#include <cereal/types/polymorphic.hpp>
//#include <cereal/types/chrono.hpp>
#include <cereal/archives/xml.hpp>
#include "cueanimationbase.h"
//#include <chrono>
class CUEAnimationTransition
{
public:
    CUEAnimationTransition() {}
    double time;
    QString color;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(time), CEREAL_NVP(color));
    }
};
CEREAL_CLASS_VERSION(CUEAnimationTransition, 200)

class CUEAnimationWithTransitions : public CUEAnimationBase
{
public:
    CUEAnimationWithTransitions() {}
    std::vector<CUEAnimationTransition> transitions;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEAnimationBase>(this)), CEREAL_NVP(transitions));
    }
    void Dummy() {}
};
CEREAL_CLASS_VERSION(CUEAnimationWithTransitions, 201)

#endif // CUEANIMATIONWITHTRANSITIONS_H
