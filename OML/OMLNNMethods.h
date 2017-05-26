//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _omlnnmethods_h
#define _omlnnmethods_h

#include "OLA/OLAFunctions.h"

class OMLNNMethods {
public:
	static void	KMeans(OLAVector* data, OLAVector* centers, int n, int k, int* assign = NULL, int distanceType = 0);
	static int	KNN(OLAVector* data, int* labels, OLAVector& sample, int n, int nclasses, int k, double* wdist = NULL, int* wlabels = NULL, int distanceType = 0);
};

#endif
