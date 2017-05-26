//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _omlldaclassifier_h
#define _omlldaclassifier_h

#include "OML/OMLLinearClassifier.h"

class OMLLDAClassifier : public OMLLinearClassifier{
public:
	virtual void	Train(OLAVector* data, double* weights, int pn, int nn);

};



#endif
