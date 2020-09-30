#ifndef EPISODIO_H
#define EPISODIO_H

#include "Video.h"

class Episodio:public Video
{
    friend ostream &operator <<(ostream& salida, const Episodio ep);

    private:
        string codigoEpisodio;
        int temporada;

    public:
        Episodio(/* args */);
        Episodio(string, string, string, string, string, float, int,int);
        string getCodigoEpisodio();
        int getTemporada();
        void setCodigoEpisodio(string);
        void setTemporada(int);
};

#endif