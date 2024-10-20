#pragma once

#include <unordered_map>
#include <memory>
#include <string>

#include "Texture.h"
#include "ShaderProgram.h"

// namespace Engine {
//     class ResourceManager {
//         public:
//             static ResourceManager& getInstance() {
//                 static ResourceManager instance;
//                 return instance;
//             }

//             std::shared_ptr<Texture> getTexture(const std::string& key) {
//                 auto it = textures.find(key);
//                 if (it != textures.end()) {
//                     return it->second;
//                 }
//                 return nullptr; // or create & return a default texture
//             }

//             std::shared_ptr<ShaderProgram> getShader(const std::string& key) {
//                 auto it = shaders.find(key);
//                 if (it != shaders.end()) {
//                     return it->second;
//                 }
//                 return nullptr; // or create & return a default shader
//             }

//             void addTexture(const std::string& key, std::shared_ptr<Texture> texture) {
//                 textures[key] = texture;
//             }

//             void addShader(const std::string& key, std::shared_ptr<ShaderProgram> shader) {
//                 shaders[key] = shader;
//             }

//         private:
//             ResourceManager() = default;
//             ~ResourceManager() = default;
//             ResourceManager(const ResourceManager&) = delete;
//             ResourceManager& operator=(const ResourceManager&) = delete;

//             std::unordered_map<std::string, std::shared_ptr<Texture>> textures;
//             std::unordered_map<std::string, std::shared_ptr<ShaderProgram>> shaders;
//     };
// }

