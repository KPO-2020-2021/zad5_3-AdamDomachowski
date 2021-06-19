#pragma once
#include <string>
#include <memory>

#include "Vector3D.hh"


class obiekt
{

public:

virtual bool czy_kolizja(std::shared_ptr <obiekt> object)=0;
virtual std::string zczytaj_nazwe_obiektu() const=0;
virtual void zapisz()=0;
virtual Vector3D zczytaj_srodek_obiektu() const=0;
virtual double promien()=0;
};

