//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//

#ifndef _oiisointegralimage_h
#define _oiisointegralimage_h

#include "OCV/OCVImageND.h"
#include "OCV/OCVBufferND.h"

class OIISOIntegralImage {
public:
	OIISOIntegralImage() {};
	OIISOIntegralImage(int width, int height, int dim) {Resize(width, height, dim);};
	~OIISOIntegralImage() {};

	void Resize(int width, int height, int dim);
	void Construct(OCVImageND& image);

	inline void Sum(int x, int y, int width, int height, double* data);
	inline operator	OCVBufferND*();

private:

	OCVBufferND iimage_;
};

inline OIISOIntegralImage::operator OCVBufferND*()
{
	return &iimage_;
}


inline void OIISOIntegralImage::Sum(int x, int y, int width, int height, double* data)
{
	/*
	if (x<=0 || y<=0 || x+width >= iimage_.GetWidth() || y+height >= iimage_.GetHeight())
		printf("Error!!!!!\n");
	*/


	int i;
	double* dataxy;
	double* dataxwy;
	double* dataxyh;
	double* dataxwyh;

	dataxy = iimage_(x, y);
	dataxwy = iimage_(x+width, y);
	dataxyh = iimage_(x, y+height);
	dataxwyh = iimage_(x+width, y+height);

	for (i=0 ; i<iimage_.GetDim(); i++)
	{
		data[i] = dataxy[i] + dataxwyh[i] - dataxwy[i] - dataxyh[i];
	}
}






#endif