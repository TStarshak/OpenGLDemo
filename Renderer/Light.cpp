#include "Light.h"

Light::Light(glm::vec3 lColor, GLfloat aIntensity, GLfloat dIntensity)
{
	color = lColor;
	ambientIntensity = aIntensity;
	diffuseIntensity = dIntensity;
}

Light::~Light()
{
}
