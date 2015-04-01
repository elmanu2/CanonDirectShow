#!/bin/bash

MSBUILD=C:/Windows/Microsoft.NET/Framework/v4.0.30319/msbuild.exe

$MSBUILD oscpack_1_1_0.vcxproj //t:Clean
rm -r bin

