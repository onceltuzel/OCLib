//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _oipimageprocessing_h
#define _oipimageprocessing_h

#include "OCV/OCVImage.h"
#include "OLA/OLALinearAlgebra.h"

class OIPImageProcessing {
public:
	static void Histogram(OCVImage& image, OLAVector& hist);
	static void HistogramEqualization(OCVImage& image, OCVImage& nimage);


};

#endif