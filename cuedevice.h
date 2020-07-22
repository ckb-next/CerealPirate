#ifndef CUEDEVICE_H
#define CUEDEVICE_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>

class CUEDeviceVidPid
{
public:
    CUEDeviceVidPid()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created CUEDeviceVidPid" << std::endl;
#endif
    }
    // Negative Vids/Pids are used
    int32_t usbVid;
    int32_t usbPid;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(usbVid), CEREAL_NVP(usbPid));
    }
};
CEREAL_CLASS_VERSION(CUEDeviceVidPid, 200)

class CUEDevice
{
public:
    CUEDevice()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created CUEDevice" << std::endl;
#endif
    }
    QString deviceId;
    CUEDeviceVidPid modelId;
    QString hidCaps;
    QString deviceLightingType;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(deviceId), CEREAL_NVP(modelId), CEREAL_NVP(hidCaps), CEREAL_NVP(deviceLightingType));
    }
};
CEREAL_CLASS_VERSION(CUEDevice, 303)

class CUEDeviceComparator
{
public:
    bool operator()(const CUEDevice& d1, const CUEDevice& d2)
    {
        return (d1.deviceId == d2.deviceId) | (d1.modelId.usbPid + d1.modelId.usbVid > d2.modelId.usbPid + d2.modelId.usbVid)
                | (d1.hidCaps == d2.hidCaps) | (d1.deviceLightingType == d2.deviceLightingType);
    }
};


class CUEDeviceNoCaps
{
public:
    CUEDeviceNoCaps()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created CUEDeviceNoCaps" << std::endl;
#endif
    }
    QString capability;
    QString deviceId;
    CUEDeviceVidPid modelId;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(capability), CEREAL_NVP(deviceId), CEREAL_NVP(modelId));
    }
};
CEREAL_CLASS_VERSION(CUEDeviceNoCaps, 301)

static std::map<QString, int> devCmpMapDefault = {
    {"StandardRgb", 0},
    {"StandardSingleColor", 1},
    {"ZoneRgb", 2},
    {"RestrictedWireless", 3},
    {"DramSingleColor", 4},
    {"Undefined", 5},
    {"DramRgb", 6},
};

class CUEDeviceNoCapsComparator
{
public:
    bool operator()(const CUEDeviceNoCaps& d1, const CUEDeviceNoCaps& d2)
    {
        std::map<QString, int>& cmpmap = *(devCmpMap ? devCmpMap : &devCmpMapDefault);
        // In case we don't have the value in the list
        if((cmpmap.count(d1.capability) && cmpmap.count(d2.capability)))
            return cmpmap[d1.capability] < cmpmap[d2.capability];

        return (d1.deviceId == d2.deviceId) | (d1.capability < d2.capability)
                | (d1.modelId.usbPid + d1.modelId.usbVid > d2.modelId.usbPid + d2.modelId.usbVid);
    }
};

// FIXME: Not a great name
class CUEDeviceNoCapsNoCap
{
public:
    CUEDeviceNoCapsNoCap()
    {
#ifdef DEBUG_DEFAULT_INIT
        std::cout << "Created CUEDeviceNoCapsNoCap" << std::endl;
#endif
    }
    QString deviceId;
    CUEDeviceVidPid vidPid;
    template <class Archive>
    void serialize(Archive& ar, const std::uint32_t version)
    {
        ar(CEREAL_NVP(deviceId), CEREAL_NVP(vidPid));
    }
};
CEREAL_CLASS_VERSION(CUEDeviceNoCapsNoCap, 300)

static std::map<QString, int> coolingCmpMapDefault = {
    {"DEMO_COMMANDER_PRO_DEVICE", 0},
    {"DEMO_PSU_DEVICE", 1},
    {"DEMO_LIQUID_COOLER_DEVICE", 2},
};

class CUEDeviceNoCapsNoCapComparator
{
public:
    bool operator()(const CUEDeviceNoCapsNoCap& d1, const CUEDeviceNoCapsNoCap& d2)
    {
        std::map<QString, int>& cmpmap = *(coolingCmpMap ? coolingCmpMap : &coolingCmpMapDefault);
        // In case we don't have the value in the list
        if((cmpmap.count(d1.deviceId) && cmpmap.count(d2.deviceId)))
            return cmpmap[d1.deviceId] < cmpmap[d2.deviceId];

        return (d1.vidPid.usbPid + d1.vidPid.usbVid > d2.vidPid.usbPid + d2.vidPid.usbVid);
    }
};

#endif // CUEDEVICE_H
