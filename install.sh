#!/bin/bash
MSBUILD=C:/Windows/Microsoft.NET/Framework/v4.0.30319/msbuild.exe

rm -r bin
mkdir bin

cd CppUtil
./install.sh
cd ..

$MSBUILD CanonCameraApp/CanonCameraApp.vcxproj //t:Clean
$MSBUILD CanonCameraApp/CanonFilter.vcxproj //t:Clean

$MSBUILD CanonCameraApp/CanonCameraApp.vcxproj //p:Configuration=Debug
$MSBUILD CanonCameraApp/CanonCameraApp.vcxproj //p:Configuration=Release
$MSBUILD CanonFilter/CanonFilter.vcxproj //p:Configuration=Debug
$MSBUILD CanonFilter/CanonFilter.vcxproj //p:Configuration=Release


cp -r -v CanonCameraApp/bin/*.exe bin/
cp -r -v CanonFilter/bin/*.ax bin/
cp -r -v batch/*.bat bin/
cp -v libjpeg-turbo/bin/turbojpeg.dll bin/
cp -r EDSDK/Dll/* bin/


cp -v CppUtil/CppUtil/bin/*.dll bin/
cp -v CppUtil/TestCppUtil/bin/*.exe bin/

