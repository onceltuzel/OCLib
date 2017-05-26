//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "OML/OMLBoostedClassifier.h"
#include "OLA/OLAFunctions.h"

void OMLBoostedClassifier::SafeRelease()
{
	nClassifiers_ = 0;

	if (weights_)
		delete[] weights_;

	if (classifiers_)
		delete[] classifiers_;

	weights_ = NULL;
	classifiers_ = NULL; 
}

OMLBoostedClassifier::OMLBoostedClassifier()
{
	nClassifiers_ = 0;
	weights_ = NULL;
	classifiers_ = NULL;
}

OMLBoostedClassifier::~OMLBoostedClassifier()
{
	SafeRelease();
}


void OMLBoostedClassifier::Train(OLAVector* data, double* weights, int nPos, int nNeg, int nClassifiers)
{
	int i, j;
	int res;
	int nTot;
	double score;
	int* labels;
	double* tweights;

	SafeRelease();

	nClassifiers_ = nClassifiers;
	nTot = nPos + nNeg;

	labels = new int[nTot];
	tweights = new double[nTot];
	memcpy(tweights, weights, sizeof(double)*nTot);

	classifiers_ = new OMLLDAClassifier[nClassifiers_];
	weights_ = new double[nClassifiers_];

	for (i=0 ; i<nClassifiers_ ; i++)
	{
		score = 0;
		Normalize(tweights, nTot);
		classifiers_[i].Train(data, tweights, nPos, nNeg);
		for (j=0 ; j<nTot ; j++)
		{
			labels[j] = classifiers_[i].Classify(data[j]);
			res = (labels[j] == (j<nPos));
			score +=  res * tweights[j];
		}
		weights_[i] = 0.5*log(score / (1 - score + 1e-5));

		for (j=0 ; j<nTot ; j++)
		{
			res = !(labels[j] == (j<nPos));
			tweights[j] *= exp (res * weights_[i]);
		}
	}

	Normalize(weights_, nClassifiers_);

	delete[] tweights;
	delete[] labels;
}

int	OMLBoostedClassifier::Classify(OLAVector& vec)
{
	int i;
	double score;
	score = 0;

	for (i=0 ; i<nClassifiers_ ; i++)
	{
		score += classifiers_[i].Classify(vec)*weights_[i];
	}

	return (score > 0.5);
}

double	OMLBoostedClassifier::Score(OLAVector& vec)
{
	int i;
	double score;
	score = 0;

	for (i=0 ; i<nClassifiers_ ; i++)
	{
		score += classifiers_[i].Classify(vec)*weights_[i];
	}

	return score;
}


void OMLBoostedClassifier::Normalize(double* data, int n)
{
	int i;
	double sum = 0;
	for (i=0 ; i<n ; i++)
		sum += data[i];
	for (i=0 ; i<n ; i++)
		data[i] /= sum;
}

void OMLBoostedClassifier::Save(FILE* fout)
{
	int i;

	fprintf(fout, "%d\n", nClassifiers_);
	for (i=0 ; i<nClassifiers_ ; i++)
	{
		fprintf(fout, "%.20E\n", weights_[i]);
		classifiers_[i].Save(fout);
	}

}

void OMLBoostedClassifier::Read(FILE* fin)
{ 
	int i;

	fscanf(fin, "%d\n", &nClassifiers_);
	classifiers_ = new OMLLDAClassifier[nClassifiers_];
	weights_ = new double[nClassifiers_];

	for (i=0 ; i<nClassifiers_ ; i++)
	{
		fscanf(fin, "%lf\n", &(weights_[i]));
		classifiers_[i].Read(fin);
	}
}

