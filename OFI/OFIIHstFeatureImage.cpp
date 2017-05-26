//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//


#include "OFIIHstFeatureImage.h"

void OFIIHstFeatureImage::Resize(int width, int height, int binCount)
{
	OFIHstFeatureImage::Resize(width, height, binCount);
	ih_.Resize(width, height, binCount);
}

void OFIIHstFeatureImage::Construct(OCVImage& image)
{
	//OFIHstFeatureImage::Construct(image);
	ih_.Construct(image);
}

void OFIIHstFeatureImage::Construct(OCVImageND& image, OLAVector* quanLevels)
{
	OFIHstFeatureImage::Construct(image, quanLevels);
	ih_.Construct(featureImage_);
}


void OFIIHstFeatureImage::Histogram(int cx, int cy, int width, int height, OLAVector& hst)
{
	ih_.Sum(cx, cy, width, height, hst.data_);
	hst /= ((width)*(height));
}

