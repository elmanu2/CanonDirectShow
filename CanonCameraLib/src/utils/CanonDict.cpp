#include "CanonDict.h"
#include "EDSDKErrors.h"
#include "logger.h"

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

void CanonDict::LogErrorIfNotOk(unsigned long propEvent_){
    if(propEvent_ != EDS_ERR_OK){
        LOG_ERROR(ErrToString(propEvent_));
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

    //Property values
    _propValueUintDict[kEdsPropID_AEMode][0] = "Program AE";
    _propValueUintDict[kEdsPropID_AEMode][1] = "Shutter-Speed priority AE";
    _propValueUintDict[kEdsPropID_AEMode][2] = "Aperture Priority AE";
    _propValueUintDict[kEdsPropID_AEMode][3] = "Manual Exposure";
    _propValueUintDict[kEdsPropID_AEMode][4] = "Bulb";
    _propValueUintDict[kEdsPropID_AEMode][5] = "Auto depth of field AE";
    _propValueUintDict[kEdsPropID_AEMode][6] = "Depth of field AE";
    _propValueUintDict[kEdsPropID_AEMode][7] = "Camera Settings registered";
    _propValueUintDict[kEdsPropID_AEMode][8] = "Lock";
    _propValueUintDict[kEdsPropID_AEMode][9] = "Auto";

    _propValueUintDict[kEdsPropID_AEMode][10] = "Night scene portrait";
    _propValueUintDict[kEdsPropID_AEMode][11] = "Sport";
    _propValueUintDict[kEdsPropID_AEMode][12] = "Portrait";
    _propValueUintDict[kEdsPropID_AEMode][13] = "Landscape";
    _propValueUintDict[kEdsPropID_AEMode][14] = "Close-Up";
    _propValueUintDict[kEdsPropID_AEMode][15] = "Flash off";
    _propValueUintDict[kEdsPropID_AEMode][18] = "Auto";
    _propValueUintDict[kEdsPropID_AEMode][20] = "Movies";
    _propValueUintDict[kEdsPropID_AEMode][21] = "Photo in Movies";

    _propValueUintDict[kEdsPropID_AEMode][22] = "Scene intelligent Auto";
    _propValueUintDict[kEdsPropID_AEMode][23] = "Night Scenes";
    _propValueUintDict[kEdsPropID_AEMode][24] = "Backlit Scenes";

    _propValueUintDict[kEdsPropID_AEMode][26] = "Children";
    _propValueUintDict[kEdsPropID_AEMode][27] = "Food";
    _propValueUintDict[kEdsPropID_AEMode][28] = "Candlelight portraits";

    _propValueUintDict[kEdsPropID_ISOSpeed][0x0] = "ISO Auto";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x40] = "ISO 50";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x48] = "ISO 100";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x50] = "ISO 200";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x53] = "ISO 250";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x55] = "ISO 320";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x58] = "ISO 400";

    _propValueUintDict[kEdsPropID_ISOSpeed][0x5b] = "ISO 500";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x5d] = "ISO 640";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x60] = "ISO 800";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x63] = "ISO 1000";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x65] = "ISO 1250";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x68] = "ISO 1600";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x6b] = "ISO 2000";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x6d] = "ISO 2500";

    _propValueUintDict[kEdsPropID_ISOSpeed][0x70] = "ISO 3200";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x73] = "ISO 4000";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x75] = "ISO 5000";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x78] = "ISO 6400";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x7b] = "ISO 8000";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x7d] = "ISO 10000";

    _propValueUintDict[kEdsPropID_ISOSpeed][0x80] = "ISO 12800";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x88] = "ISO 25600";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x90] = "ISO 51200";
    _propValueUintDict[kEdsPropID_ISOSpeed][0x98] = "ISO 102400";

    _propValueUintDict[kEdsPropID_Av][0x08] = "1";
    _propValueUintDict[kEdsPropID_Av][0x0B] = "1.1";
    _propValueUintDict[kEdsPropID_Av][0x0C] = "1.2";
    _propValueUintDict[kEdsPropID_Av][0x0D] = "1.2";
    _propValueUintDict[kEdsPropID_Av][0x10] = "1.4";
    _propValueUintDict[kEdsPropID_Av][0x13] = "1.6";
    _propValueUintDict[kEdsPropID_Av][0x14] = "1.8";
    _propValueUintDict[kEdsPropID_Av][0x15] = "1.8 (1/3)"; 
    _propValueUintDict[kEdsPropID_Av][0x18] = "2";
    _propValueUintDict[kEdsPropID_Av][0x1B] = "2.2";
    _propValueUintDict[kEdsPropID_Av][0x1C] = "2.5";
    _propValueUintDict[kEdsPropID_Av][0x1D] = "2.5 (1/3)";
    _propValueUintDict[kEdsPropID_Av][0x20] = "2.8";
    _propValueUintDict[kEdsPropID_Av][0x23] = "3.2";
    _propValueUintDict[kEdsPropID_Av][0x24] = "3.5";
    _propValueUintDict[kEdsPropID_Av][0x25] = "3.5 (1/3)";
    _propValueUintDict[kEdsPropID_Av][0x28] = "4";
    _propValueUintDict[kEdsPropID_Av][0x2B] = "4.5";
    _propValueUintDict[kEdsPropID_Av][0x2C] = "4.5 (1/3)";
    _propValueUintDict[kEdsPropID_Av][0x2D] = "5.0";
    _propValueUintDict[kEdsPropID_Av][0x30] = "5.6";
    _propValueUintDict[kEdsPropID_Av][0x33] = "6.3";
    _propValueUintDict[kEdsPropID_Av][0x34] = "6.7";
    _propValueUintDict[kEdsPropID_Av][0x35] = "7.1";
    _propValueUintDict[kEdsPropID_Av][0x38] = "8";
    _propValueUintDict[kEdsPropID_Av][0x3B] = "9";
    _propValueUintDict[kEdsPropID_Av][0x3C] = "9.5";
    _propValueUintDict[kEdsPropID_Av][0x3D] = "10";
    _propValueUintDict[kEdsPropID_Av][0x40] = "11";
    _propValueUintDict[kEdsPropID_Av][0x43] = "13 (1/3)";
    _propValueUintDict[kEdsPropID_Av][0x44] = "13";
    _propValueUintDict[kEdsPropID_Av][0x45] = "14";
    _propValueUintDict[kEdsPropID_Av][0x48] = "16";
    _propValueUintDict[kEdsPropID_Av][0x4B] = "18";
    _propValueUintDict[kEdsPropID_Av][0x4C] = "19";
    _propValueUintDict[kEdsPropID_Av][0x4D] = "20";
    _propValueUintDict[kEdsPropID_Av][0x50] = "22";
    _propValueUintDict[kEdsPropID_Av][0x53] = "25";
    _propValueUintDict[kEdsPropID_Av][0x54] = "27";
    _propValueUintDict[kEdsPropID_Av][0x55] = "29";
    _propValueUintDict[kEdsPropID_Av][0x58] = "32";
    _propValueUintDict[kEdsPropID_Av][0x5B] = "36";
    _propValueUintDict[kEdsPropID_Av][0x5C] = "38";
    _propValueUintDict[kEdsPropID_Av][0x5D] = "40";
    _propValueUintDict[kEdsPropID_Av][0x60] = "45";
    _propValueUintDict[kEdsPropID_Av][0x63] = "51";
    _propValueUintDict[kEdsPropID_Av][0x64] = "54";
    _propValueUintDict[kEdsPropID_Av][0x65] = "57";
    _propValueUintDict[kEdsPropID_Av][0x68] = "64";
    _propValueUintDict[kEdsPropID_Av][0x6B] = "72";
    _propValueUintDict[kEdsPropID_Av][0x6C] = "76";
    _propValueUintDict[kEdsPropID_Av][0x6D] = "80";
    _propValueUintDict[kEdsPropID_Av][0x70] = "91";
    
                                          
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

std::string CanonDict::PropValueToString(unsigned long prop_, unsigned long value_)
{
    return _propValueUintDict[prop_][value_];
}

std::string CanonDict::ErrToString(unsigned long objEvent_)
{
    return _errorDict[objEvent_];
}
