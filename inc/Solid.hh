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

Vector3D &operator[](int index);

Vector3D operator[](int index) const;

void wstaw_srodek(Vector3D srodek_bryly); /*! \brief ustawia wierzcholki srodka bryly*/

void ustaw_nazwe_pliku(std::string nazwa_pliku_bryly); /*! \brief umozwliwia podania nazwy pliku do ktorego zapisywane beda wierzcholki*/

Vector3D zczytaj_srodek() const; /*! \brief zczytuje wierzcholki srodka bryly*/

std::string jaka_nazwa() const; /*! \brief zczytuje nazwe pliku do ktorego zapisywane beda wierzcholki*/

void przesun_o_wektor(Vector3D wektor_przesuniecia); /*! \brief przesuwa bryle o zadany wektor*/

void obrot(Matrix3x3 macierz_obrotu); /*! \brief obraca bryle o zadany kat*/

void zapisz_do_pliku(); /*! \brief zapisuje wspolrzedne bryly do pliku*/

Vector3D czytaj_wierzcholki(int ver) const;

bool kolizja_info(std::shared_ptr <obiekt> object);

double promien(){return sqrt(pow(srodek_bryly[0]-wierzcholki[0][0],2) + pow(srodek_bryly[1]-wierzcholki[0][1],2)+pow(srodek_bryly[2]-wierzcholki[0][2],2));}
};