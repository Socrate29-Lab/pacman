#include <stdio.h>
#include "ecran.h"
#include "map.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void window(){
    SDL_Window* screen = SDL_CreateWindow(
        "PacMan",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        728, 852,
        0
    );
    if (!screen) {
        printf("Erreur creation fenetre : %s\n", SDL_GetError());
        SDL_Quit();
    }
    SDL_Surface *screen_surface = SDL_GetWindowSurface(screen);
    
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
        //Initialisation de la map en background
        SDL_Surface *background = SDL_LoadBMP("pacmap.bmp");
        if (!background){
            printf("Erreur chargement background");
            SDL_Quit();
        }
        SDL_BlitSurface(background, NULL, screen_surface , NULL);
        SDL_UpdateWindowSurface(screen);
        generate_map();
        SDL_Delay(1000);
    }
    //Nettoyage de l'ecran
    SDL_DestroyWindow(screen);
}