#pragma once

#include <stdio.h>
#include <GL\glew.h>

class Mesh
{

public:
	//public constructor
	Mesh();

	//public deconstructor
	~Mesh();

	//creates a Mesh from a specified list of vertices and indices
	void createMesh(GLfloat *vertices, unsigned int *indices, unsigned int numOfVertices, unsigned int numOfIndices);
	
	//renders the Mesh from the data specified in createMesh
	void renderMesh();

	//removes data from the Mesh object
	void clearMesh();

private: 
	GLuint VAO, VBO, IBO;
	GLsizei indexCount;
};

