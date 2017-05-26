//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//


#ifndef _ofiigwcovfeatureimage_h
#define _ofiigwcovfeatureimage_h

#include "OFICovFeatureImage.h"
#include "OII/OIIFOIntegralImage.h"
#include "OII/OIISOIntegralImage.h"
#include "OII/OIIIntegralImage.h"


class OFIIGWCovFeatureImage : public OFICovFeatureImage {
public:
	OFIIGWCovFeatureImage() {};
	OFIIGWCovFeatureImage(int width, int height, int featureCount) {Resize(width, height, featureCount);};
	virtual ~OFIIGWCovFeatureImage() {};

	virtual void Resize(int width, int height, int featureCount);

	virtual void Construct(OCVImageND& featureImage, OCVImage& weights, OCVImage& sqrtWeights);
	virtual void Covariance(int cx, int cy, int width, int height, OLAMatrix& cov);

	virtual int IsInitialized();

protected:
	OIIFOIntegralImage foII_;
	OIISOIntegralImage soII_;

	OIIIntegralImage weightsII_;
	OIIIntegralImage sqrtWeightsII_;

	int featureCount_;

};



#endif 