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


    Menu();

    return 0;

}
