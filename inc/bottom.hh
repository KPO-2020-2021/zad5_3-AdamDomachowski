#pragma once

#include "Vector3D.hh"
#include "matrix3x3.hh"
#include <fstream>
#include <vector>

/*! \brief klasa Bottom to nic innego jak plaszczyzna na ktorej dzialamy*/

class Bottom
{
protected:
    std::vector<Vector3D> wierzcholki;
    std::string nazwa;
    int proste;
public:
    /*! \brief konstruktor parametryczny*/
    Bottom(Vector3D wymiary=Vector3D(), int grubosc_kratki = 5, std::string nazwa_pliku = "../datas/Bottom.dat");

    /*! \brief operator indeksujacy*/
    Vector3D &operator[](int index);

    /*! \brief operator indeksujacy*/
    Vector3D operator[](int index)const;

    /*! \brief ustawia nazwe podloza*/
    void ustaw_nazwe(std::string nazwa);

    /*! \brief czyta nazwe podloza*/
    std::string czytaj_nazwe() const;
    
    /*! \brief zapisuje dane*/
    void zapisz();
};