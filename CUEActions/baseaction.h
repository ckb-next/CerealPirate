#ifndef BASEACTION_H
#define BASEACTION_H

#include <QString>
#include "actionexecutionhints.h"
#include "../cuerepeatoptions.h"

class BaseAction
{
public:
    BaseAction()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created BaseAction" << std::endl;
#endif
    }
    QString name;
    QString id;
    CUERepeatOptions repeatOptions;
    ActionExecutionHints executionHints;
    QString actionLighting;
    QString actionSoundPath;
#warning "FIXME: find the right data type for the vector"
    std::vector<std::unique_ptr<BaseAction>> attachedActions;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(name), CEREAL_NVP(id), CEREAL_NVP(repeatOptions), CEREAL_NVP(executionHints),
           CEREAL_NVP(actionLighting), CEREAL_NVP(actionSoundPath), CEREAL_NVP(attachedActions));
    }
    virtual void Dummy() = 0;
};
CEREAL_CLASS_VERSION(BaseAction, 202)
#endif // BASEACTION_H
