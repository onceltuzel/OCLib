//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "OML/OMLDecisionStump.h"
#include "OLA/OLAFunctions.h"



void OMLDecisionStump::Save(FILE* fout)
{
	fprintf(fout, "%d\n", dim_);
	fprintf(fout, "%.20E\n", threshold_);
	fprintf(fout, "%.20E\n", sign_);
}

void OMLDecisionStump::Read(FILE* fin)
{
	fscanf(fin, "%d\n",  &dim_);
	fscanf(fin, "%lf\n", &threshold_);
	fscanf(fin, "%lf\n", &sign_);
}

void OMLDecisionStump::Train(OLAVector* data, int pn, int nn, double* weights, int nTrials)
{
	int dim, t, d;
	int i;
	double score;
	double cscore;
	double threshold;
	double fp, fn;
	double tp, tn;
	double sign;
	int n;

	n = pn+nn;


	score = 1e+20;
	for (t = 0 ; t<nTrials ; t++)
	{
		dim = (int) ((rand()/(RAND_MAX+1.0)) * data[0].n_);
		d = (int) ((rand()/(RAND_MAX+1.0)) * n);
		threshold = data[d](dim) - 1e-10;


		tp = tn = fp = fn = 0;
		for (i=0 ; i<pn ; i++)
		{
			if (data[i](dim) <= threshold)
			{
				fp += weights[i];
			}
			else
			{
				tp += weights[i];
			}
		}
		for (i=pn ; i<n ; i++)
		{
			if (data[i](dim) > threshold)
			{
				fn += weights[i];
			}
			else
			{
				tn += weights[i];
			}
		}

		if (tp + tn > fp + fn)
			sign = 1;
		else
			sign = -1;
		
		if (sign > 0)
			cscore = fp+fn;
		else
			cscore = tp+tn;

		if (cscore < score)
		{
			dim_ = dim;
			score = cscore;
			threshold_ = threshold;
			sign_ = sign;
			
		}
	}

}

double OMLDecisionStump::Score(OLAVector& vec)
{
	return ((vec(dim_) > threshold_) - 0.5) * sign_ * 2.0;
}

int	OMLDecisionStump::Classify(OLAVector& vec)
{
	return Score(vec) > 0;
}
