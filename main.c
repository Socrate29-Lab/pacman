#include <stdio.h>
#include <SDL2/SDL.h>
#include "ecran.h"



int main(){
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Erreur SDL_Init : %s\n", SDL_GetError());
        return 1;
    }
    //Initialisation de l'ecran
    SDL_Window *helloscreen = window();
    //affichage du perso a l'ecran
    SDL_Delay(3000);
    SDL_DestroyWindow(helloscreen);
    SDL_Quit();
}