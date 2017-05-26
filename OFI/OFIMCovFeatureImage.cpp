//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//


#include "OFIMCovFeatureImage.h"
#include "OLA/OLALinearAlgebra.h"

void OFIMCovFeatureImage::Resize(int width, int height, int featureCount)
{
	OFICovFeatureImage::Resize(width, height, featureCount);

	maskImage_.Resize(width, height, 1, IPL_DEPTH_8U);
}


void OFIMCovFeatureImage::Construct(OCVImageND& featureImage, OCVImage maskImage, int x, int y, int width, int height)
{
	OFICovFeatureImage::Construct(featureImage);
	cvCopy(maskImage, maskImage_);
}



void OFIMCovFeatureImage::Covariance(int cx, int cy, int width, int height, OLAMatrix& cov, int mask)
{
	int i;
	int x, y;
	int pixelCount;
	int featureCount;


	featureCount = featureImage_.GetTime();
	
	OLALinearAlgebra::Zero(cov);
	OLALinearAlgebra::Zero(mean_);
	pixelCount = 0;
	for (x=cx ; x<cx+width ; x++)
	{
		for (y=cy ; y<cy+height ; y++)
		{
			if (maskImage_(x,y) == mask)
			{
				for (i=0 ; i<featureCount ;i++)
				{
					mean_(i) += featureImage_.F(i, x, y);
				}
				pixelCount++;
			}
		}
	} 

	if (pixelCount <=1)
	{
		OLALinearAlgebra::Identity(cov);
	}
	else
	{
		mean_ /= pixelCount;

		for (x=cx ; x<cx+width ; x++)
		{
			for (y=cy ; y<cy+height ; y++)
			{
				if (maskImage_(x,y) == mask)
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
		}
		cov /= (pixelCount-1);
	}

}



void OFIMCovFeatureImage::Covariance(int cx, int cy, int width, int height, OLAMatrix& cov)
{
	int i;
	int x, y;
	int pixelCount;
	int featureCount;


	featureCount = featureImage_.GetTime();

	OLALinearAlgebra::Zero(cov);
	OLALinearAlgebra::Zero(mean_);
	pixelCount = 0;
	for (x=cx ; x<cx+width ; x++)
	{
		for (y=cy ; y<cy+height ; y++)
		{
			if (maskImage_(x,y))
			{
				for (i=0 ; i<featureCount ; i++)
				{
					mean_(i) += featureImage_.F(i, x, y);
				}
				pixelCount++;
			}
		}
	} 
	mean_ /= pixelCount;


	for (x=cx ; x<cx+width ; x++)
	{
		for (y=cy ; y<cy+height ; y++)
		{
			if (maskImage_(x,y))
			{
				for (i=0 ; i<featureCount;i++)
				{
					vec_(i) = featureImage_.F(i, x, y);
				}

				vec_ -= mean_;
				OLALinearAlgebra::OuterProduct(vec_, vec_, mat_);
				cov += mat_;
			}
		}
	}
	cov /= (pixelCount-1);
}


int OFIMCovFeatureImage::Mask(int x, int y)
{
	return maskImage_(x, y);
}
