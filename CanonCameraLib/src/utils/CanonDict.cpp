#include "CanonDict.h"
#include "EDSDKTypes.h"
#include "EDSDKErrors.h"

CanonDict* CanonDict::_instance = NULL;

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

    std::string errPrefix = "error-";
    _errorDict[EDS_ERR_OK] = errPrefix + "NoError";
    //Miscellaneous errors

    _errorDict[EDS_ERR_UNIMPLEMENTED        ] = errPrefix + "Unimplemented";
    _errorDict[EDS_ERR_INTERNAL_ERROR       ] = errPrefix + "InternalError";
    _errorDict[EDS_ERR_MEM_ALLOC_FAILED     ] = errPrefix + "MemoryAllocationFailed";
    _errorDict[EDS_ERR_MEM_FREE_FAILED      ] = errPrefix + "MemoryFreeFailed";
    _errorDict[EDS_ERR_OPERATION_CANCELLED  ] = errPrefix + "OperationCanceled";
    _errorDict[EDS_ERR_INCOMPATIBLE_VERSION ] = errPrefix + "IncompatibleVersion";
    _errorDict[EDS_ERR_NOT_SUPPORTED        ] = errPrefix + "NotSupported";
    _errorDict[EDS_ERR_UNEXPECTED_EXCEPTION ] = errPrefix + "UnexpectedException";
    _errorDict[EDS_ERR_PROTECTION_VIOLATION ] = errPrefix + "ProtectionViolation";
    _errorDict[EDS_ERR_MISSING_SUBCOMPONENT ] = errPrefix + "MissingSubcomponent";
    _errorDict[EDS_ERR_SELECTION_UNAVAILABLE] = errPrefix + "SelectionUnavailable";

    //File errors
     prefix = errPrefix + "file-";
    _errorDict[EDS_ERR_FILE_IO_ERROR           ] = prefix + "IO";
    _errorDict[EDS_ERR_FILE_TOO_MANY_OPEN      ] = prefix + "TooManyOpen";
    _errorDict[EDS_ERR_FILE_NOT_FOUND          ] = prefix + "NotFound";
    _errorDict[EDS_ERR_FILE_OPEN_ERROR         ] = prefix + "Open";
    _errorDict[EDS_ERR_FILE_CLOSE_ERROR        ] = prefix + "Close";
    _errorDict[EDS_ERR_FILE_SEEK_ERROR         ] = prefix + "Seek";
    _errorDict[EDS_ERR_FILE_TELL_ERROR         ] = prefix + "Tell";
    _errorDict[EDS_ERR_FILE_READ_ERROR         ] = prefix + "Read";
    _errorDict[EDS_ERR_FILE_WRITE_ERROR        ] = prefix + "Write";
    _errorDict[EDS_ERR_FILE_PERMISSION_ERROR   ] = prefix + "Permission";
    _errorDict[EDS_ERR_FILE_DISK_FULL_ERROR    ] = prefix + "DiskFull";
    _errorDict[EDS_ERR_FILE_ALREADY_EXISTS     ] = prefix + "AlreadyExists";
    _errorDict[EDS_ERR_FILE_FORMAT_UNRECOGNIZED] = prefix + "FormatUnrecognized";
    _errorDict[EDS_ERR_FILE_DATA_CORRUPT       ] = prefix + "DataCorrupt";
    _errorDict[EDS_ERR_FILE_NAMING_NA          ] = prefix + "NamingNa";

    //Directory errors
    prefix = errPrefix + "Dir-";
    _errorDict[EDS_ERR_DIR_NOT_FOUND      ] = prefix + "NotFound";
    _errorDict[EDS_ERR_DIR_IO_ERROR       ] = prefix + "IOError";
    _errorDict[EDS_ERR_DIR_ENTRY_NOT_FOUND] = prefix + "EntryNotFound";
    _errorDict[EDS_ERR_DIR_ENTRY_EXISTS   ] = prefix + "EntryExists";
    _errorDict[EDS_ERR_DIR_NOT_EMPTY      ] = prefix + "NotEmpty";

    //Property errors
    prefix = errPrefix + "Properties-";
    _errorDict[EDS_ERR_PROPERTIES_UNAVAILABLE] = prefix + "Unavailable";
    _errorDict[EDS_ERR_PROPERTIES_MISMATCH   ] = prefix + "Mismatch";
    _errorDict[EDS_ERR_PROPERTIES_NOT_LOADED ] = prefix + "NotLoaded";

    //Function parameter errors
    prefix = errPrefix + "function-";
    _errorDict[EDS_ERR_INVALID_PARAMETER ] = prefix + "Parameter";
    _errorDict[EDS_ERR_INVALID_HANDLE    ] = prefix + "Handle";
    _errorDict[EDS_ERR_INVALID_POINTER   ] = prefix + "Pointer";
    _errorDict[EDS_ERR_INVALID_INDEX     ] = prefix + "Index";
    _errorDict[EDS_ERR_INVALID_LENGTH    ] = prefix + "Length";
    _errorDict[EDS_ERR_INVALID_FN_POINTER] = prefix + "FnPointer";
    _errorDict[EDS_ERR_INVALID_SORT_FN   ] = prefix + "SortFn";

    //Device errors
    prefix = errPrefix + "device-";
    _errorDict[EDS_ERR_DEVICE_NOT_FOUND         ] = prefix + "NotFound";
    _errorDict[EDS_ERR_DEVICE_BUSY              ] = prefix + "Busy";
    _errorDict[EDS_ERR_DEVICE_INVALID           ] = prefix + "Invalid";
    _errorDict[EDS_ERR_DEVICE_EMERGENCY         ] = prefix + "Emergency";
    _errorDict[EDS_ERR_DEVICE_MEMORY_FULL       ] = prefix + "MemoryFull";
    _errorDict[EDS_ERR_DEVICE_INTERNAL_ERROR    ] = prefix + "InternalError";
    _errorDict[EDS_ERR_DEVICE_INVALID_PARAMETER ] = prefix + "InvalidParameter";
    _errorDict[EDS_ERR_DEVICE_NO_DISK           ] = prefix + "NoDisk";
    _errorDict[EDS_ERR_DEVICE_DISK_ERROR        ] = prefix + "Disk";
    _errorDict[EDS_ERR_DEVICE_CF_GATE_CHANGED   ] = prefix + "CfGateChanged";
    _errorDict[EDS_ERR_DEVICE_DIAL_CHANGED      ] = prefix + "DialChanged";
    _errorDict[EDS_ERR_DEVICE_NOT_INSTALLED     ] = prefix + "NotInstalled";
    _errorDict[EDS_ERR_DEVICE_STAY_AWAKE        ] = prefix + "StayAwake";
    _errorDict[EDS_ERR_DEVICE_NOT_RELEASED      ] = prefix + "Notreleased";

    //Stream errors
    prefix = errPrefix + "Stream-";
    _errorDict[EDS_ERR_STREAM_IO_ERROR            ] = prefix + "IO";
    _errorDict[EDS_ERR_STREAM_NOT_OPEN            ] = prefix + "NotOpen";
    _errorDict[EDS_ERR_STREAM_ALREADY_OPEN        ] = prefix + "AlreadyOpen";
    _errorDict[EDS_ERR_STREAM_OPEN_ERROR          ] = prefix + "Open";
    _errorDict[EDS_ERR_STREAM_CLOSE_ERROR         ] = prefix + "Close";
    _errorDict[EDS_ERR_STREAM_SEEK_ERROR          ] = prefix + "Seek";
    _errorDict[EDS_ERR_STREAM_TELL_ERROR          ] = prefix + "Tell";
    _errorDict[EDS_ERR_STREAM_READ_ERROR          ] = prefix + "Read";
    _errorDict[EDS_ERR_STREAM_WRITE_ERROR         ] = prefix + "Write";
    _errorDict[EDS_ERR_STREAM_PERMISSION_ERROR    ] = prefix + "Permission";
    _errorDict[EDS_ERR_STREAM_COULDNT_BEGIN_THREAD] = prefix + "CouldNotBeginThread";
    _errorDict[EDS_ERR_STREAM_BAD_OPTIONS         ] = prefix + "BadOptions";
    _errorDict[EDS_ERR_STREAM_END_OF_STREAM       ] = prefix + "EndOfStream";

    //Communication errors
    prefix = errPrefix + "Communication-";
    _errorDict[EDS_ERR_COMM_PORT_IS_IN_USE     ] = prefix + "PortIsInUse";
    _errorDict[EDS_ERR_COMM_DISCONNECTED       ] = prefix + "Disconnected";
    _errorDict[EDS_ERR_COMM_DEVICE_INCOMPATIBLE] = prefix + "DeviceIncompatible";
    _errorDict[EDS_ERR_COMM_BUFFER_FULL        ] = prefix + "BufferFull";
    _errorDict[EDS_ERR_COMM_USB_BUS_ERR        ] = prefix + "UsbBus";

    //Lock/Unlock error
    prefix = errPrefix + "Lock/Unlock-";
    _errorDict[EDS_ERR_USB_DEVICE_LOCK_ERROR  ] = prefix + "Lock";
    _errorDict[EDS_ERR_USB_DEVICE_UNLOCK_ERROR] = prefix + "Unlock";

    // STI /WIA ?
    prefix = errPrefix + "STI/WIA-";
    _errorDict[EDS_ERR_STI_UNKNOWN_ERROR       ] = prefix + "Unkown";
    _errorDict[EDS_ERR_STI_INTERNAL_ERROR      ] = prefix + "Internall";
    _errorDict[EDS_ERR_STI_DEVICE_CREATE_ERROR ] = prefix + "DeviceCreate";
    _errorDict[EDS_ERR_STI_DEVICE_RELEASE_ERROR] = prefix + "DeviceRelease";
    _errorDict[EDS_ERR_DEVICE_NOT_LAUNCHED     ] = prefix + "DeviceNotlaunched";
    _errorDict[EDS_ERR_ENUM_NA                 ] = prefix + "EnumNa";
    _errorDict[EDS_ERR_INVALID_FN_CALL         ] = prefix + "InvalidFnCall";
    _errorDict[EDS_ERR_HANDLE_NOT_FOUND        ] = prefix + "HandleNotFound";
    _errorDict[EDS_ERR_INVALID_ID              ] = prefix + "InvalidId";
    _errorDict[EDS_ERR_WAIT_TIMEOUT_ERROR      ] = prefix + "WaitTimeout";

    //PTP
    prefix = errPrefix + "PTP-";
    _errorDict[EDS_ERR_SESSION_NOT_OPEN                        ] = prefix + "SessionNotOpen";
    _errorDict[EDS_ERR_INVALID_TRANSACTIONID                   ] = prefix + "InvalidTransactionId";
    _errorDict[EDS_ERR_INCOMPLETE_TRANSFER                     ] = prefix + "IncompleteTransfer";
    _errorDict[EDS_ERR_INVALID_STRAGEID                        ] = prefix + "InvalideStrategeId";
    _errorDict[EDS_ERR_DEVICEPROP_NOT_SUPPORTED                ] = prefix + "DevicePropNotSupported";
    _errorDict[EDS_ERR_INVALID_OBJECTFORMATCODE                ] = prefix + "InvalidObjectFormatCode";
    _errorDict[EDS_ERR_SELF_TEST_FAILED                        ] = prefix + "SelfTestFailed";
    _errorDict[EDS_ERR_PARTIAL_DELETION                        ] = prefix + "PartialDeletion";
    _errorDict[EDS_ERR_SPECIFICATION_BY_FORMAT_UNSUPPORTED     ] = prefix + "SpecByFormatUnsupported";
    _errorDict[EDS_ERR_NO_VALID_OBJECTINFO                     ] = prefix + "noValidObjectInfo";
    _errorDict[EDS_ERR_INVALID_CODE_FORMAT                     ] = prefix + "InvalidCodeFormat";
    _errorDict[EDS_ERR_UNKNOWN_VENDOR_CODE                     ] = prefix + "UnknownVendorCode";
    _errorDict[EDS_ERR_CAPTURE_ALREADY_TERMINATED              ] = prefix + "CaptureAlreadyTerminated";
    _errorDict[EDS_ERR_INVALID_PARENTOBJECT                    ] = prefix + "InvalidParentObject";
    _errorDict[EDS_ERR_INVALID_DEVICEPROP_FORMAT               ] = prefix + "InvalidDevicePropFormat";
    _errorDict[EDS_ERR_INVALID_DEVICEPROP_VALUE                ] = prefix + "InvalidDevicePropValue";
    _errorDict[EDS_ERR_SESSION_ALREADY_OPEN                    ] = prefix + "SessionAlreadyOpen";
    _errorDict[EDS_ERR_TRANSACTION_CANCELLED                   ] = prefix + "TransactionCancelled";
    _errorDict[EDS_ERR_SPECIFICATION_OF_DESTINATION_UNSUPPORTED] = prefix + "SpecOfDestintaionUnsupported";
    _errorDict[EDS_ERR_NOT_CAMERA_SUPPORT_SDK_VERSION          ] = prefix + "NotCameraSupportSdkVersion";

    //PTP Vendor
    prefix = errPrefix + "PTPVendor-";
    _errorDict[EDS_ERR_UNKNOWN_COMMAND      ] = prefix + "UnknownCommand";
    _errorDict[EDS_ERR_OPERATION_REFUSED    ] = prefix + "OperationRefused";
    _errorDict[EDS_ERR_LENS_COVER_CLOSE     ] = prefix + "LensCoverClose";
    _errorDict[EDS_ERR_LOW_BATTERY          ] = prefix + "LowBattery";
    _errorDict[EDS_ERR_OBJECT_NOTREADY      ] = prefix + "ObjectNotReady";
    _errorDict[EDS_ERR_CANNOT_MAKE_OBJECT   ] = prefix + "CannotMakeObject";
    _errorDict[EDS_ERR_MEMORYSTATUS_NOTREADY] = prefix + "MemoryStatusNotReady";

    //Take picture errors
    prefix = errPrefix + "TakePicture-";
    _errorDict[EDS_ERR_TAKE_PICTURE_AF_NG                  ] = prefix + "AF";
    _errorDict[EDS_ERR_TAKE_PICTURE_RESERVED               ] = prefix + "Reserved";
    _errorDict[EDS_ERR_TAKE_PICTURE_MIRROR_UP_NG           ] = prefix + "MirrorUp";
    _errorDict[EDS_ERR_TAKE_PICTURE_SENSOR_CLEANING_NG     ] = prefix + "PictureSensorCleaning";
    _errorDict[EDS_ERR_TAKE_PICTURE_SILENCE_NG             ] = prefix + "Silence";
    _errorDict[EDS_ERR_TAKE_PICTURE_NO_CARD_NG             ] = prefix + "NoCard";
    _errorDict[EDS_ERR_TAKE_PICTURE_CARD_NG                ] = prefix + "Card";
    _errorDict[EDS_ERR_TAKE_PICTURE_CARD_PROTECT_NG        ] = prefix + "CardProtect";
    _errorDict[EDS_ERR_TAKE_PICTURE_MOVIE_CROP_NG          ] = prefix + "MovieCrop";
    _errorDict[EDS_ERR_TAKE_PICTURE_STROBO_CHARGE_NG       ] = prefix + "StroboCharge";
    _errorDict[EDS_ERR_TAKE_PICTURE_NO_LENS_NG             ] = prefix + "NoLens";
    _errorDict[EDS_ERR_TAKE_PICTURE_SPECIAL_MOVIE_MODE_NG  ] = prefix + "SpecialMovieMode";
    _errorDict[EDS_ERR_TAKE_PICTURE_LV_REL_PROHIBIT_MODE_NG] = prefix + "LVRELProhibitMode";

    //Generic error
    prefix = errPrefix + "Generic-";
    _errorDict[EDS_ERR_LAST_GENERIC_ERROR_PLUS_ONE] = prefix + "GenericError+1";

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

std::string CanonDict::ErrToString(unsigned long objEvent_)
{
    return _errorDict[objEvent_];
}
