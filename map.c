#include <stdio.h>
#include "grille.h"
int generate_map(){
    extern int const GRILLE[31][28];
        for(int i=0; i<31; i++){
        for(int j=0; j<28; j++){
            switch(GRILLE[i][j]){
                case 0:
                    printf("-");
                    break;
                case 1: 
                    printf(" ");
                    break;
                case 2: 
                    printf("°");
                    break;
                case 3:
                    printf("o");
                    break;
                case 4:
                    printf("F");
                    break;
                case 5:
                    printf("P");
                    break;
                case 6:
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
                    break;
            }
        }
    printf("\n");
    }
    printf("\n");
}