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


void MostrarPartida(int Empieza, string NombreJugador1, string NombreJugador2, int DadosStockJugador1Numero[],int DadosStockJugador2Numero[],int DadosStockJugador1Cantidad,
                     int DadosStockJugador2Cantidad,int &NumeroObjetivoJugador1,int &NumeroObjetivoJugador2, int &SumaDadosJugador1, int &SumaDadosJugador2
                     ,int &DadosElegidosJugador1,int &DadosElegidosJugador2)
 //ESTA FUNCION SIRVE PARA MOSTRAR EL TRANSCURSO DE TODA LA PARTIDA
{




    if(Empieza == 1)
    {

        MostrarNombres(NombreJugador1, NombreJugador2);
        cout<<"El Jugador "<<NombreJugador1<<" Tira sus Dados Objetivo: "<<endl<<endl;
        DadosObjetivoJugador1(NumeroObjetivoJugador1);


        system("pause");
        system("cls");

        MostrarNombres(NombreJugador1, NombreJugador2);

        cout<<"El Jugador "<<NombreJugador2<<" Tira sus Dados Objetivo: "<<endl<<endl;
        DadosObjetivoJugador2(NumeroObjetivoJugador2);


        system("pause");
        system("cls");
    }
    else
    {

        MostrarNombres(NombreJugador1, NombreJugador2);

        cout<<"El Jugador "<<NombreJugador2<<" Tira sus Dados Objetivo: "<<endl<<endl;
        DadosObjetivoJugador2(NumeroObjetivoJugador2);


        system("pause");
        system("cls");

        MostrarNombres(NombreJugador1, NombreJugador2);
        cout<<"El Jugador "<<NombreJugador1<<" Tira sus Dados Objetivo: "<<endl<<endl;
        DadosObjetivoJugador1(NumeroObjetivoJugador1);

        system("pause");
        system("cls");
    }

    cout<<"El Numero Objetivo a llegar es: "<<NumeroObjetivoJugador1<<endl<<endl; //ESTO SE AGREGO PARA MOSTRAR EL NUMERO OBJETIVO

    cout<<"Estos son los Dados de la tirada del Jugador: "<< NombreJugador1<<endl<<endl; //SE PUSIERON 2 "endl" POR MOTIVOS ESTETICOS, PARA DARLE ESPACIO Y MOSTRAR LOS DADOS

    DadosStockJugador1 (DadosStockJugador1Numero,DadosStockJugador1Cantidad);

    ElegirDadosySumarJugador1 (DadosStockJugador1Numero,DadosStockJugador1Cantidad,NumeroObjetivoJugador1, SumaDadosJugador1,DadosElegidosJugador1);

    cout<<"El Numero Objetivo a llegar es: "<<NumeroObjetivoJugador2<<endl<<endl;

    cout<<"Estos son los Dados de la tirada del Jugador: "<< NombreJugador2<<endl<<endl; //SE PUSIERON 2 "endl" POR MOTIVOS ESTETICOS, PARA DARLE ESPACIO Y MOSTRAR LOS DADOS

    DadosStockJugador2 (DadosStockJugador2Numero,DadosStockJugador2Cantidad);

    ElegirDadosySumarJugador2 (DadosStockJugador2Numero,DadosStockJugador2Cantidad,NumeroObjetivoJugador1, SumaDadosJugador2,DadosElegidosJugador2);
 }

 void MostrarPuntajePuntajeJugador1 (int &SumaDadosJugador1, int &DadosElegidosJugador1, string &NombreJugador1)  //EL PUNTAJE ES = SUMASELECCIONADA X CANTIDAD DE DADOS ELEGIDOS
 {

     int PuntajeJugador1;

   PuntajeJugador1 = SumaDadosJugador1 * DadosElegidosJugador1;

   cout<<"El Puntaje del Jugador 1 es: "<<NombreJugador1<<" es: "<<PuntajeJugador1;


 }

 void MostrarPuntajePuntajeJugador2(int &SumaDadosJugador2, int &DadosElegidosJugador2, string &NombreJugador2)
 {
     int PuntajeJugador2;

    PuntajeJugador2= SumaDadosJugador2 * DadosElegidosJugador2;

   cout<<"El Puntaje del Jugador 2 "<<NombreJugador2<<" es: "<<PuntajeJugador2;

 }

/*void MostrarCOSO (string &COSO1, string &COSO2)      //ESTO SE COMENTO PARA USAR DESPUES
                                                                   NOMBRES POR REFERENCIA TENIENDO EN CUENTA
{                                                                  QUE LAS VARIABLES DE NOMBRES SE DECLAREN EN EL MAIN
     cout<<"mostar COSO" + COSO1<<endl;

     COSO1 = "COSO COSELI";

     cout<<"mostar COSO" + COSO1<<endl;




}*/












