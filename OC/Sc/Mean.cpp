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
	int i, n, d;
	n = 3000;
	d = 8;
	srand(100);
	OLAMatrix m1(d,d+5), m2(d+5,d), mMat(d,d), iMat(d,d), emMat(d,d);
	OLAMatrix* data;
	data = new OLAMatrix[n];

	for (i=0 ; i<n ; i++)
	{
		data[i].Resize(d,d);
		OLALinearAlgebra::Random(m1);
		OLALinearAlgebra::Transpose(m1, m2);
		OLALinearAlgebra::Multiply(m1, m2, data[i]);

		for (int j = 0; j<d ; j++)
		{
			double v = sqrt(data[i](j,j));
			for (int k = 0; k<d ; k++)
			{				
				data[i](j,k) /= v;
				data[i](k,j) /= v;
			}
		}
		OLALinearAlgebra::Identity(data[i]);
		data[i] *= 25;
	}
	OLALinearAlgebra::Identity(iMat);
	for (i=0 ; i<n ; i++)
		emMat+=data[i];
	emMat/=n;


	OLAFunctions::PSDMean(data, n, iMat, mMat);
	OLALinearAlgebra::Write(mMat);
	printf("\n");
	OLALinearAlgebra::Write(emMat);

	double es =0 , rs = 0;
	//OLALinearAlgebra::Identity(mMat);

	for (i=0 ; i<n ; i++)
	{
		es += OLAFunctions::CovarianceDistance(data[i], emMat);
		rs += OLAFunctions::CovarianceDistance(data[i], mMat);
	}
	printf("%f %f\n", es, rs);

	return 0;
}

  