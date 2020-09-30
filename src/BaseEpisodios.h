#ifndef BASEEPISODIOS_H
#define BASEEPISODIOS_H

#include "Episodio.h"
#include "BaseDatos.h"

class BaseEpisodios:public BaseDatos
{
    private:
        vector <Episodio> capitulos;

    public:
        BaseEpisodios(/* args */);
        void cargarArchivo();
        void mostrar();
        void compararGenero(string);
        void compararCalificacion(float); //Solo aplica para Episodios
        void compararCodigo(string);
        void buscar(string,float);
        void calificarTitulo(string,float);
};

#endif