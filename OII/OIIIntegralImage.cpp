//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//


#include "OIIIntegralImage.h"
#include <highgui.h>

void OIIIntegralImage::Resize(int width, int height, int dim)
{
	iimage_.Resize(width+1, height+1, dim, IPL_DEPTH_32F);
}


void OIIIntegralImage::Construct(OCVImage& image)
{
	int x, y, d;

	int width;
	int height;
	int dim;

	width = image.GetWidth();
	height = image.GetHeight();
	dim = image.GetDim();

//	if (iimage_ == NULL || width!= iimage_.GetWidth() || height!= iimage_.GetHeight() || dim != iimage_.GetDim())
//		iimage_.Resize(width, height, dim, IPL_DEPTH_32F);

	for (d=0 ; d<dim ; d++)
	{
		for (x = 0 ; x <= width ; x++)
		{
			iimage_.F(x, 0, d) = 0;
		}

		for (y = 0 ; y <= height ; y++)
		{
			iimage_.F(0, y, d) = 0;
		}		
	}
	for (d=0 ; d<dim ; d++)
	{
		for (y = 0 ; y < height ; y++)
		{
			for (x = 0 ; x < width ; x++)
			{
				iimage_.F(x+1, y+1, d) = iimage_.F(x, y+1, d) + iimage_.F(x+1, y, d) - iimage_.F(x, y, d) + image.F(x, y, d);
			}
		}
	}


/*
	for (d=0 ; d<dim ; d++)
	{
		iimage_.F(0, 0, d) = image.F(0, 0, d);

		for (x = 1 ; x < width ; x++)
		{
			iimage_.F(x, 0, d) = image.F(x, 0, d) + iimage_.F(x-1, 0, d);
		}

		for (y = 1 ; y < height ; y++)
		{
			iimage_.F(0, y, d) = image.F(0, y, d) + iimage_.F(0, y-1, d);
		}		
	}

	for (d=0 ; d<dim ; d++)
	{
		for (y = 1 ; y < height ; y++)
		{
			for (x = 1 ; x < width ; x++)
			{
				iimage_.F(x, y, d) = iimage_.F(x-1, y, d) + iimage_.F(x, y-1, d) - iimage_.F(x-1, y-1, d) + image.F(x, y, d);
			}
		}
	}
*/
/*
	OCVImage display;
	display.Resize(width, height);
	cvNamedWindow( "src", 1 );
	cvConvertScaleAbs(iimage_, display, 1.0/1000000.0);
	cvShowImage( "src", display );
	cvWaitKey();
*/
}
