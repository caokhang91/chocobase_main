#include <SDL.h>
#include <stdio.h>
#include <curl/curl.h>

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Chocobase SDL2 Client",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8080/ping");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("✅ Pong received from Chocobase backend!\n");
        }
        curl_easy_cleanup(curl);
    }

    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = 0;
        }

        SDL_SetRenderDrawColor(renderer, 30, 30, 120, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
