#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <iostream>
#include <vector>
#include <glad/glad.h>
#include "lib/stb_image/stb_image.h"
#include <unordered_map>

class TextureManager
{
public:
    using Texture = unsigned int;

    Texture loadTexture(const std::string & path);
    void bindTexture(Texture t);
    void bindTextures(const std::vector<Texture> & ts);


    TextureManager();

private:
    std::unordered_map<std::string, Texture> textures;
};

#endif // TEXTUREMANAGER_H
