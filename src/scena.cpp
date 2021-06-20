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
numer_elementu=0;
numer_drona=0;
double wymiary[3]={600,600,0};
Vector3D wymiary_podloza(wymiary);
podloze=new Bottom(wymiary_podloza,20);
double losowy_srodek[3];
bool kolizja = false;
for (int i = 0; i < 2; i++){
    losowy_srodek[0] = rand() % 400 - 200;
    losowy_srodek[1] = rand() % 400 - 200;
    losowy_srodek[2] = 50;
    int nr = rand() % 3;
       if(nr==0)
  lista_elementow.push_front(std::make_shared<goraSzczyt>(losowy_srodek, 100, 75, 100, "../datas/goraszczyt" + std::to_string(i) + ".dat"));
  else if(i==1)
  lista_elementow.push_front(std::make_shared<plaskowyz>(losowy_srodek, 100, 30, 100, "../datas/plaskowyz" + std::to_string(i) + ".dat"));
  else if(i==2)
  lista_elementow.push_front(std::make_shared<goraGran>(losowy_srodek, 100, 50, 100, "../datas/goragran" + std::to_string(i) + ".dat"));
  numer_elementu++;
  
  for (std::list<std::shared_ptr<obiekt>>::const_iterator a = lista_elementow.begin(); a != lista_elementow.end(); a++)
  {
      if ((*lista_elementow.begin())->kolizja_info(*a))
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

    Lista_Dronow.push_front(std::make_shared<Drone>(i, Lacze, Vector3D(pozycja)));

    for (std::list<std::shared_ptr<obiekt>>::const_iterator a = lista_elementow.begin(); a!= lista_elementow.end(); a++)
    {
        if ((*Lista_Dronow.begin())->kolizja_info(*a)){
            kolizja = true;
        }
    }
    if (kolizja)
    {
        i--;
        Lista_Dronow.erase(Lista_Dronow.begin());
    }
    else
    {
        lista_elementow.push_front(*Lista_Dronow.begin());
        std::cout << (*Lista_Dronow.begin())-> zczytaj_nazwe_obiektu() << " " << (*Lista_Dronow.begin())->promien() << std::endl;
        (*Lista_Dronow.begin())->zapisz();
        numer_drona++;
    }
    kolizja =false;
    }
    Lacze.Rysuj();
}




/*! \brief rysuje*/
void Scena::rysuj()
{
    Lacze.Rysuj();
}



/*! \brief wyswietla menu oraz odpowiada za wybor konkretnego drona */
bool Scena::menu()
{
    std::cout<<"\nWybierz  |  1.pilotaz  |   2. dodaj obiekt  |  3. usun przeszkode  |    |  5. END   |  Twoj wybor: ";
    int wybor;
    std::cin >> wybor;
    switch (wybor)
    {



        case 1:{;
        std::cout<< "\nPodaj nr drona: ";
        for(int i=0; i<(int)Lista_Dronow.size(); i++)
        {
        std::cout<<i <<" ";
        }
        std::cout<<":";
        int numer = 0;
        std::cin>>numer;
        if(numer > (int)Lista_Dronow.size() -1 || numer < 0) { std::cout << "nie ma takiego drona" << std::endl; return false; }
        std::list<std::shared_ptr<Drone>>::const_iterator a;
        a=Lista_Dronow.begin();
        for(int i=0; i<numer; i++){
            a++;
        }
        (*a)->pilot(lista_elementow);
        }//case
        break;



        case 2:{
        std::cout<< "\nWybierz |  1.gora ze szczytem  |  2.gora z grania  |  3.plaskowyz  |  4. dron  | Twoj wybor: ";

        int wybor;
        std::cin >> wybor;
        if (wybor < 1 || wybor > 4){
        std::cout << "wybrano element ktorego nie ma";
        throw "wybrano drona ktorego nie ma";
        exit(0);            
        }
        Vector3D los_srodek;
        if (wybor!=4){
        for(int i=0; i < 50; i++){
        los_srodek[0] = rand() % 400 - 200;
        los_srodek[1] = rand() % 400 - 200;
        los_srodek[2] = 50;
        bool kolizja = false;
        if (wybor == 1){

            lista_elementow.push_front(std::make_shared<goraSzczyt>(los_srodek, 100, 50, 100, 
            "../datas/goraszczyt" + std::to_string(numer_elementu) + ".dat"));
        }

        if (wybor == 2){
            lista_elementow.push_front(std::make_shared<plaskowyz>(los_srodek, 100, 50, 100, 
            "../datas/plaskowyz" + std::to_string(numer_elementu) + ".dat"));
        }

        if (wybor == 3){
            lista_elementow.push_front(std::make_shared<goraGran>(los_srodek, 100, 50, 100, 
            "../datas/gran" + std::to_string(numer_elementu) + ".dat"));
        }

        numer_elementu++;
        for (std::list<std::shared_ptr<obiekt>>::const_iterator a=lista_elementow.begin(); a!=lista_elementow.end();a++){
            if((*lista_elementow.begin())->kolizja_info(*a)){
                kolizja = true;
            }
        }
        if (kolizja){
            i--;
            lista_elementow.erase(lista_elementow.begin());
        }
        else{
            break;
         }
        }
        (*lista_elementow.begin())->zapisz();
        Lacze.DodajNazwePliku((*lista_elementow.begin())->zczytaj_nazwe_obiektu().c_str());
        
        }
        else
        {
            bool kolizja = false;
            for (int i=0; i< 35; i++)
            {
                
                double pozycja[3] = {(double)(rand() % 440 - 220), (double)(rand() % 440 - 220), 25};

                Lista_Dronow.push_front(std::make_shared<Drone>(numer_drona, Lacze, Vector3D(pozycja)));  

                for (std::list<std::shared_ptr<obiekt>>::const_iterator a = lista_elementow.begin(); a != lista_elementow.end(); a++)
                {
                    
                    if((*Lista_Dronow.begin())->kolizja_info(*a))
                    {
                        kolizja = true;
                    }
                }
                if (kolizja)
                {
                    Lista_Dronow.erase(Lista_Dronow.begin());
                    
                }
                else
                {
                    lista_elementow.push_front(*Lista_Dronow.begin());
                    std::cout << (*Lista_Dronow.begin())->zczytaj_nazwe_obiektu() << " " << (*Lista_Dronow.begin())->promien() << std::endl;
                    (*Lista_Dronow.begin())->zapisz();
                    numer_drona++;
                    break;
                }
                kolizja = false;
            }
        }
    }//case 2
        break;

        


        case 3: //usuwa element
        {
            int i = 0;
            for (std::list<std::shared_ptr<obiekt>>::const_iterator a = lista_elementow.begin(); a != lista_elementow.end(); a++)
            {
            std::cout << i << ": " << (*a)->zczytaj_nazwe_obiektu() << std::endl;
             i++;
            }   

            std::cout << "podaj numer" << std::endl;

            int numer;
            std::cin >> numer;
            std::list<std::shared_ptr<obiekt>>::const_iterator a = lista_elementow.begin();

            for (int j = 0; j < numer; j++)
            {
                a++;
            }       
            Lacze.UsunNazwePliku((*a)->zczytaj_nazwe_obiektu());
            lista_elementow.erase(a);   
        }
        break;



        case 4: 
        {
        int i = 0;
        for (std::list<std::shared_ptr<Drone>>::const_iterator a = Lista_Dronow.begin(); a != Lista_Dronow.end(); a++)
        {
        std::cout << i << ": " << (*a)->numer_drona() << std::endl;
        i++;
        }
        std::cout << "podaj numer" << std::endl;

        int numer;
        std::cin >> numer;
        std::list<std::shared_ptr<Drone>>::const_iterator a = Lista_Dronow.begin();

        for (int j = 0; j < numer; j++)
        {
         a++;
        }

    (*a)->usun();

    for (std::list<std::shared_ptr<obiekt>>::const_iterator b = lista_elementow.begin(); b != lista_elementow.end(); b++)
    {
      if (*a == *b)
      {
        lista_elementow.erase(b);
      }
    }
    Lista_Dronow.erase(a);
  }
  break;




        case 5:{
        std::cout << "koniec dzialania programu ...";
        }    
        return false;


        default:
        break;
        

        }//switch
return true;
}//pilot



