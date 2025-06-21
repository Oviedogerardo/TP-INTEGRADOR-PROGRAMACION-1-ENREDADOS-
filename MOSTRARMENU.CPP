#include <iostream>
#include "MOSTRARMENU.h"
#include "JUGAR.h"
#include "DADOS.h"

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

    int Ronda;
    int Empieza;

    int opcion; //DECLARACION DE VARIABLE PARA PODER GUARDAR LA OPCION QUE NOS PIDA

    do  //ES UN "DO/WHILE" PORQUE PRIMERO QUEREMOS QUE MUESTRE EL MENU Y DESPUES EL RESTO
    {

        cout<<"                         _______   ____________  _______   ______  ___    ____  ____  _____ "<<endl;
        cout<<"                        / ____/ | / / ____/ __  \/ ____/ | / / _ _ \/   |  / __ \/ __ \/ ___/ "<<endl;
        cout<<"                       / __/ /  |/ / /_  / /_/ / __/ /  |/ / / / / /| | / / / / / / /\__ \  "<<endl;
        cout<<"                      / /___/ /|  / __/ / _, _/ /___/ /|  / /_/ / ___ |/ /_/ / /_/ /___/ /  "<<endl;
        cout<<"                     /_____/_/ |_/_/   /_/ |_/_____/_/ |_/_____/_/  |_/_____/\____//____/   "<<endl;
        cout<<"                                                                       "<<endl;
        cout<<"                                               ---------------------                         "<<endl;
        cout<<"                                              |1 - JUGAR            |                        "<<endl;
        cout<<"                                              |2 - ESTADÍSTICAS     |                        "<<endl;
        cout<<"                                              |3 - CRÉDITOS         |                        "<<endl;
        cout<<"                                              |0 - SALIR            |                        "<<endl;
        cout<<"                                              |---------------------|                        "<<endl<<endl;

        cout<<"                                                Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {

        case 0:
            cout << "Gracias por jugar" << endl << endl << endl;
            break;
        case 1:
            system("cls");
            NombreJugador1 = PedirNombreJugador1(); //UTILIZAMOS ESTA FUNCION EN ESTA VARIABLE PARA GUARDAR EL VALOR
            NombreJugador2 = PedirNombreJugador2(); //UTILIZAMOS ESTA FUNCION EN ESTA VARIABLE PARA GUARDAR EL VALOR
            system("cls");
            cout<<"                    Ahora ambos Jugadores van a tirar el Dado Inicial para definir quien Empieza!!! (SUERTE)                               "<<endl;

            Pali();

            ValorDadoInicialJugador1 = DadoInicialJugador1();    //ACA PODEMOS VALIDAR CON 1; PARA EVITAR ESPERAR A QUE DE EL NUMERO IGUAL EJ: ValorDadoInicialJugador1 = 1, PARA VER SI EL SEGUNDO JUGADOR EMPIEZA PRIMERO Y SI ESTA BIEN HECHO.
            MostrarNombres(NombreJugador1,NombreJugador2);
            DibujarDado(ValorDadoInicialJugador1);
            MostrarNombres(NombreJugador1,NombreJugador2);
            ValorDadoInicialJugador2 = DadoInicialJugador2();    //ACA PODEMOS VALIDAR CON 1; PARA EVITAR ESPERAR A QUE DE EL NUMERO IGUAL EJ: ValorDadoInicialJugador2 = 1, PARA VER SI EL PRIMER JUGADOR EMPIEZA PRIMERO Y SI ESTA BIEN HECHO.
            DibujarDado(ValorDadoInicialJugador2); //USAMOS ESTA FUNCION PARA GRAFICAR LOS DADOS INICIALES
            Pali();

            while (ValorDadoInicialJugador1 == ValorDadoInicialJugador2) //UTILIZAMOS ESTE WHILE PARA TIRAR NUEVAMENTE EN CASO DE QUE LOS NUMEROS DE LOS DADOS INICIALES SEAN IGUALES!!!
            {
                cout<<"Como ambos Jugadores tienen el mismo valor se tira nuevamente: "<<endl;
                ValorDadoInicialJugador1 = DadoInicialJugador1();
                ValorDadoInicialJugador2 = DadoInicialJugador2();
            }

            if (ValorDadoInicialJugador1 > ValorDadoInicialJugador2)
            {
                 Empieza = 1;
                DadoMayor = ValorDadoInicialJugador1;
                cout<<"El Jugador "<<NombreJugador1<<" Tiene el dado Mayor....comienza la partida"<<endl;

            }
            else if (ValorDadoInicialJugador2 > ValorDadoInicialJugador1)
            {
                 Empieza = 2;
                DadoMayor = ValorDadoInicialJugador2;
                cout<<"El Jugador "<<NombreJugador2<<" Tiene el dado Mayor....comienza la partida"<<endl;

            }

            Pali();


           for (Ronda = 1; Ronda <= 3; Ronda++) //ESTE FOR VA A HACER LAS VECES DE RONDA, YA QUE EL LIMITE ES 3 RONDAS O QUE ALGUN JUGADOR SE QUEDE SIN DADOS!!!
           {
            MostrarRonda(Ronda);


           MostrarPartida(Empieza,NombreJugador1, NombreJugador2,
                           DadosStockJugador1Numero,DadosStockJugador2Numero,
                            DadosStockJugador1Cantidad,DadosStockJugador2Cantidad,
                            NumeroObjetivoJugador1,NumeroObjetivoJugador2,
                            SumaDadosJugador1,SumaDadosJugador2,
                            DadosElegidosJugador1,DadosElegidosJugador2,
                            Ronda);
            //EN ESTA FUNCION POR PARAMETRO PASAMOS TODOS LAS VARIABLES Y VECTORES PARA PODER TRABAJAR CON LOS MISMOS DENTRO DE LA FUNCION

            PuntajeJugador1 += SumaDadosJugador1 * DadosElegidosJugador1;
            PuntajeJugador2 += SumaDadosJugador2 * DadosElegidosJugador2;


            system("cls");

           }

                cout<<"                    ---------------------RESUMEN FINAL DE LA PARTIDA---------------------"<<endl;
                cout<<NombreJugador1<<" Tuvo ("<<PuntajeJugador1<<") puntos"<<endl;
                cout<<NombreJugador2<<" Tuvo ("<<PuntajeJugador2<<") puntos"<<endl<<endl;

                if (PuntajeJugador1 > PuntajeJugador2)
                {
                    cout<<"Felicidades "<<NombreJugador1<<"! Ganaste un juego de consola, pero......a que costo?"<<endl<<endl;
                    Pali();

                } else if (PuntajeJugador2 > PuntajeJugador1)
                {

                    cout<<"Felicidades "<<NombreJugador2<<"! Ganaste un juego de consola, pero......a que costo?"<<endl<<endl;
                    Pali();
                }  else

                {
                    cout<<"CAPO......EMPATARON!!!, COMO LLEGARON A ESTO???"<<endl<<endl;
                    Pali();
                }

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
            cout << " ESTA OPCION ES INCORRECTA " << endl;
            break;

        }


    }
    while (opcion !=0);

}
