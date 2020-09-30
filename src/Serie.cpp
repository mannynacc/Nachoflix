#include "Serie.h"

ostream &operator <<(ostream& salida, const Serie s)
{
    salida << s.codigo << ",'" << s.nombre << "'," << s.genero << "," << s.numTemporadas << endl;
    return salida;
}

Serie::Serie(/* args */)
{
    /*
    codigo = "00000";
    nombre = "Serie";
    genero = "Genero";
    numTemporadas = 0;*/
}

/* PARA JUGADORS
    Player *plr;
    int nuPl;
    cin >> numPly;
    plr = new Player[numPly];
    */
Serie::Serie(string cd, string nom, string gen,int nTemps)
{
    codigo = cd;
    nombre = nom;
    genero = gen;
    numTemporadas = nTemps;
}
string Serie::getCodigo()
{
    return codigo;
}

string Serie::getNombre()
{
    return nombre;
}

string Serie::getGenero()
{
    return genero;
}

int Serie::getNumTemporadas()
{
    return numTemporadas;
}


void Serie::setCodigo(string cd)
{
    codigo = cd;
}

void Serie::setNombre(string nom)
{
    nombre = nom;
}

void Serie::setGenero(string gen)
{
    genero = gen;
}

void Serie::setNumTemporadas(int nTemps)
{
    numTemporadas = nTemps;
}