#include <iostream>
#include <ctime>
#include <cstdlib>
#include <clocale>
#include "JUGAR.h"

using namespace std;

int main()
{
    int Despedida;
    int Opcion;
    int CantidadJugadores;
    int NombreJugadorNumero [CantidadJugadores]= {0};
    string NombreJugadorLetras [CantidadJugadores];
    int ValorDadoInicial[CantidadJugadores] = {0};

    ///INCIALIZAMOS LOS ARRAY:
    for (int i = 0; i < CantidadJugadores;i++)
    {
    NombreJugadorNumero[i] = 0;
    ValorDadoInicial[i] = 0;

    }


    srand(time(0));

    do
    {
        MostrarTitulo();

        MostrarOpciones();
        PedirOpciones(Opcion, Despedida,
                      CantidadJugadores,NombreJugadorNumero,
                      NombreJugadorLetras,ValorDadoInicial);
    }
    while (Opcion != 0);








    return 0;
}
