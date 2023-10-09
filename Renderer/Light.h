#pragma once
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <vector>

class Light
{
public:
	//public constructor
	Light() : Light::Light(1.0f, 1.0f, 1.0f, 1.0f, 1.0f) {};
	//public constructor
	Light(GLfloat red, GLfloat green, GLfloat blue,
		GLfloat aIntensity, GLfloat dIntensity) : Light::Light(glm::vec3(red, green, blue), aIntensity, dIntensity) {};
	//public constructor
	Light(glm::vec3 color,
		GLfloat aIntensity, GLfloat dIntensity);

	//public deconstructor
	~Light();

protected:
	//The color of the light
	glm::vec3 color;

	//the ambient intensity of the light
	GLfloat ambientIntensity;

	//the diffuse intensity of the light
	GLfloat diffuseIntensity;
};


