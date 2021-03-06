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
    BasicLightingLayer()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created BasicLightingLayer" << std::endl;
#endif
    }
    QString effect;
    std::map<QString, BasicLightingParams> params;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<CUEKeyBase>(this)), CEREAL_NVP(effect),
           CEREAL_NVP(params));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(BasicLightingLayer, 200)
CEREAL_REGISTER_TYPE(BasicLightingLayer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEKeyBase, BasicLightingLayer)

#endif // BasicLIGHTINGLAYER_H
