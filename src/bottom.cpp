#include "bottom.hh"

/*!
    \file
    \brief metody klasy bottom
*/


    /*!
    konstruktor prostopadloscianu                                                                                                                      
    \param [in] wymiary - wymiary podloza    
    \param [in] grubosc_kratki - grubosc kratki podloza
    \param [in] nazwa_pliku - nazwa pliku w kotrym zapisywane wspolrzende podloza                                                                                                        
    \return podloze z okreslonymi chechami.                           
 */
    Bottom::Bottom(Vector3D wymiary, int grubosc_kratki , std::string nazwa_pliku)
    {
    this->nazwa = nazwa_pliku;
    double tab[3];
    proste=0;
    for (int i = -wymiary[0] / 2; i < wymiary[0] / 2; i += grubosc_kratki)
    {
        for (int j = -wymiary[1] / 2; j < wymiary[1] / 2; j += grubosc_kratki)
        {
            tab[0] = i;
            tab[1] = j;

            wierzcholki.push_back(tab);
        }
        proste++;
    }
    }


    /*!
    Funktor podloza                                                                                                                            
    \param [in] index - index .                                                                                                              
    \return Wartosi punktu                 
    */
    Vector3D &Bottom::operator[](int index)
    {
    return wierzcholki[index];
    }


    /*!
    Funktor podloza                                                                                                                            
    \param [in] index - index .                                                                                                              
    \return Wartosi punktu                 
    */
    Vector3D Bottom::operator[](int index)const
    {
    return wierzcholki[index];
    }


    /*!
    \brief funkcja ustawiajaca nazwe podloza                                                                                                                                          
    */   
    void Bottom::ustaw_nazwe(std::string nazwa)
    {
    this->nazwa = nazwa;
    }
    

    /*!
    \brief funkcja ustawiajaca nazwe podloza 
    \return nazwa podloza                                                                                                                                         
    */  
    std::string Bottom::czytaj_nazwe() const
    {
    return nazwa;
    }


    /*!
    \brief zapisuje do pliku                                                                                                                                  
    */  
    void Bottom::zapisz()
    {
    std::fstream plik;
    plik.open(nazwa, std::ios::out);
    for (int i = 0; i < (int)wierzcholki.size(); i ++)
    {  
    if(i%proste==0)
    plik<<std::endl;
     plik<<wierzcholki[i]<<std::endl;
    }  
    plik.close();
    }