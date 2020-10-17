#include "resourcemanager.h"

ResourceManager* ResourceManager::selfInstance = nullptr;

ResourceManager & ResourceManager::instance()
{
	if (!selfInstance)
		selfInstance = new ResourceManager();
	return *selfInstance;
}

ResourceManager::ResourceManager()
{
}

void ResourceManager::load(string path) {
	resources.loadXML(path);
}

ResAnim * ResourceManager::getAnim(string tag)
{
	return resources.getResAnim(tag);
}

void ResourceManager::free() {
	resources.free();
}