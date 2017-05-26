//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//

#include "OFICovFeatureImage.h"
#include "OLA/OLALinearAlgebra.h"
#include <highgui.h>

void OFICovFeatureImage::SafeRelease()
{
}


void OFICovFeatureImage::Resize(int width, int height, int featureCount)
{
	featureImage_.Resize(featureCount, width, height, 1, IPL_DEPTH_32F);
	mean_.Resize(featureCount);
	vec_.Resize(featureCount);
	mat_.Resize(featureCount, featureCount);	

}


void OFICovFeatureImage::Construct(OCVImageND& featureImage)
{
	featureImage_ = featureImage;

//	image = cvLoadImage(imageName, 1);	
//	OFIImageFilter::GradientsWThresholds(image, featureImage_);
}


void OFICovFeatureImage::Covariance(int cx, int cy, int width, int height, OLAMatrix& cov)
{
	int i;
	int x, y;
	int featureCount;

	featureCount = featureImage_.GetTime();

	OLALinearAlgebra::Zero(cov);

	mean_.SetZero();

	for (x=cx ; x<cx+width ; x++)
	{
		for (y=cy ; y<cy+height ; y++)
		{
			for (i=0 ; i<featureCount ;i++)
			{
				mean_(i) += featureImage_.F(i, x, y);
			}
		}
	} 
	mean_ /= ((width)*(height));


	for (x=cx ; x<cx+width ; x++)
	{
		for (y=cy ; y<cy+height ; y++)
		{
			for (i=0 ; i<featureCount ;i++)
			{
				vec_(i) = featureImage_.F(i, x, y);
			}

			vec_ -= mean_;
			OLALinearAlgebra::OuterProduct(vec_, vec_, mat_);
			cov += mat_;
		}
	}
	cov /= (((width)*(height))-1);

}

int OFICovFeatureImage::GetFeatureCount()
{
	return featureImage_.GetTime();
}

int OFICovFeatureImage::GetWidth()
{
	return featureImage_.GetWidth();
}

int OFICovFeatureImage::GetHeight()
{
	return featureImage_.GetHeight();
}

int OFICovFeatureImage::IsInitialized()
{
	return mean_.n_ > 0;
}

