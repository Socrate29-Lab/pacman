#ifndef OBJETS_H
#define OBJETS_H

typedef struct perso{
    int posx;
    int posy;
    int statut; //Par exemple, en 1 Pacman se fait manger, en 2 Pacman mange les fantômes
    int index;
}S_perso;


typedef struct objet{
    int posx;
    int posy;
    int index;
    int score;
}S_objet;

#endif