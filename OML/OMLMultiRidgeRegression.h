//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _omlmultiridgeregression_h
#define _omlmultiridgeregression_h

#include "OLA/OLALinearAlgebra.h"
#include "OMLMultiLinearRegression.h"

class OMLMultiRidgeRegression : public OMLMultiLinearRegression{
public:
	virtual void	Train(OLAVector* data, OLAVector* y, int n, double r, double* weights = NULL);
	virtual void	Update(OLAVector* data, OLAVector* y, int n, double r1, double r2, double* weights = NULL);


};


#endif
