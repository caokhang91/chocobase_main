#include "keyboard.h"
#include "../scene/scene.h"

void handle_keyboard_input(const SDL_Event *event)
{
    if (event->type == SDL_KEYDOWN || event->type == SDL_KEYUP)
    {
        int is_down = (event->type == SDL_KEYDOWN);
        SDL_Keycode key = event->key.keysym.sym;
        scene_handle_key(key, is_down);
    }
}
