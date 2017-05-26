//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//


#include "OIIFOIntegralImage.h"
#include <highgui.h>

void OIIFOIntegralImage::Resize(int width, int height, int dim)
{
	iimage_.Resize(width+1, height+1, dim);
}

void OIIFOIntegralImage::Construct(OCVImageND& image)
{
	int x, y, d;

	int width;
	int height;
	int dim;


	width = image.GetWidth();
	height = image.GetHeight();
	dim = image.GetTime();

//	if (width!= iimage_.GetWidth() || height!= iimage_.GetHeight() || dim != iimage_.GetDim())
//		iimage_.Resize(width, height, dim);

	for (d=0 ; d<dim ; d++)
	{
		for (x = 0 ; x <= width ; x++)
		{
			iimage_(x, 0, d) = 0;
		}

		for (y = 0 ; y <= height ; y++)
		{
			iimage_(0, y, d) = 0;
		}		
	}

	for (y = 0 ; y < height ; y++)
	{
		for (x = 0 ; x < width ; x++)
		{
			for (d=0 ; d<dim ; d++)
			{
				iimage_(x+1, y+1, d) = iimage_(x, y+1, d) + iimage_(x+1, y, d) - iimage_(x, y, d) + image.F(d, x, y);
			}
		}
	}


/*
	for (d=0 ; d<dim ; d++)
	{
		iimage_(0, 0, d) = image.F(d, 0, 0);

		for (x = 1 ; x < width ; x++)
		{
			iimage_(x, 0, d) = image.F(d, x, 0) + iimage_(x-1, 0, d);
		}

		for (y = 1 ; y < height ; y++)
		{
			iimage_(0, y, d) = image.F(d, 0, y) + iimage_(0, y-1, d);
		}		
	}

	for (y = 1 ; y < height ; y++)
	{
		for (x = 1 ; x < width ; x++)
		{
			for (d=0 ; d<dim ; d++)
			{
				iimage_(x, y, d) = iimage_(x-1, y, d) + iimage_(x, y-1, d) - iimage_(x-1, y-1, d) + image.F(d, x, y);
			}
		}
	}
*/
}
