#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include <GL\glew.h>

#include "RendererConstants.h"

#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"

class Shader
{
public:
	Shader();

	//creates frag and vert shaders from strings
	void createFromString(const char* vertexCode, const char* fragmentCode);

	//creates frag and vert shaders from a specified file
	void createFromFiles(const char* vertexLocation, const char* fragmentLocation);

	//reads a file at specified location
	std::string readFile(const char* fileLocation);

	//Returns the location of the projection matrix uniform variable.
	GLuint getProjectionLocation();

	//Returns the location of the model matrix uniform variable.
	GLuint getModelLocation();

	//Returns the location of the view uniform variable.
	GLuint getViewLocation();

	//Returns the location of the ambient intensity uniform variable.
	GLuint getAmbientIntensityLocation();

	//Returns the location of the ambient color uniform variable.
	GLuint getAmbientColorLocation();

	//Returns the location of the diffuse intensity uniform variable.
	GLuint getDiffuseIntensityLocation();

	//Returns the location of the diffuse light direction uniform variable.
	GLuint getDirectionLocation();

	//Returns the location of the specular intensity uniform variable.
	GLuint getSpecularIntensityLocation();

	//Returns the location of the shininess (specular exponent) uniform variable.
	GLuint getShininessLocation();

	//Returns the location of the eye position uniform variable.
	GLuint getEyePositionLocation();

	//Sets a directional light for the shader
	void setDirectionalLight(DirectionalLight* dLight);

	//Sets a number of point lights for the shader
	void setPointLights(PointLight* pLight, unsigned int lightCount);

	//Sets a number of spot lights for the shader
	void setSpotLights(SpotLight* sLight, unsigned int lightCount);

	//Binds the shader as the active shader
	void useShader();

	//Removes shader data from this object
	void clearShader();

	//public deconstructor
	~Shader();

private:
	int pointLightCount;
	int spotLightCount;

	GLuint shaderID, uniformProjection, uniformModel, uniformView, uniformEyePosition,
		uniformSpecularIntensity, uniformShininess;

	struct {
		GLuint uniformColor;
		GLuint uniformAmbientIntensity;
		GLuint uniformDiffuseIntensity;

		GLuint uniformDirection;
	} uniformDirectionalLight;

	GLuint uniformPointLightCount;

	struct {
		GLuint uniformColor;
		GLuint uniformAmbientIntensity;
		GLuint uniformDiffuseIntensity;

		GLuint uniformPosition;
		GLuint uniformConstant;
		GLuint uniformLinear;
		GLuint uniformExponent;
	} uniformPointLight[constants::MAX_POINT_LIGHTS];

	GLuint uniformSpotLightCount;

	struct {
		GLuint uniformColor;
		GLuint uniformAmbientIntensity;
		GLuint uniformDiffuseIntensity;

		GLuint uniformPosition;
		GLuint uniformConstant;
		GLuint uniformLinear;
		GLuint uniformExponent;

		GLuint uniformDirection;
		GLuint uniformEdge;
	} uniformSpotLight[constants::MAX_SPOT_LIGHTS];

	void compileShader(const char* vertexCode, const char* fragmentCode);
	void addShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
};

