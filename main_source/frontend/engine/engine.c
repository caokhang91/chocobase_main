#include "engine.h"
#include "../scene/scene.h"
#include "../ui/ui.h"
#include "../input/keyboard.h"
#include "../input/mouse.h"
void engine_loop(SDL_Renderer *renderer)
{
    ui_init(renderer);
    SDL_Event event;
    int running = 1;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = 0;
            handle_keyboard_input(&event);
            handle_mouse_input(&event);
            ui_quit();
        }
        scene_update();
        scene_render(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
        ui_quit();
    }
    ui_quit();
}
ui_quit();
}
