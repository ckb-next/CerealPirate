#ifndef COOLINGCONFIGURATIONBASE_H
#define COOLINGCONFIGURATIONBASE_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>

class CustomModePoint
{
public:
    CustomModePoint() {}
    bool enabled;
    int temperature;
    int rpmPercents;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(enabled), CEREAL_NVP(temperature), CEREAL_NVP(rpmPercents));
    }
};
CEREAL_CLASS_VERSION(CustomModePoint, 300)

// fIXME: split to separate files
class CoolingConfigurationBase
{
public:
    CoolingConfigurationBase() {}
    QString id;
    QString name;
    bool predefined;
    virtual void Dummy() = 0;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(id), CEREAL_NVP(name), CEREAL_NVP(predefined));
    }
};
CEREAL_CLASS_VERSION(CoolingConfigurationBase, 300)

#endif // COOLINGCONFIGURATIONBASE_H
