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

using namespace std;

/*! \brief tu sie dzieje program*/


int main()
{
srand(time(NULL));
Scena Scena;
while (Scena.menu()){Scena.rysuj();}
}