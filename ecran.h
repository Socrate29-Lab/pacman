#ifndef ECRAN_H
#define ECRAN_H
#include <SDL2/SDL.h>

//Permet de passer l'adresse de l'écran au reste des fichiers
extern SDL_Window *screen;
extern SDL_Renderer *renderer;
extern SDL_Surface *screen_surface;

int init_ecran(const char *titre, int largeur, int hauteur);
void detruire_ecran();

#endif