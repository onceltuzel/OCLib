//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//



#ifndef _o3drenderer_h
#define _o3drenderer_h

#include "O3DModel.h"
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

class O3DRenderer
{
private:
	GLuint m_ListObject;

public:
	O3DRenderer();
	~O3DRenderer();

	// for multiple rendering
	void Init(const O3DModel& model);
	void Render();

	// for one-time rendering
	static void Render(const O3DModel& model);

};

#endif