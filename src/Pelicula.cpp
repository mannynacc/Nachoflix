#include "Pelicula.h"

Pelicula::Pelicula(/* args */)
{
}

Pelicula::Pelicula(string cd, string nom, string gen, string dur, float cal,int cr):Video(cd,nom,gen,dur,cal,cr)
{
}

/* PARA JUGADORS
    Player *plr;
    int nuPl;
    cin >> numPly;
    plr = new Player[numPly];
    */