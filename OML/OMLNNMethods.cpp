//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//

#include "OMLNNMethods.h"
#include "OLA/OLAFunctions.h"
#include "OCM/OCMFunctions.h"

#define OMLNNEPSILON 0.000001
#define OMLNNMAXITER 10000

void OMLNNMethods::KMeans(OLAVector* data, OLAVector* centers, int n, int k, int* assign, int distanceType)
{	
	double r;
	int index;
	int i, j;
	int* elementCounts;
	OLAVector* means;  
	int outputClusters;

	outputClusters = 1;
	if (assign == NULL)
	{
		assign = new int[n];
		outputClusters = 0;
	}
	
	means = new OLAVector[k];
	elementCounts = new int[k];
	
	for (i=0 ; i<k ; i++)  
	{
		means[i].Resize(data[0].Size());
	}

	for (i=0 ; i<k ; i++)
	{
		r = ((double) rand()) / (RAND_MAX+1);
		index = (int) (r*n);
		centers[i] = data[index];
		for (j=0 ; j<centers[i].Size() ; j++)
		{
			r = ((double) rand()) / (RAND_MAX+1);
			centers[i](j) += r*0.001;
		}
	}


	int it;
	int flag;
	int minIndex;
	double min;  
	double dist;

	it = 0;
	flag = 1; 
	while (flag && it < OMLNNMAXITER)
	{
		memset(elementCounts, 0, sizeof(int)*k);
		for (i=0 ; i<k ; i++)
		{
			means[i].SetZero();
		}

		for (i=0 ; i<n ; i++)
		{
			minIndex = -1;
			min = 10e+020; 
			for (j=0 ; j<k ; j++)
			{
				dist = OLAFunctions::Dist2(data[i], centers[j]);
				if (dist<min)
				{
					min = dist;
					minIndex = j;
				} 
			}
			assign[i] = minIndex;			
			means[minIndex] += data[i];
			elementCounts[minIndex]++;
		}

		flag = 0;
		for (i=0 ; i<k ; i++)
		{
			if (elementCounts[i]>0)
			{
				means[i] /= elementCounts[i];

				if (OLAFunctions::Dist2(centers[i], means[i]) > OMLNNEPSILON)
				{
					flag = 1;
				}

				centers[i] = means[i];
			}
		}

		it++;
	}

	delete[] means;
	delete[] elementCounts;
	if (outputClusters == 0)
	{
		delete[] assign;
	}
}

int	OMLNNMethods::KNN(OLAVector* data, int* labels, OLAVector& sample, int n, int nclasses, int k, double* wdist, int* wlabels, int distanceType)
{
	int i;
	int label;
	int* votes;

	int wSpecified;

	if (wdist == NULL)
	{
		wSpecified = 0;
		wdist = new double[n];
		wlabels = new int[n];
		memcpy(wlabels, labels, sizeof(int)*n);
	}
	else
	{
		wSpecified = 1;
	}

	votes = new int[nclasses];
	memset(votes, 0, sizeof(int)*nclasses); 
 
	for (i=0 ; i<n ; i++)
	{
		switch(distanceType)
		{
		case 0:
			wdist[i] = OLAFunctions::Dist2(data[i], sample);
			break;
		case 1:
			wdist[i] = OLAFunctions::Chi2(data[i], sample);
			break;
		}
	}

	OCMFunctions::ISort(wdist, n, wlabels);

	for (i=0 ; i<k ; i++)
	{
		votes[wlabels[i]]++;
	}

	label = OCMFunctions::MaxIndex(votes, nclasses);

	delete[] votes;
	if (!wSpecified)
	{
		delete[] wdist;
		delete[] wlabels;
	}

	return label;
}



