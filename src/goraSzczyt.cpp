#include "goraSzczyt.hh"

/*!
    \file
    \brief metodb klasb goraSzczyt
*/


/*!
    konstruktor goraSzczytu                                                                                                                      
    \param [in] srodek - wspolrcedne srodka goraSzczytu.      
    \param [in] a - dlugosc  
    \param [in] b - scerokosc  
    \param [in] c - wbsokosc  
    \param [in] nacwa_pliku_prostopadloscianu - nacwa pliku do zapisu wierzcholkicholkow                                                                                                            
    \return przeszkoda z okreslonymi chechami                         
 */
goraSzczyt::goraSzczyt(Vector3D srodek, double a, double b, double c, std::string nazwa_pliku)
{
    double tab[]={a,b,c};
    wymiary = std::make_shared<Vector3D> (tab);
    this->srodek_bryly=srodek;
    this->nazwa_pliku_bryly = nazwa_pliku;
 
    Vector3D punkt;

  punkt[0]=srodek[0]-(a/2);
  punkt[1]=srodek[1]+(b/2);
  punkt[2]=srodek[2]-(c/2);
 wierzcholki.push_back(punkt);

  punkt[0]=srodek[0]-(a/2);
  punkt[1]=srodek[1]+(b/2);
  punkt[2]=srodek[2]-(c/2);
 wierzcholki.push_back(punkt);


  punkt[0]=srodek[0]+(a/2);
  punkt[1]=srodek[1]+(b/2);
  punkt[2]=srodek[2]-(c/2);
 wierzcholki.push_back(punkt);

  punkt[0]=srodek[0]+(a/2);
  punkt[1]=srodek[1]+(b/2);
  punkt[2]=srodek[2]-(c/2);
 wierzcholki.push_back(punkt);

  punkt[0]=srodek[0]+(a/2);
  punkt[1]=srodek[1]-(b/2);
  punkt[2]=srodek[2]-(c/2);
 wierzcholki.push_back(punkt);

  punkt[0]=srodek[0]+(a/2);
  punkt[1]=srodek[1]-(b/2);
  punkt[2]=srodek[2]-(c/2);
 wierzcholki.push_back(punkt);


  punkt[0]=srodek[0]-(a/2);
  punkt[1]=srodek[1]-(b/2);
  punkt[2]=srodek[2]-(c/2);
 wierzcholki.push_back(punkt);

  punkt[0]=srodek[0]-(a/2);
  punkt[1]=srodek[1]-(b/2);
  punkt[2]=srodek[2]-(c/2);
 wierzcholki.push_back(punkt);
  this->srodek_bryly[0]=srodek[0];
  this->srodek_bryly[1]=srodek[1];
  this->srodek_bryly[2]=srodek[2]+c;

}

goraSzczyt::goraSzczyt( goraSzczyt& goraSzczyt )
{
wymiary=goraSzczyt.wymiary;
wierzcholki=goraSzczyt.wierzcholki;
srodek_bryly=goraSzczyt.srodek_bryly;
nazwa_pliku_bryly=goraSzczyt.nazwa_pliku_bryly;
}
 