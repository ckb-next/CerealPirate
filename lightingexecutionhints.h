#ifndef LightingExecutionHints_H
#define LightingExecutionHints_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
class LightingExecutionHints
{
public:
    LightingExecutionHints()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created LightingExecutionHints" << std::endl;
#endif
    }
    bool startOnKeyPress;
    bool startWithProfile;
    bool stopOnKeyPress;
    bool stopOnKeyRelease;
    int stopAfterTimes; // FIXME: Find correct data type
    QString playOption;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(startOnKeyPress), CEREAL_NVP(startWithProfile), CEREAL_NVP(stopOnKeyPress),
           CEREAL_NVP(stopOnKeyRelease), CEREAL_NVP(stopAfterTimes), CEREAL_NVP(playOption));
    }
};
CEREAL_CLASS_VERSION(LightingExecutionHints, 200)
#endif // LightingExecutionHints_H
