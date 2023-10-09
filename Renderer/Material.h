#pragma once

#include <GL\glew.h>

class Material
{
public:
	//public constructor
	Material();

	//public constructor
	Material(GLfloat sIntensity, GLfloat shine);

	//Binds this materials as the active materials
	void useMaterial(GLuint specularIntensityLocation, GLuint shininessLocation);

	//public deconstructor
	~Material();

private: 
	GLfloat specularIntensity;
	GLfloat shininess;
};

