//
//  main.cpp
//  lab_1_zamkniete
//
//  Created by Łukasz Gołojuch on 10/24/20.
//  Copyright © 2020 Łukasz Gołojuch. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <unistd.h>

#include "Rosliny.h"
#include "Zwierzeta.h"
#include "Organizmy.h"
#include "Swiat.h"

using namespace std;

//imie, nazwisko, numer indeksu i rozmiar planszy
 const string imie_const = "Lukasz" ; //stala przechowujaca imie autora
 const string nazwisko_const = "Golojuch" ; //stala przechowujaca nazwisko autora
 const int indeks_const = 175520 ; //stala przechowujaca nr. indeksu autora
 const int rozmiar_planszy = 20 ; //stala przechowujaca rozmiar planszy

void Swiat::skomentuj_walke(char litera)
{
    switch(litera)
    {
        case 'Z':
            //kiedy znak = 'Z' -> żółw został zaatakowany i przegral
            cout<<"O nie! Jakis zolw wlasnie zostal zaatakowany i zginal!"<<endl;

        break;
            
        case 'J':
            //kiedy znak = 'J' -> jeż został zaatakowany i przegral
            cout<<"O nie! Jakis jez wlasnie zostal zaatakowany i zginal!"<<endl;

        break;
            
        case 'W':
            //kiedy znak = 'W' -> wilk został zaatakowany i przegral
            cout<<"O nie! Jakis wilk wlasnie zostal zaatakowany i zginal!"<<endl;

        break;
            
        case 'O':
            //kiedy znak = 'O' -> owca został zaatakowany i przegral
            cout<<"O nie! Jakas owca wlasnie zostala zaatakowana i zginela!"<<endl;

        break;
            
        case 'L':
            //kiedy znak = 'L' -> leniwiec został zaatakowany i przegral
            cout<<"O nie! Jakis leniwiec wlasnie zostal zaatakowany i zginal!"<<endl;
        break;
    }
}

void Swiat::skomentuj_rozmnozenie(int id)
{
    switch(id)
    {
        case 1:
            //kiedy liczba = '1' -> urodził się nowy żółw
            cout<<"Wlasnie na swiat przyszedl nowy zolw!"<<endl;
        break;
            
        case 2:
            //kiedy liczba = '2' -> urodził się nowy jeż
            cout<<"Wlasnie na swiat przyszedl nowy jez!"<<endl;
        break;
            
        case 3:
            //kiedy liczba = '2' -> urodził się nowy wilk
            cout<<"Wlasnie na swiat przyszedl nowy wilk!"<<endl;
        break;
            
        case 4:
            //kiedy liczba = '4' -> urodziła się nowa owca
            cout<<"Wlasnie na swiat przyszla nowa owca!"<<endl;
        break;
            
        case 5:
            //kiedy liczba = '5' -> urodził się nowy leniwiec
            cout<<"Wlasnie na swiat przyszedl nowy leniwiec!"<<endl;
        break;
    }
}

Swiat::Swiat()
{
    for (int i=0; i<=rozmiar_planszy; i++)
    {
        for(int j=0; j<=rozmiar_planszy; j++)
        {
            this->mapa_swiata[i][j]= 0;
        }
    }

    this->nazwisko = nazwisko_const;
    this->imie = imie_const;
    this->indeks = indeks_const;
}

Swiat::~Swiat()
{
    cout<<"Destruktor swiata"<<endl;
}

void Swiat::wykonajTure()
{
    cout<<endl<<endl;

    this -> wypisz_dane(); //wypisujemy dane autora
    this -> komentarz(); //rozpoczynamy sekcję komentarzy
    
    srand(time(NULL));
    int ruch; //zmienna przechowująca wynik działania metody akcja()
    int p1,p2,p3,p4; //p1 & p3 -> przesunięcia w osi X p2 & p4 -> przesunięcia w osi Y
                    //przyjmują wartości -1 , 0 lub 1
    int s;
    int wynik_kolizji; //zmienna przechowująca wynik działania metody kolizja()
    char litera; //zmienna przechowująca wynik działania metody rysowanie()

    //rozpoczęcie przejścia przez tablicę świata
    for(int i=0; i<rozmiar_planszy; i++)
    {
        for(int j=0; j<rozmiar_planszy; j++)
        {
            if(this -> mapa_swiata[i][j] != 0 && this -> mapa_swiata[i][j] -> kontakt_jez <= 0 && this -> mapa_swiata[i][j] -> ruch_wykonany == false)
            {
                this -> mapa_swiata[i][j] -> ruch_wykonany = true; //ustawiamy info o wykonaniu ruchu ->
                                                                  //obiekt nie może wykonać dwóch ruchów w jednej turze
                this -> mapa_swiata[i][j] -> kontakt_jez --; //dekrementacja zmiennej przechowująca info o ataku na jeża

                ruch = this -> mapa_swiata[i][j] -> akcja(); //zapisujemy jaki ruch zostanie wykonany
                if(ruch == 0)
                {
                    //nie wykonujemy zadnego ruchu
                }
                else if (ruch == 1)
                {
                    //wykonujemy ruch
                    p1 = (rand()%3)-1; //losujemy przesuniecie w celu wykonanie ruchu (oś X)
                    p2 = (rand()%3)-1; //losujemy przesuniecie w celu wykonanie ruchu (oś Y)
                    if(i+p1 >=0 && j+p2 >=0 && i+p1 < rozmiar_planszy && j+p2 < rozmiar_planszy)
                    {
                        //sprawdzamy czy nie wyjdziemy za tablice
                        if(this -> mapa_swiata[i][j] == this -> mapa_swiata[i+p1][j+p2])
                        {
                            //rozmnazanie zwierząt
                            p3 = (rand()%3)-1; //losujemy przesuniecie w celu umiejscowienia nowego obiektu (oś X)
                            p4 = (rand()%3)-1; //losujemy przesuniecie w celu umiejscowienia nowego obiektu (oś Y)
                            if(this -> mapa_swiata[i+p1+p3][j+p2+p4] == 0) //sprawdzamy czy nic nie stoi na pozycji
                            {
                                try
                                {
                                    if(this -> mapa_swiata[i+p1][j+p2] -> rysowanie() == 'Z')
                                    {
                                        //rozmnażanie żółwia
                                        this -> mapa_swiata[i+p1+p3][j+p2+p4] = new Zolw(i+p1+p3,j+p2+p4);
                                        this -> skomentuj_rozmnozenie(1); //komentujemy rozmnażanie
                                    }
                                    else if(this -> mapa_swiata[i+p1][j+p2] -> rysowanie() == 'J')
                                    {
                                        //rozmnażanie jeża
                                        this -> mapa_swiata[i+p1+p3][j+p2+p4] = new Jez(i+p1+p3,j+p2+p4);
                                        this -> skomentuj_rozmnozenie(2); //komentujemy rozmnażanie
                                    }
                                    else if(this -> mapa_swiata[i+p1][j+p2] -> rysowanie() == 'W')
                                    {
                                        //rozmnażanie wilka
                                        this -> mapa_swiata[i+p1+p3][j+p2+p4] = new Wilk(i+p1+p3,j+p2+p4);
                                        this -> skomentuj_rozmnozenie(3); //komentujemy rozmnażanie
                                    }
                                    else if(this -> mapa_swiata[i+p1][j+p2] -> rysowanie() == 'O')
                                    {
                                        //rozmnażanie owcy
                                        this -> mapa_swiata[i+p1+p3][j+p2+p4] = new Owca(i+p1+p3,j+p2+p4);
                                        this -> skomentuj_rozmnozenie(4); //komentujemy rozmnażanie
                                    }
                                    else if(this -> mapa_swiata[i+p1][j+p2] -> rysowanie() == 'L')
                                    {
                                        //rozmnażanie leniwca
                                        this -> mapa_swiata[i+p1+p3][j+p2+p4] = new Leniwiec(i+p1+p3,j+p2+p4);
                                        this -> skomentuj_rozmnozenie(5); //komentujemy rozmnażanie
                                    }
                                }
                                catch(const std::exception& e)
                                {
                                    //w przypadku wyłapania wyjątku nie dokonujemy rozmnażania i przechodzimy dalej
                                }
                            }
                        }
                        else if(this -> mapa_swiata[i+p1][j+p2]==0)
                        {
                            //wykonujemy ruch gdy pole docelowe jest puste
                            this -> mapa_swiata[i+p1][j+p2] = this -> mapa_swiata[i][j]; //umiejscawiamy obiekt w nowym położeniu
                            //zmieniamy położenie x i y obiektu
                            this -> mapa_swiata[i+p1][j+p2] -> x = i+p1;
                            this -> mapa_swiata[i+p1][j+p2] -> y = j+p2;

                            this -> mapa_swiata[i][j] = 0; //pozostawiamy zwolnione miejsce puste
                        }
                        else if(this -> mapa_swiata[i+p1][j+p2]!=0)
                        {
                            //doszlo do kolizji - atak na przeciwnika
                            s = this -> mapa_swiata[i][j] -> sila;
                            wynik_kolizji = this -> mapa_swiata[i+p1][j+p2] -> kolizja(s); //zapisujemy wynik kolizji

                            switch(wynik_kolizji)
                            {
                                case 0:
                                    //wygrana atakujacego - przesuniecie
                                    
                                    litera = this -> mapa_swiata[i+p1][j+p2] -> rysowanie(); //pobieramy znak reprezentujący zwierzę
                                    this -> skomentuj_walke(litera); //komentujemy przegraną
                                    
                                    this -> mapa_swiata[i+p1][j+p2] = this -> mapa_swiata[i][j]; //przenosimy obiekt
                                    
                                    this -> mapa_swiata[i+p1][j+p2] -> x = i+p1;
                                    this -> mapa_swiata[i+p1][j+p2] -> y = j+p2;

                                    this -> mapa_swiata[i][j] = 0;
                                break;

                                case 1:
                                    //atakujacy przegrywa usuniecie ze swiata
                                    this -> mapa_swiata[i][j] = 0;
                                break;

                                case 2:
                                    //brak czynności do wykonania - remis
                                break;

                                case 3:
                                    //przypadek ataku na jeża
                                    this -> mapa_swiata[i+p1][j+p2] = this -> mapa_swiata[i][j]; //przenosimy obiekt
                                    this -> mapa_swiata[i+p1][j+p2] -> x = i+p1;
                                    this -> mapa_swiata[i+p1][j+p2] -> y = j+p2;
                                    this -> mapa_swiata[i+p1][j+p2] -> kontakt_jez = 2; //ustawiamy dwie kolejki do odczekania po ataku na jeża

                                    this -> mapa_swiata[i][j] = 0;
                                break;

                                case 4:
                                    //zjedzenie guarany siła +3
                                    this -> mapa_swiata[i+p1][j+p2] = this -> mapa_swiata[i][j]; //przenosimy obiekt na miejsce guarany
                                    this -> mapa_swiata[i+p1][j+p2] -> x = i+p1;
                                    this -> mapa_swiata[i+p1][j+p2] -> y = j+p2;
                                    this -> mapa_swiata[i+p1][j+p2] -> sila += 3; //+3 do siły obiektu po zjedzeniu guarany

                                    this -> mapa_swiata[i][j] = 0;
                                break;

                                case 5:
                                    //obiekt zjada wilcza jagode i umiera
                                    this -> mapa_swiata[i][j] = 0;
                                    this -> mapa_swiata[i+p1][j+p2] = 0;
                                break;
                            }
                        }
                    }
                }
                else if (ruch == 2)
                {
                    //wykonujemy ruch rosliny -> rozmnazanie się
                    p1 = (rand()%3)-1; //losujemy przesuniecie w celu wykonanie ruchu (oś X)
                    p2 = (rand()%3)-1; //losujemy przesuniecie w celu wykonanie ruchu (oś Y)
                    if(this -> mapa_swiata[i+p1][j+p2] == 0) //sprawdzamy czy nic nie stoi na pozycji
                    {
                        try
                        {
                            if(this -> mapa_swiata[i][j] -> rysowanie() == 'I')
                            {
                                //proba rozmnozenia wilczej jagody
                                this -> mapa_swiata[i+p1][j+p2] = new Wilcza_jagoda(i+p1,j+p2);
                            }
                            else if(this -> mapa_swiata[i][j] -> rysowanie() == 'T')
                            {
                                //proba rozmnozenia trawy
                                this -> mapa_swiata[i+p1][j+p2] = new Trawa(i+p1,j+p2);
                            }
                            else if(this -> mapa_swiata[i][j] -> rysowanie() == 'G')
                            {
                                //proba rozmnozenia guarany
                                this -> mapa_swiata[i+p1][j+p2] = new Guarana(i+p1,j+p2);
                            }
                        }
                        catch(const std::exception& e)
                        {
                            //jeżli złapano wyjątek nie dokonuje się rozmnożenie rośliny
                        }
                    }
                }
            }
        }
    }

}

void Swiat::rysujSwiat()
{
    
    char znak; //zmienna przechowująca znak zwracany przez funkcję rysowanie()

    //koniec sekcji komentarzy
    cout<<"======================================================================================================================================="<<endl;

    for(int j=0; j<rozmiar_planszy; j++)
    {
        //górne obramowanie planszy
        cout<<" ---";
    }
    cout<<endl;
    for(int i=0; i<rozmiar_planszy; i++)
    {
        cout<<"|";
        for(int j=0; j<rozmiar_planszy; j++)
        {
            if(this -> mapa_swiata[i][j] == 0)
            {
                //jeśli nie ma obiektu w danym miejscu tablicy wypisz 0
                cout<<"  "<<" |";
            }
            else
            {
                this -> mapa_swiata[i][j] -> ruch_wykonany = false; //zerowanie wykonania ruchu w danej turze
                
                znak = this ->mapa_swiata[i][j] -> rysowanie(); // pobieramy znak opisujący dany obiekt
                cout<<" "<<znak<<" |";
            }
        }
        cout<<endl<<" ";
        for(int j=0; j<rozmiar_planszy; j++)
        {
            // dolne obramowanie planszy
            cout<<"--- ";
        }
        cout<<endl;
    }

}

void Swiat::wypisz_dane()
{
    //wypisujemy imię, nazwisko i numer indeksu autora
    cout<<"======================================================================================================================================="<<endl<<endl;
    cout<<"Imię: "<<imie<<"  Nazwisko: "<<nazwisko<<"  Numer indeksu: "<<indeks<<endl;
    cout<<endl<<"======================================================================================================================================="<<endl;
}

void Swiat::komentarz()
{
    //rozpoczęcie sekcji komentarzy
    cout<<"======================================================================================================================================="<<endl;
    cout<<endl<<"Komentator: "<<endl<<endl;
    /*
        Tutaj dodajemy sekcje komentarzy
        
        Metody komentujące wywoływane są w metodzie wykonaj_ture() w klasie świata
    */
}


int main(int argc, const char * argv[]) {
    
    Swiat S1; //Tworzenie obiektu świata

    int x,y; //zmienne przechowujące wsp. x i y nowego obiektu
    char znak = ' ';
    srand(time(NULL));

    //Poczatek generowania par obiektow w celu rozpoczecia symulacji

    //tworzymy cztery obiekty leniwca
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Leniwiec(x,y);
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Leniwiec(x,y);
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Leniwiec(x,y);
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Leniwiec(x,y);

    //tworzymy cztery obiekty owcy
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Owca(x,y);
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Owca(x,y);
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Owca(x,y);
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Owca(x,y);

    //tworzymy cztery obiekty jeza
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Jez(x,y);
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Jez(x,y);
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Jez(x,y);
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Jez(x,y);

    //tworzymy cztery obiekty wilka
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Wilk(x,y);
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Wilk(x,y);
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Wilk(x,y);
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Wilk(x,y);

    //tworzymy cztery obiekty zolwia
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Zolw(x,y);
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Zolw(x,y);
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Zolw(x,y);
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Zolw(x,y);

    //tworzymy dwa obiekty trawy
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Trawa(x,y);
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Trawa(x,y);

    //tworzymy dwa obiekty guarany
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Guarana(x,y);
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Guarana(x,y);

    //tworzymy dwa obiekty wilczej jagody
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Wilcza_jagoda(x,y);
    x = rand()%rozmiar_planszy;
    y = rand()%rozmiar_planszy;
    S1.mapa_swiata[x][y]= new Wilcza_jagoda(x,y);
    //Koniec generowania par obiektow w celu rozpoczecia symulacji

    while(znak != 'q')
    {
        //dopóki litera podana do systemu jest różna niż 'q' -> wykonuj główną pętlę programu
        S1.wykonajTure();
        S1.rysujSwiat();
        scanf("%c", &znak); //pobranie znaku aby przejsc do nastepnej tury
        
        /*
         Dla systemu Windows można użyć:
         znak = getch(); -> funkcja getch() znajduje się w bibliotece conio.h
         Na systemach MacOS i Linux nie ma takiej możliwości
         */
    }


    return 0;
}
