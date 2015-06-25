# define the name of the installer
Outfile "Wistiti-CanonFilter.exe"
 
# define the directory to install to, the desktop in this case as specified  
# by the predefined $DESKTOP variable
InstallDir $PROGRAMFILES\Wistiti
 
# default section
Section
 
# define the output path for this file
SetOutPath $INSTDIR
 
# define what to install and place it in the output path
File ..\bin\CanonFilter.ax
File ..\bin\CanonCameraLib.dll
File ..\bin\OscPack.d.dll
File ..\bin\TurboJpeg.dll
File ..\bin\CppUtil.dll
File ..\bin\EDSDK.dll

# define uninstaller name
WriteUninstaller $INSTDIR\uninstaller.exe

Exec "$\"$SYSDIR\regsvr32.exe$\" CanonFilter.ax$\""

SectionEnd

# create a section to define what the uninstaller does.
# the section will always be named "Uninstall"
Section "Uninstall"
  
# Always delete uninstaller first
Delete $INSTDIR\uninstaller.exe
 
ExecWait "$\"$SYSDIR\regsvr32.exe$\" /u $\"$INSTDIR\CanonFilter.ax$\""

# now delete installed file
Delete $INSTDIR\CanonFilter.ax
Delete $INSTDIR\CanonCameraLib.dll
Delete $INSTDIR\OscPack.d.dll
Delete $INSTDIR\TurboJpeg.dll
Delete $INSTDIR\CppUtil.dll
Delete $INSTDIR\EDSDK.dll

SectionEnd