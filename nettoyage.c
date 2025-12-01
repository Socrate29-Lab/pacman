#include "nettoyage.h"
#include <stdio.h>
#include <SDL2/SDL.h>

void terminate(){
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}