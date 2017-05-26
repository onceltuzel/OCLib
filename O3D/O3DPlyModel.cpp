//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "O3dPlyModel.h"
#include <stdio.h>
#include <string.h>

O3DPlyModel::O3DPlyModel() : O3DModel()
{
}

O3DPlyModel::~O3DPlyModel()
{
}


void O3DPlyModel::Read(char* fileName)
{
	FILE* fin;
	char str[256];

	int i, j;
	int  nFaces, faceType;

	fin = fopen(fileName,"r");


	while (1)
	{
		fscanf(fin, "%s", str);
		if (strcmp(str, "element") == 0)
		{
			fscanf(fin, "%s", str);
			if (strcmp(str, "vertex") == 0)
			{
				fscanf(fin, "%d", &nVertices_);
			} 
			else if (strcmp(str, "face") == 0)
			{
				fscanf(fin, "%d", &nFaces);
			}
			else if (strcmp(str, "material") == 0)
			{
				fscanf(fin, "%d", &nMaterials_);
			}			
		}
		else if (strcmp(str, "end_header") == 0)
		{
			break;
		}			
	}

	vertices_ = new double[nVertices_*3];
	normals_ = new double[nVertices_*3];

	triangles_ = new unsigned int[nFaces*3];
	quads_ = new unsigned int[nFaces*4];


	nQuads_ = 0;
	nTriangles_ = 0;
	for (i=0 ; i<nVertices_ ; i++)
	{
		fscanf(fin, "%lf %lf %lf", &(vertices_[i*3]), &(vertices_[i*3+1]), &(vertices_[i*3+2]));
		fscanf(fin, "%lf %lf %lf", &(normals_[i*3]), &(normals_[i*3+1]), &(normals_[i*3+2]));
		normals_[i*3] *=-1;		
		vertices_[i*3] *=-1;		
		
		/*
		normals_[i*3] *=-1;		
		normals_[i*3+1] *=-1;
		normals_[i*3+2] *=-1;
		*/
		/*
		double tmp = vertices_[i*3];
		vertices_[i*3] = vertices_[i*3+2];
		vertices_[i*3+2] = tmp;
		*/

	}
	for (i=0 ; i<nFaces ; i++)
	{
		fscanf(fin, "%d", &faceType);
		switch(faceType)
		{
		case 3:
			fscanf(fin, "%d %d %d", &(triangles_[nTriangles_*3]), &(triangles_[nTriangles_*3+1]), &(triangles_[nTriangles_*3+2]));
			nTriangles_++;
			break;
		case 4:
			fscanf(fin, "%d %d %d %d", &(quads_[nQuads_*4]), &(quads_[nQuads_*4+1]), &(quads_[nQuads_*4+2]), &(quads_[nQuads_*4+3]));
			nQuads_++;
			break;
		}
	}

	for (i=0 ; i<nMaterials_ ; i++)
	{
		for (j=0 ; j<4 ; j++)
		{
			fscanf(fin, "%f", &(ambient_[j]));
			ambient_[j] /= 255;
		}
		for (j=0 ; j<4 ; j++)
		{
			fscanf(fin, "%f", &(diffuse_[j]));
			diffuse_[j] /= 255;
		}

	}

/*
	while(fscanf(fin, "%d", &faceType) > 0)
	{
		switch(faceType)
		{
		case 3:
			fscanf(fin, "%d %d %d", &(triangles_[nTriangles_*3]), &(triangles_[nTriangles_*3+1]), &(triangles_[nTriangles_*3+2]));
			nTriangles_++;
			break;
		case 4:
			fscanf(fin, "%d %d %d %d", &(quads_[nQuads_*4]), &(quads_[nQuads_*4+1]), &(quads_[nQuads_*4+2]), &(quads_[nQuads_*4+3]));
			nQuads_++;
			break;
		}
	}
*/

	fclose(fin);

}

