#include "BasePeliculas.h"


BasePeliculas::BasePeliculas(/* args */)
{
}

void BasePeliculas::mostrar()
{
    for (int i = 0; i < pelis.size(); i++)
    {
        cout << pelis[i] << endl;
    }
}


void BasePeliculas::cargarArchivo()
{
    string nombreArchivo;
    ifstream archivoPeliculas;

    cout << "Ingrese el nombre del archivo de peliculas (extension csv): ";
    cin >> nombreArchivo;
    archivoPeliculas.open(nombreArchivo.c_str(),ios::in);

    if (archivoPeliculas.fail())
    {
        cout << "ERROR: No se pudo abrir el archivo." << endl;
    }

    if(archivoPeliculas.is_open())
    {
        string linea;
        string isPeli;

        string cod;
        string nom;
        string gen;
        string str;
        float cal;
        string dur;

        int exito; //Revisar que todos los datos son de Peliculas

        while(getline(archivoPeliculas,linea))
        {
            stringstream ss(linea);
            getline(ss,isPeli,',');
            if (isPeli == "p")
            {
                getline(ss,cod,',');
                getline(ss,nom,',');
                getline(ss,dur,',');
                getline(ss,gen,',');
                getline(ss,str,',');
                cal = stof(str);
                Pelicula peli(cod,nom,gen,dur,cal,1);
                pelis.push_back(peli);
                exito = 1;
            }
            else
            {
                cout << "Archivo '" << nombreArchivo << "' no es de Peliculas.\n" << endl;
                exito = -1;
                break;
            }
        }

        if(exito > 0)
        {
            cout << "Archivo subido!" << endl;
            mostrar();
        }

        archivoPeliculas.close();
    }

}

void BasePeliculas::compararGenero(string gen)
{
    for (int i = 0; i < pelis.size(); i++)
    {
        if (pelis[i].getGenero() == gen)
        {
            cout << pelis[i] << endl;
        }
    }
}

/*
void BaseEpisodios::compararGenero(Video v)
{
    for (int i = 0; i < capitulos.size(); i++)
    {
        if (capitulos[i].getGenero() == v.getGenero())
        {
            cout << capitulos[i] << endl;
        }
    }
}
*/

void BasePeliculas::compararCalificacion(float cal)
{
    for (int i = 0; i < pelis.size(); i++)
    {
        if (pelis[i].getCalificacion() >= cal)
        {
            cout << pelis[i] << endl;
        }
    }
}

void BasePeliculas::compararCodigo(string cod)
{
    for (int i = 0; i < pelis.size(); i++)
    {
        if (pelis[i].getCodigo() == cod)
        {
            cout << pelis[i] << endl;
        }
    }
}


void BasePeliculas::buscar(string cod, float cal)
{
    for (int i = 0; i < pelis.size(); i++)
    {
        if ((pelis[i].getCodigo() == cod) && (pelis[i].getCalificacion() >= cal))
        {
            cout << pelis[i] << endl;
        }
    }
}

void BasePeliculas::calificarTitulo(string cod, float cal)
{
    float ultCal; //Guardar la ultima calificacion antes de cambiarla
    int cr;

    for (int i = 0; i < pelis.size(); i++)
    {
        if (pelis[i].getCodigo() == cod)
        {
            ultCal = pelis[i].getCalificacion();
            cr = pelis[i].getContRev();
            float newCal = (ultCal*cr + cal)/(cr+1); //Hacer promedio entre las viejas calificaciones y la nueva
            pelis[i].setCalificacion(newCal);
            pelis[i].setContRev(cr+1);
            std::cout << pelis[i] << endl;
        }
    }
}