#ifndef BASESERIES_H
#define BASESERIES_H

#include "Serie.h"
#include "BaseDatos.h"

class BaseSeries:public BaseDatos
{
    protected:
        vector <Serie> series;

    public:
        BaseSeries(/* args */);
        void cargarArchivo();
        void mostrar();
        void compararGenero(string);
        void compararCalificacion(float); //Mensaje de error porque no tiene calificacion
        void compararCodigo(string);
        void buscar(string,float);
        void calificarTitulo(string,float);
};

#endif