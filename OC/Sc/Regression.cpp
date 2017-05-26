// OCTest.cpp : Defines the entry point for the console application.
//
//#include "vld.h"

//#include <vector>
#include <OCV/OCVImage.h>
#include <highgui.h>


#include "OLA/OLALinearAlgebra.h"
#include "OLA/OLAFunctions.h"
#include "OML/OMLLinearMethods.h"
#include "OML/OMLLSVMClassifier.h"
#include "OML/OMLLDAClassifier.h"
#include "OML/OMLBoostedClassifier.h"
#include "OML/OMLLSRegression.h"

 
//#include <stdio.h>



int main(int argc, char** argv)
{
	int i, j;
	int n = 10000;
	int m = 36;

	double* weights = new double[n];
	OLAVector* data = new OLAVector[n];
	OLAVector labels;

	labels.Resize(n);
	for (i=0 ; i<n ; i++)
	{
		weights[i] = 1.0;
		data[i].Resize(m);
	}
	weights[0] = 0.01;

	FILE* fin = fopen("data//data.txt", "r");
	for (i=0 ; i<n ; i++)
		for (j=0 ; j<m ; j++)
		{
			fscanf(fin, "%lf", &((data[i])(j)));
		}		
	fclose(fin);

	fin = fopen("data//y.txt", "r");
	for (i=0 ; i<n ; i++)
		fscanf(fin, "%lf", &(labels(i)));
	fclose(fin);

	OMLLSRegression lsr;
	lsr.Train(data, labels, n, weights);
	OLALinearAlgebra::Write(lsr.beta_);
	printf("%lf\n", lsr.beta0_);

/*
	OMLLSVMClassifier lda;
	//OMLLDAClassifier lda;
	lda.Train(data, weights, pn, nn);

	int ec = 0;
	for (i=0 ; i<pn ;i++)
	{
		if (lda.Classify(data[i]) == 0)
			ec++;
	}



	for (i=pn ; i<pn+nn ;i++)
	{
		if (lda.Classify(data[i]) > 0)
			ec++;
	}

	printf("%f\n", ((1.0 * ec) / (pn+nn)));
	printf("%d\n", ec);

	OLALinearAlgebra::Write(lda.beta_);
	printf("%f\n", lda.beta0_);

	*/

	return 0;
}

  