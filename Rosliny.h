#include "Organizmy.h"
#include "Swiat.h"
#include <iostream>

using namespace std;

#ifndef Rosliny_h
#define Rosliny_h

/*
 W tym module znajdują sie klasy Roslin. Każda z tych klas dziedziczy po klasie Roslina
 
 Dokładny opis metod znajduje się w pliku nagłówkowym Organizmy.h
 */

class Trawa : public Roslina
{
public:
    int akcja();
    int kolizja(int);
    char rysowanie();
    ~Trawa(void)
    {}
    Trawa(int, int);
};

class Wilcza_jagoda : public Roslina
{
public:
    int akcja();
    int kolizja(int);
    char rysowanie();
    ~Wilcza_jagoda(void)
    {}
    Wilcza_jagoda(int, int);
};

class Guarana : public Zwierze
{
public:
    int akcja();
    int kolizja(int);
    char rysowanie();
    ~Guarana(void)
    {}
    Guarana(int, int);
};

#endif
