#include <cereal/types/unordered_map.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/archives/xml.hpp>
#include <fstream>
#include <QCoreApplication>
#include <QString>
#include <iostream>
#include <QMap>
#include <cereal/types/map.hpp>
#include <cereal/types/vector.hpp>
#include "cueprofileclasses.h"
#include "channelpropertiescontainerclass.h"

// QString
template <class Archive>
std::string save_minimal(Archive& ar, const QString& qs)
{
    (void)ar;
    return qs.toStdString();
}

template <class Archive>
void load_minimal(Archive& ar, QString& qs, const std::string& ss)
{
    (void)ar;
    qs = QString::fromStdString(ss);
}


// Classes
class CUERGBShareMeta
{
public:
    CUERGBShareMeta() {}
    QString CueVersion;
    QString ProfileVersion;
    QString KeyboardModel;
    QString MouseModel;
    QString HeadsetModel;
    QString MousePadModel;
    QString KeyboardColors;
    QString MouseColors;
    QString HeadsetColors;
    QString MousePadColors;
    QString KeyboardLayoutSize;
    QString KeyboardHwLayout;
    QString KeyboardSwLayout;
    template <class Archive>
    void serialize(Archive& ar)
    {
        ar(CEREAL_NVP(CueVersion), CEREAL_NVP(ProfileVersion), CEREAL_NVP(KeyboardModel),
           CEREAL_NVP(MouseModel), CEREAL_NVP(HeadsetModel), CEREAL_NVP(MousePadModel),
           CEREAL_NVP(KeyboardColors), CEREAL_NVP(MouseColors), CEREAL_NVP(HeadsetColors),
           CEREAL_NVP(MousePadColors), CEREAL_NVP(KeyboardLayoutSize), CEREAL_NVP(KeyboardHwLayout),
           CEREAL_NVP(KeyboardSwLayout));
    }
};

class listCont
{
public:
    listCont() {}
    std::vector<std::unique_ptr<BaseProperty>> l;
    template <class Archive>
    void serialize(Archive& ar)
    {
        ar(cereal::make_nvp("properties", l));
    }
};

class CUEprofile
{
public:
    CUEprofile() {}
    QString name;
    QString id;
    QString iconUrl;
    QString linkedProgramPath;
    QString backgroundImageUrl;
    bool blurBackgroundImage;
    bool tabsTransparencyEnabled;
    int tabsTransparency; // FIXME maybe not int
    std::map<QString, listCont> properties;
    bool isHardware;
    CUERGBShareMeta RGBShareMeta;

    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(name), CEREAL_NVP(id), CEREAL_NVP(iconUrl), CEREAL_NVP(linkedProgramPath),
           CEREAL_NVP(backgroundImageUrl), CEREAL_NVP(blurBackgroundImage), CEREAL_NVP(tabsTransparencyEnabled),
           CEREAL_NVP(tabsTransparency), CEREAL_NVP(properties),
           CEREAL_NVP(isHardware), CEREAL_NVP(RGBShareMeta));
    }

};
CEREAL_CLASS_VERSION(CUEprofile, 300)

// <dpiMode>
class CUEdpiSettings
{
public:
    CUEdpiSettings() {}
    bool enabled;
    bool independent;
    int dpiX;
    int dpiY;
    QString color;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(enabled), CEREAL_NVP(independent), CEREAL_NVP(dpiX),
           CEREAL_NVP(dpiY), CEREAL_NVP(color));
    }
};
CEREAL_CLASS_VERSION(CUEdpiSettings, 201)

class CUEdpiMode
{
public:
    CUEdpiMode() {}
    QString id;
    QString name;
    std::map<QString, std::shared_ptr<CUEdpiSettings>> settings;
    bool active;
    QString defaultIndex;
    int defaultModeIndex;
    bool isDefault;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(id), CEREAL_NVP(name), CEREAL_NVP(settings),
           CEREAL_NVP(active), CEREAL_NVP(defaultIndex), CEREAL_NVP(defaultModeIndex),
           CEREAL_NVP(isDefault));
    }

};
CEREAL_CLASS_VERSION(CUEdpiMode, 201)

class CUEdpiModeAdditional
{
public:
    CUEdpiModeAdditional() {}
    QString id;
    QString name;
    std::map<QString, std::shared_ptr<CUEdpiSettings>> settings;
    bool active;
    QString defaultIndex;
    int defaultModeIndex;
    bool isDefault;
    template <class Archive>
    void serialize(Archive& ar)
    {
        ar(CEREAL_NVP(id), CEREAL_NVP(name), CEREAL_NVP(settings),
           CEREAL_NVP(active), CEREAL_NVP(defaultIndex), CEREAL_NVP(defaultModeIndex),
           CEREAL_NVP(isDefault));
    }

};

class CUEProfileContainer
{
public:
    CUEProfileContainer() {}

    CUEprofile profile;
    CUEdpiMode dpiMode;
    CUEdpiModeAdditional dpiModeAdditional;

    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(profile), CEREAL_NVP(dpiMode), CEREAL_NVP(dpiModeAdditional));
    }

};
CEREAL_CLASS_VERSION(CUEProfileContainer, 300)

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::ifstream is("/tmp/gradient.cueprofile");
    //std::ifstream is("/tmp/skunk.xml");
   /* try
    {*/
    cereal::XMLInputArchive ar(is);

    CUEProfileContainer profcont;
    //ar(profcont);
    std::ofstream os("/tmp/gradient_export.cueprofile");
    cereal::XMLOutputArchive aro(os);

    profcont.profile.properties["Mouse"].l.push_back(std::unique_ptr<BaseProperty>(new ButtonResponseOptimizationProperty));
    profcont.profile.properties["Mouse"].l.push_back(std::unique_ptr<BaseProperty>(new LiftHeightProperty));
    profcont.profile.properties["Mouse"].l.push_back(std::unique_ptr<BaseProperty>(new AggregatedLightingsProperty_Proxy));
    CUEDevice cd;
    cd.modelId.usbPid = 1234;
    cd.modelId.usbVid = 4321;
    ChannelPropertiesContainerClass* cpc = new ChannelPropertiesContainerClass;
    cpc->channelProperties.push_back(std::unique_ptr<ChannelPropertiesClass>(new ChannelPropertiesClass));
    dynamic_cast<AggregatedLightingsProperty_Proxy*>(profcont.profile.properties["Mouse"].l[2].get())->properties[cd] = std::unique_ptr<ChannelPropertiesContainerClass>(cpc);
    aro(profcont);
    /*}
    catch(const cereal::Exception& e)
    {
        std::cout << e.what() << std::endl;
    }*/

    return 0;
}
