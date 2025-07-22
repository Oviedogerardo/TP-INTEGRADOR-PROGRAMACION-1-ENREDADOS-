#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>
#include "DADOS.h"
#include "JUGAR.h"
#include "MOSTRARMENU.h"
#include "rlutil.h"



using namespace std;

///*********************
///FUNCIONES JUGADOR 1.-
///*********************

void MostrarNombreJugador1 (string NombreJugador1)
{
    cout<<NombreJugador1<<endl;
}

int DadoInicialJugador1(string NombreJugador1) /////ESTA FUNCION GENERA UN NUMERO ALEATORIO DE HASTA 6 NUMEROS, SE PUSO EL "+1" PARA QUE NO DE CERO NUNCA!
{
    int  ValorDadoJugador1 = rand() % 6 + 1;

    cout<<"El Valor del Dado Inicial de "<<NombreJugador1<<" es: "<<ValorDadoJugador1<<endl<<endl;

    return ValorDadoJugador1;
}

void DadosObjetivoJugador1(int &NumeroObjetivoJugador1, string NombreJugador1) //VARIABLE PASADA POR REFERENCIA DEL ARCHIVO DADOS.CPP PARA MODIFICAR SU VALOR Y USARLO
{
    int DadoObjetivoJugador1_A = rand() % 12 + 1;
    int DadoObjetivoJugador1_B = rand() % 12 + 1;

    cout << NombreJugador1 << " lanzo los dados objetivo y salieron: " << DadoObjetivoJugador1_A << " y " << DadoObjetivoJugador1_B << endl << endl;

    MostrarDadosObjetivoJugador1(DadoObjetivoJugador1_A,DadoObjetivoJugador1_B);

    NumeroObjetivoJugador1 = DadoObjetivoJugador1_A +  DadoObjetivoJugador1_B;

    cout<<endl;

    cout << "¡Vamos " << NombreJugador1 << "! Tenés que llegar a " << NumeroObjetivoJugador1 << " puntos para ganar esta ronda." << endl << endl;

    PausayLimpia();
}

void DadosStockJugador1 (int DadosStockJugador1Numero[], int DadosStockJugador1Cantidad)
{

    for (int i = 0; i < DadosStockJugador1Cantidad; i++) //CON ESTE FOR VAMOS RECORRIENDO TODO EL VECTOR Y DANDOLE EL VALOR A CADA DADO
    {
        DadosStockJugador1Numero[i] = rand() % 6 + 1; //CON ESTE RAND VAMOS DANDO EL VALOR A CADA DADO
        cout << "Dado #" << i + 1 << ": valor " << DadosStockJugador1Numero[i] << endl;
        DibujarDado(DadosStockJugador1Numero[i]);
    }

}

void ElegirDadosySumarJugador1 (int DadosStockJugador1Numero[], int &DadosStockJugador1Cantidad,
                                int &DadosStockJugador2Cantidad, int &NumeroObjetivoJugador1,
                                int &SumaDadosJugador1,int &DadosElegidosJugador1,
                                string &NombreJugador1, int PuntajeJugador1)
{
    int CantidadDadosElegidos = 0;
    int Numero;
    SumaDadosJugador1 = 0;
    bool Tirada = false;
    int PuntajeFinal;
    bool DadosUsados[12]; /*ESTA BANDERA/VECTOR VA A VALIDAR SI UN DADO YA FUE USADO PARA EVITAR ERRORES Y TIENE 12 INDICES PORQUE ES LA
                          CANTIDAD MAXIMA DE DADOS QUE PUEDEN EXISTIR EN LA PARTIDA PORQUE? SON 6 DADOS STOCK PARA
                          EL JUGADOR 1 Y EL JUGADOR 2*/

    for (int i = 0; i < 12; i++) /*ESTE FOR ESTA PARA INICIALIZAR LA BANDERA/VECTOR Y PONER TODOS LOS DADOS EN FALSE
                             PARA VALIDAR*/
    {
        DadosUsados[i] = false;
    }

    for (int i = 0; i < DadosStockJugador1Cantidad; i++)
    {
        cout << "Ingrese el número del dado que desea usar (o 0 para pasar el turno): " << endl;

        cin>>Numero;

        if (Numero == 0)
        {
            ColorTiradaNoExitosa();
            cout<<"Tirada no Exitosa (no suma puntos)"<<endl;

            ///ACA PONER BIEN GRANDE RESUMEN, DADOS ELEGIDOS, PUNTOS ACUMULADOS Y COMO LLEGO A ESO OSE A 12X 3 (CANTIDAD DADOS), TRANSFIERE TANTOS DADOS SI ES EXITOSA AL OTRO JUGADOR

            cout<<"LOS DADOS QUE TENES ACTUALMENTE: "<<DadosStockJugador1Cantidad<<endl<<endl;

            VuelveColor();

            PausayLimpia();

            return;
        }

        if (Numero < 1 || Numero > DadosStockJugador1Cantidad)
        {
            ColorAdvertencia();
            cout<< "El numero ingresado es incorrecto, Vuelve a tirar" <<endl;
            i--; //PARA REPETIR LA RONDA

            VuelveColor();
        }
        else if ((DadosUsados[Numero - 1] == true))
        {
            ColorTiradaFallida();
            cout << "¡Epa!Ese dado ya lo usaste. Elegí otro." << endl;
            VuelveColor();

            i--;
        }

        else
        {
            DadosUsados[Numero - 1] = true;
            SumaDadosJugador1 += DadosStockJugador1Numero[Numero - 1];
            CantidadDadosElegidos++;
            DadosElegidosJugador1 = CantidadDadosElegidos;

            cout<<"Va Sumando "<<SumaDadosJugador1<<endl<<endl;

            if (SumaDadosJugador1 == NumeroObjetivoJugador1)
            {

                Tirada = true;
                ColorTiradaExitosa();

                cout<<"¡Bien ahí! Sumaste justo " << NumeroObjetivoJugador1 << " puntos. ¡Tirada exitosa!" <<endl<<endl;

                cout<<"Los dados que seleccionaste ("<<CantidadDadosElegidos<<" en total) se los vamos a pasar al otro Jugador"<<endl<<endl;

                ///ACA PONER BIEN GRANDE RESUMEN, DADOS ELEGIDOS, PUNTOS ACUMULADOS Y COMO LLEGO A ESO OSE A 12X 3 (CANTIDAD DADOS), TRANSFIERE TANTOS DADOS SI ES EXITOSA AL OTRO JUGADOR


                if (Tirada == true)   ///ADEMAS ESTO VA A SER EL RESUMEN DE LA RONDA!
                {
                    DadosStockJugador1Cantidad = DadosStockJugador1Cantidad - CantidadDadosElegidos;
                    DadosStockJugador2Cantidad = DadosStockJugador2Cantidad + CantidadDadosElegidos;

                    cout<<"LOS DADOS QUE TENES ACTUALMENTE: "<<DadosStockJugador1Cantidad<<endl<<endl;

                    MostrarPuntajePuntajeJugador1(SumaDadosJugador1, DadosElegidosJugador1, NombreJugador1);

                    cout<<"Tira el proximo Jugador!!!"<<endl<<endl;

                    VuelveColor();
                    PausayLimpia();

                    return; ///ESTO SE AGREGO PARA SALIR DE LA FUNCION, SINO VUELVE A DAR LA VUELTA
                }
            }

            if (SumaDadosJugador1 > NumeroObjetivoJugador1 || SumaDadosJugador1 == 0)
            {
                Tirada = false;

                ColorTiradaFallida();
                cout<<"TIRADA FALLIDA!!!!"<<endl<<endl<<endl;
                cout<<"Como penalizacion al Jugador 2 le sacamos un dado y te lo damos a vos!!!"<<endl<<endl;


                if (DadosStockJugador1Cantidad > 1) //VALIDAMOS QUE EL JUGADOR 2 TENGA DADOS    ///ADEMAS ESTO VA A SER EL RESUMEN DE LA RONDA!
                {
                    DadosStockJugador2Cantidad--;
                    DadosStockJugador1Cantidad++;

                    ///ACA PONER BIEN GRANDE RESUMEN, DADOS ELEGIDOS, PUNTOS ACUMULADOS Y COMO LLEGO A ESO OSE A 12X 3 (CANTIDAD DADOS), TRANSFIERE TANTOS DADOS SI ES EXITOSA AL OTRO JUGADOR
                    SumaDadosJugador1 = 0;

                    cout<<"LOS DADOS QUE TENES ACTUALMENTE: "<<DadosStockJugador1Cantidad<<endl<<endl;

                    MostrarPuntajePuntajeJugador1(SumaDadosJugador1, DadosElegidosJugador1, NombreJugador1);

                    cout<<"Tira el proximo Jugador!!!"<<endl<<endl;

                    VuelveColor();
                    PausayLimpia();

                    return; ///ESTO SE AGREGO PARA SALIR DE LA FUNCION, SINO VUELVE A DAR LA VUELTA
                }
            }
        }
    }
}

void MostrarDadosObjetivoJugador1 (int DadoObjetivoJugador1_A, int DadoObjetivoJugador1_B)
{
    /// Dado A
    cout << "           ______     " << endl;
    cout << "          /      \\    " << endl;
    cout << "         /        \\   " << endl;
    cout << "        |   "   << DadoObjetivoJugador1_A << "     |   " << endl; // Más espacios aquí para asegurarte el centrado
    cout << "         \\        /   " << endl;
    cout << "          \\______/    " << endl;

    cout << endl; // Un espacio entre dados para que no se vean pegados

    /// Dado B
    cout << "           ______     " << endl;
    cout << "          /      \\    " << endl;
    cout << "         /        \\   " << endl;
    cout << "        |   "   << DadoObjetivoJugador1_B << "     |   " << endl; // Y aquí también
    cout << "         \\        /   " << endl;
    cout << "          \\______/    " << endl;


}

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

///*********************
///FUNCIONES JUGADOR 2.-
///*********************

void MostrarNombreJugador2 (string NombreJugador2)
{
    cout<<NombreJugador2<<endl;
}

int DadoInicialJugador2(string NombreJugador2) /////ESTA FUNCION GENERA UN NUMERO ALEATORIO DE HASTA 6 NUMEROS -OJO NO ESTAS TENIENDO EN CUENTA SI SALE CERO PORQUE EN REALIDAD ESTO ES UN DADO GIRANDO-
{
    int  ValorDadoJugador2 = rand() % 6 + 1;

    cout<<"El Valor del Dado Inicial de "<<NombreJugador2<<" es: "<<ValorDadoJugador2<<endl<<endl;

    return ValorDadoJugador2;
}

void DadosObjetivoJugador2(int &NumeroObjetivoJugador2, string NombreJugador2)   //VARIABLE PASADA POR REFERENCIA DEL ARCHIVO DADOS.CPP PARA MODIFICAR SU VALOR Y USARLO
{
    int DadoObjetivoJugador2_A = rand() % 12 + 1;
    int DadoObjetivoJugador2_B = rand() % 12 + 1;

    cout << NombreJugador2 << " lanzo los dados objetivo y salieron: " << DadoObjetivoJugador2_A << " y " << DadoObjetivoJugador2_B << endl << endl;

    MostrarDadosObjetivoJugador2(DadoObjetivoJugador2_A,DadoObjetivoJugador2_B);

    NumeroObjetivoJugador2 = DadoObjetivoJugador2_A +  DadoObjetivoJugador2_B;
    cout<<endl;
    cout << "¡Vamos " << NombreJugador2 << "! Tenés que llegar a " << NumeroObjetivoJugador2 << " puntos para ganar esta ronda." << endl << endl;

    PausayLimpia();
}

void DadosStockJugador2 (int DadosStockJugador2Numero[], int DadosStockJugador2Cantidad)
{
    for (int i = 0; i < DadosStockJugador2Cantidad; i++) //CON ESTE FOR VAMOS RECORRIENDO TODO EL VECTOR Y DANDOLE EL VALOR A CADA DADO
    {
        DadosStockJugador2Numero[i] = rand() % 6 + 1; //CON ESTE RAND VAMOS DANDO EL VALOR A CADA DADO
        cout << "Dado #" << i + 1 << ": valor " << DadosStockJugador2Numero[i] << endl;
        DibujarDado(DadosStockJugador2Numero[i]);
    }

    cout<<endl<<endl;//ESTO SE PUSO ACA PORQUE AL MOSTRAR LOS DADOS DE ARRIBA DEJA UN ESPACIO ESTETICO PARA EL CARTEL DE LOS DADOS A ELEGIR
}

void ElegirDadosySumarJugador2 (int DadosStockJugador2Numero[], int &DadosStockJugador2Cantidad,
                                int &DadosStockJugador1Cantidad,int &NumeroObjetivoJugador2,
                                int &SumaDadosJugador2,int &DadosElegidosJugador2,
                                string &NombreJugador2, int PuntajeJugador2)
{
    int CantidadDadosElegidos = 0;
    int Numero;
    SumaDadosJugador2 = 0;  //SE ASIGNO NUEVAMENTE 0 (CERO) A ESTA VARIABLE DE REFERENCIA PORQUE AL PASAR LAS RONDAS Y NO REINICIAR EL VALOR A CERO, NO SE PODRIA CUMPLIR (SumaDadosJugadorx == NumeroObjetivoJugador2)
    int PuntajeFinal;
    bool Tirada = false;
    bool DadosUsados[12]; /*ESTA BANDERA/VECTOR VA A VALIDAR SI UN DADO YA FUE USADO PARA EVITAR ERRORES Y TIENE 12 INDICES PORQUE ES LA
                          CANTIDAD MAXIMA DE DADOS QUE PUEDEN EXISTIR EN LA PARTIDA PORQUE? SON 6 DADOS STOCK PARA
                          EL JUGADOR 1 Y EL JUGADOR 2*/

    for (int i = 0; i < 12; i++)
    {
        DadosUsados[i] = false;
    }

    for (int i = 0; i < DadosStockJugador2Cantidad; i++)
    {
        cout << "Ingrese el número del dado que desea usar (o 0 para pasar el turno): " << endl;

        cin>>Numero;

        if (Numero == 0)
        {
            ColorTiradaNoExitosa();

            cout<<"Tirada no Exitosa (no suma puntos)"<<endl;

            ///ACA PONER BIEN GRANDE RESUMEN, DADOS ELEGIDOS, PUNTOS ACUMULADOS Y COMO LLEGO A ESO OSE A 12X 3 (CANTIDAD DADOS), TRANSFIERE TANTOS DADOS SI ES EXITOSA AL OTRO JUGADOR

            cout<<"LOS DADOS QUE TENES ACTUALMENTE: "<<DadosStockJugador2Cantidad<<endl<<endl;

            VuelveColor();
            PausayLimpia();

            return; ///ESTO SE AGREGO PARA SALIR DE LA FUNCION, SINO VUELVE A DAR LA VUELTA
        }

        if (Numero < 1 || Numero > DadosStockJugador2Cantidad)
        {
            ColorAdvertencia();
            cout<< "El numero ingresado es incorrecto, Vuelve a tirar" <<endl;
            i--; //PARA REPETIR LA RONDA
            VuelveColor();
        }
        else if ((DadosUsados[Numero - 1] == true))
        {
            ColorTiradaFallida();
            cout << "¡Epa!Ese dado ya lo usaste. Elegí otro."<< endl;
            VuelveColor();
            i--;
        }
            else
            {
                DadosUsados[Numero - 1] = true;
                SumaDadosJugador2 += DadosStockJugador2Numero[Numero-1];
                CantidadDadosElegidos++;
                DadosElegidosJugador2 = CantidadDadosElegidos;

                cout<<"Vas Sumando "<<SumaDadosJugador2<<endl<<endl;

                if (SumaDadosJugador2 == NumeroObjetivoJugador2)
                {
                    Tirada = true;

                ColorTiradaExitosa();
                cout<<"¡Bien ahí! Sumaste justo " << NumeroObjetivoJugador2 << " puntos. ¡Tirada exitosa!"<<endl<<endl;

                cout<<"Los dados que seleccionaste ("<<CantidadDadosElegidos<<" en total) se los vamos a pasar al otro Jugador"<<endl<<endl;



                ///ACA PONER BIEN GRANDE RESUMEN, DADOS ELEGIDOS, PUNTOS ACUMULADOS Y COMO LLEGO A ESO OSE A 12X 3 (CANTIDAD DADOS), TRANSFIERE TANTOS DADOS SI ES EXITOSA AL OTRO JUGADOR

                if (Tirada == true)  ///ADEMAS ESTO VA A SER EL RESUMEN DE LA RONDA!
                {
                    DadosStockJugador2Cantidad = DadosStockJugador2Cantidad - CantidadDadosElegidos;
                    DadosStockJugador1Cantidad = DadosStockJugador1Cantidad + CantidadDadosElegidos;

                    cout<<"LOS DADOS QUE TENES ACTUALMENTE: "<<DadosStockJugador2Cantidad<<endl<<endl;

                    MostrarPuntajePuntajeJugador2(SumaDadosJugador2, DadosElegidosJugador2, NombreJugador2);

                    cout<<"Tira el proximo Jugador!!!"<<endl<<endl;

                    VuelveColor();
                    PausayLimpia();

                    return; ///ESTO SE AGREGO PARA SALIR DE LA FUNCION, SINO VUELVE A DAR LA VUELTA
                }
            }

            if (SumaDadosJugador2 > NumeroObjetivoJugador2 || SumaDadosJugador2 == 0)
            {
                Tirada = false;

                ColorTiradaFallida();
                cout<<"TIRADA FALLIDA!!!!"<<endl<<endl<<endl;
                cout<<"Como penalizacion al Jugador 2 le sacamos un dado y te lo damos a vos!!!"<<endl<<endl;


                if (DadosStockJugador2Cantidad > 1) //VALIDAMOS QUE EL JUGADOR 1 TENGA DADOS    ///ADEMAS ESTO VA A SER EL RESUMEN DE LA RONDA!
                {
                    DadosStockJugador1Cantidad--;
                    DadosStockJugador2Cantidad++;

                    ///ACA PONER BIEN GRANDE RESUMEN, DADOS ELEGIDOS, PUNTOS ACUMULADOS Y COMO LLEGO A ESO OSE A 12X 3 (CANTIDAD DADOS), TRANSFIERE TANTOS DADOS SI ES EXITOSA AL OTRO JUGADOR

                    SumaDadosJugador2 = 0;
                    cout<<"LOS DADOS QUE TENES ACTUALMENTE: "<<DadosStockJugador2Cantidad<<endl<<endl;

                    MostrarPuntajePuntajeJugador2(SumaDadosJugador2, DadosElegidosJugador2, NombreJugador2);

                    cout<<"Tira el proximo Jugador!!!"<<endl<<endl;

                    VuelveColor();
                    PausayLimpia();

                    return; ///ESTO SE AGREGO PARA SALIR DE LA FUNCION, SINO VUELVE A DAR LA VUELTA
                }
            }
        }
    }
}

void MostrarDadosObjetivoJugador2 (int DadoObjetivoJugador2_A, int DadoObjetivoJugador2_B)
{
    /// Dado A
    cout << "           ______     " << endl;
    cout << "          /      \\    " << endl;
    cout << "         /        \\   " << endl;
    cout << "        |   "   << DadoObjetivoJugador2_A << "     |   " << endl; // Más espacios aquí para asegurarte el centrado
    cout << "         \\        /   " << endl;
    cout << "          \\______/    " << endl;

    cout << endl; // Un espacio entre dados para que no se vean pegados

    /// Dado B
    cout << "           ______     " << endl;
    cout << "          /      \\    " << endl;
    cout << "         /        \\   " << endl;
    cout << "        |   "   << DadoObjetivoJugador2_B << "     |   " << endl; // Y aquí también
    cout << "         \\        /   " << endl;
    cout << "          \\______/    " << endl;
}

///--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

///******************
///FUNCIONES VARIAS.-
///******************


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
