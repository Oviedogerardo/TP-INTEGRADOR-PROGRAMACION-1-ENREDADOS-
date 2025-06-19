#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

//EN  ESTE ARCHIVO PONEMOS TODOS LAS FUNCIONES DE DADOS, TODAS!!!
int DadoInicialJugador1 ();
int DadoInicialJugador2();  //ESTA FUNCION GENERA UN NUMERO ALEATORIO DE HASTA 6 NUMEROS -OJO NO ESTAS TENIENDO EN CUENTA SI SALE CERO PORQUE EN REALIDAD ESTO ES UN DADO GIRANDO-
bool DesempateDadoInicial(); //ESTA FUNCION HACE QUE SI LOS DADOS INICIALES DAN LO MISMO VUELVE A TIRAR
int ValorDadoMayor (); //ESTA FUNCION HACE LA COMPARATIVA ENTRE LOS 2 DADOS INICIALES DEL JUGADOR 1 Y EL 2 Y SACA UN CARTEL DICIENDO CUAL ES EL MAYOR
int DadosObjetivoJugador1();
int DadosObjetivoJugador2();
void DibujarDado(int valor);
void DadosStockJugador1 (int DadosStockJugador1Numero[], int DadosStockJugadorCantidad);
void DadosStockJugador2 (int DadosStockJugador2Numero[], int DadosStockJugadorCantidad);
void ElegirDadosySumarJugador1 (int DadosStockJugador1Numero[], int DadosStockJugadorCantidad);
void ElegirDadosySumarJugador2 (int DadosStockJugador2Numero[], int DadosStockJugadorCantidad);
//void AsignacionDadosJugador1 (int DadosStockJugador1Numero[]);


#endif // DADOS_H_INCLUDED
