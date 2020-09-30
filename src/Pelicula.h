#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

class Pelicula:public Video
{
    private:

    public:
        Pelicula(/* args */);
        Pelicula(string, string, string, string, float,int);
};

#endif