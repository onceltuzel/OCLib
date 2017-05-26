//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _ostfunctions_h
#define _ostfunctions_h

#include "OLA/OLALinearAlgebra.h"

class OSTFunctions {
public:
	static void Random(OLAMatrix& matrix);
	static void Random(OLAVector& vec);
	static double RandN();
	static void RandN(OLAVector& vec);

	static void RandPerm(OLAVector& vec);

	static void SelectionWOReplacement(const OLAVector& invec, OLAVector& outvec);
	static void SelectionWReplacement(const OLAVector& invec, OLAVector& outvec);


};

#endif

