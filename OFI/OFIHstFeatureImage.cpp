//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//

#include "OFIHstFeatureImage.h"
#include "OLA/OLAFunctions.h"
#include <highgui.h>


void OFIHstFeatureImage::Resize(int width, int height, int binCount)
{
	featureImage_.Resize(width, height, 1, IPL_DEPTH_32F);
	binCount_ = binCount;
}

void OFIHstFeatureImage::Construct(OCVImage& image)
{
	cvCopy(image, featureImage_);	
}

void OFIHstFeatureImage::Construct(OCVImageND& image, OLAVector* quanLevels)
{
	int i;
	int x, y;
	int d;
	int index;
	int dim;
	OLAVector feature;

	dim = image.GetTime();
	feature.Resize(dim);

	double min;
	double dist;
	for (x=0 ; x<image.GetWidth() ; x++)
	{
		for (y=0 ; y<image.GetHeight() ; y++)
		{
			for (d=0 ; d<dim ; d++)
			{
				feature(d) = image.F(d, x, y);
			}

			index = 0;
			min = OLAFunctions::Dist2(quanLevels[0], feature);
			for (i=1 ; i<binCount_ ; i++)
			{
				dist = OLAFunctions::Dist2(quanLevels[i], feature);
				if (dist<min)
				{
					min = dist;
					index = i;
				}				
			}
			featureImage_.F(x,y) = (float) index;
		}
	}
}

void OFIHstFeatureImage::Histogram(int cx, int cy, int width, int height, OLAVector& hst)
{
	int x, y;

	hst.SetZero();

	for (x=cx ; x<cx+width ; x++)
	{
		for (y=cy ; y<cy+height ; y++)
		{
			hst((int) (featureImage_.F(x, y))) += 1;
		}
	}

	hst /= ((width)*(height));
}

int OFIHstFeatureImage::GetBinCount()
{
	return binCount_;
}
