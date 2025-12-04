#include "assets.h"
#include <stdio.h>

void background(SDL_Surface surface1, SDL_Surface surface2, SDL_Window *window){
            SDL_Surface *surface1 = SDL_LoadBMP("pacmap.bmp");
        if (!background){
            printf("Erreur chargement background");
            SDL_Quit();
        }
        SDL_BlitSurface(background, NULL, surface2 , NULL);
        SDL_UpdateWindowSurface(window);
}