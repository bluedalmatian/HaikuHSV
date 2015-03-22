/*WebKioskApplication.h
 *
 *The main BApplication subclass for demo app for a HidingScrollView
 *
 *Used to demonstrate a HidingScrollView from both a user & programmer perspective
 *
 *Copyright 2013 Andrew Wood aw@simple.org
 *All rights reserved
 *Distributed under the terms of the BSD license.
 */

#ifndef CLASS_HSVDEMOAPPLICATION
 #define CLASS_HSVDEMOAPPLICATION
 
#include <string>


#include <app/Application.h>
#include "MainWindow.h"

class HSVDemoApplication : public BApplication
{
	
	public:
		HSVDemoApplication(std::string path);
		void MessageReceived(BMessage* message);
		virtual bool QuitRequested();
	
	
		
		
	protected:
		MainWindow* fMainWindow;
		std::string fDirectoryPath;

		
		//Settings from conf file
		bool fCustomScreenSize;
		int fMainWindowHeight;
		int fMainWindowWidth;
	
	
};
#endif
