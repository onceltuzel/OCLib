//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "OML/OMLDecisionStumpPW.h"
#include "OLA/OLAFunctions.h"



void OMLDecisionStumpPW::Save(FILE* fout)
{
	fprintf(fout, "%d\n", dim1_);
	fprintf(fout, "%d\n", dim2_);
	fprintf(fout, "%.20E\n", threshold_);
	fprintf(fout, "%.20E\n", sign_);
}

void OMLDecisionStumpPW::Read(FILE* fin)
{
	fscanf(fin, "%d\n",  &dim1_);
	fscanf(fin, "%d\n",  &dim2_);
	fscanf(fin, "%lf\n", &threshold_);
	fscanf(fin, "%lf\n", &sign_);
}

void OMLDecisionStumpPW::Train(OLAVector* data, int pn, int nn, double* weights, int nTrials)
{
	int dim, dim1, dim2, t, d;
	int i;
	double score;
	double cscore;
	double fp, fn;
	double tp, tn;
	double sign;
	int n;

	n = pn+nn;

	double threshold;

	score = 1e+20;
	for (t = 0 ; t<nTrials ; t++)
	{
		dim1 = (int) ((rand()/(RAND_MAX+1.0)) * data[0].n_);
		dim2 = (int) ((rand()/(RAND_MAX+1.0)) * data[0].n_);
		//dim = (int) ((rand()/(RAND_MAX+1.0)) * data[0].n_);
		//d = (int) ((rand()/(RAND_MAX+1.0)) * n);
		//threshold = data[d](dim) * (((rand()/(RAND_MAX+1.0)) > 0.5) - 0.5) * 2.0;
		threshold = ((1.0*rand())/(RAND_MAX+1) - 0.5) * 0.05;

		tp = tn = fp = fn = 0;
		for (i=0 ; i<pn ; i++)
		{
			if (data[i](dim1) <= data[i](dim2) + threshold)
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
			if (data[i](dim1) > data[i](dim2) + threshold)
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
			dim1_ = dim1;
			dim2_ = dim2;
			score = cscore;
			sign_ = sign;
			threshold_ = threshold;			
		}
	}

}

double OMLDecisionStumpPW::Score(OLAVector& vec)
{
	return ((vec(dim1_) > vec(dim2_) + threshold_) - 0.5) * sign_ * 2.0;
}

int	OMLDecisionStumpPW::Classify(OLAVector& vec)
{
	return Score(vec) > 0;
}
