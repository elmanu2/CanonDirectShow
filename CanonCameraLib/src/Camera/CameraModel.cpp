#include "cameramodel.h"


// Constructor
CameraModel::CameraModel(EdsCameraRef camera):
    _lockCount(0),
    _camera(camera)
{
    memset(&_focusInfo, 0, sizeof(_focusInfo));
}

//Acquisition of Camera Object
EdsCameraRef CameraModel::getCameraObject() const
{
    return _camera;
}


void CameraModel::setAEMode(EdsUInt32 value )
{
    _AEMode = value;
}
void CameraModel::setTv( EdsUInt32 value )
{
    _Tv = value;
}

void CameraModel::setAv( EdsUInt32 value )
{
    _Av = value;}

void CameraModel::setIso( EdsUInt32 value )
{
    _Iso = value; }

void CameraModel::setMeteringMode( EdsUInt32 value )
{
    _MeteringMode = value;
}

void CameraModel::setExposureCompensation( EdsUInt32 value)
{
    _ExposureCompensation = value;
}

void CameraModel::setImageQuality( EdsUInt32 value)
{
    _ImageQuality = value;
}

void CameraModel::setEvfMode( EdsUInt32 value)
{
    _evfMode = value;
}

void CameraModel::setEvfOutputDevice( EdsUInt32 value)
{
    _evfOutputDevice = value;
}

void CameraModel::setEvfDepthOfFieldPreview( EdsUInt32 value)
{
    _evfDepthOfFieldPreview = value;
}

void CameraModel::setEvfZoom( EdsUInt32 value)
{
    _evfZoom = value;
}

void CameraModel::setEvfZoomPosition( EdsPoint value)
{
    _evfZoomPosition = value;
}

void CameraModel::setEvfZoomRect( EdsRect value)
{
    _evfZoomRect = value;
}

void CameraModel::setModelName(EdsChar *modelName)
{
    strcpy(_modelName, modelName);
}

void CameraModel::setEvfAFMode( EdsUInt32 value)
{
    _evfAFMode = value;
}

void CameraModel::setFocusInfo( EdsFocusInfo value)
{
    _focusInfo = value;
}

// Taking a picture parameter
EdsUInt32 CameraModel::getAEMode() const
{
    return _AEMode;
}

EdsUInt32 CameraModel::getTv() const
{
    return _Tv;
}

EdsUInt32 CameraModel::getAv() const
{
    return _Av;
}

EdsUInt32 CameraModel::getIso() const
{
    return _Iso;
}

EdsUInt32 CameraModel::getMeteringMode() const
{
    return _MeteringMode;
}

EdsUInt32 CameraModel::getExposureCompensation() const
{
    return _ExposureCompensation;
}

EdsUInt32 CameraModel::getImageQuality() const
{
    return _ImageQuality;
}

EdsUInt32 CameraModel::getEvfMode() const
{
    return _evfMode;
}

EdsUInt32 CameraModel::getEvfOutputDevice() const
{
    return _evfOutputDevice;
}

EdsUInt32 CameraModel::getEvfDepthOfFieldPreview() const
{
    return _evfDepthOfFieldPreview;
}

EdsUInt32 CameraModel::getEvfZoom() const
{
    return _evfZoom;
}

EdsPoint  CameraModel::getEvfZoomPosition() const
{
    return _evfZoomPosition;
}

EdsRect	  CameraModel::getEvfZoomRect() const
{
    return _evfZoomRect;
}

EdsUInt32 CameraModel::getEvfAFMode() const
{
    return _evfAFMode;
}

EdsChar * CameraModel::getModelName()
{
    return _modelName;
}

EdsFocusInfo  CameraModel::getFocusInfo()const
{
    return _focusInfo;
}

//List of value in which taking a picture parameter can be set
EdsPropertyDesc CameraModel::getAEModeDesc() const
{
    return _AEModeDesc;
}

EdsPropertyDesc CameraModel::getAvDesc() const
{
    return _AvDesc;
}

EdsPropertyDesc CameraModel::getTvDesc()	const
{
    return _TvDesc;
}

EdsPropertyDesc CameraModel::getIsoDesc()	const
{
    return _IsoDesc;
}

EdsPropertyDesc CameraModel::getMeteringModeDesc()	const
{
    return _MeteringModeDesc;
}

EdsPropertyDesc CameraModel::getExposureCompensationDesc()	const
{
    return _ExposureCompensationDesc;
}

EdsPropertyDesc CameraModel::getImageQualityDesc()	const
{
    return _ImageQualityDesc;
}

EdsPropertyDesc CameraModel::getEvfAFModeDesc()	const
{
    return _evfAFModeDesc;
}

//List of value in which taking a picture parameter can be set
void CameraModel::setAEModeDesc(const EdsPropertyDesc* desc)
{
    _AEModeDesc = *desc;
}

void CameraModel::setAvDesc(const EdsPropertyDesc* desc)
{
    _AvDesc = *desc;
}

void CameraModel::setTvDesc(const EdsPropertyDesc* desc)
{
    _TvDesc = *desc;
}

void CameraModel::setIsoDesc(const EdsPropertyDesc* desc)
{
    _IsoDesc = *desc;
}

void CameraModel::setMeteringModeDesc(const EdsPropertyDesc* desc)
{
    _MeteringModeDesc = *desc;
}

void CameraModel::setExposureCompensationDesc(const EdsPropertyDesc* desc)
{
    _ExposureCompensationDesc = *desc;
}

void CameraModel::setImageQualityDesc(const EdsPropertyDesc* desc)
{
    _ImageQualityDesc = *desc;
}

void CameraModel::setEvfAFModeDesc(const EdsPropertyDesc* desc)
{
    _evfAFModeDesc = *desc;
}

//Setting of taking a picture parameter(UInt32)
void CameraModel::setPropertyUInt32(EdsUInt32 propertyID, EdsUInt32 value)
{
    switch(propertyID)
    {
    case kEdsPropID_AEMode:     			setAEMode(value);					break;
    case kEdsPropID_Tv:						setTv(value);						break;
    case kEdsPropID_Av:						setAv(value);						break;
    case kEdsPropID_ISOSpeed:				setIso(value);						break;
    case kEdsPropID_MeteringMode:			setMeteringMode(value);				break;
    case kEdsPropID_ExposureCompensation:	setExposureCompensation(value);		break;
    case kEdsPropID_ImageQuality:			setImageQuality(value);				break;
    case kEdsPropID_Evf_Mode:				setEvfMode(value);					break;
    case kEdsPropID_Evf_OutputDevice:		setEvfOutputDevice(value);			break;
    case kEdsPropID_Evf_DepthOfFieldPreview:setEvfDepthOfFieldPreview(value);	break;
    case kEdsPropID_Evf_AFMode:				setEvfAFMode(value);				break;
    }
}

//Setting of taking a picture parameter(String)
void CameraModel::setPropertyString(EdsUInt32 propertyID, EdsChar *str)
{
    switch(propertyID)
    {
    case kEdsPropID_ProductName:			setModelName(str);					break;
    }
}

void CameraModel::setProeprtyFocusInfo(EdsUInt32 propertyID, EdsFocusInfo info)
{
    switch(propertyID)
    {
    case kEdsPropID_FocusInfo:				setFocusInfo(info);				break;
    }
}

//Setting of value list that can set taking a picture parameter
void CameraModel::setPropertyDesc(EdsUInt32 propertyID, const EdsPropertyDesc* desc)
{
    switch(propertyID)
    {
    case kEdsPropID_AEModeSelect:			setAEModeDesc(desc);				break;
    case kEdsPropID_Tv:						setTvDesc(desc);					break;
    case kEdsPropID_Av:						setAvDesc(desc);					break;
    case kEdsPropID_ISOSpeed:				setIsoDesc(desc);					break;
    case kEdsPropID_MeteringMode:			setMeteringModeDesc(desc);			break;
    case kEdsPropID_ExposureCompensation:	setExposureCompensationDesc(desc);	break;
    case kEdsPropID_ImageQuality:			setImageQualityDesc(desc);			break;
    case kEdsPropID_Evf_AFMode:				setEvfAFModeDesc(desc);				break;
    }
}

//Acquisition of value list that can set taking a picture parameter
EdsPropertyDesc CameraModel::getPropertyDesc(EdsUInt32 propertyID)
{
    EdsPropertyDesc desc = {0};
    switch(propertyID)
    {
    case kEdsPropID_AEModeSelect:			desc = getAEModeDesc();					break;
    case kEdsPropID_Tv:						desc = getTvDesc();						break;
    case kEdsPropID_Av:						desc = getAvDesc();						break;
    case kEdsPropID_ISOSpeed:				desc = getIsoDesc();					break;
    case kEdsPropID_MeteringMode:			desc = getMeteringModeDesc();			break;
    case kEdsPropID_ExposureCompensation:	desc = getExposureCompensationDesc();	break;
    case kEdsPropID_ImageQuality:			desc = getImageQualityDesc();			break;
    case kEdsPropID_Evf_AFMode:				desc = getEvfAFModeDesc();				break;
    }
    return desc;
}

bool CameraModel::isLegacy()
{
    return false;
}


