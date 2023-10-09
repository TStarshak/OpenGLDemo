#pragma once
#include "PointLight.h"
class SpotLight :
	public PointLight
{
public:
	//public constructor
	SpotLight();

	//public constructor
	SpotLight(GLfloat red, GLfloat green, GLfloat blue,
		GLfloat aIntensity, GLfloat dIntensity,
		GLfloat xPos, GLfloat yPos, GLfloat zPos,
		GLfloat xDir, GLfloat yDir, GLfloat zDir,
		GLfloat con, GLfloat lin, GLfloat exp,
		GLfloat edg);

	//Specifies uniform variable values for this light
	void useLight(GLuint ambientIntensityLocation, GLuint ambientColorLocation,
		GLuint diffuseIntensityLocation, GLuint positionLocation, GLuint directionLocation,
		GLuint constantLocation, GLuint linearLocation, GLuint exponentLocation,
		GLuint edgeLocation);

	//Sets the position and direction of this spotlight
	void setFlash(glm::vec3 pos, glm::vec3 dir);

	//public deconstructor
	~SpotLight();

private:
	glm::vec3 direction;

	GLfloat edge, procEdge;
};

