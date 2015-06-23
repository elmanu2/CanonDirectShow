#!/bin/bash
MSBUILD=C:/Windows/Microsoft.NET/Framework/v4.0.30319/msbuild.exe

rm -r bin
mkdir bin

cd CppUtil
./install.sh
cd ..

cd oscpack_1_1_0
./install.sh
cd ..

$MSBUILD CanonCameraLib/CanonCameraLib.vcxproj //t:Clean
$MSBUILD CanonCameraLib/CanonCameraTest.vcxproj //t:Clean
$MSBUILD CanonCameraApp/CanonCameraApp.vcxproj //t:Clean
$MSBUILD CanonCameraApp/CanonFilter.vcxproj //t:Clean

$MSBUILD CanonCameraLib/CanonCameraLib.vcxproj //p:Configuration=Debug
$MSBUILD CanonCameraLib/CanonCameraLib.vcxproj //p:Configuration=Release
$MSBUILD CanonCameraLib/CanonCameraTest.vcxproj //p:Configuration=Debug
$MSBUILD CanonCameraLib/CanonCameraTest.vcxproj //p:Configuration=Release
$MSBUILD CanonCameraApp/CanonCameraApp.vcxproj //p:Configuration=Debug
$MSBUILD CanonCameraApp/CanonCameraApp.vcxproj //p:Configuration=Release
$MSBUILD CanonFilter/CanonFilter.vcxproj //p:Configuration=Debug
$MSBUILD CanonFilter/CanonFilter.vcxproj //p:Configuration=Release


./copy.sh

