#include "engine/Engine.h"

#include "MainScene.h"

int main(int argc, char* argv[]) {
    Engine::init();
    Engine::setScene(std::make_unique<MainScene>());
    Engine::startLoop();
    
    return 0;
}

