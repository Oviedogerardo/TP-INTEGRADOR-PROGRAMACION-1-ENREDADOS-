#ifndef JUGAR_H_INCLUDED
#define JUGAR_H_INCLUDED

using namespace std;


//ACA VAMOS A DECLARAR TODAS LAS FUNCIONES QUE SEAN NECESARIAS PARA JUGAR!!!
string PedirNombreJugador1();
string PedirNombreJugador2();
int ContadorRondas();
void creditos();
void MostrarNombres(string NombreJugador1, string NombreJugador2);
void MostrarPartida(int Empieza, string &NombreJugador1, string &NombreJugador2, int DadosStockJugador1Numero[],int DadosStockJugador2Numero[],int &DadosStockJugador1Cantidad,
                     int &DadosStockJugador2Cantidad,int &NumeroObjetivoJugador1,int &NumeroObjetivoJugador2, int &SumaDadosJugador1, int &SumaDadosJugador2
                     ,int &DadosElegidosJugador1,int &DadosElegidosJugador2);
 void MostrarPuntajePuntajeJugador1 (int &SumaDadosJugador1, int &DadosElegidosJugador1, string &NombreJugador1);
 void MostrarPuntajePuntajeJugador2(int &SumaDadosJugador2, int &DadosElegidosJugador2, string &NombreJugador2);
 //void MostrarPodongas (string &poronga1, string &poronga2);



//int DecidirQuienEmpieza ();




#endif // JUGAR_H_INCLUDED
