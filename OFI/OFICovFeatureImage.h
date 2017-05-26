//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//

#ifndef _oficovfeatureimage_h
#define _oficovfeatureimage_h

#include "OCV/OCVImageND.h"
#include "OCV/OCVImage.h"
#include "OLA/OLAMatrix.h"
 
class OFICovFeatureImage {
public:
	OFICovFeatureImage() {};
	OFICovFeatureImage(int width, int height, int featureCount) {Resize(width, height, featureCount);};
	virtual ~OFICovFeatureImage() { SafeRelease(); };

	virtual void Resize(int width, int height, int featureCount);
	virtual void Construct(OCVImageND& featureImage);
	virtual void Covariance(int cx, int cy, int width, int height, OLAMatrix& cov);

	virtual int GetFeatureCount();
	virtual int GetWidth();
	virtual int GetHeight();

	virtual inline operator	OCVImageND*();

	virtual int IsInitialized();


protected:
	OCVImageND featureImage_;

	OLAVector mean_;
	OLAVector vec_; 
	OLAMatrix mat_;

	virtual void SafeRelease();
};


inline OFICovFeatureImage::operator OCVImageND*()
{
	return &featureImage_;
}



#endif 
