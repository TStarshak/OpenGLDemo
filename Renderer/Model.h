#pragma once

#include <vector>
#include <string>
#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>

#include "Mesh.h"
#include "Texture.h"

class Model
{
public:
	//Creates a new Model object
	Model();

	//Loads .obj files given the file path.
	void loadModel(const std::string& fileName);

	//Renders the model specified by loadModel()
	void renderModel();

	//Removes the .obj and data from the Model object
	void clearModel();

	//Deletes the Model object
	~Model();

private:

	void loadNode(aiNode *node, const aiScene *scene);
	void loadMesh(aiMesh *mesh, const aiScene *scene);

	//Loads materials use by the model
	void loadMaterials(const aiScene *scene);

	// a list of textures used when rendering the model
	std::vector<Mesh*> meshList;

	// a list of textures used when rendering the model
	std::vector<Texture*> textureList;


	std::vector<unsigned int> meshToTex;
};

