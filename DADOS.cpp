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

void DadosObjetivoJugador1(int &NumeroObjetivoJugador1) //VARIABLE PASADA POR REFERENCIA DEL ARCHIVO DADOS.CPP PARA MODIFICAR SU VALOR Y USARLO
{

    int DadoObjetivoJugador1_A = rand() % 12 + 1;
    int DadoObjetivoJugador1_B = rand() % 12 + 1;



    cout<<DadoObjetivoJugador1_A<<endl;
    cout<<DadoObjetivoJugador1_B<<endl<<endl;



    NumeroObjetivoJugador1 = DadoObjetivoJugador1_A +  DadoObjetivoJugador1_B;

    cout<<"El Numero Objetivo a llegar es: "<<NumeroObjetivoJugador1<<endl<<endl;



}

void DadosObjetivoJugador2(int &NumeroObjetivoJugador2)   //VARIABLE PASADA POR REFERENCIA DEL ARCHIVO DADOS.CPP PARA MODIFICAR SU VALOR Y USARLO
{


    int DadoObjetivoJugador2_A = rand() % 12 + 1;
    int DadoObjetivoJugador2_B = rand() % 12 + 1;


    cout<<DadoObjetivoJugador2_A<<endl;
    cout<<DadoObjetivoJugador2_B<<endl<<endl;

    NumeroObjetivoJugador2 = DadoObjetivoJugador2_A +  DadoObjetivoJugador2_B;

    cout<<"El Numero Objetivo a llegar es: "<<NumeroObjetivoJugador2<<endl<<endl;


}

void DadosStockJugador1 (int DadosStockJugador1Numero[], int DadosStockJugador1Cantidad)

{

    for (int i = 0; i < DadosStockJugador1Cantidad; i++) //CON ESTE FOR VAMOS RECORRIENDO TODO EL VECTOR Y DANDOLE EL VALOR A CADA DADO
    {

        DadosStockJugador1Numero[i] = rand() % 6 + 1; //CON ESTE RAND VAMOS DANDO EL VALOR A CADA DADO
        cout<<DadosStockJugador1Numero[i]<<" ";


    }

    cout<<endl;//ESTO SE PUSO ACA PORQUE AL MOSTRAR LOS DADOS DE ARRIBA DEJA UN ESPACIO ESTETICO PARA EL CARTEL DE LOS DADOS A ELEGIR
    cout<<endl;
}

void DadosStockJugador2 (int DadosStockJugador2Numero[], int DadosStockJugador2Cantidad)
{

    for (int i = 0; i < DadosStockJugador2Cantidad; i++) //CON ESTE FOR VAMOS RECORRIENDO TODO EL VECTOR Y DANDOLE EL VALOR A CADA DADO
    {
        DadosStockJugador2Numero[i] = rand() % 6 + 1; //CON ESTE RAND VAMOS DANDO EL VALOR A CADA DADO
        cout<<DadosStockJugador2Numero[i]<<" ";


    }

    cout<<endl;//ESTO SE PUSO ACA PORQUE AL MOSTRAR LOS DADOS DE ARRIBA DEJA UN ESPACIO ESTETICO PARA EL CARTEL DE LOS DADOS A ELEGIR
    cout<<endl;

}

void ElegirDadosySumarJugador1 (int DadosStockJugador1Numero[], int &DadosStockJugador1Cantidad, int &DadosStockJugador2Cantidad, int &NumeroObjetivoJugador1,int &SumaDadosJugador1,int &DadosElegidosJugador1, string &NombreJugador1)
{
    SumaDadosJugador1 = 0;
    bool Tirada = false;
    int PuntajeFinal;
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
        cin>>DadosElegidosJugador1;

        if (DadosElegidosJugador1 < 1 || DadosElegidosJugador1 > DadosStockJugador1Cantidad)
        {
            cout<<"CAPO FIJATE LO QUE PONES, La cantidad pusiste con lo que tenes no va!!"<<endl;
        }
    }
    while (DadosElegidosJugador1 < 1 || DadosElegidosJugador1 > DadosStockJugador1Cantidad);



    for (int i = 0; i < DadosElegidosJugador1; i++)
    {
        cout<<"Elegi el Dado, del 1 al "<<DadosElegidosJugador1<<": ";
        cin>>IndiceVectorDados;

        if (IndiceVectorDados < 1 || IndiceVectorDados > DadosStockJugador1Cantidad)
        {

            cout<<"Genio, el numero que pusiste no va"<<endl;

            i--; /*ESTO SE AGREGO PARA QUE CUANDO EL PIBE/PIBA/PC ELIJA MAL EL NUMERO NO DE COMO VALIDA
                        LA VUELTA Y DE LA MISMA VUELTA DE NUEVO HASTA QUE LO HAGAN BIEN*/

        }
        else if (DadosUsados [IndiceVectorDados - 1] == true)
        {
            cout<<"MAQUINA, Mira el dado ya lo usaste, Elegi otro "<<endl;
            i--;
        }
        else
        {
            DadosUsados [IndiceVectorDados - 1] = true;

            SumaDadosJugador1 += DadosStockJugador1Numero [IndiceVectorDados - 1];
            cout<<"Van Sumados: "<<SumaDadosJugador1<<endl<<endl;

        }

    }

    cout<<"La Suma de los dados Seleccionados es: "<<SumaDadosJugador1<<endl<<endl;

    if (SumaDadosJugador1 == NumeroObjetivoJugador1)
    {
        Tirada = true;
        cout<<"Tirada Exitosa"<<endl<<endl;
        cout<<"Los dados que seleccionaste se los vamos a pasar al otro Jugador, Divertido no?"<<endl<<endl;


        if (Tirada == true)
        {
            DadosStockJugador1Cantidad = DadosStockJugador1Cantidad - DadosElegidosJugador1;
            DadosStockJugador2Cantidad = DadosStockJugador2Cantidad + DadosElegidosJugador1;

            cout<<"LOS DADOS QUE TENES ACTUALMENTE: "<<DadosStockJugador1Cantidad<<endl<<endl;


        }


        cout<<"Tira el proximo Jugador!!!"<<endl<<endl;
        Pali();


    }
    else
    {
        Tirada = false;
        cout<<"Tirada Fallida, solo tenias que hacer 1 sola cosa!!!!"<<endl<<endl;
        cout<<"TOMA....Como penalizacion al Jugador 2 le sacamos un dado y te lo damos a vos!!!"<<endl<<endl;

        if (DadosStockJugador2Cantidad > 1) //VALIDAMOS QUE EL JUGADOR 2 TENGA DADOS
        {
            DadosStockJugador2Cantidad--;
            DadosStockJugador1Cantidad++;
        }
        else if (DadosStockJugador1Cantidad == 0)
        {
            PuntajeFinal = SumaDadosJugador1 * DadosElegidosJugador1 + 10000;

            cout<<"FELICITACIONES PADRE, GANASTE ESTE JUEGO DE CONSOLA PERO.....A QUE COSTO?"<<endl<<endl;


        }

        cout<<"LOS DADOS QUE TENES ACTUALMENTE: "<<DadosStockJugador1Cantidad<<endl<<endl;
        MostrarPuntajePuntajeJugador1(SumaDadosJugador1, DadosElegidosJugador1, NombreJugador1);
    cout<<endl;

    }

}

void ElegirDadosySumarJugador2 (int DadosStockJugador2Numero[], int &DadosStockJugador2Cantidad, int &DadosStockJugador1Cantidad,int &NumeroObjetivoJugador2, int &SumaDadosJugador2,int &DadosElegidosJugador2, string &NombreJugador2)
{
    SumaDadosJugador2 = 0;  //SE ASIGNO NUEVAMENTE 0 (CERO) A ESTA VARIABLE DE REFERENCIA PORQUE AL PASAR LAS RONDAS Y NO REINICIAR EL VALOR A CERO, NO SE PODRIA CUMPLIR (SumaDadosJugadorx == NumeroObjetivoJugador2)
    int PuntajeFinal;
    bool Tirada = false;
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
        cin>>DadosElegidosJugador2;

        if (DadosElegidosJugador2 < 1 || DadosElegidosJugador2 > DadosStockJugador2Cantidad)
        {
            cout<<"CAPO FIJATE LO QUE PONES, La cantidad pusiste con lo que tenes no va!!"<<endl;
        }
    }
    while (DadosElegidosJugador2 < 1 || DadosElegidosJugador2 > DadosStockJugador2Cantidad);



    for (int i = 0; i < DadosElegidosJugador2; i++)
    {
        cout<<"Elegi el Dado, del 1 al "<<DadosStockJugador2Cantidad<<": ";
        cin>>IndiceVectorDados;

        if (IndiceVectorDados < 1 || IndiceVectorDados > DadosStockJugador2Cantidad)
        {

            cout<<"Genio, el numero que pusiste no va"<<endl;

            i--; /*ESTO SE AGREGO PARA QUE CUANDO EL PIBE/PIBA/PC ELIJA MAL EL NUMERO NO DE COMO VALIDA
                        LA VUELTA Y DE LA MISMA VUELTA DE NUEVO HASTA QUE LO HAGAN BIEN*/

        }
        else if (DadosUsados [IndiceVectorDados - 1] == true)
        {
            cout<<"MAQUINA, Mira el dado ya lo usaste, Elegi otro "<<endl;
            i--;
        }
        else
        {
            DadosUsados [IndiceVectorDados - 1] = true;

            SumaDadosJugador2 += DadosStockJugador2Numero [IndiceVectorDados - 1];
            cout<<"Van Sumados: "<<SumaDadosJugador2<<endl<<endl;

        }

    }

    cout<<"La Suma de los dados Seleccionados es: "<<SumaDadosJugador2<<endl<<endl;

    if (SumaDadosJugador2 == NumeroObjetivoJugador2)
    {
        Tirada = true;

        cout<<"Tirada Exitosa"<<endl<<endl;

        cout<<"Los dados que seleccionaste se los vamos a pasar al otro Jugador, Divertido no?"<<endl<<endl;

        if (Tirada == true)
        {
            DadosStockJugador2Cantidad = DadosStockJugador2Cantidad - DadosElegidosJugador2;
            DadosStockJugador1Cantidad = DadosStockJugador1Cantidad + DadosElegidosJugador2;

            cout<<"LOS DADOS QUE TENES ACTUALMENTE: "<<DadosStockJugador2Cantidad<<endl<<endl;


        }



        cout<<"Tira el proximo Jugador!!!"<<endl<<endl;
        Pali();


    }
    else
    {

        Tirada = false;
        cout<<"Tirada Fallida, solo tenias que hacer 1 sola cosa!!!!"<<endl<<endl<<endl;
        cout<<"TOMA....Como penalizacion al Jugador 2 le sacamos un dado y te lo damos a vos!!!"<<endl<<endl;

        if (DadosStockJugador2Cantidad > 1) //VALIDAMOS QUE EL JUGADOR 2 TENGA DADOS
        {
            DadosStockJugador1Cantidad--;
            DadosStockJugador2Cantidad++;
        }
        else if (DadosStockJugador2Cantidad == 0)
        {
            PuntajeFinal = SumaDadosJugador2 * DadosElegidosJugador2 + 10000;

            cout<<"FELICITACIONES PADRE, GANASTE ESTE JUEGO DE CONSOLA PERO.....A QUE COSTO?"<<endl;
            system("pause");

        }

        cout<<"LOS DADOS QUE TENES ACTUALMENTE: "<<DadosStockJugador2Cantidad<<endl<<endl;
        MostrarPuntajePuntajeJugador2(SumaDadosJugador2, DadosElegidosJugador2, NombreJugador2);
        cout<<endl;
    }
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







