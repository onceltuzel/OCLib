//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//


#ifndef _ofimcovfeatureimage_h
#define _ofimcovfeatureimage_h

#include "OFICovFeatureImage.h"

class OFIMCovFeatureImage : public OFICovFeatureImage{
public:
	OFIMCovFeatureImage() {};
	OFIMCovFeatureImage(int width, int height, int featureCount) {Resize(width, height, featureCount);};
	virtual ~OFIMCovFeatureImage() {};

	virtual void Resize(int width, int height, int featureCount);
	virtual void Construct(OCVImageND& featureImage, OCVImage maskImage, int x, int y, int width, int height);

	virtual void Covariance(int cx, int cy, int width, int height, OLAMatrix& cov);
	virtual void Covariance(int cx, int cy, int width, int height, OLAMatrix& cov, int mask);

	virtual int  Mask(int x, int y);

protected:

	OCVImage maskImage_;
	

};


#endif