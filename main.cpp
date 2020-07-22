#include <clocale>
#include <cereal/types/unordered_map.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/archives/xml.hpp>
#include <fstream>
#include <QCoreApplication>
#include <QString>
#include <iostream>
#include <cereal/types/vector.hpp>
#include "cueprofileclasses.h"

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

static std::map<QString, int> profileKeyComparatorMapDefault = {
    {"Mouse", 0},
    {"Keyboard", 1},
    {"Headset", 2},
    {"MouseMat", 3},
    {"HeadsetStand", 4},
    {"DRAM", 5},
    {"Profile", 6},
    {"LiquidColler", 7},
    {"PSU", 8},
    {"LightingNode", 9},
};
class CUEprofileKeyComparator
{
public:
    CUEprofileKeyComparator() {}
    bool operator() (const QString& a, const QString& b)
    {
        std::map<QString, int>& cmpmap = *(profileKeyCmpMap ? profileKeyCmpMap : &profileKeyComparatorMapDefault);
        // In case we don't have the value in the list
        if(cmpmap.count(a) && cmpmap.count(b))
            return cmpmap[a] < cmpmap[b];
        return a < b;
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
    //std::unordered_map<std::string, listCont> properties;
    //std::unordered_map<QString, listCont> properties;
    std::map<QString, listCont, CUEprofileKeyComparator> properties;
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
CEREAL_CLASS_VERSION(CUEprofile, 301)

// <dpiMode>
class CUEdpiDummyBase
{
public:
    CUEdpiDummyBase() {}
    virtual void Dummy() = 0;
    template <class Archive>
    void serialize(Archive& ar)
    {
    }
};

class CUEdpiSettings : public CUEdpiDummyBase
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
    void Dummy() {}
};
CEREAL_CLASS_VERSION(CUEdpiSettings, 201)
CEREAL_REGISTER_TYPE(CUEdpiSettings)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CUEdpiDummyBase, CUEdpiSettings)

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
    std::map<CUEDeviceNoCapsNoCap, std::shared_ptr<CoolingConfigurationStorageBase>, CUEDeviceNoCapsNoCapComparator> coolingModes;

    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(profile), CEREAL_NVP(dpiMode), CEREAL_NVP(dpiModeAdditional), CEREAL_NVP(coolingModes));
    }

};
CEREAL_CLASS_VERSION(CUEProfileContainer, 300)

class XMLTests
{
public:
    const char* file;
    std::map<QString, int>* pKeyComparatorMap;
    std::map<QString, int>* devComparatorMap;
    std::map<QString, int>* coolingComparatorMap;
};

static void trimEnd(std::string& str)
{
    std::string::size_type sl = str.length();
    if(!sl)
        return;
    sl--;
    if(str[sl] == '\r')
        str.resize(sl);
}

#include <string>
int main(int argc, char* argv[])
{
    int ret = 0;
    QString oldLocale (setlocale(LC_NUMERIC, NULL));
    QCoreApplication a(argc, argv);
    QString newLocale (setlocale(LC_NUMERIC, NULL));

    // Test maps
    std::map<QString, int> cmpmap1 = {
        {"LightingNode", -1},
        {"Mouse", 0},
        {"Keyboard", 1},
        {"Headset", 2},
        {"MouseMat", 3},
        {"HeadsetStand", 4},
        {"DRAM", 5},
        {"Profile", 6},
        {"LiquidColler", 7},
        {"PSU", 8},
    };

    std::map<QString, int> clcmpmap1 = {
        {"DEMO_COMMANDER_PRO_DEVICE", 2},
        {"DEMO_PSU_DEVICE", 1},
        {"DEMO_LIQUID_COOLER_DEVICE", 3},
    };

    std::vector<XMLTests> files = {
        {"tests/test1.cueprofile", nullptr, nullptr, nullptr},
        {"tests/test2.cueprofile", &cmpmap1, nullptr, &clcmpmap1},
        {"tests/test3.cueprofile", nullptr, nullptr, &clcmpmap1}
    };

    if(argc == 2)
    {
        if(!strcmp(argv[1], "--help"))
        {
            std::cout << "No arguments: run all tests" << std::endl << "One argument: Deserialise and reserialise the file specified" << std::endl;
            return 0;
        }
        else
            files = {{argv[1], nullptr, nullptr, nullptr}};
    }
    for(const XMLTests& test : files)
    {
        std::cout << "Testing " << test.file << "... ";
        std::ifstream is(test.file);
        std::string outfstr(test.file);
        outfstr.append("_tested");

        profileKeyCmpMap = test.pKeyComparatorMap;
        devCmpMap = test.devComparatorMap;
        coolingCmpMap = test.coolingComparatorMap;
        try
        {
            setlocale(LC_NUMERIC, oldLocale.toUtf8());
            cereal::XMLInputArchive ar(is);

            CUEProfileContainer profcont;

            ar(profcont);
            {
                std::ofstream os(outfstr);
                cereal::XMLOutputArchive aro(os);
                aro(profcont);
            }

            CUEProfileContainer profcont2;
            // Do this so that the elements in the XML are swapped back
            {
                std::ifstream is2(outfstr);
                cereal::XMLInputArchive ar2(is2);
                ar2(profcont2);
            }
            {
                std::ofstream os(outfstr);
                cereal::XMLOutputArchive aro(os);
                aro(profcont2);
            }
        }
        catch(const cereal::Exception& e)
        {
            std::cout << "Exception thrown while testing file " << test.file << std::endl << "what(): " << e.what() << std::endl;
            ret = 1;
        }

        setlocale(LC_NUMERIC, newLocale.toUtf8());

        // Read back and compare
        is.seekg(0, is.beg);
        std::ifstream is_new(outfstr);
        std::string str1;
        std::string str2;
        bool fail = false;
        uint64_t lnum = 1;
        // Compare line by line

        while(std::getline(is, str1) && std::getline(is_new, str2))
        {
            trimEnd(str1);
            trimEnd(str2);
            fail = !(str1 == str2);
            if(fail)
                break;
            lnum++;
        }
        // Once either of them reaches EOF, try to read again. If any of them succeed, then they differ.
        if(!fail && (std::getline(is, str1) || std::getline(is_new, str2)))
        {
            lnum++;
            fail = true;
        }
        if(fail)
            std::cout << "FAIL (line " << lnum << ")" << std::endl;
        else
            std::cout << "SUCCESS" << std::endl;
        ret |= fail;
    }

    /* profcont.profile.properties["Mouse"].l.push_back(std::unique_ptr<BaseProperty>(new ButtonResponseOptimizationProperty));
     profcont.profile.properties["Mouse"].l.push_back(std::unique_ptr<BaseProperty>(new LiftHeightProperty));
     profcont.profile.properties["Mouse"].l.push_back(std::unique_ptr<BaseProperty>(new AggregatedLightingsProperty_Proxy));
     CUEDevice cd;
     cd.modelId.usbPid = 1234;
     cd.modelId.usbVid = 4321;
     ChannelPropertiesContainerClass* cpc = new ChannelPropertiesContainerClass;
     cpc->channelProperties.push_back(std::unique_ptr<ChannelPropertiesClass>(new ChannelPropertiesClass));
     dynamic_cast<AggregatedLightingsProperty_Proxy*>(profcont.profile.properties["Mouse"].l[2].get())->properties[cd] = std::unique_ptr<ChannelPropertiesContainerClass>(cpc);
     ChannelPropertiesClass* meh = cpc->channelProperties[0].get();
     AdvancedLightingLayer* all = new AdvancedLightingLayer;
     all->enabled = true;
     all->lighting = std::shared_ptr<CUEAnimationBase>(new GradientLighting);
     all->lighting->brightness = 10;
     CUEAnimationTransition t;
     t.time = 0.49190938511326859;
     (dynamic_cast<GradientLighting*>(all->lighting.get()))->transitions.push_back(t);
     meh->layers.push_back(std::unique_ptr<AdvancedLightingLayer>(all));
    */

    return ret;
}
