#ifndef CUEKEYBASE_H
#define CUEKEYBASE_H
#include <QString>
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "lightingexecutionhints.h"

class CUEKeyBase
{
public:
    CUEKeyBase()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created CUEKeyBase" << std::endl;
#endif
    }
    QString name;
    std::vector<QString> keys;
    bool enabled;
    LightingExecutionHints executionHints;
    QString option;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(name), CEREAL_NVP(keys), CEREAL_NVP(enabled),
           CEREAL_NVP(executionHints), CEREAL_NVP(option));
    }
    virtual void Dummy() = 0;
};

CEREAL_CLASS_VERSION(CUEKeyBase, 300)

#endif // CUEKEYBASE_H
