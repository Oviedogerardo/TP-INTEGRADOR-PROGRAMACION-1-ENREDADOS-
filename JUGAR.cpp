#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>
#include "JUGAR.h"
#include "DADOS.h"
#include "MOSTRARMENU.h"
#include "rlutil.h"

using namespace std;

///*********************
///FUNCIONES JUGADOR 1.-
///*********************

string PedirNombreJugador1() //ESTA FUNCION PIDE NOMBRES PARA INGRESAR
{
    string NombreJugador1;

    MostrarTitulo();

   rlutil::setColor(rlutil::BLACK);
    rlutil::locate(71,11);
    cout << "Ingrese el nombre del Jugador 1: ";
    cin >> NombreJugador1;

    Limpia();
    return NombreJugador1;
}

void MostrarPuntajePuntajeJugador1 (int &SumaDadosJugador1, int &DadosElegidosJugador1, string &NombreJugador1)  //EL PUNTAJE ES = SUMASELECCIONADA X CANTIDAD DE DADOS ELEGIDOS
{
    int PuntajeJugador1;

    PuntajeJugador1 = SumaDadosJugador1 * DadosElegidosJugador1;

    cout<<"El Puntaje de "<<NombreJugador1<<" es: "<<PuntajeJugador1<<endl;
}

///-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

///*********************
///FUNCIONES JUGADOR 2.-
///*********************

string PedirNombreJugador2() //ESTA FUNCION PIDE NOMBRES PARA INGRESAR
{
    string NombreJugador2;

    MostrarTitulo();

    rlutil::locate(71,11);
    cout << "Ingrese el nombre del Jugador 2: ";
    cin >> NombreJugador2;

    return NombreJugador2;
}

void MostrarPuntajePuntajeJugador2(int &SumaDadosJugador2, int &DadosElegidosJugador2, string &NombreJugador2)
{
    int PuntajeJugador2;

    PuntajeJugador2= SumaDadosJugador2 * DadosElegidosJugador2;

    cout<<"El Puntaje de "<<NombreJugador2<<" es: "<<PuntajeJugador2<<endl;
}

///-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

///*********************
///FUNCIONES VARIAS.-
///*********************


void creditos()    //ESTA FUNCION MUESTRA LOS CREDITOS DE TODOS LOS INTEGRANTES DEL GRUPO
{
    rlutil::locate(96,2);
    cout << "-----CREDITOS-----";
    rlutil::locate(96,4);
    cout << "----Equipo #35----";
    rlutil::locate(92,7);
    cout << "BAÑULS BRIZUELA, Fernando Emmanuel";
    rlutil::locate(98,8);
    cout << "Legajo #33493";
    rlutil::locate(92,10);
    cout << "OVIEDO, Gerardo Joaquin";
    rlutil::locate(98,11);
    cout << "Legajo #31647";
    rlutil::locate(92,13);
    cout << "SARZA, Ludmila";
    rlutil::locate(98,14);
    cout << "Legajo #32540";
    rlutil::locate(92,16);
    cout << "VAZQUEZ GONZALEZ, Patricia";
    rlutil::locate(98,17);
    cout << "Legajo #31174";
    cout << endl;
}

void MostrarNombres(string NombreJugador1, string NombreJugador2)
{
    rlutil::locate(95,3);
    cout<<"Jugador 1: "<<NombreJugador1;
    rlutil::locate(95,4);
    cout<<"Jugador 2: "<<NombreJugador2<<endl;
}

void MostrarPartida(int Empieza, string &NombreJugador1, string &NombreJugador2, int DadosStockJugador1Numero[],int DadosStockJugador2Numero[],int &DadosStockJugador1Cantidad,
                    int &DadosStockJugador2Cantidad,int &NumeroObjetivoJugador1,int &NumeroObjetivoJugador2, int &SumaDadosJugador1, int &SumaDadosJugador2
                    ,int &DadosElegidosJugador1,int &DadosElegidosJugador2, int &Ronda, int PuntajeJugador1,int PuntajeJugador2)
//ESTA FUNCION SIRVE PARA MOSTRAR EL TRANSCURSO DE TODA LA PARTIDA
{
    if(Empieza == 1)
    {

        MostrarNombres(NombreJugador1, NombreJugador2);

        rlutil::locate(85,6);
        cout<<"El Jugador 1: "<<NombreJugador1<<" Tira sus Dados Objetivo: "<<endl<<endl;
        DadosObjetivoJugador1(NumeroObjetivoJugador1, NombreJugador1);

        Limpia();

        MostrarRonda(Ronda);

        MostrarNombres(NombreJugador1, NombreJugador2);

        rlutil::locate(85,6);
        cout<<"El Jugador 2: "<<NombreJugador2<<" Tira sus Dados Objetivo: "<<endl<<endl;
        DadosObjetivoJugador2(NumeroObjetivoJugador2, NombreJugador2);
    }
    else
    {
        MostrarNombres(NombreJugador1, NombreJugador2);

        rlutil::locate(85,6);
        cout<<"El Jugador 2: "<<NombreJugador2<<" Tira sus Dados Objetivo: "<<endl<<endl;
        DadosObjetivoJugador2(NumeroObjetivoJugador2,NombreJugador2);

        MostrarRonda(Ronda);

        MostrarNombres(NombreJugador1, NombreJugador2);

        rlutil::locate(85,6);
        cout<<"El Jugador 1: "<<NombreJugador1<<" Tira sus Dados Objetivo: "<<endl<<endl;

        DadosObjetivoJugador1(NumeroObjetivoJugador1,NombreJugador1);
    }

    if (Empieza == 1)
    {
        MostrarRonda(Ronda);
        MostrarNombres(NombreJugador1, NombreJugador2);
        cout<<endl;

        cout<<"El Numero Objetivo a llegar es: "<<NumeroObjetivoJugador1<<endl<<endl; //ESTO SE AGREGO PARA MOSTRAR EL NUMERO OBJETIVO

        cout<<"Estos son los Dados Stock de la tirada de : "<< NombreJugador1<<endl<<endl; //SE PUSIERON 2 "endl" POR MOTIVOS ESTETICOS, PARA DARLE ESPACIO Y MOSTRAR LOS DADOS

        DadosStockJugador1 (DadosStockJugador1Numero,DadosStockJugador1Cantidad);

        ElegirDadosySumarJugador1 (DadosStockJugador1Numero,DadosStockJugador1Cantidad, DadosStockJugador2Cantidad,NumeroObjetivoJugador1, SumaDadosJugador1,DadosElegidosJugador1, NombreJugador1,PuntajeJugador1);

        MostrarRonda(Ronda);

        MostrarNombres(NombreJugador1, NombreJugador2);

        cout<<endl;

        cout<<"El Numero Objetivo a llegar es: "<<NumeroObjetivoJugador2<<endl<<endl;

        cout<<"Estos son los Dados Stock de la tirada de: "<< NombreJugador2<<endl<<endl; //SE PUSIERON 2 "endl" POR MOTIVOS ESTETICOS, PARA DARLE ESPACIO Y MOSTRAR LOS DADOS

        DadosStockJugador2 (DadosStockJugador2Numero,DadosStockJugador2Cantidad);

        ElegirDadosySumarJugador2 (DadosStockJugador2Numero,DadosStockJugador2Cantidad, DadosStockJugador1Cantidad,NumeroObjetivoJugador2, SumaDadosJugador2,DadosElegidosJugador2, NombreJugador2,PuntajeJugador2);
    }

    else
    {
        MostrarRonda(Ronda);

        MostrarNombres(NombreJugador1, NombreJugador2);

        cout<<endl;

        cout<<"                                              El Numero Objetivo a llegar es: "<<NumeroObjetivoJugador2<<endl<<endl;

        cout<<"Estos son los Dados Stock de la tirada de: "<< NombreJugador2<<endl<<endl; //SE PUSIERON 2 "endl" POR MOTIVOS ESTETICOS, PARA DARLE ESPACIO Y MOSTRAR LOS DADOS

        DadosStockJugador2 (DadosStockJugador2Numero,DadosStockJugador2Cantidad);

        ElegirDadosySumarJugador2 (DadosStockJugador2Numero,DadosStockJugador2Cantidad, DadosStockJugador1Cantidad,NumeroObjetivoJugador2, SumaDadosJugador2,DadosElegidosJugador2, NombreJugador2,PuntajeJugador2);

        MostrarRonda(Ronda);

        MostrarNombres(NombreJugador1, NombreJugador2);

        cout<<endl;

        cout<<"                                              El Numero Objetivo a llegar es: "<<NumeroObjetivoJugador1<<endl<<endl; //ESTO SE AGREGO PARA MOSTRAR EL NUMERO OBJETIVO

        cout<<"Estos son los Dados Stock de la tirada de : "<< NombreJugador1<<endl<<endl; //SE PUSIERON 2 "endl" POR MOTIVOS ESTETICOS, PARA DARLE ESPACIO Y MOSTRAR LOS DADOS

        DadosStockJugador1 (DadosStockJugador1Numero,DadosStockJugador1Cantidad);

        ElegirDadosySumarJugador1 (DadosStockJugador1Numero,DadosStockJugador1Cantidad, DadosStockJugador2Cantidad,NumeroObjetivoJugador1, SumaDadosJugador1,DadosElegidosJugador1, NombreJugador1, PuntajeJugador1);
    }
}

void PausayLimpia() //FUNCION PARA PAUSAR Y LIMPIAR LA PANTALLA y no estar escribiendo system y lo demas!!!
{
    rlutil::locate(90,25);
    system ("pause");
    system("cls");
}

void Pausa()
{
    system("pause");
}

void Limpia()
{
    system("cls");
}

void Estadisticas (string NombreJugador1, string NombreJugador2, int PuntajeJugador1, int PuntajeJugador2)
{
    int MayorPuntaje;

    Limpia();

    rlutil::locate(80,1);
    cout<<"---------------------ESTADISTICAS---------------------";
    rlutil::locate(75,2);
    cout<<"---------------------ULTIMO RESUMEN PARTIDA---------------------";
    rlutil::locate(90,4);
    cout<<"El Jugador 1: "<<NombreJugador1<<" tuvo estos puntos: "<<PuntajeJugador1;
    rlutil::locate(90,5);
    cout<<"El Jugador 2: "<<NombreJugador2<<" tuvo estos puntos: "<<PuntajeJugador2;
    rlutil::locate(80,7);
    cout<<"---------------------MAYOR PUNTAJE---------------------";

    if (PuntajeJugador1 > PuntajeJugador2)
    {
        MayorPuntaje = PuntajeJugador1;

        rlutil::locate(90,9);
        cout<<"El mayor puntaje de la ultima partida es "<<MayorPuntaje<<endl<<endl;
    }
    if (PuntajeJugador1 < PuntajeJugador2)
    {
        MayorPuntaje = PuntajeJugador2;

        rlutil::locate(90,9);
        cout<<"El mayor puntaje de la ultima partida es "<<MayorPuntaje<<endl<<endl;
    }

    if (PuntajeJugador1 == 0 & PuntajeJugador2 == 0)
    {
        ColorAdvertencia();
        rlutil::locate(90,9);
        cout<<"TODAVIA NO SE JUGO NINGUNA RONDA"<<endl<<endl;
        VuelveColor();
    }

    PausayLimpia();
}

void MostrarRonda(int &Ronda)
{
    rlutil::locate(95,1);
    cout<<"RONDA NUMERO: "<<Ronda<<endl<<endl;
}

void GanarAutomaticamente(int DadosStockJugador1Cantidad, int DadosStockJugador2Cantidad, int PuntajeJugador1,int PuntajeJugador2, string NombreJugador1, string NombreJugador2)
{
    Limpia();
    //DadosStockJugador1Cantidad = 0; ///DEBUG: PARA VER COMO QUEDA
    //DadosStockJugador2Cantidad = 1; ///DEBUG: PARA VER COMO QUEDA

    if (DadosStockJugador1Cantidad == 0 || DadosStockJugador2Cantidad == 0)
    {
        Limpia();
        rlutil::locate(80,1);
        cout<<"********************************************************************************";
        rlutil::locate(85,3);
        cout<<"UNO DE LOS JUGADORES SE QUEDO SIN DADOS!!!"<<endl<<endl;
        if (DadosStockJugador1Cantidad == 0)
        {
            PuntajeJugador1 += 10000;
            rlutil::locate(90,25);
            cout<<"FELICIDADES "<<NombreJugador1<<"      TE QUEDASTE SIN DADOS, TOMA 10.000 PUNTOS Y GANAS AUTOMATICAMENTE!!!";
            rlutil::locate(93,27);
            cout<<"CERRAS CON ESTOS PUNTOS: "<<PuntajeJugador1<<endl;
        }
        else if (DadosStockJugador2Cantidad == 0)
        {
            PuntajeJugador2 += 10000;
            rlutil::locate(90,25);
            cout<<"FELICIDADES "<<NombreJugador2<<"      TE QUEDASTE SIN DADOS, TOMA 10.000 PUNTOS Y GANAS AUTOMATICAMENTE!!!";
            rlutil::locate(93,27);
            cout<<"CERRAS CON ESTOS PUNTOS: "<<PuntajeJugador2<<endl;
        }
    }
}

void ReiniciarValores(int &DadosStockJugador1Cantidad,int &SumaDadosJugador1,
                      int &PuntajeJugador1,int &DadosStockJugador2Cantidad,
                      int &SumaDadosJugador2,int &PuntajeJugador2)
{
    DadosStockJugador1Cantidad = 6;
    SumaDadosJugador1 = 0;
    PuntajeJugador1 = 0;
    DadosStockJugador2Cantidad = 6;
    SumaDadosJugador2 = 0;
    PuntajeJugador2 = 0;
}


