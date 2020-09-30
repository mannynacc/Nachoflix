#ifndef BASEPELICULAS_H
#define BASEPELICULAS_H

#include "Pelicula.h"
#include "BaseDatos.h"

class BasePeliculas:public BaseDatos
{
    private:
        vector <Pelicula> pelis;

    public:
        BasePeliculas(/* args */);
        void cargarArchivo();
        void mostrar();
        void compararGenero(string);
        void compararCalificacion(float);
        void compararCodigo(string);
        void buscar(string,float);
        void calificarTitulo(string,float);
};


#endif