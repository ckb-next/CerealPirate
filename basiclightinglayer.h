#ifndef BasicLIGHTINGLAYER_H
#define BasicLIGHTINGLAYER_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include "cuekeybase.h"
#include <QString>
#include "basiclightingparams.h"

class BasicLightingLayer : public CUEKeyBase
{
public:
    BasicLightingLayer() {}
    QString effect;
    std::map<QString, BasicLightingParams> params;
    template <class Archive>
    void serialize(Archive& ar)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEKeyBase>(this)), CEREAL_NVP(effect),
           CEREAL_NVP(params));
    }
    void Dummy() {}
};

CEREAL_REGISTER_TYPE(BasicLightingLayer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEKeyBase, BasicLightingLayer)

#endif // BasicLIGHTINGLAYER_H
