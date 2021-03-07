//
//  Rosliny.cpp
//  projekt C++ JPO xcode
//
//  Created by Łukasz Gołojuch on 3/7/21.
//

#include "Rosliny.h"

//Poczatek informacji o sile roslin
 const int trawa_sila = 0 ; //sila trawy
 const int wilcza_jagoda_sila = 0 ; //sila wilczej jagody
 const int guarana_sila = 0 ; //sila guarany
//Koniec informacji o sile roslin

//Znaki odpowiadajace konkretnym roslina
 const char znak_trawy = 'T'; //znak zolwia
 const char znak_wilcza_jagoda = 'I'; //znak jeza
 const char znak_guarany = 'G'; //znak wilka

int Roslina::kolizja(int s)
{
    return 0;
}

int Roslina::akcja()
{
    return 2;
}

Trawa::Trawa(int px, int py)
{
        this -> sila = trawa_sila; //przypisujemy siłę ze statica
        this -> x = px; //deklarujemy położenie początkowe x
        this -> y = py; //deklarujemy położenie początkowe y
        this -> symbol = znak_trawy; //przypisujemy symbol obiektu ze statica
}

int Trawa::kolizja(int s)
{
    return 0;
}

char Trawa::rysowanie()
{
    return this -> symbol;
}

int Trawa::akcja()
{
   return 2;
}

Wilcza_jagoda::Wilcza_jagoda(int px, int py)
{
        this -> sila = wilcza_jagoda_sila; //przypisujemy siłę ze statica
        this -> x = px; //deklarujemy położenie początkowe x
        this -> y = py; //deklarujemy położenie początkowe y
        this -> symbol = znak_wilcza_jagoda; //przypisujemy symbol obiektu ze statica
}

int Wilcza_jagoda::kolizja(int s)
{
    return 0;
}

int Wilcza_jagoda::akcja()
{
    return 2;
}

char Wilcza_jagoda::rysowanie()
{
    return this -> symbol;
}

Guarana::Guarana(int px, int py)
{
        this -> sila = guarana_sila; //przypisujemy siłę ze statica
        this -> x = px; //deklarujemy położenie początkowe x
        this -> y = py; //deklarujemy położenie początkowe y
        this -> symbol = znak_guarany; //przypisujemy symbol obiektu ze statica
}

int Guarana::kolizja(int s)
{
    return 0;
}

char Guarana::rysowanie()
{
    return this -> symbol;
}

int Guarana::akcja()
{
   return 2;
}
