//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "O3DRenderer.h"


O3DRenderer::O3DRenderer() : m_ListObject(0)
{
}

O3DRenderer::~O3DRenderer()
{
	if (m_ListObject)
	{
		glDeleteLists(m_ListObject, 1);
		m_ListObject = 0;
	}
}

void
O3DRenderer::Init(const O3DModel& model)
{
	if (m_ListObject)
	{
		glDeleteLists(m_ListObject, 1);
		m_ListObject = 0;
	}

	m_ListObject = glGenLists(1);

	// create object list
	glNewList(m_ListObject, GL_COMPILE);
	{
		Render(model);
	}
	glEndList();
}


void
O3DRenderer::Render()
{
	glCallList(m_ListObject);
}

void
O3DRenderer::Render(const O3DModel &model)
{
	model.Render();

	/*
	if (model.nMaterials_)
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, model.ambient_);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, model.diffuse_);
	}

	glPushMatrix();
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	glVertexPointer(3, GL_DOUBLE, 0, model.vertices_);
	glNormalPointer(GL_DOUBLE, 0, model.normals_);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDrawElements(GL_TRIANGLES, model.nTriangles_*3, GL_UNSIGNED_INT, model.triangles_);
	glDrawElements(GL_QUADS, model.nQuads_*4, GL_UNSIGNED_INT, model.quads_);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glPopMatrix();
	*/

}


