#include <iostream>
#include <typeinfo>
#include <stdlib.h>
#include <limits>

#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include "Serie.h"
#include "BaseDatos.h"
#include "BasePeliculas.h"
#include "BaseSeries.h"
#include "BaseEpisodios.h"

using namespace std;

//Implementar algo para que suban todos los datos antes de hacer cualquier cosa 
//Porque si no no hay forma de jalar los datos ?


int verifInt()
{
    int opcion;
    char ch;
    bool bFail = true;
    while (bFail == true)
    {
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        
        bFail = cin.fail();
        if (bFail == true)
        {
            cout << "Error. Entrada no valida. Intente de nuevo.\n" << endl;
        }
        cin.clear();
        std::cin.ignore(numeric_limits < streamsize > ::max(), '\n');
    }
    return opcion;
}

float verifFloat()
{
    float opcion;
    bool bFail = true;
    while (bFail == true)
    {
        cin >> opcion;
        
        bFail = cin.fail();
        if (cin.fail() == true)
        {
            cout << "Error. Entrada no valida. Intente de nuevo.\n" << endl;
        }
        cin.clear();
        std::cin.ignore(numeric_limits < streamsize > ::max(), '\n');
    }
    return opcion;
}

string verifString()
{
    string opcion;
    bool bFail = true;
    while (bFail == true)
    {
        cin >> opcion;
        
        bFail = cin.fail();
        if (cin.fail() == true)
        {
            cout << "Error. Entrada no valida. Intente de nuevo.\n" << endl;
        }
        cin.clear();
        std::cin.ignore(numeric_limits < streamsize > ::max(), '\n');
    }
    return opcion;
}

void menu()
{
    cout << "-----NACHOFLIX-----" << endl;
    cout << "Opciones: " << endl;
    cout << "1. Cargar archivo de datos para guardar informacion de peliculas, series y episodios." << endl;
    cout << "2. Mostrar videos por calificacion o por genero." << endl;
    cout << "3. Mostrar episodios de una serie con cierta calificacion." << endl;
    cout << "4.  Mostrar peliculas con cierta calificacion." << endl;
    cout << "5. Calificar un titulo." << endl;
    cout << "0. Salir de NACHOFLIX." << endl;
}

int main()
{
    int opcion;
    Video *vid;
    bool bFail = true;

    menu();
    opcion = verifInt();

    
    while (opcion > 5 || opcion < 0)
    {
        cout << "Error. Opcion no valida. Intenta de nuevo." << endl;
        opcion = verifInt();
    }

    if (opcion == 0)
    {
        cout << "Cerrado NACHOFLIX..." <<endl;
        cin.get();
        std::exit(0);
    }

    else
    { 
        while (opcion != 1)
        {
            cout << "Error. Informacion de video no encontrada." << endl;
            cout << "Cargue los archivos de video para accesar a la informacion de video.\n" << endl;
            menu();
            opcion = verifInt();
        }
    }
    
    BaseDatos *bd[3];
    bd[0] = new BasePeliculas; //Peliculas en el sistema
    bd[1] = new BaseSeries; //Series en el sistema
    bd[2] = new BaseEpisodios; //Episodios en el sistema
    
    while (opcion != 0)
    {
        while (opcion > 5 || opcion < 0)
        {
            cout << "Error. Opcion no valida. Intenta de nuevo." << endl;
            opcion = verifInt();
        }

        if(opcion == 1) //Cargar archivo de datos
        {
            int tipo;
            cout << "----Tipos de video compatibles con NACHOFLIX----" << endl;
            cout << "1. Pelicula" << endl;
            cout << "2. Series" << endl;
            cout << "3. Episodios de serie" << endl;
            tipo = verifInt();

            while(tipo <= 0 || tipo > 3)
            {
                cout << "Opcion no valida. Selecciona una opcion." << endl;
                cout << "1. Pelicula" << endl;
                cout << "2. Series" << endl;
                cout << "3. Episodios de serie" << endl;
                tipo = verifInt();
            }

            if (tipo == 1)
            {
                bd[0]->cargarArchivo();
            }
            else if (tipo == 2)
            {
                bd[1]->cargarArchivo();
            }
            else if (tipo == 3)
            {
                bd[2]->cargarArchivo();
            }
        }
        else if (opcion == 2)//Mostrar los videos en general con una cierta calificacion o de un cierto genero
        {
            int tipo;
            float calMin;
            string gen;
            cout << "Buscar por: \n1.   Calificacion.\n2.   Genero." << endl;
            tipo = verifInt();

            while(tipo < 1 || tipo > 2)
            {
                cout << "Entrada fuera de rango. Seleccione de nuevo.\n" << endl;
                cout << "Buscar por: \n1.   Calificacion.\n2.   Genero." << endl;
                tipo = verifInt();
            }
            if (tipo == 1)//Solo aplica para peliculas y episodios
            {
                cout << "Calificacion minima del video: ";
                calMin = verifFloat();
                bd[0]->compararCalificacion(calMin);
                bd[2]->compararCalificacion(calMin);
            }
            if (tipo == 2)//Aplica para todos
            {
                cout << "Genero: ";
                gen = verifString();
                bd[0]->compararGenero(gen);
                bd[1]->compararGenero(gen);
                bd[2]->compararGenero(gen);
            }
        }
        else if (opcion == 3)//Mostrar los episodios de una determinada serie con una calificacion determinada
        {
            string codSerie;
            float calMin;
            cout << "Ingrese el codigo de la serie: ";
            codSerie = verifString();

            bd[1]->compararCodigo(codSerie);
            cout << "Ingrese la calificacion minima para los episodios: ";
            calMin = verifFloat();
            bd[2]->buscar(codSerie,calMin);
        }
        else if (opcion == 4)//Mostrar las peliculas con cierta calficacion
        {
            float calMin;
            cout << "Ingrese la calificacion minima para las peliculas: ";
            calMin = verifFloat();

            bd[0]->compararCalificacion(calMin);
        }
        else if (opcion == 5)//Calificar un video
        {
            string ep;
            string cod;
            float cal;
            cout << "Esta calificando un episodio? (y/n): ";
            ep = verifString();

            while (ep != "y" && ep != "n")
            {
                cout << "Entrada invalida. Selecciona una opcion." << endl;
                cout << "Esta calificando un episodio? (y/n): ";
                ep = verifString();
            }

            if (ep == "y")
            {
                cout << "Ingrese el codigo del episodio a calificar: ";
                cod = verifString();

                bd[2]->compararCodigo(cod);
                cout << "Ingrese calificacion: ";
                cal = verifFloat();

                bd[2]->calificarTitulo(cod,cal);
            }
            else
            {
                cout << "Ingrese el codigo de la pelicula a calificar: ";
                cod = verifString();
                bd[0]->compararCodigo(cod);

                cout << "Ingrese calificacion: ";
                cal = verifFloat();

                bd[0] ->calificarTitulo(cod,cal);
            }
            
        }
        menu();
        opcion = verifInt();
    }
    
    cout << "Cerrado NACHOFLIX..." <<endl;
    cin.get();
    std::exit(0);

    system("pause");
    return 0;
}