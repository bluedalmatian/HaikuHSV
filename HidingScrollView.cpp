/*HidingScrollView.cpp
 *
 *
 *Copyright 2013 Andrew Wood aw@simple.org
 *All rights reserved
 *Distributed under the terms of the BSD license.
 */


#include "HidingScrollView.h"
#include <stdio.h>

HidingScrollView::HidingScrollView(BRect frame,char* name,BView* target): BView(frame,name,B_FOLLOW_ALL,B_FRAME_EVENTS|B_WILL_DRAW)
{
	SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	
	fTarget=target;
	BRect viewRect;
	float height=Bounds().Height();
	float width=Bounds().Width();
	float targetHeight;
	float targetWidth;
	fTarget->GetPreferredSize(&targetWidth,&targetHeight);
	
	viewRect.Set(0,height-B_H_SCROLL_BAR_HEIGHT,width-B_V_SCROLL_BAR_WIDTH,height);
	fHorizontalScrollBar=new HidingScrollBar(viewRect,"fHorizontalScrollBar",target,0,0,B_HORIZONTAL);
	
	viewRect.Set(width-B_V_SCROLL_BAR_WIDTH,0,width,height-B_H_SCROLL_BAR_HEIGHT);
	fVerticalScrollBar=new HidingScrollBar(viewRect,"fVerticalScrollBar",target,0,0,B_VERTICAL);
	
	AddChild(fTarget);
	AddChild(fVerticalScrollBar);
	AddChild(fHorizontalScrollBar);
	FrameResized(width,height);
	
}
void HidingScrollView::FrameResized(float width, float height)
{
	//called automatically when we (parent) are resized
	//we are now width x height

	float targetHeight;
	float targetWidth;
	fTarget->GetPreferredSize(&targetWidth,&targetHeight);
	
	DoResizing(width,height,targetWidth,targetHeight,true);

}
void HidingScrollView::DoResizing(float width, float height, float targetWidth,float targetHeight,bool notifyChild)
{
	
	printf("DoResizing::width:%f height:%f targetWidth:%f targetHeight%f\n",width,height,targetWidth,targetHeight);
	
	if (targetWidth<width)
	{
		printf("HidingScrollView::DoResizing(): target not as wide as me\n");
		fHorizontalScrollBar->SetRange(0.0,0.0);
		fTarget->ResizeTo(width,height);
	}
	if (targetHeight<height)
	{
		printf("HidingScrollView::DoResizing(): target not as tall as me\n");
		fVerticalScrollBar->SetRange(0.0,0.0);
		fTarget->ResizeTo(width,height);
	}
	if (targetWidth==width)
	{
		printf("HidingScrollView::DoResizing(): target same width as me\n");
		//inform target to change to our size
		fHorizontalScrollBar->SetRange(0.0,0.0);
		fTarget->ResizeTo(width,height);
	}
	if (targetHeight==height)
	{
		printf("HidingScrollView::DoResizing(): target same height as me\n");
		fVerticalScrollBar->SetRange(0.0,0.0);
		fTarget->ResizeTo(width,height);
	}
	if (targetHeight>height)
	{
		printf("HidingScrollView::DoResizing(): target taller than me vertical bar needed\n");
		//scrollbars needed
		
		if (targetWidth>width)
		{
			//horiz bar visible
			printf("   horizontal bar also visible\n");
			fTarget->ResizeTo(width-B_V_SCROLL_BAR_WIDTH,height-B_H_SCROLL_BAR_HEIGHT);
			fVerticalScrollBar->ResizeTo(B_V_SCROLL_BAR_WIDTH,height-B_H_SCROLL_BAR_HEIGHT);
			float range=targetHeight-height-B_H_SCROLL_BAR_HEIGHT;
			printf("   vert bar range: %f\n",range);
			fVerticalScrollBar->SetRange(0.0,range);
			
		}
		else
		{
			fTarget->ResizeTo(width-B_V_SCROLL_BAR_WIDTH,height);
			fVerticalScrollBar->ResizeTo(B_V_SCROLL_BAR_WIDTH,height);
			float range=targetHeight-height;
			printf("   vert bar range: %f\n",range);
			fVerticalScrollBar->SetRange(0.0,range);
			
		}
		fVerticalScrollBar->MoveTo(width-B_V_SCROLL_BAR_WIDTH,0);
		
	}
	if (targetWidth>width)
	{
		printf("HidingScrollView::DoResizing(): target wider than me horizontal bar needed\n");
		//scrollbars needed
		
		if (targetHeight>height)
		{
			//vert bar visible
			printf("  vert bar also visible\n");
			float range=targetWidth-width-B_V_SCROLL_BAR_WIDTH;
			fHorizontalScrollBar->SetRange(0.0,range);
			fTarget->ResizeTo(width-B_V_SCROLL_BAR_WIDTH,height-B_H_SCROLL_BAR_HEIGHT);
			fHorizontalScrollBar->ResizeTo(width-B_V_SCROLL_BAR_WIDTH,B_H_SCROLL_BAR_HEIGHT);	
		}
		else
		{
			float range=targetWidth-width;
			fHorizontalScrollBar->SetRange(0.0,range);
			fTarget->ResizeTo(width,height-B_H_SCROLL_BAR_HEIGHT);
			fHorizontalScrollBar->ResizeTo(width,B_H_SCROLL_BAR_HEIGHT);	
		}
		fHorizontalScrollBar->MoveTo(0,height-B_H_SCROLL_BAR_HEIGHT);
		
	}
	
}

void HidingScrollView::ChildResized()
{
	float targetHeight;
	float targetWidth;
	fTarget->GetPreferredSize(&targetWidth,&targetHeight);

	float height=Frame().Height();
	float width=Frame().Width();
	printf("ChildResized:: targetHeight: %f\n",targetHeight);
	DoResizing(width,height,targetWidth,targetHeight,false);
	
}

