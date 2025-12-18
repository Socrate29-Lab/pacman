#ifndef ASSETS_H
#define ASSETS_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void print_empty();
void print_candy(int x, int y, SDL_Renderer *renderer);
void print_pacgum(int x, int y, SDL_Renderer *renderer);
void print_pacman(int x, int y, SDL_Renderer *renderer);

#endif