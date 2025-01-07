#pragma once
#include "Texture.h"
#include <unordered_map>
#include <memory>

class TextureManager
{
public:

	static TextureManager& GetInstance() {
		static TextureManager instance;
		return instance;
	};

	void LoadTexture(const std::string& name, const std::string& filePath);

	std::shared_ptr<Texture> GetTexture(const std::string& name);
	
	void ClearTextures() { m_Textures.clear(); };

private:
	
	TextureManager() = default;
	TextureManager(const TextureManager&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;
	
	std::unordered_map<std::string, std::shared_ptr<Texture>> m_Textures;



};

