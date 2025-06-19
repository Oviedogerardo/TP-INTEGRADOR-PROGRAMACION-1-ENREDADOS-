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
    int NumeroObjetivo;  //VARIABLE INTERNA DE LA FUNCION NO AFECTA A NADA MAS
    int DadoObjetivoJugador1_A = rand() % 12 + 1;
    int DadoObjetivoJugador1_B = rand() % 12 + 1;



    cout<<DadoObjetivoJugador1_A<<endl;
    cout<<DadoObjetivoJugador1_B<<endl<<endl;



    NumeroObjetivo = DadoObjetivoJugador1_A +  DadoObjetivoJugador1_B;

    cout<<"El Numero Objetivo a llegar es: "<<NumeroObjetivo<<endl<<endl;



}

int DadosObjetivoJugador2()
{

    int NumeroObjetivo;  //VARIABLE INTERNA DE LA FUNCION NO AFECTA A NADA MAS
    int DadoObjetivoJugador2_A = rand() % 12 + 1;
    int DadoObjetivoJugador2_B = rand() % 12 + 1;


    cout<<DadoObjetivoJugador2_A<<endl;
    cout<<DadoObjetivoJugador2_B<<endl<<endl;

    NumeroObjetivo = DadoObjetivoJugador2_A +  DadoObjetivoJugador2_B;

    cout<<"El Numero Objetivo a llegar es: "<<NumeroObjetivo<<endl<<endl;


}

void DadosStockJugador1 (int DadosStockJugador1Numero[], int DadosStockJugadorCantidad)

{

    for (int i = 0; i < DadosStockJugadorCantidad; i++) //CON ESTE FOR VAMOS RECORRIENDO TODO EL VECTOR Y DANDOLE EL VALOR A CADA DADO
    {

        DadosStockJugador1Numero[i] = rand() % 6 + 1; //CON ESTE RAND VAMOS DANDO EL VALOR A CADA DADO
        cout<<DadosStockJugador1Numero[i]<<" ";


    }

    cout<<endl;//ESTO SE PUSO ACA PORQUE AL MOSTRAR LOS DADOS DE ARRIBA DEJA UN ESPACIO ESTETICO PARA EL CARTEL DE LOS DADOS A ELEGIR
    cout<<endl;
}

void DadosStockJugador2 (int DadosStockJugador2Numero[], int DadosStockJugadorCantidad)
{

    for (int i = 0; i < DadosStockJugadorCantidad; i++) //CON ESTE FOR VAMOS RECORRIENDO TODO EL VECTOR Y DANDOLE EL VALOR A CADA DADO
    {
        DadosStockJugador2Numero[i] = rand() % 6 + 1; //CON ESTE RAND VAMOS DANDO EL VALOR A CADA DADO
        cout<<DadosStockJugador2Numero[i]<<" ";


    }

}

void ElegirDadosySumarJugador1 (int DadosStockJugador1Numero[], int DadosStockJugador1Cantidad)
{
    int DadosElegidos;
    int SumaDados = 0;
    int IndiceVectorDados;
    bool DadosUsados[12]; /*ESTA BANDERA/VECTOR VA A VALIDAR SI UN DADO YA FUE USADO PARA EVITAR ERRORES Y TIENE 12 INDICES PORQUE ES LA
                          CANTIDAD MAXIMA DE DADOS QUE PUEDEN EXISTIR EN LA PARTIDA PORQUE? SON 6 DADOS STOCK PARA
                          EL JUGADOR 1 Y EL JUGADOR 2*/

    for (int i = 0; i < 12; i++) /*ESTE FOR ESTA PARA INICIALIZAR LA BANDERA/VECTOR Y PONER TODOS LOS DADOS EN FALSE
                                    PARA VALIDAR*/
    {
        DadosUsados[i] = false;
    }

    do
    {
        /*ESTO SE AGREGO PARA FORZAR A QUE EL MUCHACHO QUE VAYA A PONER EL DADO A ELEGIR LO PONGA BIEN, TENIENDO EN CUENTA
                   LA CANTIDAD DE DADOS QUE TIENE*/
        cout<<"DALE PA, Elegi cuantos dados vas a sumar: (como maximo podes "<<DadosStockJugador1Cantidad<<"):";
        cin>>DadosElegidos;

        if (DadosElegidos < 1 || DadosElegidos > DadosStockJugador1Cantidad)
        {
            cout<<"CAPO FIJATE LO QUE PONES, La cantidad pusiste con lo que tenes no va!!"<<endl;
        }
    }
    while (DadosElegidos < 1 || DadosElegidos > DadosStockJugador1Cantidad);



    for (int i = 0; i < DadosElegidos; i++)
    {
        cout<<"Elegi el Dado, del 1 al "<<DadosElegidos<<": ";
        cin>>IndiceVectorDados;

        if (IndiceVectorDados < 1 || IndiceVectorDados > DadosStockJugador1Cantidad)
        {

            cout<<"Genio, el numero que pusiste no va"<<endl;

            i--; /*ESTO SE AGREGO PARA QUE CUANDO EL PIBE/PIBA/PC ELIJA MAL EL NUMERO NO DE COMO VALIDA
                        LA VUELTA Y DE LA MISMA VUELTA DE NUEVO HASTA QUE LO HAGAN BIEN*/

        } else if (DadosUsados [IndiceVectorDados - 1] == true)
        {
            cout<<"MAQUINA, Mira el dado ya lo usaste, Elegi otro "<<endl;
            i--;
        } else
        {
            DadosUsados [IndiceVectorDados - 1] = true;

         SumaDados += DadosStockJugador1Numero [IndiceVectorDados - 1];
         cout<<"Van Sumados: "<<SumaDados<<endl;

        }

    }

    cout<<"La Suma de los dados Seleccionados es: "<<SumaDados<<endl;

}

void ElegirDadosySumarJugador2 (int DadosStockJugador2Numero[], int DadosStockJugador2Cantidad)
{
    int DadosElegidos;
    int SumaDados = 0;
    int IndiceVectorDados;
    bool DadosUsados[12]; /*ESTA BANDERA/VECTOR VA A VALIDAR SI UN DADO YA FUE USADO PARA EVITAR ERRORES Y TIENE 12 INDICES PORQUE ES LA
                          CANTIDAD MAXIMA DE DADOS QUE PUEDEN EXISTIR EN LA PARTIDA PORQUE? SON 6 DADOS STOCK PARA
                          EL JUGADOR 1 Y EL JUGADOR 2*/

    for (int i = 0; i < 12; i++) /*ESTE FOR ESTA PARA INICIALIZAR LA BANDERA/VECTOR Y PONER TODOS LOS DADOS EN FALSE
                                    PARA VALIDAR*/
    {
        DadosUsados[i] = false;
    }

    do
    {
        /*ESTO SE AGREGO PARA FORZAR A QUE EL MUCHACHO QUE VAYA A PONER EL DADO A ELEGIR LO PONGA BIEN, TENIENDO EN CUENTA
                   LA CANTIDAD DE DADOS QUE TIENE*/
        cout<<"DALE PA, Elegi cuantos dados vas a sumar: (como maximo podes "<<DadosStockJugador2Cantidad<<"):";
        cin>>DadosElegidos;

        if (DadosElegidos < 1 || DadosElegidos > DadosStockJugador2Cantidad)
        {
            cout<<"CAPO FIJATE LO QUE PONES, La cantidad pusiste con lo que tenes no va!!"<<endl;
        }
    }
    while (DadosElegidos < 1 || DadosElegidos > DadosStockJugador2Cantidad);



    for (int i = 0; i < DadosElegidos; i++)
    {
        cout<<"Elegi el Dado, del 1 al "<<DadosElegidos<<": ";
        cin>>IndiceVectorDados;

        if (IndiceVectorDados < 1 || IndiceVectorDados > DadosStockJugador2Cantidad)
        {

            cout<<"Genio, el numero que pusiste no va"<<endl;

            i--; /*ESTO SE AGREGO PARA QUE CUANDO EL PIBE/PIBA/PC ELIJA MAL EL NUMERO NO DE COMO VALIDA
                        LA VUELTA Y DE LA MISMA VUELTA DE NUEVO HASTA QUE LO HAGAN BIEN*/

        } else if (DadosUsados [IndiceVectorDados - 1] == true)
        {
            cout<<"MAQUINA, Mira el dado ya lo usaste, Elegi otro "<<endl;
            i--;
        } else
        {
            DadosUsados [IndiceVectorDados - 1] = true;

         SumaDados += DadosStockJugador2Numero [IndiceVectorDados - 1];
         cout<<"Van Sumados: "<<SumaDados<<endl;

        }

    }

    cout<<"La Suma de los dados Seleccionados es: "<<SumaDados<<endl;

}


void DibujarDado(int valor)
{
    cout << "+-------+" << endl;
    switch(valor)
    {
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







