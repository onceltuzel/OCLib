//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//

#ifndef _ofihstfeatureimage_h
#define _ofihstfeatureimage_h

#include "OCV/OCVImageND.h"
#include "OCV/OCVImage.h"
#include "OLA/OLAMatrix.h"

class OFIHstFeatureImage {
public:
	OFIHstFeatureImage() {};
	OFIHstFeatureImage(int width, int height, int binCount) {Resize(width, height, binCount);};
	virtual ~OFIHstFeatureImage() {};

	virtual void Resize(int width, int height, int binCount);
	virtual void Construct(OCVImage& image);
	virtual void Construct(OCVImageND& image, OLAVector* quanLevels);

	virtual void Histogram(int cx, int cy, int width, int height, OLAVector& hst);
	virtual int GetBinCount();

	virtual inline operator	OCVImage*();

protected:
	OCVImage featureImage_;
	int binCount_;
};


inline OFIHstFeatureImage::operator OCVImage*()
{
	return &featureImage_;
}


#endif 
