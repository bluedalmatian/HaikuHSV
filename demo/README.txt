HidingScrollView (HSV) overview
===============================

HSV is passed a target view for which it will provide scrolling functionality.

The target view must notify the HidingScrollView whenever it updates
its content (e.g in its Draw() method so that the HSV can adjust the
scrollbars if needbe.

The target view must also implement its ResizeToPreferred() method and its
GetPreferredSize() method. GetPreferredSize() should return the size needed
to draw the content without scrollbars so that HSV can determine if scrollbars
are needed.

The target view notifies its parent when it redraws itself by using the parent
variable and calling

		HidingScrollView* hsv=(HidingScrollView*)parent;
		hsv->ChildResized();
		
note that it must ONLY call ChildResized() IF the new size is different from 
its previous size

See the TempView class implementation of Draw().

