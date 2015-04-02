#!/bin/bash
MSBUILD=C:/Windows/Microsoft.NET/Framework/v4.0.30319/msbuild.exe

cp -r -v CanonCameraApp/bin/*.exe bin/
cp -r -v CanonFilter/bin/*.ax bin/
cp -r -v CanonFilterClient/bin/*.exe bin/
cp -r -v oscpack_1_1_0/bin/*.dll bin/
cp -r -v batch/*.bat bin/
cp -v libjpeg-turbo/bin/turbojpeg.dll bin/
cp -r EDSDK/Dll/* bin/
cp -v CppUtil/CppUtil/bin/*.dll bin/
cp -v CppUtil/TestCppUtil/bin/*.exe bin/

