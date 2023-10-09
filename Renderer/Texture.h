#pragma once

#include <GL\glew.h>
#include "stb_image.h"


class Texture
{
public:
	//Public default constructor
	Texture() : Texture("") {};

	//Public constructor that specifies the texture file location
	Texture(const char* fileLoc);

	//public deconstructor
	~Texture();

	//Loads an RGB texture from this Object's file location
	bool loadTexture();

	//Loads an RGBA texture from this Object's file location
	bool loadTextureA();

	//Binds this texture as the active texture. 
	void useTexture();

	//Removes texture information from this object
	void clearTexture();

private:
	GLuint textureID;
	int width, height, bitDepth;
	const char* fileLocation;
};

