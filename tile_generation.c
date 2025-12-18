#include <stdio.h>
#include "tile_generation.h"
#include "objets.h"
#include "map.h"
#include "ecran.h"
#include "assets.h"

//Fonction pour attribuer des tuiles vides/objet sur la map en association avec le chiffre référence de grille.h
void generate_tile(int x, int y, int a){
    switch(a){
        case 0:
            
            break;
        case 1: 
           
            break;
        case 2: 
            print_candy(y,x,renderer);
            break;
        case 3:
            print_pacgum(y,x,renderer);
            break;
        /*case 4:
            printf("F");
            break;*/
        case 5:
            print_pacman(y,x,renderer);
            break;
        /*case 6:
            printf("G");
            break;
        case 7:
            printf("G");
            break;
        case 8:
            printf("G");
            break;
        case 9:
            printf("G");
            break;
        case 10:
            printf("=");
            break;
        case 11:
            printf("=");
            break;
        case 12:
            printf("_");
            break;
        default :
            break;*/
    }
}