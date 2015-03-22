/*HSVDemoApplication.cpp
 *
 *The main BApplication subclass for the HidingScrollview demo app
 *
 *Copyright 2013 Andrew Wood aw@simple.org
 *All rights reserved
 *Distributed under the terms of the BSD license.
 */

#include "HSVDemoApplication.h"
#include "AppWideBMessageDefs.h"
#include "AppWideConstDefs.h"
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <interface/Rect.h>
#include <interface/Screen.h>
#include <algorithm> //for std::transform



HSVDemoApplication::HSVDemoApplication(std::string path) : BApplication("application/x-vnd.org.simple-HSVDemo")
{

	fMainWindowWidth=300;
	fMainWindowHeight=200;
	fDirectoryPath=path;
	
	BRect arect;
	arect.Set(kMAINWINDOWTOPLEFTX,kMAINWINDOWTOPLEFTY,fMainWindowWidth-kMAINWINDOWTOPLEFTX,fMainWindowHeight-kMAINWINDOWTOPLEFTY);
	fMainWindow = new MainWindow(arect,fMainWindowWidth,fMainWindowHeight);
	fMainWindow->MoveTo(50,50);
			
}



bool HSVDemoApplication::QuitRequested()
{
	printf("be_app received QUIT_REQUESTED\n");
	return true;	
}

void HSVDemoApplication::MessageReceived(BMessage* message)
{
	
	BApplication::MessageReceived(message);
}
