/******************************************************************************
*                                                                             *
*   PROJECT : EOS Digital Software Development Kit EDSDK                      *
*      NAME : CameraModel.h	                                                  *
*                                                                             *
*   Description: This is the Sample code to show the usage of EDSDK.          *
*                                                                             *
*                                                                             *
*******************************************************************************
*                                                                             *
*   Written and developed by Camera Design Dept.53                            *
*   Copyright Canon Inc. 2006-2008 All Rights Reserved                        *
*                                                                             *
*******************************************************************************/

#ifndef CAMERAMODEL
#define CAMERAMODEL

#include "EDSDK.h"

#include "Observer.h"

class CameraModel : public Observable
{
protected:
    EdsCameraRef _camera;

    //Count of UIlock
    int     _lockCount;

    // Model name
    EdsChar  _modelName[EDS_MAX_NAME];

    // Taking a picture parameter
    EdsUInt32 _AEMode;
    EdsUInt32 _Av;
    EdsUInt32 _Tv;
    EdsUInt32 _Iso;
    EdsUInt32 _MeteringMode;
    EdsUInt32 _ExposureCompensation;
    EdsUInt32 _ImageQuality;
    EdsUInt32 _AvailableShot;
    EdsUInt32 _evfMode;
    EdsUInt32 _evfOutputDevice;
    EdsUInt32 _evfDepthOfFieldPreview;
    EdsUInt32 _evfZoom;
    EdsPoint  _evfZoomPosition;
    EdsRect	  _evfZoomRect;
    EdsUInt32 _evfAFMode;

    EdsFocusInfo _focusInfo;

    // List of value in which taking a picture parameter can be set
    EdsPropertyDesc _AEModeDesc;
    EdsPropertyDesc _AvDesc;
    EdsPropertyDesc _TvDesc;
    EdsPropertyDesc _IsoDesc;
    EdsPropertyDesc _MeteringModeDesc;
    EdsPropertyDesc _ExposureCompensationDesc;
    EdsPropertyDesc _ImageQualityDesc;
    EdsPropertyDesc _evfAFModeDesc;

public:
    // Constructor
    CameraModel(EdsCameraRef camera);

    //Acquisition of Camera Object
    EdsCameraRef getCameraObject() const ;

    //Property
public:
    // Taking a picture parameter
    void setAEMode(EdsUInt32 value )				;
    void setTv( EdsUInt32 value )					;
    void setAv( EdsUInt32 value )					;
    void setIso( EdsUInt32 value )					;
    void setMeteringMode( EdsUInt32 value )			;
    void setExposureCompensation( EdsUInt32 value)	;
    void setImageQuality( EdsUInt32 value)			;
    void setEvfMode( EdsUInt32 value)				;
    void setEvfOutputDevice( EdsUInt32 value)		;
    void setEvfDepthOfFieldPreview( EdsUInt32 value);
    void setEvfZoom( EdsUInt32 value)				;
    void setEvfZoomPosition( EdsPoint value)		;
    void setEvfZoomRect( EdsRect value)				;
    void setModelName(EdsChar *modelName)			;
    void setEvfAFMode( EdsUInt32 value)				;
    void setFocusInfo( EdsFocusInfo value)			;

    // Taking a picture parameter
    EdsUInt32 getAEMode() const					;
    EdsUInt32 getTv() const						;
    EdsUInt32 getAv() const						;
    EdsUInt32 getIso() const					;
    EdsUInt32 getMeteringMode() const			;
    EdsUInt32 getExposureCompensation() const	;
    EdsUInt32 getImageQuality() const			;
    EdsUInt32 getEvfMode() const				;
    EdsUInt32 getEvfOutputDevice() const		;
    EdsUInt32 getEvfDepthOfFieldPreview() const	;
    EdsUInt32 getEvfZoom() const				;
    EdsPoint  getEvfZoomPosition() const		;
    EdsRect	  getEvfZoomRect() const			;
    EdsUInt32 getEvfAFMode() const				;
    EdsChar *getModelName()						;
    EdsFocusInfo getFocusInfo()const			;

    //List of value in which taking a picture parameter can be set
    EdsPropertyDesc getAEModeDesc() const					;
    EdsPropertyDesc getAvDesc() const						;
    EdsPropertyDesc getTvDesc()	const						;
    EdsPropertyDesc getIsoDesc()	const					;
    EdsPropertyDesc getMeteringModeDesc()	const			;
    EdsPropertyDesc getExposureCompensationDesc()	const	;
    EdsPropertyDesc getImageQualityDesc()	const			;
    EdsPropertyDesc getEvfAFModeDesc()	const				;

    //List of value in which taking a picture parameter can be set
    void setAEModeDesc(const EdsPropertyDesc* desc)                 ;
    void setAvDesc(const EdsPropertyDesc* desc)						;
    void setTvDesc(const EdsPropertyDesc* desc)						;
    void setIsoDesc(const EdsPropertyDesc* desc)					;
    void setMeteringModeDesc(const EdsPropertyDesc* desc)			;
    void setExposureCompensationDesc(const EdsPropertyDesc* desc)   ;
    void setImageQualityDesc(const EdsPropertyDesc* desc)			;
    void setEvfAFModeDesc(const EdsPropertyDesc* desc)			    ;

public:
    //Setting of taking a picture parameter(UInt32)
    void setPropertyUInt32(EdsUInt32 propertyID, EdsUInt32 value);
    //Setting of taking a picture parameter(String)
    void setPropertyString(EdsUInt32 propertyID, EdsChar *str);

    void setProeprtyFocusInfo(EdsUInt32 propertyID, EdsFocusInfo info);

    //Setting of value list that can set taking a picture parameter
    void setPropertyDesc(EdsUInt32 propertyID, const EdsPropertyDesc* desc);

    //Acquisition of value list that can set taking a picture parameter
    EdsPropertyDesc getPropertyDesc(EdsUInt32 propertyID);

    //Access to camera
public:
    virtual bool isLegacy();

};

#endif

