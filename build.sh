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

$MSBUILD CanonCameraApp/CanonCameraApp.vcxproj //t:Clean
$MSBUILD CanonCameraApp/CanonFilter.vcxproj //t:Clean

$MSBUILD CanonCameraApp/CanonCameraApp.vcxproj //p:Configuration=Debug
$MSBUILD CanonCameraApp/CanonCameraApp.vcxproj //p:Configuration=Release
$MSBUILD CanonFilter/CanonFilter.vcxproj //p:Configuration=Debug
$MSBUILD CanonFilter/CanonFilter.vcxproj //p:Configuration=Release


./copy.sh

