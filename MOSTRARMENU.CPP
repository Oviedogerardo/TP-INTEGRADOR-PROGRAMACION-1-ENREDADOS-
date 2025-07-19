#include <iostream>
#include <clocale>
#include "MOSTRARMENU.h"
#include "JUGAR.h"
#include "DADOS.h"
#include "rlutil.h"

using namespace std;

void MostrarTitulo()
{
    int Equis = 41;
    int LaY = 1;

    Limpia();

    rlutil::locate(Equis,LaY++);
    cout<<"#######  #     #  ######   #######  #####       #     #####      ###     #####";
    rlutil::locate(Equis,LaY++);
    cout<<"#        ##    #  #     #  #        #    #      #     #    #    #   #   #     #";
    rlutil::locate(Equis,LaY++);
    cout<<"#        # #   #  #     #  #        #     #    ###    #     #  #     #  #";
    rlutil::locate(Equis,LaY++);
    cout<<"#####    #  #  #  ######   #####    #     #    # #    #     #  #     #   #####";
    rlutil::locate(Equis,LaY++);
    cout<<"#        #   # #  #   #    #        #     #   #####   #     #  #     #        ";
    rlutil::locate(Equis,LaY++);
    cout<<"#        #    ##  #    #   #        #    #    #   #   #    #    #   #   #     #";
    rlutil::locate(Equis,LaY++);
    cout<<"#######  #     #  #     #  #######  #####    ##   ##  #####      ###     #####";
}

void MostrarMenu(int &opcion)
{
    int Equis = 71;
    int LaY = 10;

    rlutil::locate(Equis,LaY++);
    cout<<"+---------------------+";
    rlutil::locate(Equis,LaY++);
    cout<<"|1 - JUGAR            |";
    rlutil::locate(Equis,LaY++);
    cout<<"|2 - ESTADISTICAS     |";
    rlutil::locate(Equis,LaY++);
    cout<<"|3 - CREDITOS         |";
    rlutil::locate(Equis,LaY++);
    cout<<"|0 - SALIR            |";
    rlutil::locate(Equis,LaY++);
    cout<<"+---------------------+";
    rlutil::locate(Equis,LaY+3);
    cout<<"Ingrese una opcion: ";
    cin >> opcion;
}

void Menu()
{
    ///*********************
    ///VARIABLES JUGADOR 1.-
    ///*********************

    string NombreJugador1;//DECLARACION DE LA VARIABLE PARA EL NOMBRE
    int ValorDadoInicialJugador1; //DECLARACION DE LA VARIABLE PARA GUARDAR EL NUMERO QUE NOS DE LA FUNCION RAND
    int NumeroObjetivoJugador1;  //VARIABLE PARA PODER LLAMAR DESPUES DE QUE PASE POR LA FUNCION PARA VALIDAR DADOS DESPUES
    int DadosStockJugador1Cantidad = 6; //DECLARACION DE VARIABLE DE CANTIDAD DE DADOS
    int DadosStockJugador1Numero [DadosStockJugador1Cantidad]; //DECLARACION DE VECTOR DE DADOS DE STOCK PARA GUARDAR EL VALOR DE CADA DADO
    int DadosElegidosJugador1;
    int SumaDadosJugador1 = 0; //SE CREO ESTA VARIABLE PARA DESPUES CALCULAR LOS PUNTOS
    int PuntajeJugador1 = 0;

    ///*********************
    ///VARIABLES JUGADOR 2.-
    ///*********************

    string NombreJugador2;//DECLARACION DE LA VARIABLE PARA EL NOMBRE
    int ValorDadoInicialJugador2; //DECLARACION DE LA VARIABLE PARA GUARDAR EL NUMERO QUE NOS DE LA FUNCION RAND
    int DadoMayor; //DECLARACION DE LA VARIABLE PARA GUARDAR EL VALOR QUE NOS SALGA DE VALIDAR SI UNO U OTRO DADO ES MAYOR
    int NumeroObjetivoJugador2;  //VARIABLE PARA PODER LLAMAR DESPUES DE QUE PASE POR LA FUNCION PARA VALIDAR DADOS DESPUES
    int DadosStockJugador2Cantidad = 6; //DECLARACION DE VARIABLE DE CANTIDAD DE DADOS
    int DadosStockJugador2Numero [DadosStockJugador2Cantidad]; //DECLARACION DE VECTOR DE DADOS DE STOCK PARA GUARDAR EL VALOR DE CADA DADO
    int DadosElegidosJugador2;
    int SumaDadosJugador2 = 0;  //SE CREO ESTA VARIABLE PARA DESPUES CALCULAR LOS PUNTOS
    int PuntajeJugador2 = 0;

    ///*********************
    ///VARIABLES VARIAS.-
    ///*********************

    int Ronda = 1;
    int Empieza;
    int opcion; //DECLARACION DE VARIABLE PARA PODER GUARDAR LA OPCION QUE NOS PIDA

    do  //ES UN "DO/WHILE" PORQUE PRIMERO QUEREMOS QUE MUESTRE EL MENU Y DESPUES EL RESTO
    {
        // rlutil::locate(0,0);

        MostrarTitulo();

        MostrarMenu(opcion);

        //cin >> opcion;

        switch (opcion)
        {

        case 0:

            rlutil::locate(105,2);
            cout << "Gracias por jugar" << endl << endl << endl;

            break;

        case 1:

            ReiniciarValores(DadosStockJugador1Cantidad,SumaDadosJugador1,
                             PuntajeJugador1,DadosStockJugador2Cantidad,
                             SumaDadosJugador2, PuntajeJugador2); //ESTA FUNCION SE UTILIZA EN EL CASO DE QUE SE EMPIECE OTRA PARTIRA

            Limpia();

            NombreJugador1 = PedirNombreJugador1(); //UTILIZAMOS ESTA FUNCION EN ESTA VARIABLE PARA GUARDAR EL VALOR
            NombreJugador2 = PedirNombreJugador2(); //UTILIZAMOS ESTA FUNCION EN ESTA VARIABLE PARA GUARDAR EL VALOR

            Limpia();

            rlutil::locate(105,2);
            cout<<"              Ambos jugadores lanzaran sus dados para ver quién arranca. ¡Mucha suerte y que los dados estén de su lado!                            "<<endl;

            PausayLimpia();

            MostrarNombres(NombreJugador1,NombreJugador2);
            ValorDadoInicialJugador1 = DadoInicialJugador1(NombreJugador1);    //ACA PODEMOS VALIDAR CON 1; PARA EVITAR ESPERAR A QUE DE EL NUMERO IGUAL EJ: ValorDadoInicialJugador1 = 1, PARA VER SI EL SEGUNDO JUGADOR EMPIEZA PRIMERO Y SI ESTA BIEN HECHO.
            DibujarDado(ValorDadoInicialJugador1);
            ValorDadoInicialJugador2 = DadoInicialJugador2(NombreJugador2);    //ACA PODEMOS VALIDAR CON 1; PARA EVITAR ESPERAR A QUE DE EL NUMERO IGUAL EJ: ValorDadoInicialJugador2 = 1, PARA VER SI EL PRIMER JUGADOR EMPIEZA PRIMERO Y SI ESTA BIEN HECHO.
            DibujarDado(ValorDadoInicialJugador2); //USAMOS ESTA FUNCION PARA GRAFICAR LOS DADOS INICIALES

            PausayLimpia();

            while (ValorDadoInicialJugador1 == ValorDadoInicialJugador2) //UTILIZAMOS ESTE WHILE PARA TIRAR NUEVAMENTE EN CASO DE QUE LOS NUMEROS DE LOS DADOS INICIALES SEAN IGUALES!!!
            {
                rlutil::locate(105,2);
                cout<<"Como ambos Jugadores empataron se tira nuevamente: "<<endl<<endl;
                ValorDadoInicialJugador1 = DadoInicialJugador1(NombreJugador1);
                DibujarDado(ValorDadoInicialJugador1);
                ValorDadoInicialJugador2 = DadoInicialJugador2(NombreJugador2);
                DibujarDado(ValorDadoInicialJugador2);
            }

            if (ValorDadoInicialJugador1 > ValorDadoInicialJugador2)
            {
                Empieza = 1;
                DadoMayor = ValorDadoInicialJugador1;

                rlutil::locate(95,2);
                cout<<NombreJugador1<<" comienza esta emocionante partida. ¡Mucha suerte!"<<endl<<endl;
            }

            else if (ValorDadoInicialJugador2 > ValorDadoInicialJugador1)
            {
                Empieza = 2;
                DadoMayor = ValorDadoInicialJugador2;

                rlutil::locate(95,2);
                cout<<NombreJugador2<<" comienza esta emocionante partida. ¡Mucha suerte!"<<endl;
            }

            PausayLimpia();

            while (Ronda <= 3 && DadosStockJugador1Cantidad != 0 && DadosStockJugador2Cantidad != 0)
            {
                MostrarRonda(Ronda);

                MostrarPartida(Empieza,NombreJugador1, NombreJugador2,
                               DadosStockJugador1Numero,DadosStockJugador2Numero,
                               DadosStockJugador1Cantidad,DadosStockJugador2Cantidad,
                               NumeroObjetivoJugador1,NumeroObjetivoJugador2,
                               SumaDadosJugador1,SumaDadosJugador2,
                               DadosElegidosJugador1,DadosElegidosJugador2,
                               Ronda, PuntajeJugador1, PuntajeJugador2);

                //EN ESTA FUNCION POR PARAMETRO PASAMOS TODOS LAS VARIABLES Y VECTORES PARA PODER TRABAJAR CON LOS MISMOS DENTRO DE LA FUNCION

                PuntajeJugador1 += SumaDadosJugador1 * DadosElegidosJugador1;
                PuntajeJugador2 += SumaDadosJugador2 * DadosElegidosJugador2;

                GanarAutomaticamente(DadosStockJugador1Cantidad, DadosStockJugador2Cantidad,PuntajeJugador1, PuntajeJugador2, NombreJugador1, NombreJugador2);

                PausayLimpia();

                Ronda++;
            }

            rlutil::locate(90,2);
            cout<<"---------------------------------RESUMEN FINAL DE LA PARTIDA---------------------------------"<<endl;

            rlutil::locate(30,10);
            cout<<NombreJugador1<<" Tuvo ("<<PuntajeJugador1<<") puntos"<<endl;
            rlutil::locate(30,10);
            cout<<NombreJugador2<<" Tuvo ("<<PuntajeJugador2<<") puntos"<<endl<<endl;

            if (PuntajeJugador1 > PuntajeJugador2)
            {
                rlutil::locate(30,10);
                cout<<"Felicidades "<<NombreJugador1<<"! Ganaste!"<<endl<<endl;

                PausayLimpia();
            }
            else if (PuntajeJugador2 > PuntajeJugador1)
            {
                rlutil::locate(30,10);
                cout<<"Felicidades "<<NombreJugador2<<"! Ganaste!"<<endl<<endl;
                PausayLimpia();
            }
            else

            {
                rlutil::locate(30,10);
                cout<<"AMBOS JUGADORES EMPATARON"<<endl<<endl;
                PausayLimpia();
            }

            Ronda = 1;

            break;

        case 2:  //ESTADISTICAS

            Estadisticas(NombreJugador1,NombreJugador2,PuntajeJugador1,PuntajeJugador2);

            break;

        case 3: //CREDITOS

            Limpia();
            creditos();
            PausayLimpia();

            break;

        default:

            rlutil::setColor(rlutil::RED);
            rlutil::locate(105,10);

            cout << "ESTA OPCION ES INCORRECTA " << endl;
            //rlutil::anykey ();
            rlutil::setColor(rlutil::BLACK);

            PausayLimpia();
            break;
        }
    }
    while (opcion !=0);
}
