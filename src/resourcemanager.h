#pragma once
#include <string>
#include <oxygine-framework.h>

using namespace std;
using namespace oxygine;

class ResourceManager
{
public:
	static ResourceManager& instance();
	
	void load(string path);
	ResAnim* getAnim(string tag);
	void free();

private:
	ResourceManager();
	Resources resources;

	static ResourceManager* selfInstance;
};