#ifndef JUGAR_H_INCLUDED
#define JUGAR_H_INCLUDED

///NUMERACION EN ORDEN DE CREACION.-

void MostrarTitulo();  /// [1]
void MostrarOpciones(); /// [2]
void Despedidas(int &Despedida); /// [3a]
void PedirOpciones(int &Opcion, int &Despedida,
                   int &CantidadJugadores, int NombreJugadorNumero[],
                   std::string NombreJugadorLetras[],int ValorDadoInicial[]); /// [3]
void PedirNombres(int &CantidadJugadores,int NombreJugadorNumero[],
                  std::string NombreJugadorLetras[]); /// [4]
void PausayLimpia(); ///[5].-
void Estadisticas (std::string NombreJugadorLetras[]); ///[6].-
void Limpia(); ///[7].-
void Pausa();  ///[8].-
void Creditos();///[9].-
void MostrarNombres(std::string NombreJugadorLetras[]);///[10].-
void TiraDadoInicial(int &CantidadJugadores, int ValorDadoInicial[]); ///[11].-
void IngresarJugadores (int &CantidadJugadores); ///[12].-




#endif // JUGAR_H_INCLUDED
