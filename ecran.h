#include <stdio.h>
#include <SDL2/SDL.h>

int window(){
    // Creation de la fenetre
    SDL_Window* window = SDL_CreateWindow(
        "PacMan",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1280, 1024,
        0
    );
    if (!window) {
        printf("Erreur creation fenetre : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    // Creation du renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Erreur creation renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    SDL_Delay(3000);
}