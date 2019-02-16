#pragma once

#include <string>
#include <GL/glew.h>
#include <filesystem>
#include "imgui.h"
#include "stb_image.hpp"

namespace st{
namespace utility{

class TexHandler{
public:

    static ImTextureID load(const std::string& path,
                            bool flip = true,
                            uint16_t stb_mode = STBI_rgb_alpha,
                            GLint minFilter = GL_LINEAR, 
                            GLint magFilter = GL_LINEAR)
    {
        using namespace std::filesystem;
        
        if(exists(path)){
            int width, height, channels;
            stbi_set_flip_vertically_on_load(flip);
            
            unsigned char *image = stbi_load(path.c_str(),
                                             &width,
                                             &height,
                                             &channels,
                                             stb_mode);
            GLuint textureId;
            
            glGenTextures(1, &textureId);
            glBindTexture(GL_TEXTURE_2D, textureId);
            
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
            
            if(channels == 4){
                glTexImage2D(GL_TEXTURE_2D, 
                             0, GL_RGBA, 
                             width, 
                             height, 
                             0, 
                             GL_RGBA, 
                             GL_UNSIGNED_BYTE, 
                             image);
            }else if(channels == 3){
                glTexImage2D(GL_TEXTURE_2D, 
                             0, 
                             GL_RGB, 
                             width, 
                             height, 
                             0, 
                             GL_RGB, 
                             GL_UNSIGNED_BYTE,
                             image);
                
            }else
                throw "undefined channels";
            
            
            stbi_image_free(image);
            
            return ImTextureID(textureId);
        }
        else
            throw "image file not found: " + path;
    }    
};
}
}
