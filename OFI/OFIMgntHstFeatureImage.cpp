//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//


#include "OFIMgntHstFeatureImage.h"

void OFIMgntHstFeatureImage::Resize(int width, int height, int binCount)
{
	featureImage_.Resize(width, height, 1, IPL_DEPTH_32F);
	mgntImage_.Resize(width, height, 1, IPL_DEPTH_32F);
	binCount_ = binCount;
}

void OFIMgntHstFeatureImage::Construct(OCVImage& image, OCVImage& mgnt)
{
	cvCopy(image, featureImage_);	
	cvCopy(mgnt, mgntImage_);	
}


void OFIMgntHstFeatureImage::Histogram(int cx, int cy, int width, int height, OLAVector& hst)
{
	int x, y;
	double sum;

	hst.SetZero();

	sum = 0;
	for (x=cx ; x<cx+width ; x++)
	{
		for (y=cy ; y<cy+height ; y++)
		{			
			hst((int) (featureImage_.F(x, y))) += mgntImage_.F(x, y);
			sum +=mgntImage_.F(x, y);
		}
	}

	hst /= (sum + 1e-10);

}

int OFIMgntHstFeatureImage::GetFeatureCount()
{
	return binCount_;
}

int OFIMgntHstFeatureImage::GetWidth()
{
	return featureImage_.GetWidth();
}

int OFIMgntHstFeatureImage::GetHeight()
{
	return featureImage_.GetHeight();
}


