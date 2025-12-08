#ifndef OBJETS_H
#define OBJETS_H

struct perso{
    int posx;
    int posy;
    int statut; //Par exemple, en 1 Pacman se fait manger, en 2 Pacman mange les fantômes
    int index;
};

struct objet{
    int posx;
    int posy;
    int index;
};

#endif