#ifndef ActionExecutionHints_H
#define ActionExecutionHints_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
class ActionExecutionHints
{
public:
    ActionExecutionHints()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created ActionExecutionHints" << std::endl;
#endif
    }
    bool terminateOnSecondExec;
    bool restartOnSecondExec;
    QString execHint;
    bool retainOriginalKeyOutput;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(terminateOnSecondExec), CEREAL_NVP(restartOnSecondExec), CEREAL_NVP(execHint),
           CEREAL_NVP(retainOriginalKeyOutput));
    }
};
CEREAL_CLASS_VERSION(ActionExecutionHints, 201)
#endif // ActionExecutionHints_H
