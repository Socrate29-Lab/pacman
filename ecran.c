#include <stdio.h>
#include "ecran.h"
#include <SDL2/SDL.h>

void window(){
    SDL_Window* helloscreen = SDL_CreateWindow(
        "PacMan",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1280, 1024,
        0
    );
    if (!window) {
        printf("Erreur creation fenetre : %s\n", SDL_GetError());
        SDL_Quit();
    }
}