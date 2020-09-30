#ifndef SERIE_H
#define SERIE_H

#include "Episodio.h"
#include "Video.h"

class Serie
{
    friend ostream &operator <<(ostream& salida, const Serie s);

    private:
        string codigo;
        string nombre;
        string genero;
        int numTemporadas;
        vector <Episodio> episodios;

    public:
        Serie(/* args */);
        Serie(string, string, string,int);
        string getCodigo();
        string getNombre();
        string getGenero();
        int getNumTemporadas();
        void setCodigo(string);
        void setNombre(string);
        void setGenero(string);
        void setNumTemporadas(int);
};

#endif 