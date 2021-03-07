#include "Organizmy.h"
#include "Swiat.h"
#include <iostream>

using namespace std;

#ifndef Zwierzeta_h
#define Zwierzeta_h
/*
 W tym module znajdują sie klasy Zwierząt. Każda z tych klas dziedziczy po klasie Zwierze.
 
 Dokładny opis metod znajduje się w pliku nagłówkowym Organizmy.h
 */

class Zolw : public Zwierze
{
public:
    int akcja();
    int kolizja(int);
    char rysowanie();
    ~Zolw(void)
    {}
    Zolw(int, int);
};

class Jez : public Zwierze
{
public:
    int akcja();
    int kolizja(int);
    char rysowanie();
    ~Jez(void)
    {}
    Jez(int, int);
};

class Wilk : public Zwierze
{
public:
    int akcja();
    int kolizja(int);
    char rysowanie();
    ~Wilk(void)
    {}
    Wilk(int, int);
};

class Owca : public Zwierze
{
public:
    int akcja();
    int kolizja(int);
    char rysowanie();
    ~Owca(void)
    {}
    Owca(int, int);
};

class Leniwiec : public Zwierze
{
public:
    bool kolejna_tura; //zmienna boolowska przechowująca info on ruchu leniwca
                      //leniwiec wykonuje ruch co dwie tury
                     //true - ruch w kolejnej turze
                    //false - brak ruchu w kolejnej turze
    int akcja();
    int kolizja(int);
    char rysowanie();
    Leniwiec(int, int);
    ~Leniwiec(void)
    {}
};
#endif
