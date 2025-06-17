#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MOSTRARMENU.h"
#include "JUGAR.h"
#include "DADOS.h"

using namespace std;

//MAIN PRONCIPAL CON LA LOGICA DEL JUEGO:

int main()
{
    srand(time(nullptr));


   // string porongaNumero1 = "carlo";
    //string porongaNumero2;

  /* for (int i = 1; i <= 6; i++)       //ESTO SE HIZO PARA DIBUJAR LOS DADOS, SE VA A BORRAR
   {


   DibujarDado(i);
   }  */

    //cout<<porongaNumero1<<endl;

   // MostrarPodongas(porongaNumero1, porongaNumero2);

    //cout<<porongaNumero1<<endl;

  mostrarMenu(); //POSIBLE FUNCION QUE VA A CAMBIAR DE NOMBRE POR EL CONTENIDO QUE TIENE!





    return 0;
}
