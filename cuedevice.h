#ifndef CUEDEVICE_H
#define CUEDEVICE_H
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/xml.hpp>
class CUEDevice
{
public:
    CUEDevice() {}
    QString deviceId;
    class {
    public:
        uint16_t usbVid;
        uint16_t usbPid;
        template <class Archive>
        void serialize(Archive& ar)
        {
            ar(CEREAL_NVP(usbVid), CEREAL_NVP(usbPid));
        }
    } modelId;
    QString hidCaps;
    QString deviceLightingType;
    template <class Archive>
    void serialize(Archive& ar)
    {
        ar(CEREAL_NVP(deviceId), CEREAL_NVP(modelId), CEREAL_NVP(hidCaps), CEREAL_NVP(deviceLightingType));
    }
};
CEREAL_CLASS_VERSION(CUEDevice, 303)

class CUEDeviceComparator {
public:
    bool operator()(const CUEDevice& d1, const CUEDevice& d2)
    {
        // This may as well be completely wrong
        return (d1.deviceId == d2.deviceId) | (d1.modelId.usbPid + d1.modelId.usbVid < d2.modelId.usbPid + d2.modelId.usbVid)
                | (d1.hidCaps == d2.hidCaps) | (d1.deviceLightingType == d2.deviceLightingType);
    }
};

#endif // CUEDEVICE_H
