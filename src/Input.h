#ifndef INPUT_H
#define INPUT_H

#include <vector>
#include "SDL.h"

#include "Global.h"

namespace Engine {
    class Input {
        public :
            std::vector<SDL_Event> keyEvents;
            std::vector<SDL_Event> mouseEvents;
            U8 *keyBoardState;
            U32 mouseState;

            void update ();
            bool ifCondApplyToKeyEventCont (U32 inputType, U8 scanCode, U8 repeatAmount);
            bool ifCondApplyToMouseEventCont (U32 inputType, U8 scanCode, U8 clickAmount);
            bool keyPressed (U8 scanCode);
            bool keyReleased (U8 scanCode);
            bool keyHeldDown (U8 scanCode);
            bool mousePressed (U8 scanCode);
            bool mouseReleased (U8 scanCode);
            bool mouseHeldDown (U8 mask);
    };
}

#endif // INPUT_H
