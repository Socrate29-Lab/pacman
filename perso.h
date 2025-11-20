#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ecran.h"

void perso(){
    
    // Creation du renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Erreur creation renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    //Affichage du personnage PacMan
    int x = 300;
    int y = 300;
    SDL_Rect perso = {x,y, 50,50};
    SDL_Surface* pacman = IMG_Load("pacman.bmp");
    if(!pacman)
        printf("Surface error");
    SDL_Texture* pactext = SDL_CreateTextureFromSurface(renderer, pacman);
    SDL_FreeSurface(pacman);
    if(!pactext)
        printf("Erreur texture");

    SDL_RenderCopy(renderer, pactext, NULL, &perso);
}