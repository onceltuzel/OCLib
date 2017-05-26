//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "OIPImageProcessing.h"


void OIPImageProcessing::Histogram(OCVImage& image, OLAVector& hist)
{
	int index;
	int x, y;

	hist.Resize(256);
	OLALinearAlgebra::Zero(hist);

	for (x = 0 ; x < image.GetWidth() ; x++)
	{
		for (y = 0 ; y < image.GetHeight() ; y++)
		{
			index = image(x, y);
			hist(index) += 1;
		}
	}
}

void OIPImageProcessing::HistogramEqualization(OCVImage& image, OCVImage& nimage)
{
	int i;
	int x, y;
	int index;
	OLAVector hist(256), ihist(256);

	OIPImageProcessing::Histogram(image, hist);

	ihist(0) = hist(0);
	for (i=1 ; i< 256 ; i++)
	{
		ihist(i) = ihist(i-1) + hist(i);
	}
	ihist *= (255.0/(((image.GetWidth()+1) * (image.GetHeight()+1))));

	for (x = 0 ; x < image.GetWidth() ; x++)
	{
		for (y = 0 ; y < image.GetHeight() ; y++)
		{
			index = image(x, y);
			nimage(x, y) = (int) ihist(index);
		}
	}
}
