//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//


#include "OFIIMgntHstFeatureImage.h"

void OFIIMgntHstFeatureImage::Resize(int width, int height, int binCount)
{
	OFIMgntHstFeatureImage::Resize(width, height, binCount);
	ih_.Resize(width, height, binCount);
}

void OFIIMgntHstFeatureImage::Construct(OCVImage& image, OCVImage& mgnt)
{
	ih_.Construct(image, mgnt);
}


void OFIIMgntHstFeatureImage::Histogram(int cx, int cy, int width, int height, OLAVector& hst)
{
	double sum;
	ih_.Sum(cx, cy, width, height, hst.data_, sum);
	//sum = im_.Sum(cx, cy, width, height);
	hst /= (sum + 1e-10);
}

void OFIIMgntHstFeatureImage::Histogram(int cx, int cy, int width, int height, OLAVector& hst, double& sum)
{
	ih_.Sum(cx, cy, width, height, hst.data_, sum);
	//sum = im_.Sum(cx, cy, width, height);
	hst /= (sum + 1e-10);
}
