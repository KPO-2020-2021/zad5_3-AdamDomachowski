#pragma once

#include "Solid.hh"
/*! \brief klasa Prism6 jest klasa pochodna i dziedziczy wzystko z klasy Solid */
class Prism6 : public Solid
{
    public:
    /*! \brief konstruktor parametryczny*/
    Prism6(Vector3D srodek = Vector3D(), double R = 10 , double dlugosc_graniastoslupa = 15 , std::string nazwa_pliku_graniastoslupa6 = "../datas/graniastoslup6.dat" );
};