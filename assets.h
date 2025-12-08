#ifndef ASSETS_H
#define ASSETS_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct persos{
    int posx;
    int posy;
    int statut; //Par exemple, en 1 Pacman se fait manger, en 2 Pacman mange les fantômes
};

#endif