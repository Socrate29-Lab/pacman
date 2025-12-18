#include <stdio.h>
#include "ecran.h"
#include "map.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//Déclaration de l'écran
SDL_Window *screen = NULL;
SDL_Renderer *renderer = NULL;

//Initialisation de l'écran
int init_ecran(const char *titre, int largeur, int hauteur){
    if (SDL_Init(SDL_INIT_VIDEO) != 0) return 0;
        screen = SDL_CreateWindow(
            "Pacman",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            728, 852,
            0
            );
    if (!screen) return 0;

    //Creation du renderer
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Erreur création renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(screen);
        SDL_Quit();
    } 
}

//Nettoyage de l'ecran
void detruire_ecran(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(screen);
    SDL_Quit();
}
