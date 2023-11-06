#include "TextureContainer.h"

#include <stdexcept>

namespace Engine {
    void TextureContainer::pushBack (std::shared_ptr<Texture> texture) {
        this->cont.push_back(texture);
    }
    std::shared_ptr<Texture> TextureContainer::get (GLuint id) {
        try {
            return this->cont.at(id);
        } catch (const std::out_of_range& oor) {
            return nullptr;
        }
    }
    bool TextureContainer::contains (GLuint id) {
        try {
            this->cont.at(id);
            return true;
        } catch (const std::out_of_range& oor) {
            return false;
        }
    }
}
