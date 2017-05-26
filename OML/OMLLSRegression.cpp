//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "OML/OMLLSRegression.h"
#include "OLA/OLAFunctions.h"



void OMLLSRegression::Train(OLAVector* data, OLAVector& y, int n, double* weights)
{
	/*
	int i, j, m;
	OLAMatrix X, Xpi;
	OLAVector theta;

	m = data[0].n_;

	X.Resize(n, m + 1);
	Xpi.Resize(m + 1, n);
	theta.Resize(m + 1);

	for (i=0 ; i<n ; i++)
	{
		for (j=0 ; j<m ; j++)
		{
			X(i, j) = data[i](j);
		}

		X(i, m) = 1.0;
	}

	if (weights)
	{
		for (i=0 ; i<n ; i++)
		{
			for (j=0 ; j<m+1 ; j++)
			{
				X(i,j) *= sqrt(weights[i]);
			}
		}
	}

	OLALinearAlgebra::PInverse(X, Xpi);
	OLALinearAlgebra::Multiply(Xpi, y, theta);
*/

	int m;
	int i, j;
	OLAMatrix X, Xtw, C, Ci;
	OLAVector xtwy, theta;

	
	m = data[0].n_;

	X.Resize(n, m + 1);
	Xtw.Resize(m + 1, n);
	C.Resize(m + 1, m + 1);
	Ci.Resize(m + 1, m + 1);
	xtwy.Resize(m + 1);
	theta.Resize(m + 1);

	for (i=0 ; i<n ; i++)
	{
		for (j=0 ; j<m ; j++)
		{
			X(i, j) = data[i](j);
		}

		X(i, m) = 1.0;
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
	//printf("Rows: %d Columns: %d Rank: %d\n", C.nRows_, C.nCols_, OLALinearAlgebra::Rank(C));
	//OLALinearAlgebra::Inverse(C, Ci);
	OLALinearAlgebra::PInverse(C, Ci);
	OLALinearAlgebra::Multiply(Xtw, y, xtwy);
	OLALinearAlgebra::Multiply(Ci, xtwy, theta);


	beta_.Resize(m);
	for (i=0 ; i<m ; i++)
		beta_(i) = theta(i);
	beta0_ = theta(m);
}


