
//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//

#include "O3DFunctions.h"
#include <OLA/OLALinearAlgebra.h>

double O3DFunctions::GetRadius(O3DModel& model)
{
	int i;
	double radius = -1;

	for (i=0 ; i<model.nVertices_*3 ; i++)
	{
		if (fabs(model.vertices_[i]) > radius)
			radius = fabs(model.vertices_[i]);
	}

	return radius;
}

void O3DFunctions::Scale(O3DModel& model, double scaleX, double scaleY, double scaleZ)
{
	int i;
	for (i=0 ; i<model.nVertices_ ; i++)
	{
		model.vertices_[i*3] *= scaleX;
		model.vertices_[i*3+1] *= scaleY;
		model.vertices_[i*3+2] *= scaleZ;
	}
}



void O3DFunctions::Center(O3DModel& model)
{
	int i;
	double maxX = -1e+20, maxY = -1e+20, maxZ = -1e+20, minX = 1e+20, minY = 1e+20, minZ = 1e+20;
	double centerX, centerY, centerZ;

	for (i=0 ; i<model.nVertices_ ; i++)
	{
		if (model.vertices_[i*3] < minX) minX = model.vertices_[i*3];
		if (model.vertices_[i*3] > maxX) maxX = model.vertices_[i*3];
		if (model.vertices_[i*3+1] < minY) minY = model.vertices_[i*3+1];
		if (model.vertices_[i*3+1] > maxY) maxY = model.vertices_[i*3+1];
		if (model.vertices_[i*3+2] < minZ) minZ = model.vertices_[i*3+2];
		if (model.vertices_[i*3+2] > maxZ) maxZ = model.vertices_[i*3+2];
	}
	
	centerX = 0.5*(maxX+minX);
	centerY = 0.5*(maxY+minY);
	centerZ = 0.5*(maxZ+minZ);

	for (i=0 ; i<model.nVertices_ ; i++)
	{
		model.vertices_[i*3] -= centerX;
		model.vertices_[i*3+1] -= centerY;
		model.vertices_[i*3+2] -= centerZ;
	}

	//printf("Center: %f, %f, %f\n", maxX, maxY, maxZ);
}

void O3DFunctions::GetCoordinateSwitch(const char* xyzOrder, double& sign, int& index)
{
	switch (xyzOrder[0])
	{
	case'-':
		sign = -1;
		break;
	case '+':
		sign = 1;
		break;
	default:
		printf("Error in XYZ order sign\n");
		break;
	}

	switch (xyzOrder[1])
	{
	case 'X':case 'x':
		index = 0;
		break;
	case 'Y':case 'y':
		index = 1;
		break;
	case 'Z':case 'z':
		index = 2;
		break;
	default:
		printf("Error in XYZ order coordinate\n");
		break;
	}
}

void O3DFunctions::SetXYZOrder(O3DModel& model, const char* xyzOrder)
{
	int i;
	double sign;
	int index;

	double* newVertices = 0;
	double* newNormals = 0;

	newVertices = new double[model.nVertices_*3];

	if (model.normals_)
	{
		newNormals = new double[model.nVertices_*3];
	}

	O3DFunctions::GetCoordinateSwitch(xyzOrder, sign, index);
	for (i=0 ; i<model.nVertices_ ; i++)
	{
		newVertices[i*3] = model.vertices_[i*3+index]*sign;

		if (newNormals)
		{
			newNormals[i*3] = model.normals_[i*3+index]*sign;
		}
	}

	O3DFunctions::GetCoordinateSwitch(xyzOrder+2, sign, index);
	for (i=0 ; i<model.nVertices_ ; i++)
	{
		newVertices[i*3+1] = model.vertices_[i*3+index]*sign;

		if (newNormals)
		{
			newNormals[i*3+1] = model.normals_[i*3+index]*sign;
		}
	}

	O3DFunctions::GetCoordinateSwitch(xyzOrder+4, sign, index);
	for (i=0 ; i<model.nVertices_ ; i++)
	{
		newVertices[i*3+2] = model.vertices_[i*3+index]*sign;
		
		if (newNormals)
		{
			newNormals[i*3+2] = model.normals_[i*3+index]*sign;
		}
	}

	delete[] model.vertices_;
	model.vertices_ = newVertices;
	
	if (newNormals)
	{
		delete[] model.normals_;
		model.normals_ = newNormals;
	}
}


void O3DFunctions::ReadPlyModel(const char* fileName, O3DModel& model)
{
	FILE* fin;
	char str[256];

	int i;
	int  nFaces, faceType;

	bool isHasNormal = false;

	fin = fopen(fileName,"r");


	while (1)
	{
		fscanf(fin, "%s", str);
		if (strcmp(str, "element") == 0)
		{
			fscanf(fin, "%s", str);
			if (strcmp(str, "vertex") == 0)
			{
				fscanf(fin, "%d", &model.nVertices_);
			} 
			else if (strcmp(str, "face") == 0)
			{
				fscanf(fin, "%d", &nFaces);
			}

		}
		else if (strcmp(str, "property") == 0)
		{
			fscanf(fin, "%s", str);
			if (strcmp(str, "float") == 0)
			{
				fscanf(fin, "%s", str);
				if (strcmp(str, "nx") == 0 || strcmp(str, "ny") == 0 || strcmp(str, "nz") == 0)
				{
					isHasNormal = true;
				}
			}
		}
		else if (strcmp(str, "end_header") == 0)
		{
			break;
		}			
	}

	model.vertices_ = new double[model.nVertices_*3];

	if (isHasNormal)
	{
		model.normals_ = new double[model.nVertices_*3];
	}

	model.triangles_ = new unsigned int[nFaces*3];
	model.quads_ = new unsigned int[nFaces*4];


	model.nQuads_ = 0;
	model.nTriangles_ = 0;
	for (i=0 ; i<model.nVertices_ ; i++)
	{
		fscanf(fin, "%lf %lf %lf", &(model.vertices_[i*3]), &(model.vertices_[i*3+1]), &(model.vertices_[i*3+2]));

		if (isHasNormal)
		{
			fscanf(fin, "%lf %lf %lf", &(model.normals_[i*3]), &(model.normals_[i*3+1]), &(model.normals_[i*3+2]));
		}
	}
	while(fscanf(fin, "%d", &faceType) > 0)
	{
		switch(faceType)
		{
		case 3:
			fscanf(fin, "%d %d %d", &(model.triangles_[model.nTriangles_*3]), &(model.triangles_[model.nTriangles_*3+1]), &(model.triangles_[model.nTriangles_*3+2]));
			model.nTriangles_++;
			break;

		case 4:
			fscanf(fin, "%d %d %d %d", &(model.quads_[model.nQuads_*4]), &(model.quads_[model.nQuads_*4+1]), &(model.quads_[model.nQuads_*4+2]), &(model.quads_[model.nQuads_*4+3]));
			model.nQuads_++;
			break;
		}
	}

	fclose(fin);

}


void O3DFunctions::RecomputeTriangularMesh(O3DModel& model)
{
	int i;

	int nModifiedVertices;
	int nModifiedTriangles;
	double* modifiedVertices;
	double* modifiedNormals;
	unsigned int* modifiedTriangles;
	

	nModifiedTriangles = model.nTriangles_ + model.nQuads_ *2;
	nModifiedVertices = nModifiedTriangles * 3 ;
	modifiedVertices = new double[nModifiedVertices*3];
	modifiedNormals = new double[nModifiedVertices*3];
	modifiedTriangles = new unsigned int[nModifiedTriangles*3];

	OLAVector v1(3);
	OLAVector v2(3);
	OLAVector v3(3);
	OLAVector n(3);

	int c = 0;
	for (i=0 ; i<model.nTriangles_ ; i++)
	{
		v1 = &(model.vertices_[model.triangles_[i*3]*3]);
		v2 = &(model.vertices_[model.triangles_[i*3+1]*3]);
		v3 = &(model.vertices_[model.triangles_[i*3+2]*3]);
		memcpy(&(modifiedVertices[i*9]), v1.data_, 3*sizeof(double));
		memcpy(&(modifiedVertices[i*9 + 3]), v2.data_, 3*sizeof(double));
		memcpy(&(modifiedVertices[i*9 + 6]), v3.data_, 3*sizeof(double));
		v2 -= v1;
		v2 /= OLALinearAlgebra::Norm(v2);
		v3 -= v1;
		v3 /= OLALinearAlgebra::Norm(v3);
		OLALinearAlgebra::Cross3(v3, v2, n);
		n /= OLALinearAlgebra::Norm(n);
		memcpy(&(modifiedNormals[i*9]), n.data_, 3*sizeof(double));
		memcpy(&(modifiedNormals[i*9+3]), n.data_, 3*sizeof(double));
		memcpy(&(modifiedNormals[i*9+6]), n.data_, 3*sizeof(double));


		modifiedTriangles[i*3] = i*3;
		modifiedTriangles[i*3+1] = i*3+1;
		modifiedTriangles[i*3+2] = i*3+2;
	}


	for (i=0 ; i<model.nQuads_ ; i++)
	{
		v1 = &(model.vertices_[model.quads_[i*4]*3]);
		v2 = &(model.vertices_[model.quads_[i*4+1]*3]);
		v3 = &(model.vertices_[model.quads_[i*4+2]*3]);

		memcpy(&(modifiedVertices[model.nTriangles_*9 + i*18]), v1.data_, 3*sizeof(double));
		memcpy(&(modifiedVertices[model.nTriangles_*9 + i*18 + 3]), v2.data_, 3*sizeof(double));
		memcpy(&(modifiedVertices[model.nTriangles_*9 + i*18 + 6]), v3.data_, 3*sizeof(double));
		v2 -= v1;
		v2 /= OLALinearAlgebra::Norm(v2);
		v3 -= v1;
		v3 /= OLALinearAlgebra::Norm(v3);
		OLALinearAlgebra::Cross3(v3, v2, n);
		n /= OLALinearAlgebra::Norm(n);
		memcpy(&(modifiedNormals[model.nTriangles_*9 + i*18]), n.data_, 3*sizeof(double));
		memcpy(&(modifiedNormals[model.nTriangles_*9 + i*18 + 3]), n.data_, 3*sizeof(double));
		memcpy(&(modifiedNormals[model.nTriangles_*9 + i*18 + 6]), n.data_, 3*sizeof(double));


		modifiedTriangles[model.nTriangles_*3 + i*6] = model.nTriangles_*3 + i*6;
		modifiedTriangles[model.nTriangles_*3 + i*6+1] =model.nTriangles_*3 + i*6+1;
		modifiedTriangles[model.nTriangles_*3 + i*6+2] = model.nTriangles_*3 + i*6+2;

		v1 = &(model.vertices_[model.quads_[i*4]*3]);
		v2 = &(model.vertices_[model.quads_[i*4+2]*3]);
		v3 = &(model.vertices_[model.quads_[i*4+3]*3]);

		memcpy(&(modifiedVertices[model.nTriangles_*9 + i*18 + 9]), v1.data_, 3*sizeof(double));
		memcpy(&(modifiedVertices[model.nTriangles_*9 + i*18 + 12]), v2.data_, 3*sizeof(double));
		memcpy(&(modifiedVertices[model.nTriangles_*9 + i*18 + 15]), v3.data_, 3*sizeof(double));
		v2 -= v1;
		v2 /= OLALinearAlgebra::Norm(v2);
		v3 -= v1;
		v3 /= OLALinearAlgebra::Norm(v3);
		OLALinearAlgebra::Cross3(v3, v2, n);
		n /= OLALinearAlgebra::Norm(n);
		memcpy(&(modifiedNormals[model.nTriangles_*9 + i*18 + 9]), n.data_, 3*sizeof(double));
		memcpy(&(modifiedNormals[model.nTriangles_*9 + i*18 + 12]), n.data_, 3*sizeof(double));
		memcpy(&(modifiedNormals[model.nTriangles_*9 + i*18 + 15]), n.data_, 3*sizeof(double));


		modifiedTriangles[model.nTriangles_*3 + i*6+3] = model.nTriangles_*3 + i*6+3;
		modifiedTriangles[model.nTriangles_*3 + i*6+4] =model.nTriangles_*3 + i*6+4;
		modifiedTriangles[model.nTriangles_*3 + i*6+5] = model.nTriangles_*3 + i*6+5;

	}


	delete[] model.normals_;
	delete[] model.vertices_;
	delete[] model.triangles_;
	delete[] model.quads_;

	model.nVertices_ = nModifiedVertices;
	model.nTriangles_ = nModifiedTriangles;
	model.vertices_ = modifiedVertices;
	model.normals_ = modifiedNormals;
	model.triangles_ = modifiedTriangles;

	model.nQuads_ = 0;
	model.quads_ = NULL;

}



void O3DFunctions::SmoothNormals(O3DModel& model)
{
	int i;
	int iv1, iv2, iv3;
	OLAVector v1(3), v2(3), v3(3);
	OLAVector n(3);
	OLAVector* smoothedNormals;
	int*	   vertexReferenceCounts;

	smoothedNormals = new OLAVector[model.nVertices_];
	vertexReferenceCounts = new int[model.nVertices_];
	memset(vertexReferenceCounts, 0, model.nVertices_*sizeof(int));

	for (i=0 ; i<model.nVertices_ ; i++)
	{
		smoothedNormals[i].Resize(3);
	}


	for (i=0 ; i<model.nTriangles_ ; i++)
	{
		iv1 = model.triangles_[i*3];
		iv2 = model.triangles_[i*3+1];
		iv3 = model.triangles_[i*3+2];

		v1 = &(model.vertices_[iv1*3]);
		v2 = &(model.vertices_[iv2*3]);
		v3 = &(model.vertices_[iv3*3]);

		v2 -= v1;
		v2 /= OLALinearAlgebra::Norm(v2);
		v3 -= v1;
		v3 /= OLALinearAlgebra::Norm(v3);
		OLALinearAlgebra::Cross3(v3, v2, n);
		n /= OLALinearAlgebra::Norm(n);

		vertexReferenceCounts[iv1]++;
		vertexReferenceCounts[iv2]++;
		vertexReferenceCounts[iv3]++;
		smoothedNormals[iv1] += n;
		smoothedNormals[iv2] += n;
		smoothedNormals[iv3] += n;
	}


	for (i=0 ; i<model.nQuads_ ; i++)
	{
		iv1 = model.quads_[i*4];
		iv2 = model.quads_[i*4+1];
		iv3 = model.quads_[i*4+2];

		v1 = &(model.vertices_[iv1*3]);
		v2 = &(model.vertices_[iv2*3]);
		v3 = &(model.vertices_[iv3*3]);

		v2 -= v1;
		v2 /= OLALinearAlgebra::Norm(v2);
		v3 -= v1;
		v3 /= OLALinearAlgebra::Norm(v3);
		OLALinearAlgebra::Cross3(v3, v2, n);
		n /= OLALinearAlgebra::Norm(n);

		vertexReferenceCounts[iv1]++;
		vertexReferenceCounts[iv2]++;
		vertexReferenceCounts[iv3]++;
		smoothedNormals[iv1] += n;
		smoothedNormals[iv2] += n;
		smoothedNormals[iv3] += n;

		iv1 = model.quads_[i*4];
		iv2 = model.quads_[i*4+2];
		iv3 = model.quads_[i*4+3];

		v1 = &(model.vertices_[iv1*3]);
		v2 = &(model.vertices_[iv2*3]);
		v3 = &(model.vertices_[iv3*3]);

		v2 -= v1;
		v2 /= OLALinearAlgebra::Norm(v2);
		v3 -= v1;
		v3 /= OLALinearAlgebra::Norm(v3);
		OLALinearAlgebra::Cross3(v3, v2, n);
		n /= OLALinearAlgebra::Norm(n);

		vertexReferenceCounts[iv1]++;
		vertexReferenceCounts[iv2]++;
		vertexReferenceCounts[iv3]++;
		smoothedNormals[iv1] += n;
		smoothedNormals[iv2] += n;
		smoothedNormals[iv3] += n;

	}

	for (i=0 ; i<model.nVertices_ ; i++)
	{
		if (vertexReferenceCounts[i] > 0)
		{
			smoothedNormals[i] /= OLALinearAlgebra::Norm(smoothedNormals[i]);
			memcpy(&(model.normals_[i*3]), smoothedNormals[i].data_, 3*sizeof(double));
		}
		else
		{
			printf("Error vertex without face\n");
		}

	}

	delete[] smoothedNormals;
	delete[] vertexReferenceCounts;


}
