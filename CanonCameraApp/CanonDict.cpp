#include "CanonDict.h"
#include "EDSDKTypes.h"

CanonDict* CanonDict::_instance = NULL;

std::map<unsigned long, std::string> CanonDict::_objectEventDict;

std::map<unsigned long, std::string> CanonDict::_propEventDict;

std::map<unsigned long, std::string> CanonDict::_stateEventDict;

std::map<unsigned long, std::string> CanonDict::_propIdDict;

CanonDict* CanonDict::getInstance()
{
    if(_instance == NULL)
    {
        return _instance = new CanonDict();
    }
    else
    {
        return _instance;
    }
}

CanonDict::CanonDict(void)
{
    _objectEventDict[kEdsObjectEvent_All] = "ObjectEvent-All";
    _objectEventDict[kEdsObjectEvent_VolumeInfoChanged] = "ObjectEvent-VolumeInfoChanged";
    _objectEventDict[kEdsObjectEvent_VolumeUpdateItems] = "ObjectEvent-VolumeUpdateItems";
    _objectEventDict[kEdsObjectEvent_DirItemCreated] = "ObjectEvent-DirItemCreated";
    _objectEventDict[kEdsObjectEvent_DirItemRemoved] = "ObjectEvent-DirItemRemoved";
    _objectEventDict[kEdsObjectEvent_DirItemInfoChanged] = "ObjectEvent-DirItemInfoChanged";
    _objectEventDict[kEdsObjectEvent_DirItemContentChanged] = "ObjectEvent-DirItemContentChanged";
    _objectEventDict[kEdsObjectEvent_DirItemRequestTransfer] = "ObjectEvent-DirItemRequestTransfer";
    _objectEventDict[kEdsObjectEvent_DirItemRequestTransferDT] = "ObjectEvent-DirItemRequestTransferDT";
    _objectEventDict[kEdsObjectEvent_DirItemCancelTransferDT] = "ObjectEvent-DirItemCancelTransferDT";
    _objectEventDict[kEdsObjectEvent_VolumeAdded] = "ObjectEvent-VolumeAdded";
    _objectEventDict[kEdsObjectEvent_VolumeRemoved] = "ObjectEvent-VolumeRemoved";

    _propEventDict[kEdsPropertyEvent_All] = "PropertyEvent-All";
    _propEventDict[kEdsPropertyEvent_PropertyChanged] = "PropertyEvent-PropertyChanged";
    _propEventDict[kEdsPropertyEvent_PropertyDescChanged] = "PropertyEvent-PropertyDescChanged";

    _stateEventDict[kEdsStateEvent_All] = "StateEvent-All";
    _stateEventDict[kEdsStateEvent_Shutdown] = "StateEvent-Shutdown";
    _stateEventDict[kEdsStateEvent_JobStatusChanged] = "StateEvent-JobStatusChanged";
    _stateEventDict[kEdsStateEvent_WillSoonShutDown] = "StateEvent-WillSoonShutdown";
    _stateEventDict[kEdsStateEvent_ShutDownTimerUpdate] = "StateEvent-ShutDownTimerUpdate";
    _stateEventDict[kEdsStateEvent_CaptureError] = "StateEvent-CaptureError";
    _stateEventDict[kEdsStateEvent_InternalError] = "StateEvent-InternalError";
    _stateEventDict[kEdsStateEvent_AfResult] = "StateEvent-AfResult";
    _stateEventDict[kEdsStateEvent_BulbExposureTime] = "StateEvent-BulbExposureTime";

    std::string prefix = "PropId-";
    _propIdDict[kEdsPropID_Unknown] = prefix + "Unknown";
    _propIdDict[kEdsPropID_ProductName] = prefix + "ProductName";
    _propIdDict[kEdsPropID_OwnerName] = prefix + "OwnerName";
    _propIdDict[kEdsPropID_MakerName] = prefix + "MakerName";
    _propIdDict[kEdsPropID_DateTime] = "DateTime";
    _propIdDict[kEdsPropID_FirmwareVersion] = "FirmwareVersion";
    _propIdDict[kEdsPropID_BatteryLevel] = "BatteryLevel";
    _propIdDict[kEdsPropID_CFn] = "CFn";
    _propIdDict[kEdsPropID_SaveTo] = "SaveTo";
    _propIdDict[kEdsPropID_CurrentStorage] = "CurrentStorage";
    _propIdDict[kEdsPropID_CurrentFolder ] = "CurrentFolder";
    _propIdDict[kEdsPropID_MyMenu] = "MyMenu";
    _propIdDict[kEdsPropID_BatteryQuality] = "BatteryQuality";
    _propIdDict[kEdsPropID_BodyIDEx] = "BodyIndex";
    _propIdDict[kEdsPropID_HDDirectoryStructure] = "HDDirectoryStructure";
    _propIdDict[kEdsPropID_ImageQuality       ] = "ImageQuality";
    _propIdDict[kEdsPropID_JpegQuality        ] = "JpegQuality";
    _propIdDict[kEdsPropID_Orientation        ] = "Orientation";
    _propIdDict[kEdsPropID_ICCProfile         ] = "ICCProfile";
    _propIdDict[kEdsPropID_FocusInfo          ] = "FocusInfo";
    _propIdDict[kEdsPropID_DigitalExposure    ] = "DigitalExposure";
    _propIdDict[kEdsPropID_WhiteBalance       ] = "WhiteBalance";
    _propIdDict[kEdsPropID_ColorTemperature   ] = "ColorTemperature";
    _propIdDict[kEdsPropID_WhiteBalanceShift  ] = "WhiteBalanceShift";
    _propIdDict[kEdsPropID_Contrast           ] = "Contrast";
    _propIdDict[kEdsPropID_ColorSaturation    ] = "ColorSaturation";
    _propIdDict[kEdsPropID_ColorTone          ] = "ColorTone";
    _propIdDict[kEdsPropID_Sharpness          ] = "Sharpness";
    _propIdDict[kEdsPropID_ColorSpace         ] = "ColorSpace";
    _propIdDict[kEdsPropID_ToneCurve          ] = "ToneCurve";
    _propIdDict[kEdsPropID_PhotoEffect        ] = "PhotoEffect";
    _propIdDict[kEdsPropID_FilterEffect       ] = "FilterEffect";
    _propIdDict[kEdsPropID_ToningEffect       ] = "ToningEffect";
    _propIdDict[kEdsPropID_ParameterSet       ] = "ParameterSet";
    _propIdDict[kEdsPropID_ColorMatrix        ] = "ColorMatrix";
    _propIdDict[kEdsPropID_PictureStyle       ] = "PictureStyle";
    _propIdDict[kEdsPropID_PictureStyleDesc   ] = "PictureStyleDesc";
    _propIdDict[kEdsPropID_PictureStyleCaption] = "PictureStyleCaption";
    _propIdDict[kEdsPropID_ClickWBPoint] = "ClickWBPoint";
    _propIdDict[kEdsPropID_WBCoeffs    ] = "WBCoeffs";
    _propIdDict[kEdsPropID_GPSVersionID		] = "GPSVersionId";
    _propIdDict[kEdsPropID_GPSLatitudeRef	] = "GPSLatitudeRef";
    _propIdDict[kEdsPropID_GPSLatitude		] = "GPSLatitude";
    _propIdDict[kEdsPropID_GPSLongitudeRef	] = "GPSLongitudeRef";
    _propIdDict[kEdsPropID_GPSLongitude		] = "GPSLongitude";
    _propIdDict[kEdsPropID_GPSAltitudeRef	] = "GPSAltitudeRef";
    _propIdDict[kEdsPropID_GPSAltitude		] = "GPSAltitude";
    _propIdDict[kEdsPropID_GPSTimeStamp		] = "GPSTimeStamp";
    _propIdDict[kEdsPropID_GPSSatellites	] = "GPSSatellites";
    _propIdDict[kEdsPropID_GPSStatus		] = "GPSStatus";
    _propIdDict[kEdsPropID_GPSMapDatum		] = "GPSMapDatum";
    _propIdDict[kEdsPropID_GPSDateStamp		] = "GPSDateStamp";
    _propIdDict[kEdsPropID_AtCapture_Flag] = "AtCaptureFlaf";
    _propIdDict[kEdsPropID_AEMode                ] = "AEMode";
    _propIdDict[kEdsPropID_DriveMode             ] = "DriveMode";
    _propIdDict[kEdsPropID_ISOSpeed              ] = "ISOSpeed";
    _propIdDict[kEdsPropID_MeteringMode          ] = "MeteringMode";
    _propIdDict[kEdsPropID_AFMode                ] = "AFMode";
    _propIdDict[kEdsPropID_Av                    ] = "Av";
    _propIdDict[kEdsPropID_Tv                    ] = "Tv";
    _propIdDict[kEdsPropID_ExposureCompensation  ] = "ExposureCompensation";
    _propIdDict[kEdsPropID_FlashCompensation     ] = "FlashCompensation";
    _propIdDict[kEdsPropID_FocalLength           ] = "FocalLength";
    _propIdDict[kEdsPropID_AvailableShots        ] = "AvailableShots";
    _propIdDict[kEdsPropID_Bracket               ] = "Bracket";
    _propIdDict[kEdsPropID_WhiteBalanceBracket   ] = "WhiteBalanceBracket";
    _propIdDict[kEdsPropID_LensName              ] = "LensName";
    _propIdDict[kEdsPropID_AEBracket             ] = "AEBracket";
    _propIdDict[kEdsPropID_FEBracket             ] = "FEBracket";
    _propIdDict[kEdsPropID_ISOBracket            ] = "ISOBracket";
    _propIdDict[kEdsPropID_NoiseReduction        ] = "NoiseReduction";
    _propIdDict[kEdsPropID_FlashOn               ] = "FlashOn";
    _propIdDict[kEdsPropID_RedEye                ] = "RedEye";
    _propIdDict[kEdsPropID_FlashMode             ] = "FlashMode";
    _propIdDict[kEdsPropID_LensStatus            ] = "LensStatus";
    _propIdDict[kEdsPropID_Artist	             ] = "Artist";
    _propIdDict[kEdsPropID_Copyright	         ] = "Copyright";
    _propIdDict[kEdsPropID_DepthOfField	         ] = "DepthOfField";
    _propIdDict[kEdsPropID_EFCompensation        ] = "EFCompensation";
    _propIdDict[kEdsPropID_AEModeSelect          ] = "AEModeSelect";
    _propIdDict[kEdsPropID_Evf_OutputDevice       ] = "EVFOutputDevice";
    _propIdDict[kEdsPropID_Evf_Mode               ] = "EVFMode";
    _propIdDict[kEdsPropID_Evf_WhiteBalance       ] = "EVFWhiteBalance";
    _propIdDict[kEdsPropID_Evf_ColorTemperature   ] = "EVFColorTemperature";
    _propIdDict[kEdsPropID_Evf_DepthOfFieldPreview] = "EVFDepthOfFieldPreview";
    _propIdDict[kEdsPropID_Evf_Zoom           ] = "EVFZoom";
    _propIdDict[kEdsPropID_Evf_ZoomPosition   ] = "EVFZoomPosition";
    _propIdDict[kEdsPropID_Evf_FocusAid       ] = "EVFFocusAid";
    _propIdDict[kEdsPropID_Evf_Histogram      ] = "EVFHistogram";
    _propIdDict[kEdsPropID_Evf_ImagePosition  ] = "EVFImagePosition";
    _propIdDict[kEdsPropID_Evf_HistogramStatus] = "EVFHistogramStatus";
    _propIdDict[kEdsPropID_Evf_AFMode         ] = "EVFAFMode";
    _propIdDict[kEdsPropID_Record] = "Record";
    _propIdDict[kEdsPropID_Evf_HistogramY] = "EVFHistogramY";
    _propIdDict[kEdsPropID_Evf_HistogramR] = "EVFHistogramR";
    _propIdDict[kEdsPropID_Evf_HistogramG] = "EVFHistogramG";
    _propIdDict[kEdsPropID_Evf_HistogramB] = "EVFHistogramB";
    _propIdDict[kEdsPropID_Evf_CoordinateSystem ] = "CoordinateSystem";
    _propIdDict[kEdsPropID_Evf_ZoomRect         ] = "ZoomRect";
    _propIdDict[kEdsPropID_Evf_ImageClipRect    ] = "ImageClipRect";

}


CanonDict::~CanonDict(void)
{
}

std::string CanonDict::ObjectEventToString(unsigned long objEvent_)
{
    return _objectEventDict[objEvent_];
}

std::string CanonDict::PropertyEventToString(unsigned long objEvent_)
{
    return _propEventDict[objEvent_];
}

std::string CanonDict::StateEventToString(unsigned long objEvent_)
{
    return _stateEventDict[objEvent_];
}

std::string CanonDict::PropIdToString(unsigned long objEvent_)
{
    return _propIdDict[objEvent_];
}

