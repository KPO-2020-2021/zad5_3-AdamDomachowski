#include "goraGran.hh"

/*!
    \file
    \brief metody klasy goraGran
*/


/*!
    konstruktor goraGranu                                                                                                                      
    \param [in] srodek - wspolrzedne srodka goraGranu.      
    \param [in] a - dlugosc  
    \param [in] b - szerokosc  
    \param [in] c - wysokosc  
    \param [in] nazwa_pliku - nazwa pliku do zapisu wierzcholkicholkow                                                                                                            
    \return przeszkoda z okreslonymi chechami.                           
 */
goraGran::goraGran(Vector3D srodek, double a, double b, double c, std::string nazwa_pliku)
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
  punkt[2]=srodek[2]+(c/2);
  wierzcholki.push_back(punkt);

  punkt[0]=srodek[0]+(a/2);
  punkt[1]=srodek[1]-(b/2);
  punkt[2]=srodek[2]-(c/2);
  wierzcholki.push_back(punkt);


  punkt[0]=srodek[0]-(a/2);
  punkt[1]=srodek[1]-(b/2);
  punkt[2]=srodek[2]+(c/2);
  wierzcholki.push_back(punkt);

  punkt[0]=srodek[0]-(a/2);
  punkt[1]=srodek[1]-(b/2);
  punkt[2]=srodek[2]-(c/2);
  wierzcholki.push_back(punkt);

  this->srodek_bryly[0]=srodek[0];
  this->srodek_bryly[1]=srodek[1];
  this->srodek_bryly[2]=srodek[2]-(c/2);

}

goraGran::goraGran( goraGran& goraGran )
{
wymiary=goraGran.wymiary;
wierzcholki=goraGran.wierzcholki;
srodek_bryly=goraGran.srodek_bryly;
nazwa_pliku_bryly=goraGran.nazwa_pliku_bryly;
}
 

