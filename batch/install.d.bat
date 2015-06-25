REM The file batch file muste be executed with administrator privilege
REM When the batch file is executed from contextual menu, the default path is
REM set to System32 directory, so before launchin the regsvr command
REM we must set the true path where we can find the dll to record

D:
cd Workspace\CanonDirectShow\Bin
regsvr32 CanonFilter.d.ax
pause