//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//


#include "OFIICovFeatureImage.h"
#include "OLA/OLALinearAlgebra.h"
#include <highgui.h>

void OFIICovFeatureImage::Resize(int width, int height, int featureCount)
{
	OFICovFeatureImage::Resize(width, height, featureCount);
	foII_.Resize(width, height, featureCount);
	soII_.Resize(width, height, featureCount);
}


void OFIICovFeatureImage::Construct(OCVImageND& featureImage)
{
	//OFICovFeatureImage::Construct(featureImage);
	foII_.Construct(featureImage);
	soII_.Construct(featureImage);
}


void OFIICovFeatureImage::Covariance(int cx, int cy, int width, int height, OLAMatrix& cov)
{
	soII_.Sum(cx, cy, width, height, cov.data_);
	foII_.Sum(cx, cy, width, height, vec_.data_);

	OLALinearAlgebra::OuterProduct(vec_, vec_, mat_);
	mat_ /= ((width)*(height));

	cov -= mat_;
	cov /= (((width)*(height))-1);


	//OLALinearAlgebra::PD(cov, cov);
}


