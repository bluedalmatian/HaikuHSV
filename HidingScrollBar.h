/*HidingScrollBar.h
 *
 *A HidingScrollBar is a BScrollBar which automatically
 *completely hides if the target view is small enough that its not needed.
 *It is designed to be used in conjuntion with a HidingScrollView
 *
 *Copyright 2013 Andrew Wood aw@simple.org
 *All rights reserved
 *Distributed under the terms of the BSD license.
 */

#ifndef CLASS_HIDINGSCROLLBAR
 #define CLASS_HIDINGSCROLLBAR
 
 

#include <interface/ScrollBar.h>




class HidingScrollBar: public BScrollBar
{
	public:
		HidingScrollBar(BRect frame,
					     const char* name, 
					     BView* target, 
					     float min,
					     float max,
					     orientation posture
					);
		HidingScrollBar(BMessage* archive);
		void SetRange(float min, float max);


	protected:
		orientation fPosture;
			
};




#endif
