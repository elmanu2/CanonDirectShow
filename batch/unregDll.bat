#The file batch file muste be executed with administrator privilege
#When the batch file is executed from contextual menu, the default path is
#set to System32 directory, so before launchin the regsvr command
#we must set the true path where we can find the dll to record

regsvr32 /u CanonCam.d.ax
pause