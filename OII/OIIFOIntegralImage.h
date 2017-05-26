//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//

#ifndef _oiifointegralimage_h
#define _oiifointegralimage_h

#include "OCV/OCVImageND.h"
#include "OCV/OCVBufferND.h"

class OIIFOIntegralImage {
public:
	OIIFOIntegralImage() {};
	OIIFOIntegralImage(int width, int height, int dim) {Resize(width, height, dim);};
	~OIIFOIntegralImage() {};

	void Resize(int width, int height, int dim);
	void Construct(OCVImageND& image);

	inline void Sum(int x, int y, int width, int height, double* data);
	inline operator	OCVBufferND*();

private:

	OCVBufferND iimage_;
};

inline OIIFOIntegralImage::operator OCVBufferND*()
{
	return &iimage_;
}


inline void OIIFOIntegralImage::Sum(int x, int y, int width, int height, double* data)
{
	int i;
	double* dataxy;
	double* dataxwy;
	double* dataxyh;
	double* dataxwyh;

	dataxy = iimage_(x, y);
	dataxwy = iimage_(x+width, y);
	dataxyh = iimage_(x, y+height);
	dataxwyh = iimage_(x+width, y+height);

	for (i=0 ; i<iimage_.GetDim() ; i++)
	{
		data[i] = dataxy[i] + dataxwyh[i] - dataxwy[i] - dataxyh[i];
	}
}






#endif