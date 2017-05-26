//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "O3DMyPlyModel.h"
#include <stdio.h>
#include <string.h>

O3DMyPlyModel::O3DMyPlyModel() : O3DModel()
{
}

O3DMyPlyModel::~O3DMyPlyModel()
{
}



void O3DMyPlyModel::Read(char* fileName)
{
	FILE* fin;
	char str[256];

	int i;
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
		//normals_[i*3] *=-1;		
		//vertices_[i*3] *=-1;		
		
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
	while(fscanf(fin, "%d", &faceType) > 0)
	{
		switch(faceType)
		{
		case 3:
			fscanf(fin, "%d %d %d", &(triangles_[nTriangles_*3]), &(triangles_[nTriangles_*3+1]), &(triangles_[nTriangles_*3+2]));
			nTriangles_++;
			break;
		case 4:
			/*
			int v1, v2, v3, v4;
			fscanf(fin, "%d %d %d %d", &v1, &v2, &v3, &v4);
			triangles_[nTriangles_*3] = v1;
			triangles_[nTriangles_*3+1] = v2;
			triangles_[nTriangles_*3+2] = v3;
			nTriangles_++;
			triangles_[nTriangles_*3] = v3;
			triangles_[nTriangles_*3+1] = v4;
			triangles_[nTriangles_*3+2] = v1;
			nTriangles_++;
			*/
			fscanf(fin, "%d %d %d %d", &(quads_[nQuads_*4]), &(quads_[nQuads_*4+1]), &(quads_[nQuads_*4+2]), &(quads_[nQuads_*4+3]));
			nQuads_++;
			break;
		}

	}


	fclose(fin);

}


