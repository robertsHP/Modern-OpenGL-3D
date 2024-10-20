#ifndef SCENE_H
#define SCENE_H

namespace Engine {
    class Scene {
        public:
            virtual void input () {}
            virtual void update (float deltaTime) {}
            virtual void draw () {}
    };
}

#endif // SCENE_H
