#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ecran.h"
#include "perso.h"
#include "nettoyage.h"


int main(){
    window();
    perso();
    SDL_Delay(3000);
    terminate();
}