#pragma once
#include <unistd.h>
#include "Cuboid.hh"
#include "prism6.hh"
#include "../inc/lacze_do_gnuplota.hh"

/*! \brief klasa drona przechowuje wszystkie informacje, metody, funkcje dotyczace dronow*/

class Drone :public obiekt, public std::enable_shared_from_this<Drone>
{
    PzG::LaczeDoGNUPlota &Lacze;
    int nr_drona; /*! \brief numer drona do identyfikacji obiektu*/
    double kat;   /*! \brief kat obrotu*/
    std::vector<Vector3D> trajektoria; /*! \brief trajektoria lotu drona*/
    Matrix3x3 macierz_obrotu; /*! \brief macierz do oborotu bryly*/
    Vector3D droga; /*! \brief na podstawie drogi obliczany jest wektor przesuniecia*/
    Cuboid body_org; /*! \brief obiekt oryginalny*/
    Cuboid body_copy;  /*! \brief kopia*/
    Prism6 wings_org[4]; /*! \brief obiekt oryginalny*/
    Prism6 wings_copy[4];  /*! \brief kopia*/
public:

    /*! \brief konstruktor parametryczny*/
    Drone(int nr_drona,PzG::LaczeDoGNUPlota &Lacze,Vector3D wspolrzende); 

    /*! \brief funkcja wizualizująca oraz wykonująca lot drona w kierunku prostopadlym do podloza*/
    void lot_do_gory(double droga);

    /*! \brief funkcja odpowiedzialna za obracanie drona*/
    void obrot(double kat);

    /*! \brief funkcja odpowiedzialna za symulacje obrotu wiernikow oraz ich przemieszcanie*/
    void obrot_wiernikow();

    /*! \brief funkcja odpowiadająca za zapis informacji o wspolrzednych do pliku*/
    void zapisz();

    /*! \brief funkcja odpowiedzialna za przesuwanie drona (lot) po plaszczyznie*/
    void przesun(double dorga); 

    /*! \brief funkcja odpowiadająca rysowanie trajektorii lotu drona w przestrzeni*/
    void narysuj_trase(double droga);
    
    /*! \brief funkcja odpowiadająca za pilotaz dronem*/
    void pilot(std::list<std::shared_ptr<obiekt>> &lista_elementow);

    /*! \brief zweaca numer drona*/
    int numer_drona(){return nr_drona;}

    /*! \brief usuwa dane o dronie*/
    void usun();


    bool kolizja_info(std::shared_ptr <obiekt> object);
};