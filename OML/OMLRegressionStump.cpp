//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "OML/OMLRegressionStump.h"
#include "OLA/OLAFunctions.h"



void OMLRegressionStump::Save(FILE* fout)
{
	fprintf(fout, "%d\n", dim_);
	fprintf(fout, "%.20E\n", a_);
	fprintf(fout, "%.20E\n", b_);
	fprintf(fout, "%.20E\n", threshold_);
}

void OMLRegressionStump::Read(FILE* fin)
{
	fscanf(fin, "%d\n",  &dim_);
	fscanf(fin, "%lf\n", &a_);
	fscanf(fin, "%lf\n", &b_);
	fscanf(fin, "%lf\n", &threshold_);
}

void OMLRegressionStump::Train(OLAVector* data, OLAVector& y, int n, double* weights, int nTrials)
{
	int t;
	int dim, d;
	int i, c;
	double score;
	double cscore;
	double val;
	double a;
	double b;
	double threshold;
	double weight;
	double pw, pv;
	double nw, nv;


	score = 1e+20;
	for (t = 0 ; t<nTrials ; t++)
	{
		dim = (int) ((rand()/(RAND_MAX+1.0)) * data[0].n_);
		d = (int) ((rand()/(RAND_MAX+1.0)) * n);
		threshold = data[d](dim) - 1e-10;

		pw = pv = nw = nv = 0.0;
		for (i=0 ; i<n ; i++)
		{
			if (weights)
				weight = weights[i];
			else
				weight = 1.0;

			if (data[i](dim) <= threshold)
			{
				nw += weight;
				nv += y(i) * weight;
			}
			else
			{
				pw += weight;
				pv += y(i) * weight;
			}
		}

		b = nv / (nw + 1e-10);
		a = (pv / (pw + 1e-10)) - b;

		cscore = 0;
		for (i=0 ; i<n ; i++)
		{
			if (weights)
				weight = weights[i];
			else
				weight = 1.0;

			val = a*((double)(data[i](dim) > threshold)) + b;
			cscore += weight * (y(i) - val) * (y(i) - val);
		}

		if (cscore < score)
		{
			dim_ = dim;
			score = cscore;
			a_ = a;
			b_ = b;
			threshold_ = threshold;
		}
	}

}

double OMLRegressionStump::Score(OLAVector& vec)
{
	return  a_*((double)(vec(dim_) > threshold_)) + b_;
}

