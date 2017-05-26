//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//


#ifndef _ofiicovfeatureimage_h
#define _ofiicovfeatureimage_h

#include "OFICovFeatureImage.h"
#include "OII/OIIFOIntegralImage.h"
#include "OII/OIISOIntegralImage.h"

class OFIICovFeatureImage : public OFICovFeatureImage {
public:
	OFIICovFeatureImage() {};
	OFIICovFeatureImage(int width, int height, int featureCount) {Resize(width, height, featureCount);};
	virtual ~OFIICovFeatureImage() {};

	virtual void Resize(int width, int height, int featureCount);

	virtual void Construct(OCVImageND& featureImage);
	virtual void Covariance(int cx, int cy, int width, int height, OLAMatrix& cov);

protected:
	
	OIIFOIntegralImage foII_;
	OIISOIntegralImage soII_;
};



#endif 