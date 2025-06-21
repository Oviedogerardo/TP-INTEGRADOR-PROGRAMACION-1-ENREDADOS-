#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>
#include "JUGAR.h"
#include "DADOS.h"
#include "MOSTRARMENU.h"


using namespace std;

string PedirNombreJugador1() //ESTA FUNCION PIDE NOMBRES PARA INGRESAR
{
    string NombreJugador1;

    cout << "                                              Ingrese el nombre del Jugador 1: ";
    cin >> NombreJugador1;

    return NombreJugador1;
}

string PedirNombreJugador2() //ESTA FUNCION PIDE NOMBRES PARA INGRESAR
{
    string NombreJugador2;

    cout << "                                              Ingrese el nombre del Jugador 2: ";
    cin >> NombreJugador2;

    return NombreJugador2;
}


void creditos()    //ESTA FUNCION MUESTRA LOS CREDITOS DE TODOS LOS INTEGRANTES DEL GRUPO
{
    cout << "                                              -----CREDITOS-----" << endl;
    cout << endl;
    cout << "                                              ----Equipo #35----" << endl;
    cout << endl;
    cout << "                                              BAÑULS BRIZUELA, Fernando Emmanuel" << endl;
    cout << "                                              Legajo #33493" << endl;
    cout << endl;
    cout << "                                              OVIEDO, Gerardo Joaquin" << endl;
    cout << "                                              Legajo #31647" << endl;
    cout << endl;
    cout << "                                              SARZA, Ludmila" << endl;
    cout << "                                              Legajo #32540" << endl;
    cout << endl;
    cout << "                                              VAZQUEZ GONZALEZ, Patricia" << endl;
    cout << "                                              Legajo #31174" << endl;
    cout << endl;

}

void MostrarNombres(string NombreJugador1, string NombreJugador2)
{
    cout<<"                                              Jugador 1: "<<NombreJugador1<<endl;

    cout<<"                                              Jugador 2: "<<NombreJugador2<<endl<<endl;
}

void MostrarPartida(int Empieza, string &NombreJugador1, string &NombreJugador2, int DadosStockJugador1Numero[],int DadosStockJugador2Numero[],int &DadosStockJugador1Cantidad,
                    int &DadosStockJugador2Cantidad,int &NumeroObjetivoJugador1,int &NumeroObjetivoJugador2, int &SumaDadosJugador1, int &SumaDadosJugador2
                    ,int &DadosElegidosJugador1,int &DadosElegidosJugador2, int &Ronda)
//ESTA FUNCION SIRVE PARA MOSTRAR EL TRANSCURSO DE TODA LA PARTIDA
{
    if(Empieza == 1)
    {
        MostrarNombres(NombreJugador1, NombreJugador2);

        cout<<"                                              El Jugador 1: "<<NombreJugador1<<" Tira sus Dados Objetivo: "<<endl<<endl;
        DadosObjetivoJugador1(NumeroObjetivoJugador1);

        system("cls");
        MostrarRonda(Ronda);
        MostrarNombres(NombreJugador1, NombreJugador2);

        cout<<"                                              El Jugador 2: "<<NombreJugador2<<" Tira sus Dados Objetivo: "<<endl<<endl;
        DadosObjetivoJugador2(NumeroObjetivoJugador2);

        system("cls");
    }
    else
    {
        MostrarNombres(NombreJugador1, NombreJugador2);

        cout<<"                                              El Jugador 2: "<<NombreJugador2<<" Tira sus Dados Objetivo: "<<endl<<endl;
        DadosObjetivoJugador2(NumeroObjetivoJugador2);


        system("cls");
        MostrarRonda(Ronda);
        MostrarNombres(NombreJugador1, NombreJugador2);
        cout<<"                                              El Jugador 1: "<<NombreJugador1<<" Tira sus Dados Objetivo: "<<endl<<endl;
        DadosObjetivoJugador1(NumeroObjetivoJugador1);


        system("cls");
    }
    MostrarRonda(Ronda);
    MostrarNombres(NombreJugador1, NombreJugador2);
    cout<<endl;

    cout<<"                                              El Numero Objetivo a llegar es: "<<NumeroObjetivoJugador1<<endl<<endl; //ESTO SE AGREGO PARA MOSTRAR EL NUMERO OBJETIVO

    cout<<"Estos son los Dados Stock de la tirada del Jugador 1: "<< NombreJugador1<<endl<<endl; //SE PUSIERON 2 "endl" POR MOTIVOS ESTETICOS, PARA DARLE ESPACIO Y MOSTRAR LOS DADOS

    DadosStockJugador1 (DadosStockJugador1Numero,DadosStockJugador1Cantidad);

    ElegirDadosySumarJugador1 (DadosStockJugador1Numero,DadosStockJugador1Cantidad, DadosStockJugador2Cantidad,NumeroObjetivoJugador1, SumaDadosJugador1,DadosElegidosJugador1, NombreJugador1);

    Pali();

    MostrarRonda(Ronda);
    MostrarNombres(NombreJugador1, NombreJugador2);
    cout<<endl;

    cout<<"                                              El Numero Objetivo a llegar es: "<<NumeroObjetivoJugador2<<endl<<endl;

    cout<<"Estos son los Dados Stock de la tirada del Jugador 2: "<< NombreJugador2<<endl<<endl; //SE PUSIERON 2 "endl" POR MOTIVOS ESTETICOS, PARA DARLE ESPACIO Y MOSTRAR LOS DADOS

    DadosStockJugador2 (DadosStockJugador2Numero,DadosStockJugador2Cantidad);

    ElegirDadosySumarJugador2 (DadosStockJugador2Numero,DadosStockJugador2Cantidad, DadosStockJugador1Cantidad,NumeroObjetivoJugador2, SumaDadosJugador2,DadosElegidosJugador2, NombreJugador2);
    Pali();
}

void MostrarPuntajePuntajeJugador1 (int &SumaDadosJugador1, int &DadosElegidosJugador1, string &NombreJugador1)  //EL PUNTAJE ES = SUMASELECCIONADA X CANTIDAD DE DADOS ELEGIDOS
{
    int PuntajeJugador1;

    PuntajeJugador1 = SumaDadosJugador1 * DadosElegidosJugador1;

    cout<<"El Puntaje del Jugador 1 "<<NombreJugador1<<" es: "<<PuntajeJugador1<<endl;
}

void MostrarPuntajePuntajeJugador2(int &SumaDadosJugador2, int &DadosElegidosJugador2, string &NombreJugador2)
{
    int PuntajeJugador2;

    PuntajeJugador2= SumaDadosJugador2 * DadosElegidosJugador2;

    cout<<"El Puntaje del Jugador 2 "<<NombreJugador2<<" es: "<<PuntajeJugador2<<endl;
}

void Pali() //FUNCION PARA PAUSAR Y LIMPIAR LA PANTALLA y no estar escribiendo system y lo demas!!!
{
    system ("pause");
    system("cls");
}

void Estadisticas (string NombreJugador1, string NombreJugador2, int PuntajeJugador1, int PuntajeJugador2)
{
    system("cls");
    cout<<"                    ---------------------ESTADISTICAS---------------------"<<endl<<endl;

    cout<<"El Jugador 1: "<<NombreJugador1<<" Tubo estos puntos: "<<PuntajeJugador1<<endl<<endl;

    cout<<"El Jugador 2: "<<NombreJugador2<<" Tubo estos puntos: "<<PuntajeJugador2<<endl<<endl;

    if (PuntajeJugador1 == 0 & PuntajeJugador2 == 0)
    {
        cout<<"QUE HACEN MIRANDO ESTO?? VAYAN A JUGAR Y VUELVAN!!!"<<endl<<endl;
    }

    Pali();
}

void MostrarRonda(int &Ronda)
{
    cout<<"                                              RONDA NUMERO: "<<Ronda<<endl<<endl;
}

void GanarAutomaticamente(int DadosStockJugador1Cantidad, int DadosStockJugador2Cantidad, int PuntajeJugador1,int PuntajeJugador2, string NombreJugador1, string NombreJugador2)
{
    if (DadosStockJugador1Cantidad == 0 || DadosStockJugador2Cantidad)
    {
        cout<<"********************************************************************************"<<endl;
        cout<<"      UNO DE LOS JUGADORES SE QUEDO SIN DADOS!!!"<<endl<<endl;
        if (DadosStockJugador1Cantidad == 0)
        {
            PuntajeJugador1 += 10000;
            cout<<"FELICIDADES "<<NombreJugador1<<"      TE QUEDASTE SIN DADOS, TOMA 10.000 PUNTOS Y GANAS AUTOMATICAMENTE!!!"<<endl;
        }
        else if (DadosStockJugador2Cantidad == 0)
        {
            PuntajeJugador2 += 10000;
            cout<<"FELICIDADES "<<NombreJugador2<<"      TE QUEDASTE SIN DADOS, TOMA 10.000 PUNTOS Y GANAS AUTOMATICAMENTE!!!"<<endl;
        }


    }



}
