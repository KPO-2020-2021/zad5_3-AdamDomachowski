#include "Solid.hh"

/*!
    \file
        \brief  metody klasy Solid
*/


/*! \brief ustawia wierzcholki srodka bryly*/
void Solid::wstaw_srodek(Vector3D srodek_bryly)
{
    this->srodek_bryly = srodek_bryly; //aby zapobiec przykrywaniu się zmiennych uzywam this*/
}

/*! \brief zczytuje wierzcholki srodka bryly*/
Vector3D Solid::zczytaj_srodek_obiektu() const
{
    return srodek_bryly;
}

/*! \brief zwraca konkretny wierzchołek*/
Vector3D Solid::czytaj_wierzcholki(int ver) const
{
    return wierzcholki[ver];
}

/*! \brief umozwliwia podania nazwy pliku do ktorego zapisywane beda wierzcholki*/
void Solid::ustaw_nazwe_pliku(std::string nazwa_pliku_bryly)
{
    this->nazwa_pliku_bryly = nazwa_pliku_bryly;
}

/*! \brief zczytuje nazwe pliku do ktorego zapisywane beda wierzcholki*/
std::string Solid::zczytaj_nazwe_obiektu() const
{
    return nazwa_pliku_bryly;
}

/*! \brief operator indeksujacy*/
Vector3D &Solid::operator[](int index)
{
    return wierzcholki[index];
}

/*! \brief operator indeksujacy*/
Vector3D Solid::operator[](int index) const
{
    return wierzcholki[index];
}

/*! \brief przesuwa bryle o zadany wektor*/
void Solid::przesun_o_wektor(Vector3D wektor_przesuniecia)
{
    for(int i=0; i < (int)wierzcholki.size() ; i++)
    {
        wierzcholki[i] =  wierzcholki[i] + wektor_przesuniecia;
    }
    srodek_bryly =  srodek_bryly + wektor_przesuniecia;
}

/*! \brief obraca bryle o zadany kat*/
void Solid::obrot(Matrix3x3 macierz_obrotu)
{
    for(int i=0; i < (int)wierzcholki.size() ; i++)
    {
        wierzcholki[i] = ( macierz_obrotu * wierzcholki[i]);
    }
    srodek_bryly = macierz_obrotu*srodek_bryly;
} 

/*! \brief zapisuje wspolrzedne bryly do pliku*/
void Solid::zapisz()
{
    std::fstream plik;
    double tab[]={0,0,(*wymiary)[2]/2};
    Vector3D wysokosc(tab);
    plik.open(nazwa_pliku_bryly, std::ios::out);
    for(int i=0; i<(int)wierzcholki.size() ; i+=2)
    {
      plik << srodek_bryly+wysokosc << std::endl;;  
        for(int j=0; j<2 ; j++)
        {
            plik << wierzcholki[j+i] << std::endl;
        }
      plik << srodek_bryly-wysokosc << std::endl << std::endl;
    }
    
      plik << srodek_bryly+wysokosc << std::endl;;  
        for(int j=0; j<2 ; j++)
        {
            plik << wierzcholki[j] << std::endl;
        }
      plik << srodek_bryly-wysokosc << std::endl << std::endl;
    plik.close();
}


bool Solid::kolizja_info(std::shared_ptr <obiekt> object)
{
    std::shared_ptr<Solid> self = shared_from_this();

    if (object != self)
    {

        Vector3D srodek_Bryla= zczytaj_srodek_obiektu();
        Vector3D srodek_Obiektu = object->zczytaj_srodek_obiektu();
        double l = sqrt(pow(srodek_Bryla[0] - srodek_Obiektu[0], 2) + pow(srodek_Bryla[1] - srodek_Obiektu[1], 2) + pow(srodek_Bryla[2] - srodek_Obiektu[2], 2));
        if (promien() + object->promien() >= l)
        {
            return true;
        }
    }
    return false;
}