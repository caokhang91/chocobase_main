#include "scene.h"
#include <SDL.h>
#include <stdio.h>

static SDL_Rect player = {100, 100, 40, 40};
static int move_up, move_down, move_left, move_right;

void scene_update()
{
    const int speed = 4;
    if (move_up)
        player.y -= speed;
    if (move_down)
        player.y += speed;
    if (move_left)
        player.x -= speed;
    if (move_right)
        player.x += speed;
}

void scene_render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 20, 20, 80, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // player color
    SDL_RenderFillRect(renderer, &player);
}

void scene_handle_key(SDL_Keycode key, int down)
{
    switch (key)
    {
    case SDLK_w:
        move_up = down;
        break;
    case SDLK_s:
        move_down = down;
        break;
    case SDLK_a:
        move_left = down;
        break;
    case SDLK_d:
        move_right = down;
        break;
    default:
        break;
    }
}
