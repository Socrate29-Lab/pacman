#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ecran.h"

//Compile avec :
//gcc main.c ecran.c map.c -o build/pacman $(pkg-config --cflags --libs sdl2)

int main(){
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Erreur SDL_Init : %s\n", SDL_GetError());
        return 1;
    }

    //Initialisation de l'ecran
    window();

    //Nettoyage du SDL
    SDL_Quit();
}