#include "TextureManager.h"

void TextureManager::LoadTexture(const std::string& name, const std::string& filePath)
{
	if (m_Textures.find(name) != m_Textures.end()) {
		throw std::runtime_error("Texture " + name + " is already Loaded!\n");
	}

	auto texture = std::make_shared<Texture>();
	texture->LoadTexture(filePath.c_str());
	m_Textures[name] = texture;
}

std::shared_ptr<Texture> TextureManager::GetTexture(const std::string& name)
{

	auto it = m_Textures.find(name);
	if (it == m_Textures.end()) {
		throw std::runtime_error("Texture with name '" + name + "' not found.");
	}

	// Note: it->second gets the second value from the unordered map<name, filepath> which is the filepath
	return it->second;
}
