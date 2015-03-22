#include "TempView.h"
#include <stdio.h>
#include "HidingScrollView.h"

TempView::TempView(BRect frame,char* name): BView(frame,name,B_FOLLOW_NONE,B_WILL_DRAW)
{
	fDataWidth=0;
	fDataHeight=0;
	fBmp1=BTranslationUtils::GetBitmap("1.JPG");
	fBmp2=BTranslationUtils::GetBitmap("2.JPG");
	fCurrentBmp=fBmp1;
}

void TempView::Draw(BRect updateRect)
{
	float oldHeight=fDataHeight;
	float oldWidth=fDataWidth;
	
	printf("TempView Draw()\n");
	
	rgb_color black ={0,0,0,255};
	SetViewColor(black);
	
	MovePenTo(0,0);
	DrawBitmap(fCurrentBmp);
	BRect bmprect=fCurrentBmp->Bounds();  
	float bmpw=bmprect.Width();
	float bmph=bmprect.Height();
	BView* parent=Parent();
	fDataWidth=bmpw;
	fDataHeight=bmph;
	
	if ( (fDataHeight!=oldHeight) || (fDataWidth !=oldWidth) )
	{
		HidingScrollView* hsv=(HidingScrollView*)parent;
		hsv->ChildResized();
	}
	printf("TempView::Draw() returning\n");

}

void TempView::FrameResized(float width, float height)
{
		
}

void TempView::GetPreferredSize(float* width, float* height)
{
	*width=fDataWidth;
	*height=fDataHeight;
	printf("GetPreferredSize::height:%f\n",height);
}
void TempView::ResizeToPreferred()
{
	float w;
	float h;
	GetPreferredSize(&w,&h);
	ResizeTo(w,h);
}
void TempView::Navigate()
{
	
	if (fCurrentBmp==fBmp1)
	{
			fCurrentBmp=fBmp2;
	}
	else
	{
			fCurrentBmp=fBmp1;	
	}
	Invalidate();	
		
}
