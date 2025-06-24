#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>
#include "DADOS.h"
#include "JUGAR.h"
#include "MOSTRARMENU.h"
#include "rlutil.h"



using namespace std;


void MostrarNombreJugador1 (string NombreJugador1)
{
    cout<<NombreJugador1<<endl;
}
void MostrarNombreJugador2 (string NombreJugador2)
{
    cout<<NombreJugador2<<endl;
}


int DadoInicialJugador1(string NombreJugador1) /////ESTA FUNCION GENERA UN NUMERO ALEATORIO DE HASTA 6 NUMEROS, SE PUSO EL "+1" PARA QUE NO DE CERO NUNCA!
{
    int  ValorDadoJugador1 = rand() % 6 + 1;

    cout<<"El Valor del Dado Inicial de "<<NombreJugador1<<" es: "<<ValorDadoJugador1<<endl<<endl;

    return ValorDadoJugador1;
}

int DadoInicialJugador2(string NombreJugador2) /////ESTA FUNCION GENERA UN NUMERO ALEATORIO DE HASTA 6 NUMEROS -OJO NO ESTAS TENIENDO EN CUENTA SI SALE CERO PORQUE EN REALIDAD ESTO ES UN DADO GIRANDO-
{
    int  ValorDadoJugador2 = rand() % 6 + 1;

    cout<<"El Valor del Dado Inicial de "<<NombreJugador2<<" es: "<<ValorDadoJugador2<<endl<<endl;

    return ValorDadoJugador2;
}

void DadosObjetivoJugador1(int &NumeroObjetivoJugador1, string NombreJugador1) //VARIABLE PASADA POR REFERENCIA DEL ARCHIVO DADOS.CPP PARA MODIFICAR SU VALOR Y USARLO
{
    int DadoObjetivoJugador1_A = rand() % 12 + 1;
    int DadoObjetivoJugador1_B = rand() % 12 + 1;

    cout<<"Valor primer dado Objetivo de "<<NombreJugador1<<": "<<DadoObjetivoJugador1_A<<endl;
    cout<<"Valor segundo dado Objetivo de "<<NombreJugador1<<": "<<DadoObjetivoJugador1_B<<endl<<endl;

    MostrarDadosObjetivoJugador1(DadoObjetivoJugador1_A,DadoObjetivoJugador1_B);

    NumeroObjetivoJugador1 = DadoObjetivoJugador1_A +  DadoObjetivoJugador1_B;

    cout<<endl;

    cout<<"El Numero Objetivo a llegar es: "<<NumeroObjetivoJugador1<<endl<<endl;
    Pali();
}

void DadosObjetivoJugador2(int &NumeroObjetivoJugador2, string NombreJugador2)   //VARIABLE PASADA POR REFERENCIA DEL ARCHIVO DADOS.CPP PARA MODIFICAR SU VALOR Y USARLO
{
    int DadoObjetivoJugador2_A = rand() % 12 + 1;
    int DadoObjetivoJugador2_B = rand() % 12 + 1;


    cout<<"Valor primer dado Objetivo de "<<NombreJugador2<<": "<<DadoObjetivoJugador2_A<<endl;
    cout<<"Valor segundo dado Objetivo de "<<NombreJugador2<<": "<<DadoObjetivoJugador2_B<<endl<<endl;

    MostrarDadosObjetivoJugador2(DadoObjetivoJugador2_A,DadoObjetivoJugador2_B);

    NumeroObjetivoJugador2 = DadoObjetivoJugador2_A +  DadoObjetivoJugador2_B;
    cout<<endl;
    cout<<"El Numero Objetivo a llegar es: "<<NumeroObjetivoJugador2<<endl<<endl;
    Pali();
}

void DadosStockJugador1 (int DadosStockJugador1Numero[], int DadosStockJugador1Cantidad)
{

    for (int i = 0; i < DadosStockJugador1Cantidad; i++) //CON ESTE FOR VAMOS RECORRIENDO TODO EL VECTOR Y DANDOLE EL VALOR A CADA DADO
    {
        DadosStockJugador1Numero[i] = rand() % 6 + 1; //CON ESTE RAND VAMOS DANDO EL VALOR A CADA DADO
        cout << "El numero del dado "<< i+1 << " es: " << DadosStockJugador1Numero[i]<<endl;
        DibujarDado(DadosStockJugador1Numero[i]);
    }

}

void DadosStockJugador2 (int DadosStockJugador2Numero[], int DadosStockJugador2Cantidad)
{

    for (int i = 0; i < DadosStockJugador2Cantidad; i++) //CON ESTE FOR VAMOS RECORRIENDO TODO EL VECTOR Y DANDOLE EL VALOR A CADA DADO
    {
        DadosStockJugador2Numero[i] = rand() % 6 + 1; //CON ESTE RAND VAMOS DANDO EL VALOR A CADA DADO
        cout << "El numero del dado "<< i+1 << " es: " << DadosStockJugador2Numero[i]<<endl;
        DibujarDado(DadosStockJugador2Numero[i]);
    }

    cout<<endl<<endl;//ESTO SE PUSO ACA PORQUE AL MOSTRAR LOS DADOS DE ARRIBA DEJA UN ESPACIO ESTETICO PARA EL CARTEL DE LOS DADOS A ELEGIR
}

void ElegirDadosySumarJugador1 (int DadosStockJugador1Numero[], int &DadosStockJugador1Cantidad, int &DadosStockJugador2Cantidad, int &NumeroObjetivoJugador1,int &SumaDadosJugador1,int &DadosElegidosJugador1, string &NombreJugador1, int PuntajeJugador1)
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
        /*ESTO SE AGREGO PARA FORZAR A QUE EL MUCHACHO/A QUE VAYA A PONER EL DADO A ELEGIR LO PONGA BIEN, TENIENDO EN CUENTA
                   LA CANTIDAD DE DADOS QUE TIENE*/
        cout<<"DALE PA, Elegi cuantos dados vas a Utilizar: (como maximo podes "<<DadosStockJugador1Cantidad<<"):";

        cin>>DadosElegidosJugador1;

        if (DadosElegidosJugador1 < 1 || DadosElegidosJugador1 > DadosStockJugador1Cantidad) //PARA VALIDAR QUE AL MENOS 1 DADO Y COMO MAXIMO LOS QUE TIENE DISPONIBLES SE UTILICEN PARA ELEGIR
        {
            rlutil::setColor(rlutil::RED);
            cout<<"CAPO FIJATE LO QUE PONES, La cantidad pusiste con lo que tenes no va!!"<<endl;
            rlutil::setColor(rlutil::BLACK);
        }
    }
    while (DadosElegidosJugador1 < 1 || DadosElegidosJugador1 > DadosStockJugador1Cantidad);

    for (int i = 0; i < DadosElegidosJugador1; i++)


    {
        cout<<"Elegi el Dado, del 1 al "<<DadosElegidosJugador1<<": ";
        cin>>IndiceVectorDados;

        if (IndiceVectorDados < 1 || IndiceVectorDados > DadosStockJugador1Cantidad)    //SE VALIDA SI LOS DADOS QUE EL JUGADOR ELIGIO SON MAYORES A LOS DADOS DE STOCK
        {
            rlutil::setColor(rlutil::RED);
            cout<<"Genio, el numero que pusiste no va"<<endl;
            rlutil::setColor(rlutil::BLACK);

            i--; /*ESTO SE AGREGO PARA QUE CUANDO EL PIBE/PIBA/PC ELIJA MAL EL NUMERO NO DE COMO VALIDA
                        LA VUELTA Y DE LA MISMA VUELTA DE NUEVO HASTA QUE LO HAGAN BIEN*/
        }
        else if (DadosUsados [IndiceVectorDados - 1] == true) //EVALUA SI YA SE ELIGIO, COMO? SI ES FALSE, AL SEGUIR EL DADO/NUMERO PASA A TRUE Y AL HACER LA VUELTA ENTRA DE NUEVO
        {
            rlutil::setColor(rlutil::RED);                                                  //LLEGADO EL CASO DE Q EL MISMO INDICE SEA TRUE, TIRA ADVERTENCIA Y SE TIRA DE NUEVO!
            cout<<"MAQUINA, Mira el dado ya lo usaste, Elegi otro "<<endl;
            rlutil::setColor(rlutil::BLACK);
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

    Pali();
    //system("cls");

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

            MostrarPuntajePuntajeJugador1(SumaDadosJugador1, DadosElegidosJugador1, NombreJugador1);
        }

        cout<<"Tira el proximo Jugador!!!"<<endl<<endl;
        Pali();
    }
    else
    {
        Tirada = false;
        rlutil::setColor(rlutil::RED);
        cout<<"Tirada Fallida, solo tenias que hacer 1 sola cosa!!!!"<<endl<<endl;
        cout<<"TOMA....Como penalizacion al Jugador 2 le sacamos un dado y te lo damos a vos!!!"<<endl<<endl;
         rlutil::setColor(rlutil::BLACK);
        if (DadosStockJugador2Cantidad > 1) //VALIDAMOS QUE EL JUGADOR 2 TENGA DADOS
        {
            DadosStockJugador2Cantidad--;
            DadosStockJugador1Cantidad++;

            cout<<"LOS DADOS QUE TENES ACTUALMENTE: "<<DadosStockJugador1Cantidad<<endl<<endl;
        }
        else if (DadosStockJugador1Cantidad == 0)
        {
            cout<<"LOS DADOS QUE TENES ACTUALMENTE: "<<DadosStockJugador1Cantidad<<endl<<endl;
            PuntajeFinal = SumaDadosJugador1 * DadosElegidosJugador1 + PuntajeJugador1 + 10000;

            cout<<"FELICITACIONES PADRE, GANASTE CON "<<PuntajeFinal<<" PUNTOS ESTE JUEGO DE CONSOLA PERO.....A QUE COSTO?"<<endl<<endl;
        }

        MostrarPuntajePuntajeJugador1(SumaDadosJugador1, DadosElegidosJugador1, NombreJugador1);
        Pali();
        cout<<endl;
    }
}

void ElegirDadosySumarJugador2 (int DadosStockJugador2Numero[], int &DadosStockJugador2Cantidad, int &DadosStockJugador1Cantidad,int &NumeroObjetivoJugador2, int &SumaDadosJugador2,int &DadosElegidosJugador2, string &NombreJugador2, int PuntajeJugador2)
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
        cout<<"DALE PA, Elegi cuantos dados vas a Utilizar: (como maximo podes "<<DadosStockJugador2Cantidad<<"):";
        cin>>DadosElegidosJugador2;

        if (DadosElegidosJugador2 < 1 || DadosElegidosJugador2 > DadosStockJugador2Cantidad)
        {
            rlutil::setColor(rlutil::RED);
            cout<<"CAPO FIJATE LO QUE PONES, La cantidad pusiste con lo que tenes no va!!"<<endl;
            rlutil::setColor(rlutil::BLACK);
        }
    }
    while (DadosElegidosJugador2 < 1 || DadosElegidosJugador2 > DadosStockJugador2Cantidad);

    for (int i = 0; i < DadosElegidosJugador2; i++)
    {
        cout<<"Elegi el Dado, del 1 al "<<DadosElegidosJugador2<<": ";
        cin>>IndiceVectorDados;

        if (IndiceVectorDados < 1 || IndiceVectorDados > DadosStockJugador2Cantidad)
        {
            rlutil::setColor(rlutil::RED);
            cout<<"Genio, el numero que pusiste no va"<<endl;
            rlutil::setColor(rlutil::BLACK);

            i--; /*ESTO SE AGREGO PARA QUE CUANDO EL PIBE/PIBA/PC ELIJA MAL EL NUMERO NO DE COMO VALIDA
                        LA VUELTA Y DE LA MISMA VUELTA DE NUEVO HASTA QUE LO HAGAN BIEN*/
        }
        else if (DadosUsados [IndiceVectorDados - 1] == true)
        {
            rlutil::setColor(rlutil::RED);
            cout<<"MAQUINA, Mira el dado ya lo usaste, Elegi otro "<<endl;
            rlutil::setColor(rlutil::BLACK);
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

    Pali();
    //system("cls");

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

            MostrarPuntajePuntajeJugador2(SumaDadosJugador2, DadosElegidosJugador2, NombreJugador2);
        }

        cout<<"Tira el proximo Jugador!!!"<<endl<<endl;

        Pali();
    }
    else
    {
        Tirada = false;

        rlutil::setColor(rlutil::RED);
        cout<<"Tirada Fallida, solo tenias que hacer 1 sola cosa!!!!"<<endl<<endl<<endl;
        cout<<"TOMA....Como penalizacion al Jugador 1 le sacamos un dado y te lo damos a vos!!!"<<endl<<endl;
        rlutil::setColor(rlutil::BLACK);

        if (DadosStockJugador2Cantidad > 1) //VALIDAMOS QUE EL JUGADOR 2 TENGA DADOS
        {
            DadosStockJugador1Cantidad--;
            DadosStockJugador2Cantidad++;

            cout<<"LOS DADOS QUE TENES ACTUALMENTE: "<<DadosStockJugador2Cantidad<<endl<<endl;
        }
        else if (DadosStockJugador2Cantidad == 0)
        {
            cout<<"LOS DADOS QUE TENES ACTUALMENTE: "<<DadosStockJugador2Cantidad<<endl<<endl;
            PuntajeFinal = SumaDadosJugador2 * DadosElegidosJugador2 + PuntajeJugador2 + 10000;

            cout<<"FELICITACIONES PADRE, GANASTE CON "<<PuntajeFinal<<" PUNTOS ESTE JUEGO DE CONSOLA PERO.....A QUE COSTO?"<<endl<<endl;
            system("pause");
        }

        MostrarPuntajePuntajeJugador2(SumaDadosJugador2, DadosElegidosJugador2, NombreJugador2);
        Pali();
        cout<<endl;
    }
}

void DibujarDado(int valor)
{

    switch(valor)
    {
    case 1:
        cout << "+-------+" << endl;
        cout << "|       |" << endl;
        cout << "|   *   |" << endl;
        cout << "|       |" << endl;
        cout << "+-------+" << endl;
        break;
    case 2:
        cout << "+-------+" << endl;
        cout << "| *     |" << endl;
        cout << "|       |" << endl;
        cout << "|     * |" << endl;
        cout << "+-------+"  << endl;
        break;
    case 3:
        cout << "+-------+" << endl;
        cout << "| *     |" << endl;
        cout << "|   *   |" << endl;
        cout << "|     * |" << endl;
        cout << "+-------+"  << endl;
        break;
    case 4:
        cout << "+-------+" << endl;
        cout << "| *   * |" << endl;
        cout << "|       |" << endl;
        cout << "| *   * |" << endl;
        cout << "+-------+" << endl;
        break;
    case 5:
        cout << "+-------+" << endl;
        cout << "| *   * |" << endl;
        cout << "|   *   |" << endl;
        cout << "| *   * |" << endl;
        cout << "+-------+"  << endl;
        break;
    case 6:
        cout << "+-------+" << endl;
        cout << "| *   * |" << endl;
        cout << "| *   * |" << endl;
        cout << "| *   * |" << endl;
        cout << "+-------+" << endl;
        break;
    }
}

void MostrarDadosObjetivoJugador1 (int DadoObjetivoJugador1_A, int DadoObjetivoJugador1_B)
{
    // Dado A
    cout << "           ______     " << endl;
    cout << "          /      \\    " << endl;
    cout << "         /        \\   " << endl;
    cout << "        |   "   << DadoObjetivoJugador1_A << "     |   " << endl; // Más espacios aquí para asegurarte el centrado
    cout << "         \\        /   " << endl;
    cout << "          \\______/    " << endl;

    cout << endl; // Un espacio entre dados para que no se vean pegados

    // Dado B
    cout << "           ______     " << endl;
    cout << "          /      \\    " << endl;
    cout << "         /        \\   " << endl;
    cout << "        |   "   << DadoObjetivoJugador1_B << "     |   " << endl; // Y aquí también
    cout << "         \\        /   " << endl;
    cout << "          \\______/    " << endl;

   //system("pause");
}


void MostrarDadosObjetivoJugador2 (int DadoObjetivoJugador2_A, int DadoObjetivoJugador2_B)
{
    // Dado A
    cout << "           ______     " << endl;
    cout << "          /      \\    " << endl;
    cout << "         /        \\   " << endl;
    cout << "        |   "   << DadoObjetivoJugador2_A << "     |   " << endl; // Más espacios aquí para asegurarte el centrado
    cout << "         \\        /   " << endl;
    cout << "          \\______/    " << endl;

    cout << endl; // Un espacio entre dados para que no se vean pegados

    // Dado B
    cout << "           ______     " << endl;
    cout << "          /      \\    " << endl;
    cout << "         /        \\   " << endl;
    cout << "        |   "   << DadoObjetivoJugador2_B << "     |   " << endl; // Y aquí también
    cout << "         \\        /   " << endl;
    cout << "          \\______/    " << endl;

    //system("pause");
}
