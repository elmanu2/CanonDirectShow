#!/bin/bash

MSBUILD=C:/Windows/Microsoft.NET/Framework/v4.0.30319/msbuild.exe

mkdir -p bin

$MSBUILD oscpack_1_1_0.vcxproj //p:Configuration=Debug
$MSBUILD oscpack_1_1_0.vcxproj //p:Configuration=Release

$MSBUILD unittest.vcxproj //p:Configuration=Debug
$MSBUILD unittest.vcxproj //p:Configuration=Release


