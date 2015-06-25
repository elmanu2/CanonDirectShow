#!/bin/bash

MSBUILD=C:/Windows/Microsoft.NET/Framework/v4.0.30319/msbuild.exe

$MSBUILD oscpack_1_1_0.vcxproj //t:Clean
$MSBUILD unittest.vcxproj //t:Clean
$MSBUILD testserver.vcxproj //t:Clean
$MSBUILD testclient.vcxproj //t:Clean
rm -r bin

