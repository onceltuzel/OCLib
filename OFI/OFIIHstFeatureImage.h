//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//


#ifndef _ofiihstfeatureimage_h
#define _ofiihstfeatureimage_h

#include "OFIHstFeatureImage.h"
#include "OII/OIIIntegralHistogram.h"


class OFIIHstFeatureImage : public OFIHstFeatureImage{
public:
	OFIIHstFeatureImage() {};
	OFIIHstFeatureImage(int width, int height, int binCount) {Resize(width, height, binCount);};
	virtual ~OFIIHstFeatureImage() {};

	virtual void Resize(int width, int height, int binCount);
	virtual void Construct(OCVImage& image);
	virtual void Construct(OCVImageND& image, OLAVector* quanLevels);
	virtual void Histogram(int cx, int cy, int width, int height, OLAVector& hst);

protected:
	
	OIIIntegralHistogram ih_;
};



#endif 
