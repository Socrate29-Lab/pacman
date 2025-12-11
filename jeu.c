#include <stdio.h>
#include "jeu.h"
#include "ecran.h"
#include "map.h"


//Initialisation du jeu
void jouer(){
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
        //Affichage du labyrinthe en background
        screen_surface = SDL_GetWindowSurface(screen);
        SDL_Surface *background = SDL_LoadBMP("pacmap.bmp");
        if (!background){
            printf("Erreur chargement background");
            SDL_Quit();
        }
        SDL_BlitSurface(background, NULL, screen_surface , NULL);
        SDL_UpdateWindowSurface(screen);

        //Affichage des objets sur la map
        generate_map();
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
    }
}