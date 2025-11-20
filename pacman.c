#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ecran.h"
#include "perso.h"
#include "nettoyage.h"


int main(){
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Erreur SDL_Init : %s\n", SDL_GetError());
        return 1;
    }
    //Initialisation de l'ecran
    window();
    //affichage du perso a l'ecran
    perso();
    //Met fin a l'ecran au bout de 3 secondes (pour faire les tests)
    SDL_Delay(3000);
    terminate();
}