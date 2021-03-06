#ifndef CUEPROFILECLASSES_H
#define CUEPROFILECLASSES_H
#include <map>
#include <QString>
// This is used to change the comparator if needed for the tests
std::map<QString, int>* profileKeyCmpMap = nullptr;
std::map<QString, int>* coolingCmpMap = nullptr;
std::map<QString, int>* devCmpMap = nullptr;

// Properties
#include "CUEProperties/baseproperty.h"
#include "CUEProperties/buttonresponseoptimizationproperty.h"
#include "CUEProperties/liftheightproperty.h"
#include "CUEProperties/aggregatedlightingsproperty_proxy.h"
#include "CUEProperties/actionsproperty.h"
#include "CUEProperties/anglesnappingproperty.h"
#include "CUEProperties/basiclightingsproperty_proxy.h"
#include "CUEProperties/advancedlightingsproperty_proxy.h"
#include "CUEProperties/hardwaremetaproperty_proxy.h"
#include "CUEProperties/profileindicatorproperty.h"
#include "CUEProperties/dpiproperty_proxy.h"
#include "CUEProperties/systempointerproperty.h"
#include "CUEProperties/brightnessindicatorproperty_proxy.h"
#include "CUEProperties/winlockindicatorproperty_proxy.h"
#include "CUEProperties/winlockproperty.h"
#include "CUEProperties/sidelightingproperty.h"
#include "CUEProperties/macrorecordingproperty.h"
#include "CUEProperties/touchpadperformanceproperty.h"
#include "CUEProperties/joystickperformanceproperty.h"
#include "CUEProperties/gesturesproperty.h"
#include "CUEProperties/presetsproperty.h"
#include "CUEProperties/dolbyproperty.h"
#include "CUEProperties/indicatorbrightnessproperty.h"
#include "CUEProperties/sidetoneproperty.h"
#include "CUEProperties/batteryproperty.h"
#include "CUEProperties/microphoneproperty.h"
#include "CUEProperties/temperaturealertproperty.h"
#include "CUEProperties/osdproperty.h"
#include "CUEProperties/alldevicescoolingproperty.h"
#include "CUEProperties/lightinglinkproperty.h"
#include "CUEProperties/xdlprofileproperty.h"
#include "CUEProperties/coolingconfigurationproperty_proxy.h"
#include "CUEProperties/channelpropertiescontainerclass.h"
#include "CUEProperties/katardpiproperty.h"

// Lighting-related
#include "advancedlightinglayer.h"
#include "basiclightinglayer.h"

// Animations
#include "CUEAnimations/gradientlighting.h"
#include "CUEAnimations/staticlighting.h"
#include "CUEAnimations/blinklighting.h"
#include "CUEAnimations/wavelighting.h"
#include "CUEAnimations/ripplelighting.h"
#include "CUEAnimations/solidlighting.h"
#include "CUEAnimations/frequencyvisualizerlighting.h"
#include "CUEAnimations/typelighting.h"
#include "CUEAnimations/rainlighting.h"
#include "CUEAnimations/visorlighting.h"
#include "CUEAnimations/colorwavelighting.h"
#include "CUEAnimations/colorpulselighting.h"
#include "CUEAnimations/colorshiftlighting.h"
#include "CUEAnimations/rainbowwavelighting.h"
#include "CUEAnimations/spiralrainbowlighting.h"
#include "CUEAnimations/rainbowlighting.h"
#include "CUEAnimations/singlecolorpulselighting.h"
#include "CUEAnimations/singlecolorvisorlighting.h"
#include "CUEAnimations/lightinglink.h"
#include "CUEAnimations/strobinglighting.h"
#include "CUEAnimations/temperaturelighting.h"
#include "CUEAnimations/colorwarplighting.h"
#include "CUEAnimations/marqueelighting.h"
#include "CUEAnimations/breathelighting.h"

// Actions
#include "CUEActions/dpiaction.h"
#include "CUEActions/profileswitchingaction.h"
#include "CUEActions/keyremapaction.h"
#include "CUEActions/winlockaction.h"
#include "CUEActions/brightnessaction.h"
#include "CUEActions/macrorecordingaction.h"
#include "CUEActions/eqpresetswitchingaction.h"
#include "CUEActions/dolbystatechangeaction.h"
#include "CUEActions/micmuteaction.h"
#include "CUEActions/sidetonemuteaction.h"
#include "CUEActions/gestureaction.h"
#include "CUEActions/macroaction.h"

// Behaviours
#include "CUEBehaviours/directiondpibehavior.h"
#include "CUEBehaviours/sniperdpibehavior.h"

// Cooling
#include "CUECooling/asetekcoolingconfiguration.h"
#include "CUECooling/psucoolingconfiguration.h"
#include "CUECooling/lightingnodecoolingconfiguration.h"
#include "CUECooling/coolingconfigurationbase.h"
#include "CUECooling/coolingconfigurationstoragebase.h"
#include "CUECooling/coolingconfigurationstoragebasebase.h"
#include "CUECooling/asetekcoolingconfigurationstorage.h"
#include "CUECooling/lightingnodeconfigurationstorage.h"
#include "CUECooling/psucoolingconfigurationstorage.h"
#include "CUECooling/starcoolingconfiguration.h"
#include "CUECooling/platinumcoolingconfiguration.h"
#include "CUECooling/platinumcoolersconfigurationstorage.h"
#include "CUECooling/starcoolersconfigurationstorage.h"

// Action Events
#include "CUEActionEvents/keyboardmacroactionevent.h"
#include "CUEActionEvents/delaymacroactionevent.h"
#include "CUEActionEvents/mousescrollmacroactionevent.h"
#include "CUEActionEvents/mousebuttonmacroactionevent.h"

#endif // CUEPROFILECLASSES_H
