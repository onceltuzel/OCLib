//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//

#ifndef _olalinearalgebra_h
#define _olalinearalgebra_h

#include "OLAMatrix.h"
#include <stdio.h>
#include <cv.h>


class OLALinearAlgebra {
public:
	static void Copy(OLAVector* vec, OLAMatrix& mat, int n, int order = 0);
	static void Subtract(OLAMatrix& inmat, OLAVector& vec, OLAMatrix& outmat,int order = 0);


	//Vector Operations
	static void Zero(OLAVector& vec);

	//Two element operations
	static void Subtract(const OLAVector& invec1, const OLAVector& invec2, OLAVector& outvec);
	static void Add(const OLAVector& invec1, const OLAVector& invec2, OLAVector& outvec);

	//Norms
	static double Norm(const OLAVector& vec);  //L2 norm
	static double Norm1(const OLAVector& vec); //L1 norm
	static double Norm2(const OLAVector& vec); //Squared L2 norm

	static void Normalize(OLAVector& vec);

	static double Dot(const OLAVector& vec1, const OLAVector& vec2); //Dot product
	static void Cross3(const OLAVector& invec1, const OLAVector& invec2, OLAVector& outvec);


	//Matrix Operations
	static void Zero(OLAMatrix& matrix);
	static void Identity(OLAMatrix& matrix);

	// transpose matrix
	static void Transpose(const OLAMatrix& inmatrix, OLAMatrix& outmatrix );
	static void MultiplyTranspose(const OLAMatrix& inmatrix, OLAMatrix& outmatrix, int order = 1);


	// matrix vector multiplication
	static void MultiplyAdd(const OLAMatrix& inmatrix, const OLAVector& invec, const OLAVector& addvec, OLAVector& outvec);
	static void Multiply(const OLAMatrix& inmatrix, const OLAVector& invec, OLAVector& outvec);

	// two operants
	static void MultiplyAdd(const OLAMatrix& inmatrix1, const OLAMatrix& inmatrix2, const OLAMatrix& addmatrix, OLAMatrix& outmatrix);	
	static void Multiply(const OLAMatrix& inmatrix1, const OLAMatrix& inmatrix2, OLAMatrix& outmatrix);
	static void Subtract(const OLAMatrix& inmatrix1, const OLAMatrix& inmatrix2, OLAMatrix& outmatrix);
	static void Add(const OLAMatrix& inmatrix1, const OLAMatrix& inmatrix2, OLAMatrix& outmatrix);

	static void OuterProduct(const OLAVector& invec1, const OLAVector& invec2, OLAMatrix& outmatrix);

	// invert matrix
	static void Inverse(const OLAMatrix& inmatrix, OLAMatrix& outmatrix);

	//matrix determinant
	static double Determinant(const OLAMatrix& matrix);

	//solve
	static void Solve(const OLAMatrix& A, const OLAVector& b, OLAVector& x, int method = CV_LU);
	static void Solve(const OLAMatrix& A, const OLAMatrix& B, OLAMatrix& X, int method = CV_LU);

	//matrix norms
	static double FrobeniusNorm(const OLAMatrix& matrix);

	// complex functions
	static int Sqrt(const OLAMatrix& inmatrix, OLAMatrix& outmatrix);
	static int Log(const OLAMatrix& inmatrix, OLAMatrix& outmatrix);
	static int Exp(const OLAMatrix& inmatrix, OLAMatrix& outmatrix);
	static int SPDSqrt(const OLAMatrix& inmatrix, OLAMatrix& outmatrix);
	static int SPDLog(const OLAMatrix& inmatrix, OLAMatrix& outmatrix);
	static int SPDExp(const OLAMatrix& inmatrix, OLAMatrix& outmatrix);
	static int PD(const OLAMatrix& inmatrix, OLAMatrix& outmatrix);
	static int Rank(const OLAMatrix& matrix);

	static void SVD(const OLAMatrix& matrix, OLAMatrix& U, OLAVector& S, OLAMatrix& Vt);
	static void EIG(const OLAMatrix& matrix, OLAMatrix& V, OLAVector& D);




	static void PInverse(const OLAMatrix& inmatrix, OLAMatrix& outmatrix);

	// input output
	static void Write(const OLAVector& vec);
	static void Write(const OLAMatrix& matrix);
	static void Write(FILE* fout, const OLAVector& vec);
	static void Write(FILE* fout, const OLAMatrix& matrix);

	static void Read(FILE* fin, OLAVector& vec);
	static void Read(FILE* fin, OLAMatrix& matrix);
};



#endif