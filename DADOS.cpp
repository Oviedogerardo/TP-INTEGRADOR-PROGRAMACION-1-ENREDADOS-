#include <iostream>
#include <cstdlib>
#include <ctime>
#include "DADOS.h"
#include "JUGAR.h"

using namespace std;


void MostrarSeisDados()
{



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






