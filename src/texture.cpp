#include "../include/texture.h"

TextureManager::Texture TextureManager::loadTexture(const std::string &path)
{
    const auto tex = textures.find(path);
    if (tex != textures.cend())
        return tex->second;

    Texture texture1;

    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        textures[path] = texture1;
    }
    else
    {
        std::cerr << "Failed to load texture" << std::endl;
        return 0;
    }
    stbi_image_free(data);

    return texture1;
}

void TextureManager::bindTexture(TextureManager::Texture t)
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, t);
}

void TextureManager::bindTextures(const std::vector<TextureManager::Texture> &ts)
{
    for (unsigned int i = 0; i < ts.size(); ++i)
    {
        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, ts[i]);
    }
}

TextureManager::TextureManager()
{

}
