//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//


#ifndef _ofiimagefilter_h
#define _ofiimagefilter_h

#include "OCV/OCVImageND.h"
#include "OCV/OCVImage.h"
#include "OLA/OLAMatrix.h"

class OFIImageFilter {
public:

	static void ColorGradientsXY(OCVImage& image, OCVImageND& featureImage);
	static void ColorGradients(OCVImage& image, OCVImageND& featureImage);
	static void Gradients(OCVImage& image, OCVImageND& featureImage);
	static void GradientsWThresholds(OCVImage& image, OCVImageND& featureImage);
	static void Schmidt(OCVImage& image, OCVImageND& featureImage);
	static void M8(OCVImage& image, OCVImageND& featureImage);

protected:
	static void NormalizeImage(OCVImage& image, OCVImage& oImage);


};



#endif 
