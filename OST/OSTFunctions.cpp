//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "OSTFunctions.h"


double OSTFunctions::RandN()
{
	double x1, x2, w, y1, y2;

	w = 2.0;
	while(w > 1.0)
	{
		x1 = 2.0 * ((double)rand()/(RAND_MAX+1)) - 1.0;
		x2 = 2.0 * ((double)rand()/(RAND_MAX+1)) - 1.0;
		w = x1 * x1 + x2 * x2;
	}

	w = sqrt( (-2.0 * log( w ) ) / w );
	y1 = x1 * w;
	y2 = x2 * w;

	return y1;
}


void OSTFunctions::RandN(OLAVector& vec)
{
	int i;
	double x1, x2, w, y1, y2;

	int c = 0;
	for (i=0; i <vec.n_/2 ; i++)
	{
		w = 2.0;
		while(w > 1.0)
		{
			x1 = 2.0 * ((double)rand()/(RAND_MAX+1)) - 1.0;
			x2 = 2.0 * ((double)rand()/(RAND_MAX+1)) - 1.0;
			w = x1 * x1 + x2 * x2;
		}

		w = sqrt( (-2.0 * log( w ) ) / w );		
		y1 = x1 * w;
		y2 = x2 * w;
		vec(c++) = y1;
		vec(c++) = y2;
	}
	if (c<=vec.n_)
		vec(vec.n_-1) = RandN();
}


void OSTFunctions::Random(OLAMatrix& matrix)
{
	int i;
	double* data = matrix.data_;

	for (i=0 ; i<matrix.n_ ; i++)
	{
		*data = (double)rand()/(RAND_MAX+1) - 0.5;
		data++;
	}
}

void  OSTFunctions::Random(OLAVector& vec)
{
	int i;

	for (i=0 ; i<vec.n_ ;i++)
	{
		vec(i)= (double)rand()/(RAND_MAX+1);
	}
} 


void OSTFunctions::RandPerm(OLAVector& vec)
{
	OLAVector tvec(vec.n_);
	
	for (int i=0 ; i<vec.n_ ; i++)
		tvec(i) = i;

	SelectionWOReplacement(tvec, vec);
}

void OSTFunctions::SelectionWOReplacement(const OLAVector& invec, OLAVector& outvec)
{
	int i, n, d, index;
	double r;
	OLAVector tvec;

	n = invec.n_;
	d = outvec.n_;

	tvec.Resize(n);
	tvec = invec;

	for (i=0 ; i<d ; i++)
	{
 		r = ((double)rand())/(RAND_MAX+1);
		index = (int) (r*n);
		outvec(i) = tvec(index);
		tvec(index) = tvec(n - 1);
		n--;
	}
}

void OSTFunctions::SelectionWReplacement(const OLAVector& invec, OLAVector& outvec)
{
	int i, n, d, index;
	double r;

	n = invec.n_;
	d = outvec.n_;

	for (i=0 ; i<d ; i++)
	{
		r = ((double)rand())/(RAND_MAX+1);
		index = (int) (r*n);
		outvec(i) = invec(index);
	}
}
