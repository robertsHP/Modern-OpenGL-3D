#include "Engine.h"

int main(int argc, char* argv[]) {
    Engine::start();
    return 0;
}


// #include <SDL.h>
// #include <SDL_image.h>
// #include <iostream>

// // Screen dimension constants
// const int SCREEN_WIDTH = 640;
// const int SCREEN_HEIGHT = 480;

// bool init(SDL_Window*& window, SDL_Renderer*& renderer);
// bool loadMedia(SDL_Texture*& texture, SDL_Renderer* renderer);
// void close(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture);

// int main(int argc, char* args[])
// {
//     SDL_Window* window = nullptr;
//     SDL_Renderer* renderer = nullptr;
//     SDL_Texture* texture = nullptr;

//     // Initialize SDL
//     if (!init(window, renderer))
//     {
//         std::cout << "Failed to initialize!\n";
//     }
//     else
//     {
//         // Load media
//         if (!loadMedia(texture, renderer))
//         {
//             std::cout << "Failed to load media!\n";
//         }
//         else
//         {
//             // Main loop flag
//             bool quit = false;

//             // Event handler
//             SDL_Event e;

//             // While application is running
//             while (!quit)
//             {
//                 // Handle events on queue
//                 while (SDL_PollEvent(&e) != 0)
//                 {
//                     // User requests quit
//                     if (e.type == SDL_QUIT)
//                     {
//                         quit = true;
//                     }
//                 }

//                 // Clear screen
//                 SDL_RenderClear(renderer);

//                 // Render texture to screen
//                 SDL_RenderCopy(renderer, texture, nullptr, nullptr);

//                 // Update screen
//                 SDL_RenderPresent(renderer);
//             }
//         }
//     }

//     // Free resources and close SDL
//     close(window, renderer, texture);

//     return 0;
// }

// bool init(SDL_Window*& window, SDL_Renderer*& renderer)
// {
//     // Initialize SDL
//     if (SDL_Init(SDL_INIT_VIDEO) < 0)
//     {
//         std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n";
//         return false;
//     }
//     else
//     {
//         // Create window
//         window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//         if (window == nullptr)
//         {
//             std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << "\n";
//             return false;
//         }
//         else
//         {
//             // Create renderer for window
//             renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//             if (renderer == nullptr)
//             {
//                 std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << "\n";
//                 return false;
//             }
//             else
//             {
//                 // Initialize renderer color
//                 SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

//                 // Initialize PNG loading
//                 int imgFlags = IMG_INIT_PNG;
//                 if (!(IMG_Init(imgFlags) & imgFlags))
//                 {
//                     std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << "\n";
//                     return false;
//                 }
//             }
//         }
//     }

//     return true;
// }

// bool loadMedia(SDL_Texture*& texture, SDL_Renderer* renderer)
// {
//     // Load PNG texture
//     texture = IMG_LoadTexture(renderer, "../test.jpg");
//     if (texture == nullptr)
//     {
//         std::cout << "Failed to load texture image! SDL_image Error: " << IMG_GetError() << "\n";
//         return false;
//     }

//     return true;
// }

// void close(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture)
// {
//     // Free loaded image
//     SDL_DestroyTexture(texture);
//     texture = nullptr;

//     // Destroy renderer
//     SDL_DestroyRenderer(renderer);
//     renderer = nullptr;

//     // Destroy window
//     SDL_DestroyWindow(window);
//     window = nullptr;

//     // Quit SDL subsystems
//     IMG_Quit();
//     SDL_Quit();
// }
