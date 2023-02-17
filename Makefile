# MPLAB IDE generated this makefile for use with GNU make.
# Project: AT24C04_EEPROM.mcp
# Date: Tue Sep 03 17:04:35 2019

AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = rm

AT24C04_EEPROM.cof : config.o process.o main.o busyxlcd.o openxlcd.o putrxlcd.o putsxlcd.o readaddr.o readdata.o setcgram.o setddram.o wcmdxlcd.o writdata.o
	$(LD) /l"C:\MCC18\lib" /l"C:\MCC18\lib" /k"C:\MCC18\lkr" "C:\MCC18\lkr\18f4520.lkr" "config.o" "process.o" "main.o" "busyxlcd.o" "openxlcd.o" "putrxlcd.o" "putsxlcd.o" "readaddr.o" "readdata.o" "setcgram.o" "setddram.o" "wcmdxlcd.o" "writdata.o" /u_CRUNTIME /z__MPLAB_BUILD=1 /o"AT24C04_EEPROM.cof" /M"AT24C04_EEPROM.map" /W

config.o : config.c C:/MCC18/h/delays.h C:/MCC18/h/xlcd.h prototyper.h config.c C:/MCC18/h/p18f4520.h C:/MCC18/h/p18cxxx.h
	$(CC) -p=18F4520 /i"C:\MCC18\bin" "config.c" -fo="config.o" -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

process.o : process.c C:/MCC18/h/delays.h C:/MCC18/h/xlcd.h prototyper.h process.c C:/MCC18/h/p18f4520.h C:/MCC18/h/p18cxxx.h
	$(CC) -p=18F4520 /i"C:\MCC18\bin" "process.c" -fo="process.o" -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

main.o : main.c C:/MCC18/h/delays.h C:/MCC18/h/xlcd.h prototyper.h main.c C:/MCC18/h/p18f4520.h C:/MCC18/h/p18cxxx.h
	$(CC) -p=18F4520 /i"C:\MCC18\bin" "main.c" -fo="main.o" -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

busyxlcd.o : C:/MCC18/src/extended/pmc/XLCD/busyxlcd.c C:/MCC18/h/xlcd.h C:/MCC18/src/extended/pmc/XLCD/busyxlcd.c C:/MCC18/h/p18cxxx.h C:/MCC18/h/p18f4520.h
	$(CC) -p=18F4520 /i"C:\MCC18\bin" "C:\MCC18\src\extended\pmc\XLCD\busyxlcd.c" -fo="busyxlcd.o" -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

openxlcd.o : C:/MCC18/src/extended/pmc/XLCD/openxlcd.c C:/MCC18/h/delays.h C:/MCC18/h/xlcd.h C:/MCC18/src/extended/pmc/XLCD/openxlcd.c C:/MCC18/h/p18cxxx.h C:/MCC18/h/p18f4520.h
	$(CC) -p=18F4520 /i"C:\MCC18\bin" "C:\MCC18\src\extended\pmc\XLCD\openxlcd.c" -fo="openxlcd.o" -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

putrxlcd.o : C:/MCC18/src/extended/pmc/XLCD/putrxlcd.c C:/MCC18/h/xlcd.h C:/MCC18/src/extended/pmc/XLCD/putrxlcd.c C:/MCC18/h/p18cxxx.h C:/MCC18/h/p18f4520.h
	$(CC) -p=18F4520 /i"C:\MCC18\bin" "C:\MCC18\src\extended\pmc\XLCD\putrxlcd.c" -fo="putrxlcd.o" -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

putsxlcd.o : C:/MCC18/src/extended/pmc/XLCD/putsxlcd.c C:/MCC18/h/xlcd.h C:/MCC18/src/extended/pmc/XLCD/putsxlcd.c C:/MCC18/h/p18cxxx.h C:/MCC18/h/p18f4520.h
	$(CC) -p=18F4520 /i"C:\MCC18\bin" "C:\MCC18\src\extended\pmc\XLCD\putsxlcd.c" -fo="putsxlcd.o" -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

readaddr.o : C:/MCC18/src/extended/pmc/XLCD/readaddr.c C:/MCC18/h/xlcd.h C:/MCC18/src/extended/pmc/XLCD/readaddr.c C:/MCC18/h/p18cxxx.h C:/MCC18/h/p18f4520.h
	$(CC) -p=18F4520 /i"C:\MCC18\bin" "C:\MCC18\src\extended\pmc\XLCD\readaddr.c" -fo="readaddr.o" -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

readdata.o : C:/MCC18/src/extended/pmc/XLCD/readdata.c C:/MCC18/h/xlcd.h C:/MCC18/src/extended/pmc/XLCD/readdata.c C:/MCC18/h/p18cxxx.h C:/MCC18/h/p18f4520.h
	$(CC) -p=18F4520 /i"C:\MCC18\bin" "C:\MCC18\src\extended\pmc\XLCD\readdata.c" -fo="readdata.o" -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

setcgram.o : C:/MCC18/src/extended/pmc/XLCD/setcgram.c C:/MCC18/h/xlcd.h C:/MCC18/src/extended/pmc/XLCD/setcgram.c C:/MCC18/h/p18cxxx.h C:/MCC18/h/p18f4520.h
	$(CC) -p=18F4520 /i"C:\MCC18\bin" "C:\MCC18\src\extended\pmc\XLCD\setcgram.c" -fo="setcgram.o" -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

setddram.o : C:/MCC18/src/extended/pmc/XLCD/setddram.c C:/MCC18/h/xlcd.h C:/MCC18/src/extended/pmc/XLCD/setddram.c C:/MCC18/h/p18cxxx.h C:/MCC18/h/p18f4520.h
	$(CC) -p=18F4520 /i"C:\MCC18\bin" "C:\MCC18\src\extended\pmc\XLCD\setddram.c" -fo="setddram.o" -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

wcmdxlcd.o : C:/MCC18/src/extended/pmc/XLCD/wcmdxlcd.c C:/MCC18/h/xlcd.h C:/MCC18/src/extended/pmc/XLCD/wcmdxlcd.c C:/MCC18/h/p18cxxx.h C:/MCC18/h/p18f4520.h
	$(CC) -p=18F4520 /i"C:\MCC18\bin" "C:\MCC18\src\extended\pmc\XLCD\wcmdxlcd.c" -fo="wcmdxlcd.o" -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

writdata.o : C:/MCC18/src/extended/pmc/XLCD/writdata.c C:/MCC18/h/xlcd.h C:/MCC18/src/extended/pmc/XLCD/writdata.c C:/MCC18/h/p18cxxx.h C:/MCC18/h/p18f4520.h
	$(CC) -p=18F4520 /i"C:\MCC18\bin" "C:\MCC18\src\extended\pmc\XLCD\writdata.c" -fo="writdata.o" -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

clean : 
	$(RM) "config.o" "process.o" "main.o" "busyxlcd.o" "openxlcd.o" "putrxlcd.o" "putsxlcd.o" "readaddr.o" "readdata.o" "setcgram.o" "setddram.o" "wcmdxlcd.o" "writdata.o" "AT24C04_EEPROM.cof" "AT24C04_EEPROM.hex"

