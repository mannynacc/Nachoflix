#include "Episodio.h"

ostream &operator <<(ostream& salida, const Episodio ep)
{
    salida << ep.codigo << "," << ep.codigoEpisodio << ",'" << ep.nombre << "'," << ep.genero << "," << ep.duracion << "," << std::fixed << std::setprecision(1) << ep.calificacion << "," << ep.temporada;
    return salida;
}

Episodio::Episodio(/* args */):Video()
{
    codigoEpisodio = "0000-0000";
    temporada = 0;
}

Episodio::Episodio(string cd, string cdEp, string nom, string gen, string dur, float cal, int temp,int cr):Video(cd,nom,gen,dur,cal,cr)
{
    codigoEpisodio = cdEp;
    temporada = temp;
}

string Episodio::getCodigoEpisodio()
{
    return codigoEpisodio;
}

int Episodio::getTemporada()
{
    return temporada;
}

void Episodio::setCodigoEpisodio(string cdEp)
{
    codigoEpisodio = cdEp;
}

void Episodio::setTemporada(int temp)
{
    temporada = temp;
}