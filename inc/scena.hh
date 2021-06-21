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
#define ilosc_dronow_na_scenie  2
/*! \brief klasa Scena odpowiada za umieszczanie obiektów na scenie oraz za obslge uzytkownika */

class Scena
{
/*! \brief lista elemenow na scenie*/
std::list<std::shared_ptr<obiekt>>lista_elementow;

PzG::LaczeDoGNUPlota Lacze;

/*! \brief lista zawierajaca wskazniki na drony*/
std::list<std::shared_ptr<Drone>> Lista_Dronow; 

/*! \brief numery elementow*/
int numer_elementu, numer_drona;

/*! \brief wskaźnik na przygotowaną podloge*/
Bottom *podloze; 

public:

/*! \brief przygotowuje scene*/
Scena(); 

/*! \brief rysuje sytuacje*/
void rysuj(); 

/*! \brief rysuje sytuacje*/
void dodaj_drona(); 

/*! \brief wyswietla menu i odpowiada za wybor drona*/
bool menu(); 

};
