QT -= gui

CONFIG += c++11 console precompile_header
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    CUEActionEvents/actioneventbase.h \
    CUEActionEvents/delaymacroactionevent.h \
    CUEActionEvents/keyboardmacroactionevent.h \
    CUEActionEvents/mousebuttonmacroactionevent.h \
    CUEActionEvents/mousescrollmacroactionevent.h \
    CUEActions/baseaction.h \
    CUEActions/brightnessaction.h \
    CUEActions/dolbystatechangeaction.h \
    CUEActions/dpiaction.h \
    CUEActions/eqpresetswitchingaction.h \
    CUEActions/gestureaction.h \
    CUEActions/keyremapaction.h \
    CUEActions/macroaction.h \
    CUEActions/macrorecordingaction.h \
    CUEActions/micmuteaction.h \
    CUEActions/profileswitchingaction.h \
    CUEActions/sidetonemuteaction.h \
    CUEActions/winlockaction.h \
    CUEAnimations/blinklighting.h \
    CUEAnimations/breathelighting.h \
    CUEAnimations/colorpulselighting.h \
    CUEAnimations/colorshiftlighting.h \
    CUEAnimations/colorwarplighting.h \
    CUEAnimations/colorwavelighting.h \
    CUEAnimations/cueanimationwithtransitions.h \
    CUEAnimations/cuecolourclass.h \
    CUEAnimations/frequencyvisualizerlighting.h \
    CUEAnimations/gradientlighting.h \
    CUEAnimations/lightinglink.h \
    CUEAnimations/marqueelighting.h \
    CUEAnimations/rainbowlighting.h \
    CUEAnimations/rainbowwavelighting.h \
    CUEAnimations/rainlighting.h \
    CUEAnimations/ripplelighting.h \
    CUEAnimations/singlecolorpulselighting.h \
    CUEAnimations/singlecolorvisorlighting.h \
    CUEAnimations/solidlighting.h \
    CUEAnimations/spiralrainbowlighting.h \
    CUEAnimations/staticlighting.h \
    CUEAnimations/strobinglighting.h \
    CUEAnimations/temperaturelighting.h \
    CUEAnimations/typelighting.h \
    CUEAnimations/visorlighting.h \
    CUEAnimations/wavelighting.h \
    CUEBehaviours/basebehaviour.h \
    CUEActions/actionexecutionhints.h \
    CUEBehaviours/directiondpibehavior.h \
    CUEBehaviours/sniperdpibehavior.h \
    CUECooling/asetekcoolingconfiguration.h \
    CUECooling/asetekcoolingconfigurationstorage.h \
    CUECooling/coolingconfigurationbase.h \
    CUECooling/coolingconfigurationstoragebase.h \
    CUECooling/coolingconfigurationstoragebasebase.h \
    CUECooling/lightingnodeconfigurationstorage.h \
    CUECooling/lightingnodecoolingconfiguration.h \
    CUECooling/platinumcoolersconfigurationstorage.h \
    CUECooling/platinumcoolingconfiguration.h \
    CUECooling/psucoolingconfiguration.h \
    CUECooling/psucoolingconfigurationstorage.h \
    CUECooling/starcoolersconfigurationstorage.h \
    CUECooling/starcoolingconfiguration.h \
    CUEProperties/actionsproperty.h \
    CUEProperties/katardpiproperty.h \
    advancedlightinglayer.h \
    CUEProperties/advancedlightingsproperty_proxy.h \
    CUEProperties/aggregatedlightingsproperty_proxy.h \
    CUEProperties/alldevicescoolingproperty.h \
    CUEProperties/anglesnappingproperty.h \
    CUEProperties/baseproperty.h \
    CUEProperties/basiclightingsproperty_proxy.h \
    CUEProperties/batteryproperty.h \
    CUEProperties/brightnessindicatorproperty_proxy.h \
    CUEProperties/buttonresponseoptimizationproperty.h \
    CUEProperties/channelpropertiesbase.h \
    CUEProperties/channelpropertiesclass.h \
    CUEProperties/channelpropertiescontainerclass.h \
    CUEProperties/coolingconfigurationproperty_proxy.h \
    CUEAnimations/cueanimationbase.h \
    basiclightinglayer.h \
    basiclightingparams.h \
    cuedevice.h \
    cuekeybase.h \
    cueprofileclasses.h \
    CUEProperties/dolbyproperty.h \
    CUEProperties/dpiproperty_proxy.h \
    CUEProperties/gesturesproperty.h \
    CUEProperties/hardwaremetaproperty_proxy.h \
    CUEProperties/indicatorbrightnessproperty.h \
    CUEProperties/joystickperformanceproperty.h \
    CUEProperties/liftheightproperty.h \
    CUEProperties/lightinglinkproperty.h \
    CUEProperties/macrorecordingproperty.h \
    CUEProperties/microphoneproperty.h \
    CUEProperties/osdproperty.h \
    CUEProperties/presetsproperty.h \
    CUEProperties/profileindicatorproperty.h \
    CUEProperties/sidelightingproperty.h \
    CUEProperties/sidetoneproperty.h \
    CUEProperties/systempointerproperty.h \
    CUEProperties/temperaturealertproperty.h \
    CUEProperties/touchpadperformanceproperty.h \
    CUEProperties/winlockindicatorproperty_proxy.h \
    CUEProperties/winlockproperty.h \
    CUEProperties/xdlprofileproperty.h \
    cuerepeatoptions.h \
    lightingexecutionhints.h
QMAKE_CXXFLAGS += "-Wno-unused-parameter"

CONFIG += file_copies
COPIES += tests
tests.files = $$files(tests/*.cueprofile)
tests.path = $$OUT_PWD/tests

PRECOMPILED_HEADER = cueprofileclasses.h
