#ifndef CUEDEVICE_H
#define CUEDEVICE_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
#include <QString>

class CUEDeviceVidPid
{
public:
    CUEDeviceVidPid() {}
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

static std::map<QString, int> devcmpmap = {
    {"StandardRgb", 0},
    {"StandardSingleColor", 1},
    {"ZoneRgb", 2},
    {"RestrictedWireless", 3},
    {"DramSingleColor", 4},
    {"Undefined", 5},
    {"DramRgb", 6},
};

class CUEDevice
{
public:
    CUEDevice() {}
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
    CUEDeviceNoCaps() {}
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

class CUEDeviceNoCapsComparator
{
public:
    bool operator()(const CUEDeviceNoCaps& d1, const CUEDeviceNoCaps& d2)
    {
        // In case we don't have the value in the list
        if((devcmpmap.count(d1.capability) && devcmpmap.count(d2.capability)))
            return devcmpmap[d1.capability] < devcmpmap[d2.capability];

        return (d1.deviceId == d2.deviceId) | (d1.capability < d2.capability)
                | (d1.modelId.usbPid + d1.modelId.usbVid > d2.modelId.usbPid + d2.modelId.usbVid);
    }
};

#endif // CUEDEVICE_H
