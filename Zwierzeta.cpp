//
//  Zwierzeta.cpp
//  projekt C++ JPO xcode
//
//  Created by Łukasz Gołojuch on 12/25/20.
//

#include "Zwierzeta.h"


//Znaki odpowiadajace konkretnym zwierzeta
 const char znak_zolw = 'Z'; //znak zolwia
 const char znak_jez = 'J'; //znak jeza
 const char znak_wilk = 'W'; //znak wilka
 const char znak_owca = 'O'; //znak owcy
 const char znak_leniwiec = 'L'; //znak lwa

//Początek informacji o sile i inicjatywie zwierząt
 const int leniwiec_sila = 2 ; //sila leniwca
 const int leniwiec_inicjatywa = 1 ; //inicjatywa leniwca

 const int zolw_sila = 2 ; //sila zolwia
 const int zolw_inicjatywa = 1 ; //inicjatywa zolwia

 const int jez_sila = 2 ; //sila jeza
 const int jez_inicjatywa = 3 ; //inicjatywa jeza

 const int wilk_sila = 9 ; //sila wilka
 const int wilk_inicjatywa = 5 ; //inicjatywa wilka

 const int owca_sila = 4 ; //sila owcy
 const int owca_inicjatywa = 4 ; //inicjatywa owcy
//Koniec informacji o sile i inicjatywie zwierząt


int Zwierze::kolizja(int s)
{
    if(this -> sila < s)
    {
        //sila atakujacego wieksza od sily zwierzecia atakowanego -> porażka
        return 0;
    }
    else if(this -> sila == s)
    {
        //sila atakujacego rowna sile zwierzecia atakowanego -> remis
        return 2;
    }
    else
    {
        //sila atakujacego mniejsza od sily zwierzecia atakowanego -> zwycięstwo
        return 1;
    }
}

int Zwierze::akcja()
{
    return 1;
}

Owca::Owca(int px, int py)
{
        this -> sila = owca_sila; //przypisujemy siłę ze statica
        this -> inicjatywa = owca_inicjatywa; //przypisujemy inicjatywę ze statica
        this -> x = px; //deklarujemy położenie początkowe x
        this -> y = py; //deklarujemy położenie początkowe y
        this -> symbol = znak_owca; //przypisujemy symbol obiektu ze statica
        this -> kontakt_jez = 0; //ustawiamy info o zderzeniu z jeżem na 0
}

char Owca::rysowanie()
{
    return this -> symbol;
}

int Owca::akcja()
{
   return 1;
}

int Owca::kolizja(int s)
{
    if(this -> sila < s)
    {
        return 0;
    }
    else if(this -> sila == s)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}


Wilk::Wilk(int px, int py)
{
        this -> sila = wilk_sila; //przypisujemy siłę ze statica
        this -> inicjatywa = wilk_inicjatywa; //przypisujemy inicjatywę ze statica
        this -> x = px; //deklarujemy położenie początkowe x
        this -> y = py; //deklarujemy położenie początkowe y
        this -> symbol = znak_wilk; //przypisujemy symbol obiektu ze statica
        this -> kontakt_jez = 0; //ustawiamy info o zderzeniu z jeżem na 0
}

char Wilk::rysowanie()
{
    return this -> symbol;
}

int Wilk::akcja()
{
   return 1;
}

int Wilk::kolizja(int s)
{
    if(this -> sila < s)
    {
        return 0;
    }
    else if(this -> sila == s)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

Jez::Jez(int px, int py)
{
        this -> sila = jez_sila; //przypisujemy siłę ze statica
        this -> inicjatywa = jez_inicjatywa; //przypisujemy inicjatywę ze statica
        this -> x = px; //deklarujemy położenie początkowe x
        this -> y = py; //deklarujemy położenie początkowe y
        this -> symbol = znak_jez; //przypisujemy symbol obiektu ze statica
}

int Jez::kolizja(int s)
{
   // Gdy ginie, tak mocno kaleczy
  //  swojego pogromcę, że ten nie może się ruszać przez kolejne dwie tury.
    return 3;
}

char Jez::rysowanie()
{
    return this -> symbol;
}

int Jez::akcja()
{
   return 1;
}


Zolw::Zolw(int px, int py)
{
        this -> sila = zolw_sila; //przypisujemy siłę ze statica
        this -> inicjatywa = zolw_inicjatywa; //przypisujemy inicjatywę ze statica
        this -> x = px; //deklarujemy położenie początkowe x
        this -> y = py; //deklarujemy położenie początkowe y
        this -> symbol = znak_zolw; //przypisujemy symbol obiektu ze statica
        this -> kontakt_jez = 0; //ustawiamy info o zderzeniu z jeżem na 0
}

int Zolw::akcja()
{
    // 25% szans na wykonanie ruchu
    int szansa;
    srand(time(NULL));
    szansa = (rand()%100)+1; //losujemy liczbę z zakresu 1-100
    if (szansa <= 25)
    {
        //jesli liczba z zakresu 1-25 (25% szansy) - wykonuj ruch
        return 1;
    }
    else
    {
        //gdy szansa > 25 (75% szans) - nie wykonuj ruchu
        return 0;
    }
}

int Zolw::kolizja(int s)
{
//Odpiera ataki zwierząt o sile <5.
//Napastnik musi wrócić na swoje poprzednie pole.
    if( s<5 )
    {
        //jesli sila atakujacego mniejsza niz 5 - remis
        return 2;
    }
    else
    {
        //jesli atakujacy jest silniejszy - porażka
        return 0;
    }
    
}

char Zolw::rysowanie()
{
    return this -> symbol;
}

Leniwiec::Leniwiec(int px, int py)
{
        this -> sila = leniwiec_sila; //przypisujemy siłę ze statica
        this -> inicjatywa = leniwiec_inicjatywa; //przypisujemy inicjatywę ze statica
        this -> x = px; //deklarujemy położenie początkowe x
        this -> y = py; //deklarujemy położenie początkowe y
        this -> kolejna_tura = true; //deklarujemy zmienna dotyczaca ruchu -> brak ruchu 2x pod rząd
        this -> symbol = znak_leniwiec; //przypisujemy symbol obiektu ze statica
        this -> kontakt_jez = 0; //ustawiamy info o zderzeniu z jeżem na 0

}

int Leniwiec::akcja()
{
    //przemieszcza się co 2 tury
    if (this -> kolejna_tura  == true)
    {
        return 1;
    }
    else
    {
        this -> kolejna_tura = true;
        return 0;
    }
}

char Leniwiec::rysowanie()
{
    return this -> symbol;
}

int Leniwiec::kolizja(int s)
{
    if(this -> sila < s)
    {
        return 0;
    }
    else if(this -> sila == s)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}
