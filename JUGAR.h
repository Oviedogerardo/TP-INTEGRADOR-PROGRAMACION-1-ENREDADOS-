#ifndef JUGAR_H_INCLUDED
#define JUGAR_H_INCLUDED

//ACA VAMOS A DECLARAR TODAS LAS FUNCIONES QUE SEAN NECESARIAS PARA JUGAR!!!

///*********************
///FUNCIONES JUGADOR 1.-
///*********************

std::string PedirNombreJugador1();
void MostrarPuntajePuntajeJugador1 (int &SumaDadosJugador1, int &DadosElegidosJugador1, std::string &NombreJugador1);

///-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

///*********************
///FUNCIONES JUGADOR 2.-
///*********************

std::string PedirNombreJugador2();
void MostrarPuntajePuntajeJugador2(int &SumaDadosJugador2, int &DadosElegidosJugador2, std::string &NombreJugador2);

 ///*********************
///FUNCIONES VARIAS.-
///*********************

int ContadorRondas();
void creditos();
void MostrarNombres(std::string NombreJugador1, std::string NombreJugador2);
void MostrarRonda(int &Ronda);
void MostrarPartida(int Empieza, std::string &NombreJugador1, std::string &NombreJugador2, int DadosStockJugador1Numero[],int DadosStockJugador2Numero[],int &DadosStockJugador1Cantidad,
                    int &DadosStockJugador2Cantidad,int &NumeroObjetivoJugador1,int &NumeroObjetivoJugador2, int &SumaDadosJugador1, int &SumaDadosJugador2
                    ,int &DadosElegidosJugador1,int &DadosElegidosJugador2, int &Ronda, int PuntajeJugador1,int PuntajeJugador2);
void PausayLimpia();
void Pausa();
void Limpia();
void Estadisticas (std::string NombreJugador1, std::string NombreJugador2, int PuntajeJugador1, int PuntajeJugador2);
void GanarAutomaticamente(int DadosStockJugador1Cantidad, int DadosStockJugador2Cantidad, int PuntajeJugador1,int PuntajeJugador2, std::string NombreJugador1, std::string NombreJugador2);
void ReiniciarValores(int &DadosStockJugador1Cantidad,int &SumaDadosJugador1,
                      int &PuntajeJugador1,int &DadosStockJugador2Cantidad,
                      int &SumaDadosJugador2,int &PuntajeJugador2);


#endif // JUGAR_H_INCLUDED
