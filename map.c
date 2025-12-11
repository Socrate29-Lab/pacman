#include <stdio.h>
#include "grille.h"
#include "assets.h"
#include "ecran.h"
#include "tile_generation.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int generate_map(){
    extern int grille[31][28];
        for(int i=0; i<31; i++){
        for(int j=0; j<28; j++){
            int index = grille[i][j];
            generate_tile(i, j, index);
        }
    }
}