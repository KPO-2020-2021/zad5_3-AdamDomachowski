#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "scena.hh"
#include "exampleConfig.h"
#include "example.h"
#include "Vector.hh"
#include "Matrix.hh"
#include "Cuboid.hh"
#include "prism6.hh"
#include "Drone.hh"
#include "../inc/lacze_do_gnuplota.hh"

/*! \brief tu sie dzieje program*/


int main()
{
       std::cout << "Dron 5.2 by studenciak"
                 << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
                 << "."
                 << PROJECT_VERSION_MINOR /* istotne zmiany */
                 << "."
                 << PROJECT_VERSION_PATCH /* naprawianie bugów */
                 << "."
                 << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
                 << std::endl;
   Scena Scena;
       while (Scena.menu()){Scena.rysuj();}
}