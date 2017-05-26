//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _omllslassifier_h
#define _omllslassifier_h

#include "OML/OMLLinearClassifier.h"

class OMLLSClassifier : public OMLLinearClassifier{
public:
	virtual void	Train(OLAVector* data, double* weights, int pn, int nn);

};



#endif
