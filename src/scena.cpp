#include "scena.hh"

/*!
    \file
        \brief przygotowuje scene, rysuje podloze, tworzy drony, ustawia gnuplota
*/

Scena::Scena()
{
Lacze.ZmienTrybRys(PzG::TR_3D);
Lacze.UstawZakresY(-300, 300);
Lacze.UstawZakresX(-300, 300);
Lacze.UstawZakresZ(-300, 300);

double wymiary[3]={600,600,0};
Vector3D wymiary_podloza(wymiary);
podloze=new Bottom(wymiary_podloza,20);
Vector3D losowy_srodek;
bool kolizja = false;
for (int i = 0; i < 4; i++){
    losowy_srodek[0] = rand() % 400 - 200;
    losowy_srodek[1] = rand() % 400 - 200;
    losowy_srodek[2] = 50;

  int nr_p=rand()%3;
       if(nr_p==0)
  lista_elementow.push_front(std::make_shared<goraSzczyt>(losowy_srodek, 100, 50, 100, "../datas/Element" + std::to_string(numer_elementu) + ".dat"));
  else if(nr_p==1)
  lista_elementow.push_front(std::make_shared<plaskowyz>(losowy_srodek, 100, 50, 100, "../datas/Element" + std::to_string(numer_elementu) + ".dat"));
  else if(nr_p==2)
  lista_elementow.push_front(std::make_shared<goraGran>(losowy_srodek, 100, 50, 100, "../datas/Element" + std::to_string(numer_elementu) + ".dat"));
  numer_elementu++;
  
  for (std::list<std::shared_ptr<obiekt>>::const_iterator a = lista_elementow.begin(); a != lista_elementow.end(); a++)
  {
      if ((*lista_elementow.begin())->czy_kolizja(*a))
      {
          kolizja = true;
      }
  }
  if (kolizja)
  {
      i--;
      lista_elementow.erase(lista_elementow.begin());
  }
  kolizja = false;
}

  for (std::list<std::shared_ptr<obiekt>>::const_iterator a = lista_elementow.begin(); a != lista_elementow.end(); a++)
  {
    Lacze.DodajNazwePliku((*a)->zczytaj_nazwe_obiektu().c_str());
    (*a)->zapisz();
    std::cout << (*a) -> zczytaj_nazwe_obiektu() << " " << (*a) -> promien() << std::endl;
  }


    Lacze.DodajNazwePliku(podloze->czytaj_nazwe().c_str());
    podloze->zapisz();
    kolizja = false;


    for(int i=0;i<ilosc_dronow_na_scenie; i++){

    double pozycja[3]={(double)(rand()%440-220),(double)(rand()%440-220),25};

    Lista_Dronow.push_front(std::make_shared<Drone>(numer_drona, Lacze, Vector3D(pozycja)));

    for (std::list<std::shared_ptr<obiekt>>::const_iterator a = lista_elementow.begin(); a!= lista_elementow.end(); a++)
    {
        if (*Lista_Dronow.begin())->czy_kolizja(*a))
    (*Lista_Dronow.begin())->zapisz();
    numer_drona++;
    Lacze.Rysuj();
    }

}



 void Scena::dodaj_drona(){}






/*! \brief rysuje*/
void Scena::rysuj()
{
    Lacze.Rysuj();
}



/*! \brief wyswietla menu oraz odpowiada za wybor konkretnego drona */
bool Scena::menu()
{
    std::cout<<"\nWybierz  |  1.pilotaz  |   2. dodaj przeszkode  |  3. usun przeszkode  |   4. dodaj drona   |    5. usun drona  |  6. END   |  Twoj wybor: ";
    int wybor;
    std::cin >> wybor;
    switch (wybor)
    {



        case 1:{
        std::cout<< "\nPodaj nr drona: ";
        for(int i=0; i<(int)Lista_Dronow.size(); i++)
        {
        std::cout<<i <<" ";
        }
        std::cout<<":";
        int numer_drona = 0;
        std::cin>>numer_drona;
        if(numer_drona > (int)Lista_Dronow.size() -1 || numer_drona < 0) { std::cout << "nie ma takiego drona" << std::endl; return false; }
        std::list<std::shared_ptr<Drone>>::const_iterator a;
        a=Lista_Dronow.begin();
        for(int i=0; i<numer_drona; i++){
            a++;
        }
        (*a)->pilot();
        }//case
        break;



        case 2:{
        std::cout<< "\nWybierz |  1.gora ze szczytem  |  2.gora z grania  |  3.plaskowyz  Twoj wybor: ";

        int wybor;
        std::cin >> wybor;
        if (wybor < 1 || wybor > 3){
        std::cout << "wybrano element ktorego nie ma";
        throw "wybrano drona ktorego nie ma";
        exit(0);            
        }
        Vector3D los_srodek;
        los_srodek[0] = rand() % 400 - 200;
        los_srodek[1] = rand() % 400 - 200;
        los_srodek[2] = 50;

        if (wybor == 1){
            lista_przeszkod.push_front(std::make_shared<goraSzczyt>(los_srodek, 100, 50, 100, 
            "../datas/Element" + std::to_string(numer_elementu) + ".dat"));
        }

        if (wybor == 2){
            lista_przeszkod.push_front(std::make_shared<plaskowyz>(los_srodek, 100, 50, 100, 
            "../datas/Element" + std::to_string(numer_elementu) + ".dat"));
        }

        if (wybor == 3){
            lista_przeszkod.push_front(std::make_shared<goraGran>(los_srodek, 100, 50, 100, 
            "../datas/Element" + std::to_string(numer_elementu) + ".dat"));
        }

        numer_elementu++;
        (*lista_przeszkod.begin())->zapisz_do_pliku();
         Lacze.DodajNazwePliku((*lista_przeszkod.begin())->jaka_nazwa().c_str());


        }//case 2
        break;

        

        case 3:{
        int i = 0;

        for (std::list<std::shared_ptr<Solid>>::const_iterator a = lista_przeszkod.begin(); a != lista_przeszkod.end(); a++){
        std::cout << "obiekt nr " << i << ": " << (*a)->jaka_nazwa() << std::endl;
        i++;
        }

        std::cout << "podaj numer" << std::endl;

        int numer;
        std::cin >> numer;
        std::list<std::shared_ptr<Solid>>::const_iterator a = lista_przeszkod.begin();
        for (int j = 0; j < numer; j++)
        {
        a++;
        }
        Lacze.UsunNazwePliku((*a)->jaka_nazwa());
        lista_przeszkod.erase(a);
        }
        break;



        case 4:{
        dodaj_drona();
        }    
        break;


        case 5:{
        int i = 0;
        for (std::list<std::shared_ptr<Drone>>::const_iterator a = Lista_Dronow.begin(); a != Lista_Dronow.end(); a++){
        std::cout << i << ": " << (*a)->numer_drona() << std::endl;
        i++;
        }
        std::cout << "podaj numer" << std::endl;
        int nr;
        std::cin >> nr;
        std::list<std::shared_ptr<Drone>>::const_iterator a = Lista_Dronow.begin();
        for (int j = 0; j < nr; j++){
        a++;
        }   
        (*a)->usun();
        Lista_Dronow.erase(a);
        }
        break;  




        case 6:{
        std::cout << "koniec dzialania programu ...";
        free(podloze);
        }    
        return false;


        default:
        break;
        

        }//switch
return true;
}//pilot




