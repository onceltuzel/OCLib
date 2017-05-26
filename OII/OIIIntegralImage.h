//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//

#ifndef _oiiintegralimage_h
#define _oiiintegralimage_h

#include "OCV/OCVImage.h"

class OIIIntegralImage {
public:
	OIIIntegralImage() {};
	OIIIntegralImage(int width, int height, int dim = 1) {Resize(width, height, dim);};
	virtual ~OIIIntegralImage() {};

	virtual void Resize(int width, int height, int dim = 1);
	virtual void Construct(OCVImage& image);

	virtual inline float Sum(int x, int y, int width, int height, int d=0);

	inline operator	OCVImage*();

//protected:

	OCVImage iimage_;
};

inline OIIIntegralImage::operator OCVImage*()
{
	return &iimage_;
}

inline float OIIIntegralImage::Sum(int x, int y, int width, int height, int d)
{
	float value = 0;

	value += iimage_.F(x, y, d);
	value += iimage_.F(x+width, y+height, d);
	value -= iimage_.F(x+width, y, d);
	value -= iimage_.F(x, y+height, d);	

	return value;
}




#endif