#include <stdio.h>
#include "ecran.h"
#include "perso.h"
#include "map.h"
#include <SDL2/SDL.h>

void window(){
    SDL_Window* screen = SDL_CreateWindow(
        "PacMan",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1280, 1024,
        0
    );
    if (!window) {
        printf("Erreur creation fenetre : %s\n", SDL_GetError());
        SDL_Quit();
    }
        //Initialisation du jeu
    int running = 1;
    SDL_Event event;
    while(running){
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT)
                running = 0;
            if (event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_ESCAPE)
                running = 0;
            }
        }
    generate_map();
    SDL_Delay(1000);
    }
    //Nettoyage de l'ecran
    SDL_DestroyWindow(screen);
}