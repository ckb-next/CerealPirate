#ifndef CoolingConfigurationProperty_Proxy_H
#define CoolingConfigurationProperty_Proxy_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>
#include "baseproperty.h"
#include "CUECooling/asetekcoolingconfiguration.h"

class AssignmentConfig
{
public:
    AssignmentConfig() {}
    QString assignmentConfigId;
    std::shared_ptr<CoolingConfigurationBase> defaultConfig;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(assignmentConfigId), CEREAL_NVP(defaultConfig));
    }
};
CEREAL_CLASS_VERSION(AssignmentConfig, 300)

class CoolingConfigurationProperty : public BaseProperty
{
public:
    CoolingConfigurationProperty() {}
    void Dummy() {}
    std::map<QString, AssignmentConfig> assignments;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(assignments));
    }
};
CEREAL_CLASS_VERSION(CoolingConfigurationProperty, 300)

class CoolingConfigurationProperty_Proxy : public BaseProperty
{
public:
    CoolingConfigurationProperty_Proxy() {}
    std::map<QString, std::unique_ptr<CoolingConfigurationProperty>> properties;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(cereal::make_nvp("base", cereal::virtual_base_class<BaseProperty>(this)), CEREAL_NVP(properties));
    }
    void Dummy() {}
};

CEREAL_CLASS_VERSION(CoolingConfigurationProperty_Proxy, 300)
CEREAL_REGISTER_TYPE_WITH_NAME(CoolingConfigurationProperty_Proxy, "CoolingConfigurationProperty::Proxy")
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseProperty, CoolingConfigurationProperty_Proxy)
#endif // CoolingConfigurationProperty_Proxy_H
