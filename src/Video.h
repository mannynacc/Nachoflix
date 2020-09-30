#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Video
{
    friend ostream &operator <<(ostream& salida, const Video vid);
   
    protected:
        string codigo;
        string nombre;
        string genero;
        string duracion;
        float calificacion;
        int contRev; //Contador para no. de calificaciones acumuladas

    public:
        Video(/* args */);
        Video(string, string, string, string, float,int);
        string getCodigo();
        string getNombre();
        string getGenero();
        float getCalificacion();
        string getDuracion();
        int getContRev();
        void setCodigo(string);
        void setNombre(string);
        void setGenero(string);
        void setCalificacion(float);
        void setDuracion(string);
        void setContRev(int);
};


#endif