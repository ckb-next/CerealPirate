#ifndef BASICLIGHTINGPARAMS_H
#define BASICLIGHTINGPARAMS_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/types/utility.hpp>
#include <cereal/archives/xml.hpp>
#include <cstdint>
#include <QString>
#include "CUEAnimations/cuecolourclass.h"

class BasicLightingParams
{
public:
    BasicLightingParams() {}
    int speed;
    int color;
    int direction;
    int duration;
    uint8_t opacity;
    std::pair<QString, QString> alternatingColors;
    int equaliserAnimation;
    int equaliserPattern;
    QString temperatureWarningColor;
    int warningTemperature;
    bool temperatureWarningEnabled;
    // FIXME: make sure this is uint32_t
    std::pair<uint32_t, QString> temperatureBasedColors[3];
    uint32_t cycledColors[4];
    int groupDelay;
    int dramSpeed;
    // FIXME: find the right data type for colorArray
    std::vector<CUEColourClass> colorArray;
    QString sensorId;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(speed), CEREAL_NVP(color), CEREAL_NVP(direction), CEREAL_NVP(duration), CEREAL_NVP(opacity),
           CEREAL_NVP(alternatingColors), CEREAL_NVP(equaliserAnimation), CEREAL_NVP(equaliserPattern),
           CEREAL_NVP(temperatureWarningColor), CEREAL_NVP(warningTemperature), CEREAL_NVP(temperatureWarningEnabled),
           CEREAL_NVP(temperatureBasedColors), CEREAL_NVP(cycledColors), CEREAL_NVP(groupDelay), CEREAL_NVP(dramSpeed),
           CEREAL_NVP(colorArray), CEREAL_NVP(sensorId));
    }
};
CEREAL_CLASS_VERSION(BasicLightingParams, 301)
#endif // BASICLIGHTINGPARAMS_H
