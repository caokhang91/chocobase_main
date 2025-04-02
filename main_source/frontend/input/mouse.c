#include "mouse.h"
#include <stdio.h>

void handle_mouse_input(const SDL_Event *event) {
    if (event->type == SDL_MOUSEBUTTONDOWN) {
        printf("🖱 Mouse click at (%d, %d)\n", event->button.x, event->button.y);
    }
}
