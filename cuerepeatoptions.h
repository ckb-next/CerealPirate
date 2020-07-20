#ifndef CUEREPEATOPTIONS_H
#define CUEREPEATOPTIONS_H
#include <QString>
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>

class CUERepeatOptions
{
public:
    CUERepeatOptions() {}
    int repeatCount;
    QString repeatMode;
    unsigned int delay;
    QString delayMode;
    unsigned int randomDelayFrom;
    unsigned int randomDelayTo;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(repeatCount), CEREAL_NVP(repeatMode), CEREAL_NVP(delay),
           CEREAL_NVP(delayMode), CEREAL_NVP(randomDelayFrom), CEREAL_NVP(randomDelayTo));
    }
};
CEREAL_CLASS_VERSION(CUERepeatOptions, 300)
#endif // CUEREPEATOPTIONS_H
