#include <SDL.h>
#include "engine/engine.h"
int main(int argc, char *argv[]) {
 SDL_Init(SDL_INIT_VIDEO);
 SDL_Window *win = SDL_CreateWindow("Modular Titan Client", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
 SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
 engine_loop(ren);
 SDL_DestroyRenderer(ren);
 SDL_DestroyWindow(win);
 SDL_Quit();
 return 0;
}
