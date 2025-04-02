#pragma once
#include <SDL.h>
void scene_update();
void scene_render(SDL_Renderer *renderer);
void scene_handle_key(SDL_Keycode key, int down);
