//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//



#ifndef _o3dmodel_h
#define _o3dmodel_h

class O3DModel {

public:
	friend class O3DFunctions;

	O3DModel();
	virtual ~O3DModel();
	virtual void SafeRelease();

	virtual void operator=(O3DModel& model);

	virtual void Read(char* fileName) {};

	void Render() const;

	void RecomputeTriangularMesh();
	void SmoothNormals();

	void SetMaterial(float* diffuse);
	
	virtual void Center();
	virtual void Scale(double s);

protected:
	int		nVertices_;
	double* vertices_;
	double* normals_;

	int		nTriangles_;
	unsigned int*	triangles_;

	int		nQuads_;
	unsigned int*	quads_;

	int		nMaterials_;
	float	ambient_[4];
	float	diffuse_[4];
};

#endif