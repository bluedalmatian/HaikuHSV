/*MainWindow.h
 *
 *The main window BWindow subclass for HSVDemo
 *
 *Copyright 2013 Andrew Wood aw@simple.org
 *All rights reserved
 *
 */

#ifndef CLASS_MAINWINDOW
 #define CLASS_MAINWINDOW
 
 
#include <interface/Window.h>
#include <interface/View.h>
#include <interface/ScrollView.h>
#include <interface/Button.h>
#include <interface/ListView.h>
#include <interface/TextControl.h>
#include <kernel/OS.h>
#include "HidingScrollView.h"
#include "TempView.h"


class MainWindow : public BWindow
{
	public:
		MainWindow(BRect frame,int width, int height);
		virtual bool QuitRequested();
		void MessageReceived(BMessage* msg);
		virtual void DispatchMessage(BMessage* msg, BHandler* handler);
		virtual void FrameResized(float width, float height);

	protected:

		int fMainWindowWidth;
		int fMainWindowHeight;
		BView* fMainView;
		BView* fToolbarView;
		BView* fDisplayPaneView;
		HidingScrollView* fDisplayPaneScrollView;

		TempView* fContentView;
		BButton* fForwardButton;
		
	
};




#endif
