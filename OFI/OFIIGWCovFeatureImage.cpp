//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//


#include "OFIIGWCovFeatureImage.h"
#include "OLA/OLALinearAlgebra.h"
#include <highgui.h>

void OFIIGWCovFeatureImage::Resize(int width, int height, int featureCount)
{
	OFICovFeatureImage::Resize(width, height, featureCount);
	foII_.Resize(width, height, featureCount);
	soII_.Resize(width, height, featureCount);
	weightsII_.Resize(width, height);
	sqrtWeightsII_.Resize(width, height);

	featureCount_ = featureCount;
}


void OFIIGWCovFeatureImage::Construct(OCVImageND& featureImage, OCVImage& weights, OCVImage& sqrtWeights)
{
	foII_.Construct(featureImage);
	soII_.Construct(featureImage);
	weightsII_.Construct(weights);
	sqrtWeightsII_.Construct(sqrtWeights);
}


void OFIIGWCovFeatureImage::Covariance(int cx, int cy, int width, int height, OLAMatrix& cov)
{

	soII_.Sum(cx, cy, width, height, cov.data_);
	foII_.Sum(cx, cy, width, height, vec_.data_);

	OLALinearAlgebra::OuterProduct(vec_, vec_, mat_);
	mat_ /= ((width)*(height));

	cov -= mat_;
	cov /= (((width)*(height))-1);

	int i;
	double w, sqrtw;
	w = weightsII_.Sum(cx, cy, width, height) / (((width)*(height))-1) + .5;
	sqrtw = (sqrtWeightsII_.Sum(cx, cy, width, height) / (((width)*(height))-1)) + .5;

	for (i=0 ; i<featureCount_-1 ; i++)
	{
		cov(featureCount_-1, i) /= sqrtw;
		cov(i, featureCount_-1) /= sqrtw;
	}
	cov(featureCount_-1, featureCount_-1) /= (sqrtw*sqrtw);//w;//
	
}

int OFIIGWCovFeatureImage::IsInitialized()
{
	return mean_.n_ > 0;
}

