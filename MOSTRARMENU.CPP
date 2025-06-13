#include <iostream>
#include "MOSTRARMENU.h"
#include "JUGAR.h"
#include "DADOS.h"

using namespace std;


void mostrarMenu()

{

    string NombreJugador1;
    string NombreJugador2;
    int ValorDadoInicialJugador1;
    int ValorDadoInicialJugador2;
    int DadoMayor;


    int opcion;

    do
    {

        cout<<"    _______   ____________  _______   ______ ___ ____  ____  _____ "<<endl;
        cout<<"   / ____/ | / / ____/ __ \/ ____/ | / / __ \/   |  / __ \/ __ \/ ___/ "<<endl;
        cout<<"  / __/ /  |/ / /_  / /_/ / __/ /  |/ / / / / /| | / / / / / / /\__ \  "<<endl;
        cout<<" / /___/ /|  / __/ / _, _/ /___/ /|  / /_/ / ___ |/ /_/ / /_/ /___/ /  "<<endl;
        cout<<"/_____/_/ |_/_/   /_/ |_/_____/_/ |_/_____/_/  |_/_____/\____//____/   "<<endl;
        cout<<"                                                                       "<<endl;
        cout<<"                                                                       "<<endl;
        cout<<"1 - JUGAR                                                              "<<endl;
        cout<<"2 - ESTADÍSTICAS                                                       "<<endl;
        cout<<"3 - CRÉDITOS                                                           "<<endl;
        cout<<"---------------------                                                  "<<endl;
        cout<<"0 - SALIR "<<endl<<endl;

        cout<<"Ingrese una opcion: "<<endl;
        cin >> opcion;

        switch (opcion)
        {

        case 0:
            cout << "Gracias por jugar" << endl << endl << endl;
            break;
        case 1:

            NombreJugador1 = PedirNombreJugador1();
            NombreJugador2 = PedirNombreJugador2();
            system("cls"); //ESTO LIMPIA TODO LO ANTERIOR ASI NO SE VE EN PANTALLA

            ValorDadoInicialJugador1 = DadoInicialJugador1();    //ACA PODEMOS VALIDAR CON 1; PARA EVITAR ESPERAR A QUE DE EL NUMERO IGUAL
            ValorDadoInicialJugador2 = DadoInicialJugador2();    //ACA PODEMOS VALIDAR CON 1; PARA EVITAR ESPERAR A QUE DE EL NUMERO IGUAL
            system("pause"); //ESTO PAUSA EL PROGRAMA Y ESPERA A APRETAR UNA TECLA PARA CONTINUAR
            system("cls");

            while (ValorDadoInicialJugador1 == ValorDadoInicialJugador2)
            {
                cout<<"Como ambos Jugadores tienen el mismo valor se tira nuevamente: "<<endl;
                ValorDadoInicialJugador1 = DadoInicialJugador1();
                ValorDadoInicialJugador2 = DadoInicialJugador2();
            }

            if (ValorDadoInicialJugador1 > ValorDadoInicialJugador2)
            {

                DadoMayor = ValorDadoInicialJugador1;
                cout<<"El Jugador "<<NombreJugador1<<" Tiene el dado Mayor....comienza la partida"<<endl;

            }
            else if (ValorDadoInicialJugador2 > ValorDadoInicialJugador1)
            {

                DadoMayor = ValorDadoInicialJugador2;
                cout<<"El Jugador "<<NombreJugador2<<" Tiene el dado Mayor....comienza la partida"<<endl;

            }

            MostrarPartida(NombreJugador1, NombreJugador2);


            //ContadorRondas();





            //GuardaValorJugador1();
            // ValorDadoMayor ();
            //DesempateDadoInicial();


            break;
        case 2:  //ESTADISTICAS
            break;
        case 3: //CREDITOS
             system("cls");
            creditos();
             system("pause");
             system("cls");

            break;
        default:
            cout << " ESTA OPCION ES INCORRECTA " << endl;
            break;

        }


    }
    while (opcion !=0);

}
