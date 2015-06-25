#include "CameraEventListener.h"
#include "logger.h"

EdsError CameraEventListener::downloadImage(EdsDirectoryItemRef dirItemRef_, 
                                std::string directory_,
                                std::string fileName_,
                                std::string extension_)
{
    EdsDirectoryItemInfo dirInfo;
    EdsStreamRef streamRef;
    //get information about object
    EdsError Error = EdsGetDirectoryItemInfo(dirItemRef_, &dirInfo);
    if (Error != EDS_ERR_OK)
        cout<< "SDK Error: " << Error << endl;
    string path;


    if ( !fileName_.empty() )
    {
        path = directory_ + "/" + fileName_ + extension_;
    }
    else
    {
        path = directory_ + "/" + dirInfo.szFileName ;
    }

    const EdsChar* CurrentPhoto = path.c_str() ;

    //create filestream to data
    //Error = EdsCreateFileStream("D:\\toto.jpg", kEdsFileCreateDisposition_CreateAlways, kEdsAccess_ReadWrite, &streamRef);
    Error = EdsCreateFileStream(path.c_str(), kEdsFileCreateDisposition_CreateAlways, kEdsAccess_ReadWrite, &streamRef);
    
    if(Error != EDS_ERR_OK)
    {
        LOG_ERROR("Error when creating picture " + path + "Code error : " + CanonDict::getInstance()->ErrToString(Error) );
    }
    //download file
    Error = EdsDownload(dirItemRef_, dirInfo.size, streamRef);
    //release stream
    Error = EdsRelease(streamRef);
    Error = EdsRelease(dirItemRef_);

    if(Error == EDS_ERR_OK)
    {
        LOG_INFO("Picture sucessfully created at " + path);
    }
    return Error;

}