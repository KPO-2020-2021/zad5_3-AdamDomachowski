#pragma once  

#include "Solid.hh"
/*! \brief klasa goraGran przechowuje informacjie o przeszkodzie i jest to klasa pochodna i dziedziczy wzystko z klasy Solid */
class goraGran : public Solid 
{
public:
/*! \brief konstruktor parametryczny*/
goraGran(Vector3D srodek=Vector3D(), double a=50, double b=50, double c=50, std::string nazwa_pliku_goraGranu = "../datas/goraGran.dat");
goraGran( goraGran& goraGran );
goraGran &operator=(const goraGran &drugi)
{
wymiary=drugi.wymiary;
wierzcholki=drugi.wierzcholki;
srodek_bryly=drugi.srodek_bryly;
nazwa_pliku_bryly=drugi.nazwa_pliku_bryly;
return *this;
}
};

