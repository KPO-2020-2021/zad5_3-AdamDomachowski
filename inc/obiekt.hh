#pragma once
#include <string>
#include <memory>



class obiekt
{

public:

/*! \brief zwraca promien obiektu*/
virtual bool kolizja_info(shared_ptr <obiekt> object)=0;

/*! \brief zczytuje nazwe obiektu*/
virtual std::string zczytaj_nazwe_obiektu() const=0;

/*! \brief zapisuje obiekt*/
virtual void zapisz()=0;

/*! \brief zczytuje wspolrzedne srodka obiektu*/
virtual Vector3D zczytaj_srodek_obiektu() const=0;

/*! \brief zwraca promien obiektu*/
virtual double promien()=0;
};

