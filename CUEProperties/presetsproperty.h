#ifndef PresetsProperty_H
#define PresetsProperty_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"

class CUEPreset
{
public:
    CUEPreset() {}
    QString id;
    QString name;
    std::vector<double> stages;
    bool visible;
    bool linkSliders;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(id), CEREAL_NVP(name), CEREAL_NVP(stages), CEREAL_NVP(visible), CEREAL_NVP(linkSliders));
    }
};
CEREAL_CLASS_VERSION(CUEPreset, 201)

class PresetsProperty : public BaseProperty
{
public:
    PresetsProperty() {}
    int activePresetIndex;
    bool forceIndexChange;
    std::vector<std::shared_ptr<CUEPreset>> presets;
    std::vector<QString> defaultPresetsIds;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(activePresetIndex),
           CEREAL_NVP(forceIndexChange), CEREAL_NVP(presets), CEREAL_NVP(defaultPresetsIds));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(PresetsProperty, 200)
CEREAL_REGISTER_TYPE(PresetsProperty)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, PresetsProperty)
#endif // PresetsProperty_H
