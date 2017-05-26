//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "O3DModel.h"
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <OLA/OLALinearAlgebra.h>

O3DModel::O3DModel()
{
	nVertices_ = 0;
	vertices_ = NULL;
	normals_ = NULL;

	nTriangles_ = 0;
	triangles_ = NULL;

	nQuads_ = 0;
	quads_ = NULL;

	nMaterials_ = 0;
	memset(ambient_, 0, sizeof(float)*4);
	memset(diffuse_, 0, sizeof(float)*4);
}

O3DModel::~O3DModel()
{
	SafeRelease();
}



void O3DModel::SafeRelease()
{
	if (vertices_)
		delete[] vertices_;
	vertices_ = NULL;

	if (normals_)
		delete[] normals_;
	normals_ = NULL;

	if (triangles_)
		delete[] triangles_;
	triangles_ = NULL;

	if (quads_)
		delete[] quads_;
	quads_ = NULL;

	nVertices_ = 0;
	nTriangles_ = 0;
	nQuads_ = 0;
}


void O3DModel::Center()
{
	int i, j;
	double max, min, val;
	double* vertices;

	for (i=0 ; i<3; i++)
	{
		max = -1e+10;
		min = 1e+10;
		vertices = &(vertices_[i]);
		for (j=0 ; j<nVertices_ ; j++)
		{
			if (vertices[j*3] > max)
				max = vertices[j*3];
			if (vertices[j*3] < min)
				min = vertices[j*3];
		}
		val = (max + min)/2;
		for (j=0 ; j<nVertices_ ; j++)
		{
			vertices[j*3] -= val;
		}
	}

}

void O3DModel::Scale(double s)
{
	int i;
	for (i=0 ; i<3*nVertices_; i++)
	{
		vertices_[i] *= s;
	}
}



void O3DModel::Render() const
{
	/*
	glEnable(GL_LIGHTING);
	GLfloat colorcar[]={.9,.9,.1};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE,colorcar);
	glTranslatef(0,0,-20);
	glTranslatef(0,0,-20);
	*/

	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);

	if (nMaterials_)
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_);
	}

	glPushMatrix();
	glEnableClientState(GL_VERTEX_ARRAY);

	if (normals_)
	{
		glEnableClientState(GL_NORMAL_ARRAY);
	}

	glVertexPointer(3, GL_DOUBLE, 0, vertices_);
	if (normals_)
	{
		glNormalPointer(GL_DOUBLE, 0, normals_);
	}

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	if (nTriangles_ > 0)
	{
		glDrawElements(GL_TRIANGLES, nTriangles_*3, GL_UNSIGNED_INT, triangles_);
	}
	if (nQuads_ > 0)
	{
		glDrawElements(GL_QUADS, nQuads_*4, GL_UNSIGNED_INT, quads_);
	}

	glDisableClientState(GL_VERTEX_ARRAY);

	if (normals_)
	{
		glDisableClientState(GL_NORMAL_ARRAY);
	}

	glPopMatrix();

}


void O3DModel::RecomputeTriangularMesh()
{
	int i;

	int nModifiedVertices;
	int nModifiedTriangles;
	double* modifiedVertices;
	double* modifiedNormals;
	unsigned int* modifiedTriangles;
	

	nModifiedTriangles = nTriangles_ + nQuads_ *2;
	nModifiedVertices = nModifiedTriangles * 3 ;
	modifiedVertices = new double[nModifiedVertices*3];
	modifiedNormals = new double[nModifiedVertices*3];
	modifiedTriangles = new unsigned int[nModifiedTriangles*3];

	OLAVector v1(3);
	OLAVector v2(3);
	OLAVector v3(3);
	OLAVector n(3);

	int c = 0;
	for (i=0 ; i<nTriangles_ ; i++)
	{
		v1 = &(vertices_[triangles_[i*3]*3]);
		v2 = &(vertices_[triangles_[i*3+1]*3]);
		v3 = &(vertices_[triangles_[i*3+2]*3]);
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


	for (i=0 ; i<nQuads_ ; i++)
	{
		v1 = &(vertices_[quads_[i*4]*3]);
		v2 = &(vertices_[quads_[i*4+1]*3]);
		v3 = &(vertices_[quads_[i*4+2]*3]);

		memcpy(&(modifiedVertices[nTriangles_*9 + i*18]), v1.data_, 3*sizeof(double));
		memcpy(&(modifiedVertices[nTriangles_*9 + i*18 + 3]), v2.data_, 3*sizeof(double));
		memcpy(&(modifiedVertices[nTriangles_*9 + i*18 + 6]), v3.data_, 3*sizeof(double));
		v2 -= v1;
		v2 /= OLALinearAlgebra::Norm(v2);
		v3 -= v1;
		v3 /= OLALinearAlgebra::Norm(v3);
		OLALinearAlgebra::Cross3(v3, v2, n);
		n /= OLALinearAlgebra::Norm(n);
		memcpy(&(modifiedNormals[nTriangles_*9 + i*18]), n.data_, 3*sizeof(double));
		memcpy(&(modifiedNormals[nTriangles_*9 + i*18 + 3]), n.data_, 3*sizeof(double));
		memcpy(&(modifiedNormals[nTriangles_*9 + i*18 + 6]), n.data_, 3*sizeof(double));


		modifiedTriangles[nTriangles_*3 + i*6] = nTriangles_*3 + i*6;
		modifiedTriangles[nTriangles_*3 + i*6+1] =nTriangles_*3 + i*6+1;
		modifiedTriangles[nTriangles_*3 + i*6+2] = nTriangles_*3 + i*6+2;

		v1 = &(vertices_[quads_[i*4]*3]);
		v2 = &(vertices_[quads_[i*4+2]*3]);
		v3 = &(vertices_[quads_[i*4+3]*3]);

		memcpy(&(modifiedVertices[nTriangles_*9 + i*18 + 9]), v1.data_, 3*sizeof(double));
		memcpy(&(modifiedVertices[nTriangles_*9 + i*18 + 12]), v2.data_, 3*sizeof(double));
		memcpy(&(modifiedVertices[nTriangles_*9 + i*18 + 15]), v3.data_, 3*sizeof(double));
		v2 -= v1;
		v2 /= OLALinearAlgebra::Norm(v2);
		v3 -= v1;
		v3 /= OLALinearAlgebra::Norm(v3);
		OLALinearAlgebra::Cross3(v3, v2, n);
		n /= OLALinearAlgebra::Norm(n);
		memcpy(&(modifiedNormals[nTriangles_*9 + i*18 + 9]), n.data_, 3*sizeof(double));
		memcpy(&(modifiedNormals[nTriangles_*9 + i*18 + 12]), n.data_, 3*sizeof(double));
		memcpy(&(modifiedNormals[nTriangles_*9 + i*18 + 15]), n.data_, 3*sizeof(double));


		modifiedTriangles[nTriangles_*3 + i*6+3] = nTriangles_*3 + i*6+3;
		modifiedTriangles[nTriangles_*3 + i*6+4] =nTriangles_*3 + i*6+4;
		modifiedTriangles[nTriangles_*3 + i*6+5] = nTriangles_*3 + i*6+5;

	}


	delete[] normals_;
	delete[] vertices_;
	delete[] triangles_;
	delete[] quads_;

	nVertices_ = nModifiedVertices;
	nTriangles_ = nModifiedTriangles;
	vertices_ = modifiedVertices;
	normals_ = modifiedNormals;
	triangles_ = modifiedTriangles;

	nQuads_ = 0;
	quads_ = NULL;

}

void O3DModel::SmoothNormals()
{
	int i;
	int iv1, iv2, iv3;
	OLAVector v1(3), v2(3), v3(3);
	OLAVector n(3);
	OLAVector* smoothedNormals;
	int*	   vertexReferenceCounts;

	smoothedNormals = new OLAVector[nVertices_];
	vertexReferenceCounts = new int[nVertices_];
	memset(vertexReferenceCounts, 0, nVertices_*sizeof(int));

	for (i=0 ; i<nVertices_ ; i++)
	{
		smoothedNormals[i].Resize(3);
	}


	for (i=0 ; i<nTriangles_ ; i++)
	{
		iv1 = triangles_[i*3];
		iv2 = triangles_[i*3+1];
		iv3 = triangles_[i*3+2];

		v1 = &(vertices_[iv1*3]);
		v2 = &(vertices_[iv2*3]);
		v3 = &(vertices_[iv3*3]);

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


	for (i=0 ; i<nQuads_ ; i++)
	{
		iv1 = quads_[i*4];
		iv2 = quads_[i*4+1];
		iv3 = quads_[i*4+2];

		v1 = &(vertices_[iv1*3]);
		v2 = &(vertices_[iv2*3]);
		v3 = &(vertices_[iv3*3]);

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

		iv1 = quads_[i*4];
		iv2 = quads_[i*4+2];
		iv3 = quads_[i*4+3];

		v1 = &(vertices_[iv1*3]);
		v2 = &(vertices_[iv2*3]);
		v3 = &(vertices_[iv3*3]);

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

	for (i=0 ; i<nVertices_ ; i++)
	{
		if (vertexReferenceCounts[i] > 0)
		{
			smoothedNormals[i] /= OLALinearAlgebra::Norm(smoothedNormals[i]);
			memcpy(&(normals_[i*3]), smoothedNormals[i].data_, 3*sizeof(double));
		}
		else
		{
			printf("Error vertex without face\n");
		}

	}

	delete[] smoothedNormals;
	delete[] vertexReferenceCounts;

}


void O3DModel::SetMaterial(float* diffuse)
{
	nMaterials_ = 1;
	memcpy(diffuse_, diffuse, sizeof(float)*4);
}


void O3DModel::operator=(O3DModel& model)
{
	SafeRelease();

	nVertices_ = model.nVertices_;

	if (model.nVertices_ > 0 && model.vertices_)
	{
		vertices_ = new double[nVertices_*3];
		memcpy(vertices_, model.vertices_, sizeof(double)*3*nVertices_);
	}

	if (model.nVertices_ > 0 && model.normals_)
	{
		normals_ = new double[nVertices_*3];
		memcpy(normals_, model.normals_, sizeof(double)*3*nVertices_);
	}

	nTriangles_ = model.nTriangles_;

	if (model.nTriangles_ > 0 && model.triangles_)
	{
		triangles_ = new unsigned int[nTriangles_*3];
		memcpy(triangles_, model.triangles_, sizeof(unsigned int)*3*nTriangles_);
	}

	nQuads_ = model.nQuads_;

	if (model.nQuads_ > 0 && model.quads_)
	{
		quads_ = new unsigned int[nQuads_*4];
		memcpy(quads_, model.quads_, sizeof(unsigned int)*4*nQuads_);
	}

	nMaterials_ = model.nMaterials_;
	memcpy(ambient_, model.ambient_, 4*sizeof(float));
	memcpy(diffuse_, model.diffuse_, 4*sizeof(float));
}

