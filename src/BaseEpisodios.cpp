#include "BaseEpisodios.h"

BaseEpisodios::BaseEpisodios()
{
}


void BaseEpisodios::mostrar()
{
    for(int i =0; i < capitulos.size(); i++)
    {
        cout << capitulos[i] << endl;
    }
}

void BaseEpisodios::cargarArchivo()
{
    string nombreArchivo;
    ifstream archivoEpisodios;

    cout << "Ingrese el nombre del archivo de episodios (extension csv): ";
    cin >> nombreArchivo;
    archivoEpisodios.open(nombreArchivo.c_str(),ios::in);

    if (archivoEpisodios.fail())
    {
        cout << "ERROR: No se pudo abrir el archivo." << endl;
    }

    if(archivoEpisodios.is_open())
    {
        string linea;
        string isEp;

        string cod;
        string codEp;
        string nom;
        string gen;
        string dur;
        string strn;
        float cal;
        string str;
        int temp;

        int exito; //Para verificar que todos los datos sean episodios
        while(getline(archivoEpisodios,linea))
        {
            stringstream ss(linea);
            getline(ss,isEp,',');
            if (isEp == "e")
            {    
                getline(ss,cod,',');
                getline(ss,codEp,',');
                getline(ss,nom,',');
                getline(ss,gen,',');
                getline(ss,dur,',');

                getline(ss,strn,',');
                cal = stof(strn);

                getline(ss,str,',');
                temp = stoi(str);

                Episodio ep(cod,codEp,nom,gen,dur,cal,temp,1);
                capitulos.push_back(ep);
                exito = 1;
            }
            else
            {
                cout << "Archivo '" << nombreArchivo << "' no es de Episodios.\n" << endl;
                exito = -1;
                break;
            }
        }

        if(exito > 0)
        {
            cout << "Archivo subido!" << endl;
            mostrar();
        }

        archivoEpisodios.close();
    }
}

void BaseEpisodios::compararGenero(string gen)
{
    for (int i = 0; i < capitulos.size(); i++)
    {
        if (capitulos[i].getGenero() == gen)
        {
            cout << capitulos[i] << endl;
        }
    }
}

void BaseEpisodios::compararCalificacion(float cal)
{
    for (int i = 0; i < capitulos.size(); i++)
    {
        if (capitulos[i].getCalificacion() >= cal)
        {
            cout << capitulos[i] << endl;
        }
    }
}

void BaseEpisodios::compararCodigo(string cod)
{
    for (int i = 0; i < capitulos.size(); i++)
    {
        if (capitulos[i].getCodigo() == cod)
        {
            cout << capitulos[i] << endl;
        }
    }
}

void BaseEpisodios::buscar(string cod, float cal)
{
    for (int i = 0; i < capitulos.size(); i++)
    {
        if ((capitulos[i].getCodigo() == cod) && (capitulos[i].getCalificacion() >= cal))
        {
            cout << capitulos[i] << endl;
        }
    }
}

void BaseEpisodios::calificarTitulo(string cod, float cal)
{
    float ultCal; //Guardar la ultima calificacion antes de cambiarla
    int cr; //Para llevar control del no. de calif. de cada episodio

    for (int i = 0; i < capitulos.size(); i++)
    {
        if (capitulos[i].getCodigoEpisodio() == cod)
        {
            ultCal = capitulos[i].getCalificacion();
            cr = capitulos[i].getContRev();
            float newCal = (ultCal*cr + cal)/(cr+1); //Hacer promedio entre las viejas calificaciones y la nueva
            capitulos[i].setCalificacion(newCal);
            capitulos[i].setContRev(cr+1);
            cout << capitulos[i] << endl;
        }
    }
}