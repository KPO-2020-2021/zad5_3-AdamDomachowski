#pragma once

#include "Vector3D.hh"
#include "matrix3x3.hh"
#include <fstream>
#include <vector>
#include <memory>
#include "obiekt.hh"

/*! \brief klasa matka dla wszystkich innych klas które sa zwiazane z brylami geometrycznymi*/

class Solid:public obiekt, public std::enable_shared_from_this<Solid>
{
protected:

std::shared_ptr<Vector3D> wymiary; /*! \brief wymiary bryly*/

std::vector<Vector3D> wierzcholki; /*! \brief wierzcholki bryly*/

Vector3D srodek_bryly; /*! \brief przechowuje wspolrzedne srodka bryly*/ 

std::string nazwa_pliku_bryly;  /*! \brief przechowuje nazwe pliku do którego zapisywane beda wierzcholki*/


public:

/*! \brief operator indeksujacy*/
Vector3D &operator[](int index);

/*! \brief operator indeksujacy*/
Vector3D operator[](int index) const;

/*! \brief ustawia wierzcholki srodka bryly*/
void wstaw_srodek(Vector3D srodek_bryly); 

/*! \brief umozwliwia podania nazwy pliku do ktorego zapisywane beda wierzcholki*/
void ustaw_nazwe_pliku(std::string nazwa_pliku_bryly); 

/*! \brief zczytuje wierzcholki srodka bryly*/
Vector3D zczytaj_srodek_obiektu() const; 

/*! \brief zczytuje nazwe pliku do ktorego zapisywane beda wierzcholki*/
std::string zczytaj_nazwe_obiektu() const; 

/*! \brief przesuwa bryle o zadany wektor*/
void przesun_o_wektor(Vector3D wektor_przesuniecia); 

/*! \brief obraca bryle o zadany kat*/
void obrot(Matrix3x3 macierz_obrotu); 

/*! \brief zapisuje wspolrzedne bryly do pliku*/
void zapisz(); 

/*! \brief zwraca wartosc danego wierzcholka*/
Vector3D czytaj_wierzcholki(int ver) const;

/*! \brief ifnormuje o tym czy zaszla kolizja*/
bool kolizja_info(shared_ptr <obiekt> object);

/*! \brief zwraca promien obiektu*/
double promien(){return sqrt(pow(srodek_bryly[0]-wierzcholki[0][0],2) + pow(srodek_bryly[1]-wierzcholki[0][1],2)+pow(srodek_bryly[2]-wierzcholki[0][2],2));}
};