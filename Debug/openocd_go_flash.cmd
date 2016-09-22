rem echo off
rem ------------------------------------------------------------------
rem openocd flash command 
rem for flash AMR LPC2368 with banana Jtag
rem Last Modify 54-08-01 21:35
rem by Advanced Embedded Solution Co.,Ltd.
rem ------------------------------------------------------------------

set OOCD_INSTALLDIR="c:\Program Files\openocd\0.4.0"
set OOCD_BIN_FTDI= 	 "c:\Program Files\openocd\0.4.0\bin\openocd.exe"
set OOCD_INTERFACE=FTDI
set OOCD_EXE=%OOCD_BIN_FTDI%
set OOCD_CFG= lpc1768_ftdi.cfg 
%OOCD_EXE% %OOCD_DBG% -f %OOCD_CFG%

