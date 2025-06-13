#include <iostream>
#include <cstdlib>
#include <ctime>
#include "JUGAR.h"

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

void MostrarPartida(string NombreJugador1, string NombreJugador2) //ESTA FUNCION SIRVE PARA MOSTRAR EL TRANSCURSO DE TODA LA PARTIDA
{

     cout<<"Jugador 1: "<<NombreJugador1;

     cout<<"Jugador 2: "<<NombreJugador2;

}










