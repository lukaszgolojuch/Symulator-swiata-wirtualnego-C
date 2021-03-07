
#ifndef swiat_h
#define swiat_h

#include <string>
#include "Organizmy.h"

using namespace std;

class Swiat
{
private:
    string imie; //zmienna przechowujaca imie autora
    string nazwisko; //zmienna przechowujaca nazwisko autor
    int indeks; //zmienna przechowujaca numer indeksu autora
    void wypisz_dane(); //wypisuje imie nazwisko i numer indeksu autora na ekranie
    void komentarz(); //komentuje wydarzenia dziejące się w świecie

public:
    Organizm* mapa_swiata[20][20]; //tablica przechowujaca aktualny stan gry
    /*
     Komentujemy walkę obiektów. Wypisujemy kto został pokonany.
     
     Character podany do funkcji:
     Z - żółw
     J - jeż
     W - wilk
     O - owca
     L - leniwiec
     */
    void skomentuj_walke(char);
    
    /*
     Komentujemy powstanie nowego osobnika.
     
     Integer podany do funkcji:
     1 - żółw
     2 - jeż
     3 - wilk
     4 - owca
     5 - leniwiec
     */
    void skomentuj_rozmnozenie(int);

    void rysujSwiat(); // wypisuje tablice świata na ekranie

    Swiat(void); //konstruktor świata
    ~Swiat(void); //destruktor świata
    void wykonajTure(); //wykonuje kolejny ruch

};

#endif 
