#pragma once
#include "Light.h"

class PointLight :
	public Light
{
public:
	//public constructor
	PointLight();
	
	//public constructor
	PointLight(GLfloat red, GLfloat green, GLfloat blue,
		GLfloat aIntensity, GLfloat dIntensity,
		GLfloat xPos, GLfloat yPos, GLfloat zPos,
		GLfloat con, GLfloat lin, GLfloat exp);
	
	//Specifies uniform variable values for this light
	void useLight(GLuint ambientIntensityLocation, GLuint ambientColorLocation,
		GLuint diffuseIntensityLocation, GLuint positionLocation,
		GLuint constantLocation, GLuint linearLocation, GLuint exponentLocation);
	
	//public deconstructor
	~PointLight();

protected:
	glm::vec3 position;

	GLfloat constant, linear, exponent;
};

