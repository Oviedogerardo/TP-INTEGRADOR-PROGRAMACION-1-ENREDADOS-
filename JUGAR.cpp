#include <iostream>
#include <cstdlib>
#include <ctime>
#include "JUGAR.h"
#include "DADOS.h"
#include "MOSTRARMENU.h"

using namespace std;

string PedirNombreJugador1() //ESTA FUNCION PIDE NOMBRES PARA INGRESAR
{
    string NombreJugador1;

    cout << "Ingrese el nombre del Jugador 1: ";
    cin >> NombreJugador1;

    return NombreJugador1;
}

string PedirNombreJugador2() //ESTA FUNCION PIDE NOMBRES PARA INGRESAR
{
    string NombreJugador2;

    cout << "Ingrese el nombre del Jugador 2: ";
    cin >> NombreJugador2;

    return NombreJugador2;
}

int ContadorRondas()
{


    for ( int NumeroRonda = 1; NumeroRonda < 3; NumeroRonda++)
    {
        cout<<NumeroRonda<<endl;
    }

}

void creditos()    //ESTA FUNCION MUESTRA LOS CREDITOS DE TODOS LOS INTEGRANTES DEL GRUPO
{
    cout << "-----CREDITOS-----" << endl;
    cout << endl;
    cout << "----Equipo #35----" << endl;
    cout << endl;
    cout << "BAÑULS BRIZUELA, Fernando Emmanuel" << endl;
    cout << "Legajo #33493" << endl;
    cout << endl;
    cout << "OVIEDO, Gerardo Joaquin" << endl;
    cout << "Legajo #31647" << endl;
    cout << endl;
    cout << "SARZA, Ludmila" << endl;
    cout << "Legajo #32540" << endl;
    cout << endl;
    cout << "VAZQUEZ GONZALEZ, Patricia" << endl;
    cout << "Legajo #31174" << endl;
    cout << endl;

}

void MostrarNombres(string NombreJugador1, string NombreJugador2)
{

    cout<<"Jugador 1: "<<NombreJugador1<<endl;

    cout<<"Jugador 2: "<<NombreJugador2<<endl;

}

//EMMA HACER FUNCION DE RONDAS
//PAR HACER FUNCION MOSTRAR DADOS DE 12 CARAS


void MostrarPartida(int Empieza, string NombreJugador1, string NombreJugador2, int DadosStockJugador1Numero[],int DadosStockJugador2Numero[],int DadosStockJugadorCantidad) //ESTA FUNCION SIRVE PARA MOSTRAR EL TRANSCURSO DE TODA LA PARTIDA
{
    if(Empieza == 1)
    {

        MostrarNombres(NombreJugador1, NombreJugador2);
        cout<<"El Jugador "<<NombreJugador1<<" Tira sus Dados Objetivo: "<<endl<<endl;
        DadosObjetivoJugador1();

        system("pause");
        system("cls");

        MostrarNombres(NombreJugador1, NombreJugador2);

        cout<<"El Jugador "<<NombreJugador2<<" Tira sus Dados Objetivo: "<<endl<<endl;
        DadosObjetivoJugador2();


        system("pause");
        system("cls");
    }
    else
    {

        MostrarNombres(NombreJugador1, NombreJugador2);

        cout<<"El Jugador "<<NombreJugador2<<" Tira sus Dados Objetivo: "<<endl<<endl;
        DadosObjetivoJugador2();


        system("pause");
        system("cls");

        MostrarNombres(NombreJugador1, NombreJugador2);
        cout<<"El Jugador "<<NombreJugador1<<" Tira sus Dados Objetivo: "<<endl<<endl;
        DadosObjetivoJugador1();

        system("pause");
        system("cls");
    }
    DadosStockJugador1 (DadosStockJugador1Numero,DadosStockJugadorCantidad);
    DadosStockJugador2 (DadosStockJugador2Numero,DadosStockJugadorCantidad);

}

/*void MostrarPodongas (string &poronga1, string &poronga2)      //ESTO SE COMENTO PARA USAR DESPUES
                                                                   NOMBRES POR REFERENCIA TENIENDO EN CUENTA
{                                                                  QUE LAS VARIABLES DE NOMBRES SE DECLAREN EN EL MAIN
     cout<<"mostar poronga" + poronga1<<endl;

     poronga1 = "PORONGA VENOSA";

     cout<<"mostar poronga" + poronga1<<endl;




}*/












