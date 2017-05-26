//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//


#ifndef _ofiimgnthstfeatureImage_h
#define _ofiimgnthstfeatureImage_h

#include "OFIMgntHstFeatureImage.h"
#include "OII/OIIIntegralImage.h"
#include "OII/OIIIntegralMgntHistogram.h"


class OFIIMgntHstFeatureImage : public OFIMgntHstFeatureImage{
public:
	OFIIMgntHstFeatureImage() {};
	OFIIMgntHstFeatureImage(int width, int height, int binCount) {Resize(width, height, binCount);};
	virtual ~OFIIMgntHstFeatureImage() {};

	virtual void Resize(int width, int height, int binCount);
	virtual void Construct(OCVImage& image, OCVImage& mgnt);
	virtual void Histogram(int cx, int cy, int width, int height, OLAVector& hst);
	virtual void Histogram(int cx, int cy, int width, int height, OLAVector& hst, double& sum);

protected:
	OIIIntegralMgntHistogram ih_;
};



#endif 
