//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//


#ifndef _ofimgnthstfeatureimage_h
#define _ofimgnthstfeatureimage_h

#include "OFIHstFeatureImage.h"

class OFIMgntHstFeatureImage : public OFIHstFeatureImage{
public:
	OFIMgntHstFeatureImage() {};
	OFIMgntHstFeatureImage(int width, int height, int binCount) {Resize(width, height, binCount);};
	virtual ~OFIMgntHstFeatureImage() {};

	virtual void Resize(int width, int height, int binCount);
	virtual void Construct(OCVImage& image, OCVImage& mgnt);
	virtual void Histogram(int cx, int cy, int width, int height, OLAVector& hst);

	virtual int GetFeatureCount();
	virtual int GetWidth();
	virtual int GetHeight();

protected:
	OCVImage mgntImage_;
};



#endif 
