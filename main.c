#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ecran.h"
#include "jeu.h"

//Compile avec :
//gcc main.c assets.c ecran.c map.c tile_generation.c -o build/pacman $(pkg-config --cflags --libs sdl2)

int main(int argc, char** argv){
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Erreur SDL_Init : %s\n", SDL_GetError());
        return 1;
    }

    //Initialisation de l'ecran
    init_ecran("Pacman", 728, 852);

    //initialisation du jeu
    jouer();

    //destruction de l'ecran
    detruire_ecran();
}