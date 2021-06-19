#pragma once

#include <iostream>
#include <list>
#include <memory>
#include <iomanip>
#include <fstream>
#include "goraGran.hh"
#include "goraSzczyt.hh"
#include "plaskowyz.hh"
#include "prism6.hh"
#include "lacze_do_gnuplota.hh"
#include "Drone.hh"
#include "bottom.hh"
#define ilosc_dronow_na_scenie 3
/*! \brief klasa Scena odpowiada za umieszczanie obiektów na scenie oraz za obslge uzytkownika */

class Scena
{
std::list<std::shared_ptr<obiekt>>lista_elementow;
PzG::LaczeDoGNUPlota Lacze;
std::list<std::shared_ptr<Drone>> Lista_Dronow; /*! \brief lista zawierajaca wskazniki na drony*/
int numer_elementu, numer_drona;
Bottom *podloze; /*! \brief wskaźnik na przygotowaną podloge*/

public:
Scena(); /*! \brief przygotowuje scene*/
void rysuj(); /*! \brief rysuje sytuacje*/
void dodaj_drona(); /*! \brief rysuje sytuacje*/
bool menu(); /*! \brief wyswietla menu i odpowiada za wybor drona*/
};
