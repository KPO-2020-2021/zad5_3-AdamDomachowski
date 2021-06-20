#include "Drone.hh"

/*!
    \file
    \brief metody klasy drone
*/

    /*!
    \brief konstruktor drona                                                                                                                      
    \param [in] nr_drona - numer drona.      
    \param [in] Lacze - gnuplot  
    \param [in] wspolrzende - poczatkowe polozenie drona.                                                                                                            
    \return nieobrocony dron we wskazanym punkcie.                              
    */
    Drone::Drone(int nr_drona,PzG::LaczeDoGNUPlota &Lacze, Vector3D wspolrzende):Lacze(Lacze)
    {
        this->nr_drona = nr_drona;
        body_org.ustaw_nazwe_pliku("../datas/body"+std::to_string(nr_drona)+ ".dat");
        

        for(int i=0; i<4; i++)
        {
        wings_org[i].ustaw_nazwe_pliku("../datas/wings"+std::to_string(nr_drona)+std::to_string(i)+".dat");
        }
        Lacze.DodajNazwePliku(body_org.zczytaj_nazwe_obiektu().c_str());

        for(int i=0; i<4; i++)
        {
        Lacze.DodajNazwePliku(wings_org[i].zczytaj_nazwe_obiektu().c_str());
        }
        
        body_copy = body_org;

        body_copy.przesun_o_wektor(wspolrzende);

        for(int i=0; i<4; i++)
        {
            wings_copy[i] = wings_org[i];
        }

        for(int i=0; i<4; i++)
        {
            wings_copy[i].przesun_o_wektor(body_org[i*2] + wspolrzende);
        }

        this->droga = this->droga + wspolrzende;
    }



  void Drone::usun()
  {
    Lacze.UsunNazwePliku(body_org.zczytaj_nazwe_obiektu().c_str());
    for (int i = 0; i < 4; i++)
        Lacze.UsunNazwePliku(wings_org[i].zczytaj_nazwe_obiektu().c_str());
  }

/*!
    \brief funkcja obrotu drona                                                                                                                      
    \param [in] kat - kat do obrotu.      
*/
    void Drone::obrot(double kat)
    {
        double tab[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
        this->kat += kat;
        Matrix3x3 jedynkowa(tab);
        macierz_obrotu = jedynkowa * obrot_Z(this->kat);
        body_copy.obrot(macierz_obrotu);
        body_copy.przesun_o_wektor(this->droga);
    }

/*!
    \brief funkcja odpowiedzialna za symulacje obrotu wiernikow oraz ich przemieszcanie                                                                                                                  
    \param [in] kat - kat do obrotu.     
*/
    void Drone::obrot_wiernikow()
    {
    static int kat = 0;
    kat+=3;
    if (kat==360)
    {
        kat=0;
    }
    Matrix3x3 mtx,xtm;
    for (int i=0; i<4; i++){
        if((i+1)%2==0){
            mtx=mtx*obrot_Z(kat);
            wings_copy[i].obrot(mtx);
        }
        else{
            xtm = xtm * obrot_Z(-kat);
            wings_copy[i].obrot(xtm);
        }
    }
    for (int i = 0; i < 4; i++)
    {
        wings_copy[i].przesun_o_wektor(body_copy[i * 2]);
    }
}



/*!
    \brief funkcja odpowiedzialna za przesuwanie drona (lot) po plaszczyznie                                                                                                          
    \param [in] droga - droga ktora przebedzie dron.     
*/
    void Drone::przesun(double droga)
    {
        Vector3D droga_1;
        droga_1[0] = droga * cos(kat*M_PI/180);
        droga_1[1] = droga * sin(kat*M_PI/180);
        droga_1[2] = 0;

        this->droga = this->droga + droga_1;
        body_copy.obrot(macierz_obrotu); 
        body_copy.przesun_o_wektor(this->droga);
    }

/*!
    \brief funkcja odpowiadająca za zapis informacji o wspolrzednych do pliku                                                                                                            
*/
    void Drone::zapisz()
    {
        body_copy.zapisz();
        for(int i=0; i<4; i++)
        {
            wings_copy[i].zapisz();
        }
    }

/*!
    \brief funkcja wizualizująca oraz wykonująca lot drona w kierunku prostopadlym do podloza                                                                                                        
    \param [in] droga - droga ktora przebedzie dron.     
*/
    void Drone::lot_do_gory(double droga)
    {
        Vector3D droga_1;
        droga_1[2] = droga;

        this->droga = this->droga + droga_1;

        body_copy.obrot(macierz_obrotu); 
        body_copy.przesun_o_wektor(this->droga);
    }

/*!
    \brief funkcja odpowiadająca za pilotaz dronem.
*/
    void Drone::pilot(std::list<std::shared_ptr<obiekt>> &lista_elementow)
    {
        double droga;
        double kat;
        char wybor;
        int stop = 0;
        while(stop==0){
        std::cout << "\nm - menu: ";
        std::cin >> wybor;
        switch (wybor)
        {
        case 'l':
        {
            std::cout << "podaj droge: ";
            std::cin >> droga;
            narysuj_trase(droga);
            Lacze.DodajNazwePliku("../datas/trajektoria.dat");
            for (int i=0;i<100; i++)
            {
            body_copy=body_org;
            for (int j = 0; j < 4; j++)
                wings_copy[j] = wings_org[j]; 
            lot_do_gory(1);
           obrot_wiernikow();
            zapisz();
            Lacze.Rysuj();
            usleep(10000);
            }
            bool kolizja = false;
            while(1){       
            for (int i=0;i<droga; i++)
            {
            body_copy = body_org;    
                for(int j=0; j<4; j++)
                {   
                    wings_copy[j] = wings_org[j];
                 }
            przesun(1);
            obrot_wiernikow();
            zapisz();
            Lacze.Rysuj();
            usleep(10000);
            }

            for (std::list<std::shared_ptr<obiekt>>::const_iterator a = lista_elementow.begin(); a != lista_elementow.end(); a++)
            {
            std::cout <<"*";
            body_copy=body_org; 
            lot_do_gory(-100);
            if (kolizja_info(*a)){
                std::cout << "kolizja z"+ (*a)->zczytaj_nazwe_obiektu() << std::endl;
                kolizja = true;
            }
            body_copy = body_org;
            lot_do_gory(100);
            }  

            if(!kolizja)
            {
                break;
            }
            kolizja=false;
            droga = 10;
            narysuj_trase(droga);
            }
            for (int i =0; i<100; i++)
            {
                body_copy = body_org;
                for(int j =0; j<4; j++)
                {
                    wings_copy[j] = wings_org[j];
                }
                lot_do_gory(-1);
                obrot_wiernikow();
                zapisz();
                Lacze.Rysuj();
                usleep(10000);
            }
            Lacze.UsunNazwePliku("../datas/droga.dat");
        }
        break;

        case 'o':
        {
            std::cout << "podaj kat (w stopniach) obrotu: ";
            std::cin >> kat;
            if (kat > 0){
                for (int i=0;i<kat; i++)
                {
                body_copy = body_org;   
                for(int j=0; j<4; j++)
                {
                wings_copy[j] = wings_org[j];
                }
                obrot(1);
                obrot_wiernikow();
                zapisz();
                Lacze.Rysuj();
                usleep(10000);
                }
            }
            else
            {
                for (int i=0;i>kat; i--)
                {
                body_copy = body_org;  
                for(int j=0; j<4; j++)
                {
                wings_copy[j] = wings_org[j];
                } 
                obrot(-1);
                obrot_wiernikow();
                zapisz();
                Lacze.Rysuj();
                usleep(10000);
                }
            }
         }
            break;

        case 'm':
        std::cout << "\nMenu wyboru opcji:" << std::endl
        << "o - obrot drona o zadany kat" << std::endl
        << "l - lot drona na danej drodze " << std::endl
        << "m - wyswietl menu" << std::endl
        << "k - powrot do main menu" << std::endl << std::endl;
            break;

        case 'k':{
        stop = 1;
        }
            break;
        
        default:
            break;
        }
    }
}//while



/*!
    \brief funkcja wizualizująca trajektorie lotu                                                                                                       
    \param [in] droga - droga ktora przebedzie dron.     
*/
    void Drone::narysuj_trase(double droga)
{
    Vector3D nastepny = body_copy.zczytaj_srodek_obiektu();
    nastepny[2] = 0;
    trajektoria.push_back(nastepny);

    nastepny[2] = 100;
    trajektoria.push_back(nastepny);

    nastepny[0] += droga * cos(kat * M_PI / 180);
    nastepny[1] += droga * sin(kat * M_PI / 180);
    trajektoria.push_back(nastepny);

    nastepny[2] = 0;
    trajektoria.push_back(nastepny);

    std::fstream plik;

    plik.open("../datas/trajektoria.dat", std::ios::out);
    for (int i = 0; i < (int)trajektoria.size(); i++)
    {

        plik << trajektoria[i] << std::endl;
    }
    plik.close();
}


bool Drone::kolizja_info(shared_ptr <obiekt> object)
{
    std::shared_ptr<Drone> A = shared_from_this();

    if (object != A)
    {

        Vector3D srodek_Drona = body_copy.zczytaj_srodek_obiektu();
        Vector3D srodek_Obiektu = object->zczytaj_srodek_obiektu();
        double l = sqrt(pow(srodek_Drona[0] - srodek_Obiektu[0], 2) + pow(srodek_Drona[1] - srodek_Obiektu[1], 2) + pow(srodek_Drona[2] - srodek_Obiektu[2], 2));
        if (promienR + object->promien() >= l)
        {
            return true;
        }
    }
    return false;
}


Vector3D Drone::zczytaj_srodek_obiektu() const
{
    return body_copy.zczytaj_srodek_obiektu();
}