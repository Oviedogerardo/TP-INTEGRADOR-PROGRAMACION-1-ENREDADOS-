#include <iostream>
#include <cstdlib>
#include <ctime>
#include "DADOS.h"
#include "JUGAR.h"
#include "MOSTRARMENU.h"

using namespace std;


void MostrarSeisDados() //DADOS INICIALES
{



}


void MostrarNombreJugador1 (string NombreJugador1)
{

    cout<<NombreJugador1<<endl;

}
void MostrarNombreJugador2 (string NombreJugador2)
{

    cout<<NombreJugador2<<endl;

}


int DadoInicialJugador1() /////ESTA FUNCION GENERA UN NUMERO ALEATORIO DE HASTA 6 NUMEROS, SE PUSO EL "+1" PARA QUE NO DE CERO NUNCA!
{

    int  ValorDadoJugador1 = rand() % 6 + 1;

    cout<<"El Valor del Dado Inicial del Jugador 1 es: "<<ValorDadoJugador1<<endl;

    return ValorDadoJugador1;

}

int DadoInicialJugador2() /////ESTA FUNCION GENERA UN NUMERO ALEATORIO DE HASTA 6 NUMEROS -OJO NO ESTAS TENIENDO EN CUENTA SI SALE CERO PORQUE EN REALIDAD ESTO ES UN DADO GIRANDO-
{

    int  ValorDadoJugador2 = rand() % 6 + 1;

    cout<<"El Valor del Dado Inicial del Jugador 2 es: "<<ValorDadoJugador2<<endl;

    return ValorDadoJugador2;
}

int DadosObjetivoJugador1()
{
    int SumaDados;  //VARIABLE INTERNA DE LA FUNCION NO AFECTA A NADA MAS
    int DadoObjetivoJugador1_A = rand() % 12 + 1;
    int DadoObjetivoJugador1_B = rand() % 12 + 1;



    cout<<DadoObjetivoJugador1_A<<endl;
    cout<<DadoObjetivoJugador1_B<<endl<<endl;



    SumaDados = DadoObjetivoJugador1_A +  DadoObjetivoJugador1_B;

    cout<<"El Numero Objetivo a llegar es: "<<SumaDados<<endl;



}

int DadosObjetivoJugador2()
{

    int SumaDados;  //VARIABLE INTERNA DE LA FUNCION NO AFECTA A NADA MAS
    int DadoObjetivoJugador2_A = rand() % 12 + 1;
    int DadoObjetivoJugador2_B = rand() % 12 + 1;


    cout<<DadoObjetivoJugador2_A<<endl;
    cout<<DadoObjetivoJugador2_B<<endl<<endl;

    SumaDados = DadoObjetivoJugador2_A +  DadoObjetivoJugador2_B;

    cout<<"El Numero Objetivo a llegar es: "<<SumaDados<<endl;


}

void DadosStockJugador1 (int DadosStockJugador1Numero[], int DadosStockJugadorCantidad)

{

    for (int i = 0; i < DadosStockJugadorCantidad; i++) //CON ESTE FOR VAMOS RECORRIENDO TODO EL VECTOR Y DANDOLE EL VALOR A CADA DADO
    {

        DadosStockJugador1Numero[i] = rand() % 6 + 1; //CON ESTE RAND VAMOS DANDO EL VALOR A CADA DADO

        cout<<DadosStockJugador1Numero[i]<<endl;


    }


}

void DadosStockJugador2 (int DadosStockJugador2Numero[], int DadosStockJugadorCantidad)
{


    for (int i = 0; i < DadosStockJugadorCantidad; i++) //CON ESTE FOR VAMOS RECORRIENDO TODO EL VECTOR Y DANDOLE EL VALOR A CADA DADO
    {

        DadosStockJugador2Numero[i] = rand() % 6 + 1; //CON ESTE RAND VAMOS DANDO EL VALOR A CADA DADO

        cout<<DadosStockJugador2Numero[i]<<endl;
    }


}

void DibujarDado(int valor)
 {
    cout << "+-------+" << endl;
    switch(valor) {
        case 1:
            cout << "|       |" << endl;
            cout << "|   *   |" << endl;
            cout << "|       |" << endl;
            break;
        case 2:
            cout << "| *     |" << endl;
            cout << "|       |" << endl;
            cout << "|     * |" << endl;
            break;
        case 3:
            cout << "| *     |" << endl;
            cout << "|   *   |" << endl;
            cout << "|     * |" << endl;
            break;
        case 4:
            cout << "| *   * |" << endl;
            cout << "|       |" << endl;
            cout << "| *   * |" << endl;
            break;
        case 5:
            cout << "| *   * |" << endl;
            cout << "|   *   |" << endl;
            cout << "| *   * |" << endl;
            break;
        case 6:
            cout << "| *   * |" << endl;
            cout << "| *   * |" << endl;
            cout << "| *   * |" << endl;
            break;
    }
    cout << "+-------+" << endl;
}







