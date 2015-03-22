#ifndef HSVDEMO_CONSTDEFS
 #define HSVDEMO_CONSTDEFS


//App wide constants a.k.a 'magic numbers'
//DO NOT PUT BMESSAGE COMMAND CONSTS IN HERE


//===MAINWINDOW STUFF=====
#define kMAINWINDOWTOPLEFTX 0
#define kMAINWINDOWTOPLEFTY 0

//====================


//===TOOLBAR STUFF=====
//You MUST ensure that the difference between kMAINWINDOWTOOLBARBUTTONSIZEH and kMAINWINDOWTOOLBARHEIGHT is an even number
//so we get equal spacing above and below each button
//a run time calculation is done and assumes it is going to produce an even no which can be divided by 2

#define kMAINWINDOWTOOLBARHEIGHT 56
#define kMAINWINDOWTOOLBARBUTTONSIZEW 100
#define kMAINWINDOWTOOLBARBUTTONSIZEH 48
#define kMAINWINDOWTOOLBARBUTTONSPACING 5 //space between buttons

//==================

#endif