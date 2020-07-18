#ifndef CUEANIMATIONBASE_H
#define CUEANIMATIONBASE_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
class CUEAnimationBase
{
public:
    CUEAnimationBase() {}
    QString name;
    QString id;
    unsigned int duration; // FIXME: Find the right type
    int brightness; // same as above
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(name), CEREAL_NVP(id), CEREAL_NVP(duration), CEREAL_NVP(brightness));
    }
    virtual void Dummy() = 0;
};
CEREAL_CLASS_VERSION(CUEAnimationBase, 300)
#endif // CUEANIMATIONBASE_H
