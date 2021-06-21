#pragma once  

#include "Solid.hh"
/*! \brief klasa goraSzczyt przechowuje informacjie o przeszkodzie i jest to klasa pochodna i dziedziczy wzystko z klasy Solid */
class goraSzczyt : public Solid 
{
public:
/*! \brief konstruktor parametryczny*/
double promien(){return (*wymiary)[2];}
goraSzczyt(Vector3D srodek=Vector3D(), double a=50, double b=50, double c=50, std::string nazwa_pliku_goraSzczytu = "../datas/goraSzczyt.dat");
goraSzczyt( goraSzczyt& goraSzczyt );
goraSzczyt &operator=(const goraSzczyt &drugi)
{
wymiary=drugi.wymiary;
wierzcholki=drugi.wierzcholki;
srodek_bryly=drugi.srodek_bryly;
nazwa_pliku_bryly=drugi.nazwa_pliku_bryly;
return *this;
}
};

