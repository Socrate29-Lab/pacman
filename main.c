#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ecran.h"
#include "jeu.h"
#include <time.h>
#include "game_over.h"
#include <SDL2/SDL_ttf.h>

//Compile avec :
//gcc *.c -o build/pacman $(pkg-config --cflags --libs sdl2 SDL2_ttf)

int finale_score = 0;

int main(int argc, char** argv){

    //Seed de l'aléatoire pour tout le reste du jeu
    srand((time)(NULL));

    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Erreur SDL_Init : %s\n", SDL_GetError());
        return 1;
    }

    //initialisation du TTF pour afficher du texte
    if(TTF_Init()==-1){
        printf("TTF_Init : %s\n", TTF_GetError());
        exit(2);
    }

    //Initialisation de l'ecran
    init_ecran("Pacman", 728, 852);

    //initialisation du jeu
    jouer(&finale_score);

    //Ecran de Game Over
    game_over_screen(&finale_score);

    //destruction de l'ecran
    detruire_ecran();
}