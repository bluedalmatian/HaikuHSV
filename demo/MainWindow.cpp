#include "MainWindow.h"
#include "AppWideConstDefs.h"
#include "AppWideBMessageDefs.h"
#include "HSVDemoApplication.h"
#include <stdio.h>
#include <app/Application.h>
#include <string>
#include <sstream>
#include <interface/ScrollView.h>
#include <interface/ScrollBar.h>
#include <storage/Path.h>
#include <translation/TranslationUtils.h>
#include <interface/Bitmap.h>
#include <interface/Picture.h>
#include "TempView.h"



MainWindow::MainWindow(BRect frame,int width,int height) : BWindow (frame, "HSVDemo", B_TITLED_WINDOW,0)
{
	fMainWindowWidth=width+1;
	fMainWindowHeight=height+1;
	
	int mainViewYPenPos=0; //will keep track of where in the window we are vertically when setting out UI
	
	int toolbarVHeightPadding=kMAINWINDOWTOOLBARHEIGHT-kMAINWINDOWTOOLBARBUTTONSIZEH;
	int toolbarSpaceTopAndBottom=toolbarVHeightPadding/2;
	int leftmostButtonOffset=5; //start 1st button 5 pixels from left
	
	BRect viewRect;
	//fMainView fills whole window
	viewRect.Set(0,0,fMainWindowWidth,fMainWindowHeight);
	fMainView= new BView(viewRect,"fMainView",B_FOLLOW_ALL,B_WILL_DRAW);
	this->AddChild(fMainView);
	fMainView->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	

		
		//fToolbarView fills a kMAINWINDOWTOOLBARHEIGHT pixel tall top strip of fMainView
		viewRect.Set(0,mainViewYPenPos,fMainWindowWidth,kMAINWINDOWTOOLBARHEIGHT-1);
		fToolbarView= new BView(viewRect,"fToolbarView",B_FOLLOW_LEFT|B_FOLLOW_TOP,B_WILL_DRAW);
		fMainView->AddChild(fToolbarView);
	
		fToolbarView->SetViewColor(fMainView->ViewColor()); //inherit colour from parent view
	
		mainViewYPenPos=mainViewYPenPos+kMAINWINDOWTOOLBARHEIGHT; //move down to below toolbar
		
		
					//fill toolbar
						viewRect.Set(leftmostButtonOffset-1,(toolbarSpaceTopAndBottom-1),(leftmostButtonOffset-1)+kMAINWINDOWTOOLBARBUTTONSIZEW,(toolbarSpaceTopAndBottom-1)+kMAINWINDOWTOOLBARBUTTONSIZEH); //single width button
						fForwardButton=new BButton(viewRect,"fForwardButton","Swap Image",new BMessage(FORWARDBUTTON_PRESSED),B_FOLLOW_LEFT|B_FOLLOW_TOP);
						fToolbarView->AddChild(fForwardButton);
		

		//fDisplayPaneView fills remaining space in fMainView
	
		viewRect.Set(0,mainViewYPenPos,fMainWindowWidth,fMainWindowHeight);
		fDisplayPaneView= new BView(viewRect,"fDisplayPaneView",B_FOLLOW_ALL,B_WILL_DRAW);
		fDisplayPaneView->SetViewColor(fMainView->ViewColor()); //inherit colour from parent view
	
		//setup target to be scrolled
		viewRect.Set(0,0,fMainWindowWidth,fMainWindowHeight);
		fContentView=new TempView(viewRect,"fContentView");
		viewRect.Set(0,0,fMainWindowWidth,fMainWindowHeight-mainViewYPenPos);
		fDisplayPaneScrollView=new HidingScrollView(viewRect,"fDisplayPaneScrollView",fContentView);
		//fDisplayPaneScrollView=new BScrollView("fDisplayPaneScrollView",webview,B_FOLLOW_ALL,0,true,true,B_PLAIN_BORDER);
		fDisplayPaneView->AddChild(fDisplayPaneScrollView);
		fMainView->AddChild(fDisplayPaneView);
	
	
	
	Show();
	
}

bool MainWindow::QuitRequested()
{
	printf("MainWindow received B_QUIT_REQUESTED\n");
	
		be_app->PostMessage(B_QUIT_REQUESTED);
		return true;
}
			
			
	

void MainWindow::MessageReceived(BMessage* msg)
{
	if (msg->what==FORWARDBUTTON_PRESSED)
	{
		printf("FORWARD button pressed\n");
		fContentView->Navigate();
		
	}
	else
	{
		BWindow::MessageReceived(msg);	
		
	}
}


void MainWindow::DispatchMessage(BMessage* msg, BHandler* handler)
{
	
	BWindow::DispatchMessage(msg,handler);
}

void MainWindow::FrameResized(float width, float height)
{
	//Do nothing
}
