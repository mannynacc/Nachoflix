#include "Video.h"

ostream &operator <<(ostream& salida, const Video vid)
{
    salida << "" << vid.codigo <<",'" << vid.nombre << "'," << vid.genero << "," << vid.duracion << "," << std::fixed << std::setprecision(1) << vid.calificacion << endl;
    return salida;
}

Video::Video(/* args */)
{
    codigo = "00000";
    nombre = "Nombre";
    genero = "Genero";
    duracion = "0:00";
    calificacion = 0.0;
    contRev = 1;
}

Video::Video(string cd, string nom, string gen, string dur, float cal, int cr)
{
    codigo = cd;
    nombre = nom;
    genero = gen;
    calificacion = cal;
    duracion = dur;
    contRev = cr;
}

string Video::getCodigo()
{
    return codigo;
}
 
string Video::getNombre()
{
    return nombre;
}
 
string Video::getGenero()
{
    return genero;
}
 
float Video::getCalificacion()
{
    return calificacion;
}
 
string Video::getDuracion()
{
    return duracion;
}

int Video::getContRev()
{
    return contRev;
}

void Video::setCodigo(string cd)
{
    codigo = cd;
}
 
void Video::setNombre(string nom)
{
    nombre = nom;
}
 
void Video::setGenero(string gen)
{
    genero = gen;
}

void Video::setCalificacion(float cal)
{
    calificacion = cal;
}
 
void Video::setDuracion(string dur)
{
    duracion = dur;
}

void Video::setContRev(int cr)
{
    contRev = cr;
}