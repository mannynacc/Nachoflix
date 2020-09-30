#ifndef BASEDATOS_H
#define BASEDATOS_H

#include "Video.h"


class BaseDatos
{
    protected:
        vector <Video> baseVid;

    public:
        BaseDatos(/* args */);
        virtual void cargarArchivo() = 0;
        virtual void mostrar() = 0;
        virtual void compararGenero(string) = 0;
        virtual void compararCalificacion(float) = 0;
        virtual void compararCodigo(string) = 0;
        virtual void buscar(string,float) = 0;
        virtual void calificarTitulo(string,float) = 0;
};

#endif