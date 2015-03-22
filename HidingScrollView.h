/*HidingScrollView.h
 *
 *A HidingScrollView is a container for another BView (the target to be scrolled).
 *Unlike a standard BScrollView which just greys out the scrollbars,a HidingScrollView 
 *automatically hides its scrollbars if the content is small enough that they are not needed.
 *
 *To be compatible with a HidingScrollView the target BView must implement its
 *GetPreferredSize() method to indicate the amount of space the view takes up when drawing
 *and implement its ResizeToPreferred() method to set it to that size.
 *
 *It must also currently call ChildResized() on the HidingScrollView whenever its preferred size
 *changes. An alternative to this which removes this necessity is under investigation.
 *
 *Copyright 2013 Andrew Wood aw@simple.org
 *All rights reserved
 *Distributed under the terms of the BSD license.
 */

#ifndef CLASS_HIDINGSCROLLVIEW
 #define CLASS_HIDINGSCROLLVIEW
 
 

#include <interface/View.h>
#include "HidingScrollBar.h"


class HidingScrollView: public BView
{
	public:
		HidingScrollView(BRect frame,char* name,BView* target);
		virtual void FrameResized(float width, float height);
		void ChildResized();
		void DoResizing(float width,float height, float targetWidth, float targetHeight,bool notifyChild);
		float ViewableWidth();
		float ViewableHeight();
		
		

	protected:

		HidingScrollBar* fVerticalScrollBar;
		HidingScrollBar* fHorizontalScrollBar;
		BView* fTarget;
	
};




#endif
