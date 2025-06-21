#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

 using namespace std;


//EN  ESTE ARCHIVO PONEMOS TODOS LAS FUNCIONES DE DADOS, TODAS!!!
int DadoInicialJugador1 ();
int DadoInicialJugador2();  //ESTA FUNCION GENERA UN NUMERO ALEATORIO DE HASTA 6 NUMEROS -OJO NO ESTAS TENIENDO EN CUENTA SI SALE CERO PORQUE EN REALIDAD ESTO ES UN DADO GIRANDO-
bool DesempateDadoInicial(); //ESTA FUNCION HACE QUE SI LOS DADOS INICIALES DAN LO MISMO VUELVE A TIRAR
int ValorDadoMayor (); //ESTA FUNCION HACE LA COMPARATIVA ENTRE LOS 2 DADOS INICIALES DEL JUGADOR 1 Y EL 2 Y SACA UN CARTEL DICIENDO CUAL ES EL MAYOR
void DadosObjetivoJugador1(int &NumeroObjetivoJugador1);
void DadosObjetivoJugador2(int &NumeroObjetivoJugador2);
void DibujarDado(int valor);
void DadosStockJugador1 (int DadosStockJugador1Numero[], int DadosStockJugadorCantidad);
void DadosStockJugador2 (int DadosStockJugador2Numero[], int DadosStockJugadorCantidad);
void ElegirDadosySumarJugador1 (int DadosStockJugador1Numero[], int &DadosStockJugador1Cantidad,  int &DadosStockJugador2Cantidad, int &NumeroObjetivoJugador1,int &SumaDadosJugador1,int &DadosElegidosJugador1, string &NombreJugador1);
void ElegirDadosySumarJugador2 (int DadosStockJugador2Numero[], int &DadosStockJugador2Cantidad, int &DadosStockJugador1Cantidad,int &NumeroObjetivoJugador2,int &SumaDadosJugador2,int &DadosElegidosJugador2, string &NombreJugador2);
//void AsignacionDadosJugador1 (int DadosStockJugador1Numero[]);


#endif // DADOS_H_INCLUDED
