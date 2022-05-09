#pragma once
#include <string>

class Texture
{
private:
	unsigned int m_RendererID;
	std::string m_FilePath;
	int m_Width, m_Height, m_BPP;	// bit per pix
	unsigned char* m_LocalBuffer;

public:

	Texture(std::string filePath);
	~Texture();

	void Bind(const unsigned int slot=0) const;

	void Unbind() const;
};