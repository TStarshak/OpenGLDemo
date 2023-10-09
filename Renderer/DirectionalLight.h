#pragma once
#include "Light.h"

class DirectionalLight :
	public Light
{
public:
	//Public constructor
	DirectionalLight();

	//Public constructor
	DirectionalLight(GLfloat red, GLfloat green, GLfloat blue, 
					GLfloat aIntensity, GLfloat dIntensity,
					GLfloat xDir, GLfloat yDir, GLfloat zDir);

	//Specifies uniform variable values for this light
	void useLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation,
		GLfloat diffuseIntensityLocation, GLfloat directionLocation);

	//public deconstructor
	~DirectionalLight();

private:
	glm::vec3 direction;
};

