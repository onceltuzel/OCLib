//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "OML/OMLMultiLSRegression.h"
#include "OLA/OLAFunctions.h"



void OMLMultiLSRegression::Train(OLAVector* data, OLAVector* y, int n, double* weights)
{
	int m, d;
	int i, j;
	OLAMatrix X, Xtw, C, Ci, Yt;
	OLAMatrix XtwY, Theta;

	
	m = data[0].n_;
	d = y[0].n_;

	X.Resize(n, m + 1);
	Xtw.Resize(m + 1, n);
	C.Resize(m + 1, m + 1);
	Ci.Resize(m + 1, m + 1);
	
	XtwY.Resize(m + 1, d);
	Theta.Resize(m + 1, d);

	Yt.Resize(n, d);

	for (i=0 ; i<n ; i++)
	{
		for (j=0 ; j<m ; j++)
		{
			X(i, j) = data[i](j);
		}
		X(i, m) = 1.0;

		for (j=0 ; j<d ; j++)
		{
			Yt(i, j) = y[i](j);
		}
	}

	OLALinearAlgebra::Transpose(X, Xtw);

	if (weights)
	{
		for (i=0 ; i<n ; i++)
		{
			for (j=0 ; j<m+1 ; j++)
			{
				Xtw(j,i) *= weights[i];
			}
		}
	}
	OLALinearAlgebra::Multiply(Xtw, X, C);
	OLALinearAlgebra::PInverse(C, Ci);
	OLALinearAlgebra::Multiply(Xtw, Yt, XtwY);
	OLALinearAlgebra::Multiply(Ci, XtwY, Theta);

	beta_.Resize(d, m);
	for (i=0 ; i<m ; i++)
	{
		for (j=0 ; j<d ; j++)
			beta_(j,i) = Theta(i,j);
	}

	beta0_.Resize(d);
	for (j=0 ; j<d ; j++)
		beta0_(j) = Theta(m, j);
}


