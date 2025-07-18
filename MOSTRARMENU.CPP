#include <iostream>
#include <clocale>
#include "MOSTRARMENU.h"
#include "JUGAR.h"
#include "DADOS.h"
#include "rlutil.h"

using namespace std;


void Menu()

{
    ///VARIABLES JUGADOR 1
    string NombreJugador1;//DECLARACION DE LA VARIABLE PARA EL NOMBRE
    int ValorDadoInicialJugador1; //DECLARACION DE LA VARIABLE PARA GUARDAR EL NUMERO QUE NOS DE LA FUNCION RAND
    int NumeroObjetivoJugador1;  //VARIABLE PARA PODER LLAMAR DESPUES DE QUE PASE POR LA FUNCION PARA VALIDAR DADOS DESPUES
    int DadosStockJugador1Cantidad = 6; //DECLARACION DE VARIABLE DE CANTIDAD DE DADOS
    int DadosStockJugador1Numero [DadosStockJugador1Cantidad]; //DECLARACION DE VECTOR DE DADOS DE STOCK PARA GUARDAR EL VALOR DE CADA DADO
    int DadosElegidosJugador1;
    int SumaDadosJugador1 = 0; //SE CREO ESTA VARIABLE PARA DESPUES CALCULAR LOS PUNTOS
    int PuntajeJugador1 = 0;

    ///VARIABLES JUGADOR 2
    string NombreJugador2;//DECLARACION DE LA VARIABLE PARA EL NOMBRE
    int ValorDadoInicialJugador2; //DECLARACION DE LA VARIABLE PARA GUARDAR EL NUMERO QUE NOS DE LA FUNCION RAND
    int DadoMayor; //DECLARACION DE LA VARIABLE PARA GUARDAR EL VALOR QUE NOS SALGA DE VALIDAR SI UNO U OTRO DADO ES MAYOR
    int NumeroObjetivoJugador2;  //VARIABLE PARA PODER LLAMAR DESPUES DE QUE PASE POR LA FUNCION PARA VALIDAR DADOS DESPUES
    int DadosStockJugador2Cantidad = 6; //DECLARACION DE VARIABLE DE CANTIDAD DE DADOS
    int DadosStockJugador2Numero [DadosStockJugador2Cantidad]; //DECLARACION DE VECTOR DE DADOS DE STOCK PARA GUARDAR EL VALOR DE CADA DADO
    int DadosElegidosJugador2;
    int SumaDadosJugador2 = 0;  //SE CREO ESTA VARIABLE PARA DESPUES CALCULAR LOS PUNTOS
    int PuntajeJugador2 = 0;

    int Ronda = 1;
    int Empieza;

    int opcion; //DECLARACION DE VARIABLE PARA PODER GUARDAR LA OPCION QUE NOS PIDA


    do  //ES UN "DO/WHILE" PORQUE PRIMERO QUEREMOS QUE MUESTRE EL MENU Y DESPUES EL RESTO
    {
        rlutil::cls();
        cout<<"                         _______   ____________  _______   ______  ___    ____  ____  _____ "<<endl;
        cout<<"                        / ____/ | / / ____/ __  \/ ____/ | / / _ _ \/   |  / __ \\/ _ \ /  ___/ "<<endl;
        cout<<"                       / __/ /  |/ / /_  / /_/ / __/ /  |/ / / / / /| | / / / / / //\__  \\  "<<endl;
        cout<<"                      / /___/ /|  / __/ / _, _/ /___/ /|  / /_/ / ___ |/ /_/ / /_//___/ /  "<<endl;
        cout<<"                     /_____/_/ |_/_/   /_/ |_/_____/_/ |_/_____/_/  |_/_____/\____//____/   "<<endl;
        cout<<""<<endl<<endl<<endl;

        rlutil::locate(30,10);
        cout<<"+---------------------+"<<endl;
        rlutil::locate(30,11);
        cout<<"|1 - JUGAR            |"<<endl;
        rlutil::locate(30,12);
        cout<<"|2 - ESTADISTICAS     |"<<endl;
        rlutil::locate(30,13);
        cout<<"|3 - CREDITOS         |"<<endl;
        rlutil::locate(30,14);
        cout<<"|0 - SALIR            |"<<endl;
        rlutil::locate(30,15);
        cout<<"+---------------------+"<<endl;
        rlutil::locate(30,18);
        cout<<"Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {

        case 0:
            cout << "Gracias por jugar" << endl << endl << endl;
            break;
        case 1:

            ReiniciarValores(DadosStockJugador1Cantidad,SumaDadosJugador1,
                             PuntajeJugador1,DadosStockJugador2Cantidad,
                             SumaDadosJugador2, PuntajeJugador2); //ESTA FUNCION SE UTILIZA EN EL CASO DE QUE SE EMPIECE OTRA PARTIRA

            system("cls");
            NombreJugador1 = PedirNombreJugador1(); //UTILIZAMOS ESTA FUNCION EN ESTA VARIABLE PARA GUARDAR EL VALOR
            NombreJugador2 = PedirNombreJugador2(); //UTILIZAMOS ESTA FUNCION EN ESTA VARIABLE PARA GUARDAR EL VALOR
            system("cls");
            cout<<"              Ambos jugadores lanzaran sus dados para ver quién arranca. ¡Mucha suerte y que los dados estén de su lado!                            "<<endl;

            Pali();

            MostrarNombres(NombreJugador1,NombreJugador2);
            ValorDadoInicialJugador1 = DadoInicialJugador1(NombreJugador1);    //ACA PODEMOS VALIDAR CON 1; PARA EVITAR ESPERAR A QUE DE EL NUMERO IGUAL EJ: ValorDadoInicialJugador1 = 1, PARA VER SI EL SEGUNDO JUGADOR EMPIEZA PRIMERO Y SI ESTA BIEN HECHO.
            DibujarDado(ValorDadoInicialJugador1);
            ValorDadoInicialJugador2 = DadoInicialJugador2(NombreJugador2);    //ACA PODEMOS VALIDAR CON 1; PARA EVITAR ESPERAR A QUE DE EL NUMERO IGUAL EJ: ValorDadoInicialJugador2 = 1, PARA VER SI EL PRIMER JUGADOR EMPIEZA PRIMERO Y SI ESTA BIEN HECHO.
            DibujarDado(ValorDadoInicialJugador2); //USAMOS ESTA FUNCION PARA GRAFICAR LOS DADOS INICIALES
            Pali();

            while (ValorDadoInicialJugador1 == ValorDadoInicialJugador2) //UTILIZAMOS ESTE WHILE PARA TIRAR NUEVAMENTE EN CASO DE QUE LOS NUMEROS DE LOS DADOS INICIALES SEAN IGUALES!!!
            {
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
                cout<<NombreJugador1<<" comienza esta emocionante partida. ¡Mucha suerte!"<<endl<<endl;

            }
            else if (ValorDadoInicialJugador2 > ValorDadoInicialJugador1)
            {
                Empieza = 2;
                DadoMayor = ValorDadoInicialJugador2;
                cout<<NombreJugador2<<" comienza esta emocionante partida. ¡Mucha suerte!"<<endl;

            }

            Pali();

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

                Pali();

                Ronda++;

            }

            cout<<"                    ---------------------RESUMEN FINAL DE LA PARTIDA---------------------"<<endl;
            cout<<NombreJugador1<<" Tuvo ("<<PuntajeJugador1<<") puntos"<<endl;
            cout<<NombreJugador2<<" Tuvo ("<<PuntajeJugador2<<") puntos"<<endl<<endl;

            if (PuntajeJugador1 > PuntajeJugador2)
            {
                cout<<"Felicidades "<<NombreJugador1<<"! Ganaste!"<<endl<<endl;


                Pali();

            }
            else if (PuntajeJugador2 > PuntajeJugador1)
            {

                cout<<"Felicidades "<<NombreJugador2<<"! Ganaste!"<<endl<<endl;
                Pali();
            }
            else

            {
                cout<<"AMBOS JUGADORES EMPATARON"<<endl<<endl;
                Pali();
            }

            Ronda = 1;

            break;

    case 2:  //ESTADISTICAS
        Estadisticas(NombreJugador1,NombreJugador2,PuntajeJugador1,PuntajeJugador2);
        break;
    case 3: //CREDITOS
        system("cls");
        creditos();
        Pali();

        break;
    default:
        rlutil::setColor(rlutil::RED);
        cout << "ESTA OPCION ES INCORRECTA " << endl;
        rlutil::anykey ();
        rlutil::setColor(rlutil::BLACK);
        Pali() ;
        break;

    }


}
while (opcion !=0);

}
