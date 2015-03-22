/*HidingScrollBar.cpp
 *
 *Copyright 2013 Andrew Wood aw@simple.org
 *All rights reserved
 *Distributed under the terms of the BSD license.
 */

#include "HidingScrollBar.h"
#include <stdio.h>


HidingScrollBar::HidingScrollBar(BRect frame,
					     const char* name, 
					     BView* target, 
					     float min,
					     float max,
					     orientation posture)
			 : BScrollBar(frame,name,target,min,max,posture)
{
	fPosture = posture;
	SetRange(min,max);
}

HidingScrollBar::HidingScrollBar(BMessage* archive) : BScrollBar(archive)
{

}

void HidingScrollBar::SetRange(float min,float max)
{
	BScrollBar::SetRange(min,max);
	if ( (min==0.0)&&(max==0.0) )
	{
		printf("scrollbar not needed so hide\n");

		if (IsHidden()==false)
		{	
			Hide();
		}

		
	}
	else
	{
		printf("scrollbar needed so show\n");

		if (IsHidden())
		{
			Show();
		}		
	}
	Invalidate();
}
