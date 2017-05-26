//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//

#include "O3DShadowedModel.h"
#include "OLA/OLAVector.h"
#include "OLA/OLAFunctions.h"
#include "OLA/OLALinearAlgebra.h"
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>

O3DShadowedModel::O3DShadowedModel() : O3DModel()
{
	nPlanes_ = 0;
	planeEqn_ = NULL;
	visible_ = NULL;
	neigh_ = NULL;
}

O3DShadowedModel::~O3DShadowedModel()
{
	SafeRelease();
}


void O3DShadowedModel::SafeRelease()
{
	O3DModel::SafeRelease();

	if(planeEqn_)
		delete [] planeEqn_;
	if (visible_)
		delete [] visible_;
	if(neigh_)
		delete [] neigh_;

	planeEqn_ = NULL;
	visible_ = NULL;
	neigh_ = NULL;
}


void O3DShadowedModel::Center()
{
	double minx = 1e10;
	double maxx = -1e10;
	double miny = 1e10;
	double maxy = -1e10;
	double minz = 1e10;
	double maxz = -1e10;

	double x,y,z;
	for(unsigned int i=0;i<(unsigned int)nVertices_;i++)
	{
		x = vertices_[3*i];
		y = vertices_[3*i+1];
		z = vertices_[3*i+2];

		if( x>maxx )
			maxx = x;
		if( x<minx )
			minx = x;

		if( y>maxy )
			maxy = y;
		if( y<miny )
			miny = y;

		if( z>maxz )
			maxz = z;
		if( z<minz )
			minz = z;
	}

	double cx = (maxx+minx)/2;
	double cy = (maxy+miny)/2;
	double cz = (maxz+minz)/2;

	for(unsigned int i=0;i<(unsigned int)nVertices_;i++)
	{
		vertices_[3*i] -= cx;;
		vertices_[3*i+1] -= cy;
		vertices_[3*i+2] -= cz;
	}

	maxx = (maxx-minx)/2;
	maxy = (maxy-miny)/2;
	maxz = (maxz-minz)/2;
	minx = -maxx;
	miny = -maxy;
	minz = -maxz;

	/*
	std::cout<<"max X = "<<maxx<<", min X = "<<minx<<std::endl;
	std::cout<<"max Y = "<<maxy<<", min Y = "<<miny<<std::endl;
	std::cout<<"max Z = "<<maxz<<", min Z = "<<minz<<std::endl;
	*/
}


#if 0

void O3DShadowedModel::Read(const char* fileName)
{
	SafeRelease();
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


	fclose(fin);

}

#endif



void O3DShadowedModel::ComputePlaneEquations()
{
//	std::cout<<"[MODEL] Compute Plane Equations"<<std::endl;

	nPlanes_ = nTriangles_;
	planeEqn_ = new double [4*nTriangles_];
	visible_ = new unsigned int [nTriangles_];

	unsigned int v0,v1,v2;
	for(unsigned int i=0;i<nPlanes_;i++)
	{
		v0 = triangles_[3*i];
		v1 = triangles_[3*i+1];
		v2 = triangles_[3*i+2];

		planeEqn_[4*i] = 
			vertices_[3*v0+1]*( vertices_[3*v1+2] - vertices_[3*v2+2] ) +
			vertices_[3*v1+1]*( vertices_[3*v2+2] - vertices_[3*v0+2] ) +
			vertices_[3*v2+1]*( vertices_[3*v0+2] - vertices_[3*v1+2] );

		planeEqn_[4*i+1] = 
			vertices_[3*v0+2]*( vertices_[3*v1+0] - vertices_[3*v2+0] ) +
			vertices_[3*v1+2]*( vertices_[3*v2+0] - vertices_[3*v0+0] ) +
			vertices_[3*v2+2]*( vertices_[3*v0+0] - vertices_[3*v1+0] );

		planeEqn_[4*i+2] = 
			vertices_[3*v0+0]*( vertices_[3*v1+1] - vertices_[3*v2+1] ) +
			vertices_[3*v1+0]*( vertices_[3*v2+1] - vertices_[3*v0+1] ) +
			vertices_[3*v2+0]*( vertices_[3*v0+1] - vertices_[3*v1+1] );

		planeEqn_[4*i+3] = -(
			vertices_[3*v0+0]*( vertices_[3*v1+1]*vertices_[3*v2+2] - vertices_[3*v2+1]*vertices_[3*v1+2] ) +
			vertices_[3*v1+0]*( vertices_[3*v2+1]*vertices_[3*v0+2] - vertices_[3*v0+1]*vertices_[3*v2+2] ) +
			vertices_[3*v2+0]*( vertices_[3*v0+1]*vertices_[3*v1+2] - vertices_[3*v1+1]*vertices_[3*v0+2] ) );
	}




}


void O3DShadowedModel::SetConnectivity()
{
//	std::cout<<"[MODEL] Set Connectivity"<<std::endl;

	unsigned int p1i, p2i, p1j, p2j;
	unsigned int P1i, P2i, P1j, P2j;
	unsigned int i,j,ki,kj;
	neigh_ = new unsigned int [3*nTriangles_];
	memset(neigh_,0,sizeof(unsigned int)*3*nTriangles_);
	for(i=0;i<nTriangles_-1;i++)
	{
		for(j=i+1;j<nTriangles_;j++)
		{
			for(ki=0;ki<3;ki++)
			{
				if(!neigh_[3*i+ki])
				{
					for(kj=0;kj<3;kj++)
					{
						p1i=ki;
						p1j=kj;
						p2i=(ki+1)%3;
						p2j=(kj+1)%3;

						//p1i=o->planes[i].p[p1i];
						//p2i=o->planes[i].p[p2i];
						//p1j=o->planes[j].p[p1j];
						//p2j=o->planes[j].p[p2j];

						// extract vertices from the triangle
						p1i = triangles_[3*i+p1i];
						p2i = triangles_[3*i+p2i];
						p1j = triangles_[3*j+p1j];
						p2j = triangles_[3*j+p2j];


						P1i= ( (p1i+p2i) - abs(int(p1i)- int(p2i)))/2;
						P2i= ( (p1i+p2i) + abs(int(p1i)- int(p2i)))/2;
						P1j= ( (p1j+p2j) - abs(int(p1j)- int(p2j)))/2;
						P2j= ( (p1j+p2j) + abs(int(p1j)- int(p2j)))/2;

						if(  ((p1i==p1j) && (p2i==p2j)) ||  ((p1i==p2j) && (p2i==p1j)) )
						{  
							//they are neighbours
							//o->planes[i].neigh[ki] = j+1;	  
							//o->planes[j].neigh[kj] = i+1;	  
							neigh_[3*i+ki] = j+1;
							neigh_[3*j+kj] = i+1;
						}
					}
				}
			}
		}
	}
}



void O3DShadowedModel::CastShadow(double *lp)
{


	//check visibility
	double side;
	for(int i=0;i<nTriangles_;i++)
	{
		side = 0;
		for(int k=0;k<4;k++)
			side +=  planeEqn_[4*i+k]*lp[k];

		if( side > 0)
			visible_[i] = 1;
		else
			visible_[i] = 0;
	}


	glPushAttrib( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_ENABLE_BIT | GL_POLYGON_BIT | GL_STENCIL_BUFFER_BIT );
	glDisable( GL_LIGHTING );					// Turn Off Lighting

	glColorMask( GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE );	// Don't Draw Into The Colour Buffer
	glDepthMask( GL_FALSE );								// Turn Off Writing To The Depth-Buffer
	glEnable(GL_STENCIL_TEST);					// Turn On Stencil Buffer Testing
	
	
	// first pass, stencil operation decreases stencil value
	glFrontFace(GL_CCW);
	glStencilOp(GL_KEEP, GL_KEEP, GL_INCR);

	unsigned int p1,p2,jj;
	OLAVector v1(3),v2(3);
	int infinity = 100000000;
	for (unsigned int i=0; i<nPlanes_;i++)
	{
		if(visible_[i])
		{
			for (unsigned int j=0;j<3;j++)
			{				
				//k = o->planes[i].neigh[j];
				unsigned int k;
				k = neigh_[3*i+j];

				//if ((!k) || (!o->planes[k-1].visible))
				if( !k || !visible_[k-1] )
				{
					// here we have an edge, we must draw a polygon
					p1 = triangles_[3*i+j];
					jj = (j+1)%3;
					p2 = triangles_[3*i+jj];

					//calculate the length of the vector
					for(int dummy=0;dummy<3;dummy++)
					{
						v1(dummy) = (vertices_[3*p1+dummy] - lp[dummy])*infinity;
						v2(dummy) = (vertices_[3*p2+dummy] - lp[dummy])*infinity;
					}

					
					//draw the polygon					
					glBegin(GL_TRIANGLE_STRIP);
						glVertex3d(vertices_[3*p1],vertices_[3*p1+1],vertices_[3*p1+2]);
						glVertex3d( vertices_[3*p1  ] + v1(0),
									vertices_[3*p1+1] + v1(1),
									vertices_[3*p1+2] + v1(2) );

						glVertex3d(vertices_[3*p2],vertices_[3*p2+1],vertices_[3*p2+2]);
						glVertex3d( vertices_[3*p2  ] + v2(0),
									vertices_[3*p2+1] + v2(1),
									vertices_[3*p2+2] + v2(2) );
					glEnd();

				}
			}
		}
	}

	// second pass, stencil operation increases stencil value
	glFrontFace(GL_CW);
	glStencilOp(GL_KEEP, GL_KEEP, GL_DECR);

	for (unsigned int i=0; i<nPlanes_;i++)
	{
		//if (o->planes[i].visible)
		if( visible_[i] )
		{
			for (unsigned int j=0;j<3;j++)
			{
				//k = o->planes[i].neigh[j];
				unsigned int k = neigh_[3*i+j];

				if ( !k || !visible_[k-1])
				{
					// here we have an edge, we must draw a polygon
					p1 = triangles_[3*i+j];
					jj = (j+1)%3;
					p2 = triangles_[3*i+jj];

					//calculate the length of the vector
					for(int dummy=0;dummy<3;dummy++)
					{
						v1(dummy) = (vertices_[3*p1+dummy] - lp[dummy])*infinity;
						v2(dummy) = (vertices_[3*p2+dummy] - lp[dummy])*infinity;
					}

					//draw the polygon					
					glBegin(GL_TRIANGLE_STRIP);
						glVertex3d(vertices_[3*p1],vertices_[3*p1+1],vertices_[3*p1+2]);
						glVertex3d( vertices_[3*p1  ] + v1(0),
									vertices_[3*p1+1] + v1(1),
									vertices_[3*p1+2] + v1(2) );

						glVertex3d(vertices_[3*p2],vertices_[3*p2+1],vertices_[3*p2+2]);
						glVertex3d( vertices_[3*p2  ] + v2(0),
									vertices_[3*p2+1] + v2(1),
									vertices_[3*p2+2] + v2(2) );
					glEnd();
				}
			}
		}
	}
	glFrontFace(GL_CCW);
	glDisable(GL_CULL_FACE);
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);

	//draw a shadowing rectangle covering the entire screen
	glColor4f(0.0f, 0.0f, 0.0f, 0.4f);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glStencilFunc(GL_NOTEQUAL, 0, 0xffffffff);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
	glPushMatrix();
	glLoadIdentity();
	glBegin(GL_QUADS);
		glVertex3f(-1000.0f, -1000.0f,-110.0f);
		glVertex3f(-1000.0f,1000.0f,-110.0f);
		glVertex3f( 1000.0f, 1000.0f,-110.0f);
		glVertex3f( 1000.0f,-1000.0f,-110.0f);
	glEnd();
	glPopMatrix();
	glPopAttrib();
	glDisable(GL_BLEND);
	glDepthFunc(GL_LEQUAL);
	glDepthMask(GL_TRUE);
	glDisable(GL_STENCIL_TEST);
	glShadeModel(GL_SMOOTH);

}

