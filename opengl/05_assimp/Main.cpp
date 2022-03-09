#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <string>
#include <iostream>
#include <vector>

void loadMode(std::string path);

void main() {
	std::string path = "C:/Users/Sparks/Downloads/project-release/PRD_T206580_001_AbsorberL.stl";
	std::string path2 = "C:/Users/Sparks/Downloads/project-release/PRD_T206580_001_AbsorberL.stp";
	loadMode(path2);
}


void loadMode(const std::string path) {
	Assimp::Importer import;

	const aiScene* scene = import.ReadFile(path, aiProcess_Triangulate);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
		std::cout << "Error::ASIMP: " << import.GetErrorString() << std::endl;
		return;
	}

}


