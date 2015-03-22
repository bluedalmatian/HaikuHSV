#TempView is an example target view to be placed in a HidingScrollView
#its purpose is to demonstrate the way the target interacts with its container
#
#This example simply switches between displaying two JPEG images
#on receipt of a FORWARDBUTTON_PRESSED message
#
#These JPEG images MUST exist in the same folder as the demo app
#and be called 1.JPG & 2.JPG
#

#ifndef CLASS_TEMPVIEW
 #define CLASS_TEMPVIEW
 
 

#include <interface/View.h>
#include <interface/Bitmap.h>
#include <translation/TranslationUtils.h>


class TempView: public BView
{
	public:
		TempView(BRect frame,char* name);
		virtual void Draw(BRect updateRect);
		virtual void FrameResized(float width, float height);
		virtual void GetPreferredSize(float* width, float* height);
		virtual void ResizeToPreferred();
		virtual void Navigate();
		
		

	protected:

		BBitmap* fBmp1;
		BBitmap* fBmp2;
		BBitmap* fCurrentBmp;
		float fDataWidth;
		float fDataHeight;
};




#endif
