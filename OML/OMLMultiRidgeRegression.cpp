//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "OML/OMLMultiRidgeRegression.h"
#include "OLA/OLAFunctions.h"



void OMLMultiRidgeRegression::Train(OLAVector* data, OLAVector* y, int n, double r, double* weights)
{
	int m, d;
	int i, j;
	OLAMatrix X, Xt, C, Ci, Yt;
	OLAMatrix XtY;
	OLAMatrix betat;
	OLAVector meanx;
	OLAVector meany;
	
	m = data[0].n_;
	d = y[0].n_;

	meanx.Resize(m);
	meany.Resize(d);

	OLAFunctions::Mean(data, n, meanx);
	OLAFunctions::Mean(y, n, meany);

	X.Resize(n, m);
	Xt.Resize(m, n);
	C.Resize(m , m );
	Ci.Resize(m , m );
	
	XtY.Resize(m , d);

	Yt.Resize(n, d);

	for (i=0 ; i<n ; i++)
	{
		for (j=0 ; j<m ; j++)
		{
			X(i, j) = data[i](j) - meanx(j);
		}

		for (j=0 ; j<d ; j++)
		{
			Yt(i, j) = y[i](j) - meany(j);
		}
	}
	OLALinearAlgebra::Transpose(X, Xt);

	OLALinearAlgebra::Multiply(Xt, X, C);
	for (j=0 ; j<m ; j++)
	{
		C(j,j) += r;
	}
	//oncel
	OLALinearAlgebra::Inverse(C, Ci);
	OLALinearAlgebra::Multiply(Xt, Yt, XtY);
	betat.Resize(m, d);
	OLALinearAlgebra::Multiply(Ci, XtY, betat);
	beta_.Resize(d, m);
	OLALinearAlgebra::Transpose(betat, beta_);
	meanx *= -1;
	beta0_.Resize(d);
	OLALinearAlgebra::MultiplyAdd(beta_, meanx, meany, beta0_);
	//beta0_ *= -1;
}


void OMLMultiRidgeRegression::Update(OLAVector* data, OLAVector* y, int n, double r1, double r2, double* weights)
{
	int m, d;
	int i, j;
	OLAMatrix X, Xt, C, Ci, Yt;
	OLAMatrix XtY, pbeta;
	OLAMatrix betat;
	OLAVector meanx;
	OLAVector meany;

	m = data[0].n_;
	d = y[0].n_;

	meanx.Resize(m);
	meany.Resize(d);

	OLAFunctions::Mean(data, n, meanx);
	OLAFunctions::Mean(y, n, meany);

	X.Resize(n, m);
	Xt.Resize(m, n);
	C.Resize(m , m );
	Ci.Resize(m , m );

	XtY.Resize(m , d);
	pbeta.Resize(m , d);

	Yt.Resize(n, d);

	for (i=0 ; i<n ; i++)
	{
		for (j=0 ; j<m ; j++)
		{
			X(i, j) = data[i](j) - meanx(j);
		}

		for (j=0 ; j<d ; j++)
		{
			Yt(i, j) = y[i](j) - meany(j);
		}
	}
	OLALinearAlgebra::Transpose(X, Xt);

	OLALinearAlgebra::Multiply(Xt, X, C);
	for (j=0 ; j<m ; j++)
	{
		C(j,j) += (r1+r2);
	}
	//oncel
	OLALinearAlgebra::Inverse(C, Ci);
	OLALinearAlgebra::Multiply(Xt, Yt, XtY);
	OLALinearAlgebra::Transpose(beta_, pbeta);
	pbeta *= r2;
	XtY += pbeta;

	betat.Resize(m, d);
	OLALinearAlgebra::Multiply(Ci, XtY, betat);
	beta_.Resize(d, m);
	OLALinearAlgebra::Transpose(betat, beta_);
	meanx *= -1;
	beta0_.Resize(d);
	OLALinearAlgebra::MultiplyAdd(beta_, meanx, meany, beta0_);
	//OLALinearAlgebra::Write(beta0_);
	//beta0_ *= -1;
}



