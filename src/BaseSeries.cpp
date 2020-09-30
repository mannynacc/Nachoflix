#include "BaseSeries.h"

BaseSeries::BaseSeries()
{
}

void BaseSeries::mostrar()
{
    for (int i = 0; i < series.size(); i++)
    {
        cout << series[i] << endl;
    }
}

void BaseSeries::cargarArchivo()
{
    string nombreArchivo;
    ifstream archivoSeries;

    cout << "Ingrese el nombre del archivo de series (extension csv): ";
    cin >> nombreArchivo;
    archivoSeries.open(nombreArchivo.c_str(),ios::in);

    if (archivoSeries.fail())
    {
        cout << "ERROR: No se pudo abrir el archivo." << endl;
    }

    if(archivoSeries.is_open())
    {
        string linea;
        string isSer;

        string cod;
        string nom;
        string gen;
        string str;
        int nTemps;

        int exito; //Para verificar que los archivos sean de Series

        while(getline(archivoSeries,linea))
        {
            stringstream ss(linea);
            getline (ss,isSer,',');
            if (isSer == "s")
            {
                getline(ss,cod,',');
                getline(ss,nom,',');
                getline(ss,gen,',');
                getline(ss,str,',');
                nTemps = stoi(str);
                Serie s(cod,nom,gen,nTemps);
                series.push_back(s);
                exito = 1;
            }
            else
            {
                cout << "Archivo '" << nombreArchivo << "' no es de Series.\n" << endl;
                exito = -1;
                break;
            }
            
        }
        if (exito > 0)
        {
            cout << "Archivo subido!" << endl;
            mostrar();
        }
        archivoSeries.close();
    }
}

void BaseSeries::compararCalificacion(float cal)
{
    cout << "No es posible comparar calificacion de series...\nAtributo calificacion no existe." << endl;
}

void BaseSeries::compararGenero(string gen)
{
    for (int i = 0; i < series.size(); i++)
    {
        if (series[i].getGenero() == gen)
        {
            cout << series[i] << endl;
        }
    }
}

void BaseSeries::compararCodigo(string cod)
{
    for (int i = 0; i < series.size(); i++)
    {
        if (series[i].getCodigo() == cod)
        {
            cout << series[i] << endl;
        }
    }
}

void BaseSeries::buscar(string cod, float cal)
{
    cout << "No se puede buscar serie por calificacion..." << endl;
}

void BaseSeries::calificarTitulo(string cod, float cal)
{
    cout << "No se puede calificar serie..." << endl;
}