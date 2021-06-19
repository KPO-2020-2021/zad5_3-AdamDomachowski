#include "prism6.hh"

/*!
    \file
    \brief metody klasy prism6
*/

/*!
    konstruktor graniastoslupa                                                                                                                      
    \param [in] centrum - wspolrzedne srodka graniastoslupa.      
    \param [in] R - promien graniastoslupa  
    \param [in] dlugosc_graniastoslupa - dluglosc scianki  
    \param [in] nazwa_pliku_graniastoslupa6 - nazwa pliku do zapisu wierzcholkow                                                                                                            
    \return graniastoslup z okreslonymi chechami.                           
 */
Prism6::Prism6(Vector3D centrum,double R , double dlugosc_graniastoslupa, std::string nazwa_pliku_graniastoslupa6 )
{
    double tab[]={0,0,dlugosc_graniastoslupa};
    wymiary = std::make_shared<Vector3D> (tab);
    this->srodek_bryly=centrum;
    this->nazwa_pliku_bryly = nazwa_pliku_graniastoslupa6;
    Vector3D punkt;

    for(int i=0; i<360; i+=60)
    {
       punkt[0] = R*cos(i*M_PI/180);
       punkt[1] = R*sin(i*M_PI/180);
       punkt[2] = centrum[2] + (dlugosc_graniastoslupa/2);
       wierzcholki.push_back(punkt);

       punkt[0] = R*cos(i*M_PI/180);
       punkt[1] = R*sin(i*M_PI/180);
       punkt[2] = centrum[2] - (dlugosc_graniastoslupa/2);
       wierzcholki.push_back(punkt);
    }
}