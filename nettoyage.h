#include <stdio.h>
#include <SDL2/SDL>

// Nettoyage
void terminate(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}