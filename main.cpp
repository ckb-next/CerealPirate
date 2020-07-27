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



// False if something went wrong
// True if we all matched
/*bool recurse(cereal::rapidxml::xml_node<>* starting_node, cereal::rapidxml::xml_node<>* starting_node2, int& depth, int& maxdepth)
{
    depth++;
    if(maxdepth < depth)
        maxdepth = depth;
    for(cereal::rapidxml::xml_node<>* node = starting_node; node; node = node->next_sibling())
    {
        //std::cout << "Node: " << node->name() << " data: " << node->value() << std::endl;
        cereal::rapidxml::xml_node<>* node2;
        for(node2 = starting_node2; node2; node2 = node2->next_sibling())
        {
            std::cout << "Comparing " << node->name() << " and " << node2->name() << std::endl;
            if(strcmp(node->name(), node2->name()) || strcmp(node->value(), node2->value()))
            {
                // It's okay to keep going if the node starts with "value"
                if(strlen(node->name()) > 5)
                {
                    if(strncmp("value", node->name(), 5))
                        continue;
                }
                // Also assume that cereal_class_version matches as well, but report it
                else if(strcmp(node->name(), "cereal_class_version"))
                {
                    std::cout << "Assuming cereal class version matches" << std::endl;
                }
                else
                    continue;
            }
            // Compare all the children if the above matched.
            // This needs to be done here because there might be similar nodes with completely different children
            if(recurse(node->first_node(), node2->first_node(), depth, maxdepth))
                break;
        }
        // If node2 is NULL, we haven't found a match
        if(!node2)
        {
            std::cout << "No match found for " << node->name() << " with value " << node->value() << std::endl;
            return false;
        }

        // Compare attributes
        // Assume they are in the same order
        cereal::rapidxml::xml_attribute<>* attr = node->first_attribute();
        cereal::rapidxml::xml_attribute<>* attr2 = node2->first_attribute();
        while(attr && attr2)
        {
            //std::cout << "Attr: " << attr->name() << " val: " << attr->value() << std::endl;
            if(strcmp(attr->name(), attr2->name()) || strcmp(attr->value(), attr2->value()))
            {
                std::cout << "Argument mismatch" << std::endl;
                return false;
            }
            attr = attr->next_attribute();
            attr2 = attr2->next_attribute();
        }
        // If we get down here and either of them isn't NULL, then one of them has extra attrs
        if(attr || attr2)
        {
            std::cout << "One file has more attributes. Original: " << attr << " Reserialised: " << attr2 << std::endl;
            return false;
        }
        std::cout << "Finished " << starting_node->name() << std::endl;
    }
    return true;
}*/

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

    std::map<QString, int> cmpmap2 = {
        {"LightingNode", 1},
        {"Mouse", 0},
        {"Keyboard", 2},
        {"Headset", 3},
        {"MouseMat", 6},
        {"HeadsetStand", 7},
        {"DRAM", 5},
        {"Profile", 4},
        {"LiquidColler", 8},
        {"PSU", 9},
    };

    std::map<QString, int> clcmpmap1 = {
        {"DEMO_COMMANDER_PRO_DEVICE", 2},
        {"DEMO_PSU_DEVICE", 1},
        {"DEMO_LIQUID_COOLER_DEVICE", 3},
    };

    std::map<QString, int> clcmpmap2 = {
        {"DEMO_COMMANDER_PRO_DEVICE", 2},
        {"DEMO_PSU_DEVICE", 0},
        {"DEMO_LIQUID_COOLER_DEVICE", 1},
    };

    std::map<QString, int> clcmpmap3 = {
        {"DEMO_COMMANDER_PRO_DEVICE", 1},
        {"vid<1b1c>pid<000c10>serial<890A0C37>index<0>", 0},
        {"vid<1b1c>pid<001d00>serial<39ABD5C0>index<0>", 2},
    };

    std::map<QString, int> dcmpmap1 = {
        {"StandardRgb", -1},
        {"StandardSingleColor", 0},
        {"ZoneRgb", 1},
        {"RestrictedWireless", 2},
        {"DramSingleColor", 3},
        {"Undefined", 5},
        {"DramRgb", 4},
    };

    std::vector<XMLTests> files = {
        {"tests/test1.cueprofile", nullptr, nullptr, nullptr},
        {"tests/test2.cueprofile", &cmpmap1, nullptr, &clcmpmap1},
        {"tests/test3.cueprofile", nullptr, nullptr, &clcmpmap1},
        {"tests/test4.cueprofile", nullptr, nullptr, &clcmpmap1},
        {"tests/test5.cueprofile", nullptr, nullptr, &clcmpmap2},
    };

    if(argc > 1)
    {
        if(!strcmp(argv[1], "--help"))
        {
            std::cout << "No arguments: run all tests" << std::endl << "One argument: Deserialise and reserialise the file specified" << std::endl;
            return 0;
        }
        else
        {
            files.clear();
            for(int i = 1; i < argc; i++)
                files.push_back({argv[i], nullptr, nullptr, nullptr});
        }
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
            std::cout << "FAIL" << std::endl << "Exception thrown while deserialising" << std::endl << "what(): " << e.what() << std::endl;
            ret = 1;
            continue;
        }

        setlocale(LC_NUMERIC, newLocale.toUtf8());

        // Read back and compare
        is.seekg(0, std::ios::beg);
        std::ifstream is_new(outfstr);
        //std::ifstream is_new("/tmp/xml1_mod.xml");
        bool fail = false;
        uint64_t lnum = 1;
        std::string str1;
        std::string str2;

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

        // Alternative comparison.
        // Not sure if it works properly
       /* is.seekg(0, std::ios::end);
        size_t size = is.tellg();
        is.seekg(0, std::ios::beg);

        char* origdta = (char*)malloc(size+1);
        origdta[size] = '\0';
        is.read(origdta, size);

        cereal::rapidxml::xml_document<> origdoc;
        origdoc.parse<cereal::rapidxml::parse_no_data_nodes>(origdta);

        // Now the newly serialised file
        is_new.seekg(0, std::ios::end);
        size = is_new.tellg();
        is_new.seekg(0, std::ios::beg);
        char* newdta = (char*)malloc(size+1);
        newdta[size] = '\0';
        is_new.read(newdta, size);

        cereal::rapidxml::xml_document<> newdoc;
        newdoc.parse<cereal::rapidxml::parse_no_data_nodes>(newdta);

        // Compare
        int depth = 0;
        int maxdepth = 0;
        fail = !recurse(origdoc.first_node(), newdoc.first_node(), depth, maxdepth);
        std::cout << "Maxdepth" << maxdepth << std::endl;

        free(origdta);
        free(newdta);*/

        if(fail)
            std::cout << "FAIL"
                      << " (" << lnum << ")"
                      << std::endl;
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
