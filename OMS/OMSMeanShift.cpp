//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "OMSMeanShift.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

#define COMSEpsilon 0.000001
#define COMSMaxIteration 200

OMSMeanShift::OMSMeanShift()
{
	h_ = NULL;
	points_ = NULL;
	bandwidths_ = NULL;
	prunedModes_ = NULL;
	localModes_ = NULL;
	prunedModeProbs_ = NULL;
	localModeProbs_ = NULL;
	basinOfAttraction_ = NULL;

	iterationCount_ = 0;
}

OMSMeanShift::~OMSMeanShift()
{
	if (h_)
		delete[] h_;

	if (points_)
		delete[] points_;

	if (bandwidths_)
		delete[] bandwidths_;

	if (basinOfAttraction_)
		delete[] basinOfAttraction_;

	if (prunedModes_)
		delete[] prunedModes_;

	if (localModes_)
		delete[] localModes_;

	if (prunedModeProbs_)
		delete[] prunedModeProbs_;

	if (localModeProbs_)
		delete[] localModeProbs_;
}

void OMSMeanShift::Set(int d, double* h, int jump, EKernelType kernel)
{
	d_ = d;
	h_ = new double[d_];
	memcpy(h_, h, sizeof(double)*d_);
	jump_ = jump;
	kernel_ = kernel;
}

void OMSMeanShift::SetPoints(int n, double** points, double** bandwidths)
{
	int i, j;
	n_ = n;
	nxd_ = n_*d_;
	points_ = new double[nxd_];
	bandwidths_ = new double[nxd_];
	basinOfAttraction_ = new int[n];
	for (i=0 ; i<n ; i++)
	{
		for (j=0 ; j<d_ ; j++)
		{
			points_[j+i*d_] = points[i][j];
		}
	}
	if (bandwidths)
	{
		for (i=0 ; i<n ; i++)
		{
			for (j=0 ; j<d_ ; j++)
			{
				bandwidths_[j+i*d_] = bandwidths[i][j];
			}
		}
	}
	else
	{
		for (i=0 ; i<n ; i++)
		{
			for (j=0 ; j<d_ ; j++)
			{
				bandwidths_[j+i*d_] = h_[j];
			}
		}
	}
}

void OMSMeanShift::Read(char* filename)
{
	FILE* fin;
	int i, j;

	fin = fopen(filename, "r");
	fscanf(fin,"%d %d", &n_, &d_);

	nxd_ = n_*d_;
	
	points_ = new double[nxd_];
	bandwidths_ = new double[nxd_];
	basinOfAttraction_ = new int[n_];

	for (i=0 ; i<nxd_ ; i++)
	{
		fscanf(fin, "%lf", &points_[i]);
	}
	fclose(fin);	

	for (i=0 ; i<n_ ; i++)
	{
		for (j=0 ; j<d_ ; j++)
		{
			bandwidths_[j+i*d_] = h_[j];
		}
	}
}

void OMSMeanShift::SaveLocalModes(char* filename)
{
	FILE* fout;
	int i, j;

	fout = fopen(filename, "w");

	for (i=0 ; i<nLocalModes_ ; i++)
	{
		for (j=0 ; j<d_ ; j++)
		{
			fprintf(fout, "%f ", localModes_[i*d_+j]);
		}

		fprintf(fout, "%f\n", localModeProbs_[i]);
	}

	fclose(fout);
}

void OMSMeanShift::SavePrunedModes(char* filename)
{
	FILE* fout;
	int i, j;

	fout = fopen(filename, "w");

	for (i=0 ; i<nPrunedModes_ ; i++)
	{
		for (j=0 ; j<d_ ; j++)
		{
			fprintf(fout, "%f ", prunedModes_[i*d_+j]);
		}

		fprintf(fout, "%f\n", prunedModeProbs_[i]);
	}

	fclose(fout);
}


void OMSMeanShift::Initialize()
{
	int i;
	
	nLocalModes_ = n_/jump_;
	localModes_ = new double[nLocalModes_*d_];
	localModeProbs_ = new double[nLocalModes_];

	for (i=0 ; i<nLocalModes_ ; i++)
	{
		memcpy(&(localModes_[i*d_]), &(points_[i*jump_*d_]), d_*sizeof(double));	
	}
}

void OMSMeanShift::Sort()
{
	Sort(localModes_, localModeProbs_, nLocalModes_, d_);
}

void OMSMeanShift::Run()
{
	int i;

	Initialize();
	
	//printf("Doing Iterations\n");
	for (i=0 ; i<nLocalModes_ ; i++)
	{
		//if (i%(nLocalModes_/20) == 0)
		//	printf(".");
		
		RunSinglePoint(&(localModes_[i*d_]));
		localModeProbs_[i] = Probability(&(localModes_[i*d_]), d_, h_);
	}
	//printf("\nIteration count: %d\n", iterationCount_);
	
	//Sort(localModes_, localModeProbs_, nLocalModes_, d_);
}

void OMSMeanShift::RunSinglePoint(double* point)
{ 
	int i;
	double* modifiedPoint;

	modifiedPoint = new double[d_];
	memcpy(modifiedPoint, point, d_*sizeof(double));

	for (i=0 ; i<COMSMaxIteration ; i++)	
	{
		iterationCount_++;
		Iterate(point, modifiedPoint);

		if (DistanceSqr(point, modifiedPoint, d_, h_) < COMSEpsilon)
		{
			memcpy(point, modifiedPoint, d_*sizeof(double));
			break;
		}
		else
		{			
			memcpy(point, modifiedPoint, d_*sizeof(double));
		}		
	}

	delete[] modifiedPoint;
}


void OMSMeanShift::Iterate(double* point, double* modifiedPoint)
{
	int i, j;
	int index;
	double weight, totalWeights;

	totalWeights = COMSEpsilon;

	memset(modifiedPoint, 0, d_*sizeof(double));

	for (i=0 ; i<n_ ; i++)
	{
		index = i*d_;

		weight = KernelDiff(point, &(points_[index]), d_, &(bandwidths_[index]));
		totalWeights += weight;

		for (j=0 ; j<d_ ; j++)
		{
			modifiedPoint[j] += weight*points_[index+j];
		}
	}

	for (j=0 ; j<d_ ; j++)
	{
		modifiedPoint[j] /= totalWeights;
	}
}



void OMSMeanShift::PruneModes(double* h, int minSize)
{
	int i, j, k;

	int flag;
	int		tLocalModeCount;
	int*		tLocalModeSizes;
	double*	tLocalModes;
	
	tLocalModeCount = 0;
	tLocalModeSizes = new int[nLocalModes_];
	tLocalModes = new double[nLocalModes_*d_];

	memset(tLocalModeSizes, 0, sizeof(int)*nLocalModes_);

	for (i=0 ; i<nLocalModes_ ; i++)
	{
		flag = 1;

		for (j=0 ; j<tLocalModeCount ; j++)
		{
			if (DistanceSqr(&(localModes_[i*d_]), &(tLocalModes[j*d_]), d_, h) < 1.0)
			{
				basinOfAttraction_[i] = j;
				for (k=0 ; k<d_ ; k++)
				{
					tLocalModes[j*d_+k] = tLocalModes[j*d_+k] * tLocalModeSizes[j] +  localModes_[i*d_+k];
				} 
				tLocalModeSizes[j]++;
				for (k=0 ; k<d_ ; k++)
				{
					tLocalModes[j*d_+k] /= tLocalModeSizes[j];
				}

				flag = 0;
				break;
			}
		}

		if (flag)
		{
			basinOfAttraction_[i] = tLocalModeCount;
			memcpy(&(tLocalModes[tLocalModeCount*d_]), &(localModes_[i*d_]), sizeof(double)*d_);
			tLocalModeSizes[tLocalModeCount]++;
			tLocalModeCount++;
		}
	}

	nPrunedModes_ = 0;
	for (i=0 ; i<tLocalModeCount ; i++)
	{
		if (tLocalModeSizes[i] > minSize)
			nPrunedModes_++;		
	}
	prunedModes_ = new double[nPrunedModes_*d_];
	prunedModeProbs_ = new double[nPrunedModes_];

	j=0;
	for (i=0 ; i<tLocalModeCount ; i++)
	{
		if (tLocalModeSizes[i] > minSize)
		{
			memcpy(&(prunedModes_[j*d_]), &(tLocalModes[i*d_]), sizeof(double)*d_);
			prunedModeProbs_[j] = Probability(&(prunedModes_[j*d_]), d_, h_);
			j++;
		}
	}
	//Sort(prunedModes_, prunedModeProbs_, nPrunedModes_, d_);

	delete[] tLocalModeSizes;
	delete[] tLocalModes;
}


void OMSMeanShift::Sort(double* points, double* probs, int n, int d)
{
	int i;
	int* index;
	double* tpoints;
	double* tprobs;

	index = new int[n];
	tprobs = new double[n];
	tpoints = new double[n*d];

	memcpy(tprobs, probs, sizeof(double)*n);
	memcpy(tpoints, points, sizeof(double)*n*d);

	for (i=0 ; i<n ; i++)
		index[i] = i;
	
	Sort(tprobs, n, index);

	for (i=0 ; i<n ; i++)
	{
		probs[n-i-1] = tprobs[i];
		memcpy(&(points[(n-i-1)*d]), &(tpoints[index[i]*d]), sizeof(double)*d);
	}

	delete[] index;
	delete[] tpoints;
	delete[] tprobs;
}

void OMSMeanShift::Sort(double* ra, int nVec, int* ira)
{
   unsigned long n, l, ir, i, j;
   n = nVec;
   double rra;
   int irra;
   
   if (n<2)
      return;
   l = (n>>1)+1;
   ir = n;
   for (;;)
   {
      if (l>1)
      {
         irra = ira[(--l)-1];
         rra = ra[l-1];
      }
      else
      {
         irra = ira[ir-1];
         rra = ra[ir-1];

         ira[ir-1] = ira[1-1];
         ra[ir-1] = ra[1-1];

         if (--ir==1)
         {
            ira[1-1] = irra;
            ra[1-1] = rra;
            break;
         }
      }
      i = l;
      j = l+l;
      while (j<=ir)
      {
         if (j<ir && ra[j-1]<ra[j+1-1])
            j++;
         if (rra<ra[j-1])
         {
            ira[i-1] = ira[j-1];
            ra[i-1] = ra[j-1];

            i = j;
            j <<= 1;
         }
         else
            j = ir+1;
      }
      ira[i-1] = irra;
      ra[i-1] = rra;
   }
}


inline double OMSMeanShift::Kernel(double* point1, double* point2, int d, double* h)
{
	double dist;
	dist = DistanceSqr(point1, point2, d, h);

	switch (kernel_)
	{
	case EEpanechnikovKernel:
		{
			if (dist > 1.0)		
				return 0.0;	
			else		
				return 1.0 - dist;
		}
		break;
	case EGaussianKernel:
		{
			if (dist >= 10.0)
				return 0.0;
			else
				return exp(-0.5*dist);
		}
		break;
	default:
		return 0;
		break;
	}	
}


inline double OMSMeanShift::KernelDiff(double* point1, double* point2, int d, double* h)
{
	double dist;
	dist = DistanceSqr(point1, point2, d, h);

	switch (kernel_)
	{
	case EEpanechnikovKernel:
		{
			if (dist > 1.0)		
				return 0.0;	
			else		
				return 1.0;
		}
		break;
	case EGaussianKernel:
		{
			if (dist >= 3.0)
				return 0.0;
			else
				return exp(-0.5*dist);
		}
		break;
	default:
		return 0;
		break;
	}
}

inline double OMSMeanShift::DistanceSqr(double* point1, double* point2, int d, double* h)
{
	int i;
	double distance, totalDistance;

	totalDistance = 0;
	distance = 0;

	for (i=0 ; i<d ; i++)
	{
		distance = (point1[i] - point2[i])/h[i];
		totalDistance += distance*distance;
	}

	return totalDistance;
}



inline double OMSMeanShift::Probability(double* point, int d, double* h)
{
	int i;
	int index;
	double probability;

	probability = 0;

	for (i=0 ; i<n_ ; i++)
	{
		index = i*d;

		probability += Kernel(point, &(points_[index]), d, h);
	}

	return probability / n_;
}
