#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>
#include "MOSTRARMENU.h"
#include "JUGAR.h"
#include "DADOS.h"
#include "rlutil.h"
using namespace std;

//MAIN PRONCIPAL CON LA LOGICA DEL JUEGO:

int main()
{

    rlutil::setBackgroundColor (rlutil::WHITE);
    VuelveColor();

    srand(time(nullptr));
    setlocale(LC_ALL, "spanish");


    Menu(); //POSIBLE FUNCION QUE VA A CAMBIAR DE NOMBRE POR EL CONTENIDO QUE TIENE! ----21/06/2025 SE CAMBIO EL NOMBRE A Menu();

    return 0;

}
