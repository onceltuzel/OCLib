//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//

#include "OIIIntegralMgntHistogram.h"
#include <highgui.h>


void OIIIntegralMgntHistogram::Resize(int width, int height, int dim)
{
	OIIIntegralHistogram::Resize(width, height, dim);
	mgnt_.Resize(width, height);
}

void OIIIntegralMgntHistogram::Construct(OCVImage& image, OCVImage& mgnt)
{
	int x, y;
	int d;

	int width;
	int height;
	int dim;

	width = image.GetWidth();
	height = image.GetHeight();
	dim = ihistogram_.GetDim();

	for (x = 0 ; x <= width ; x++)
	{
		for (d=0 ; d<dim ; d++)
		{
			ihistogram_(x, 0, d) = 0.0f;
		}		
	}

	for (y = 0 ; y <= height ; y++)
	{
		for (d=0 ; d<dim ; d++)
		{
			ihistogram_(0, y, d) = 0.0f;
		}		
	}

	for (y = 0 ; y < height ; y++)
	{
		for (x = 0 ; x < width ; x++)
		{			
			for (d=0 ; d<dim ; d++)
			{
				ihistogram_(x+1, y+1, d) = ihistogram_(x, y+1, d) + ihistogram_(x+1, y, d) - ihistogram_(x, y, d);
			}
			ihistogram_(x+1, y+1, (int)(image.F(x, y))) += mgnt.F(x,y);
		}
	}


/*
	for (d=0 ; d<dim ; d++)
	{
		ihistogram_(0, 0, d) = 0;
	}		
	ihistogram_(0, 0, (int)(image.F(0, 0))) += mgnt.F(0,0);

	for (x = 1 ; x < width ; x++)
	{
		ihistogram_(x, 0, (int)(image.F(x, 0))) += mgnt.F(x,0);

		for (d=0 ; d<dim ; d++)
		{
			ihistogram_(x, 0, d) += ihistogram_(x-1, 0, d);
		}		
	}

	for (y = 1 ; y < height ; y++)
	{
		ihistogram_(0, y, (int)(image.F(0, y))) += mgnt.F(0,y);

		for (d=0 ; d<dim ; d++)
		{
			ihistogram_(0, y, d) += ihistogram_(0, y-1, d);
		}		
	}

	for (y = 1 ; y < height ; y++)
	{
		for (x = 1 ; x < width ; x++)
		{			
			for (d=0 ; d<dim ; d++)
			{
				ihistogram_(x, y, d) = ihistogram_(x-1, y, d) + ihistogram_(x, y-1, d) - ihistogram_(x-1, y-1, d);
			}
			ihistogram_(x, y, (int)(image.F(x, y))) += mgnt.F(x,y);
		}
	}
*/


	mgnt_.Construct(mgnt);
}
