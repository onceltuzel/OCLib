//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _omllinearmethods_h
#define _omllinearmethods_h

#include "OLA/OLALinearAlgebra.h"

class OMLLinearMethods {
public:
	static void	LDATrain(OLAVector* data, double* weights, int pn, int nn, OLAVector& beta, double& beta0);
};

#endif
