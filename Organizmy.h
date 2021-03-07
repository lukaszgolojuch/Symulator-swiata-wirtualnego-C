//
//  Liczba.h
//  lab_1_zamkniete
//
//  Created by Łukasz Gołojuch on 10/24/20.
//  Copyright © 2020 Łukasz Gołojuch. All rights reserved.
//

#ifndef Organizmy_h
#define Organizmy_h

class Organizm
{
public:
    int sila; //sila organizmu
    int inicjatywa; //inicjatywa organizmu
    char symbol; //zmienna przechowująca symbol danego obiektu
    int kontakt_jez; //zmienna przechowująca info o ataku na jeża
                    //jeśli kontakt_jez > 0 -> był atak na jeża trzeba czekać określony czas aby wykonać ruch
                   //kontakt_jez <= 0 -> można wykonać ruch w przeciągu 2 kolejek brak ataku na jeża
    int x; //wsp. x obiektu
    int y; //wsp. y obiektu
    bool ruch_wykonany; //informacja o wykonaniu ruchu w danej kolejce
                        // true - obiekt wykonał ruch w danej turze
                        // false - obiekt w danej turze nie wykonał ruchu
    virtual int akcja () = 0;
    virtual int kolizja (int) = 0;   // 0 - obiekt ginie
                        // 1 - atakujacy ginie
                       // 2 - powrot na wczesniejsze pole
                      // 3 - atak na jeza nie ruszasz sie 2 kolejki
                     // s - siła atakującego
    virtual char rysowanie () = 0; //metoda czysto wirtualana. Zwraca symbol obrazujący dany obiekt
};

class Roslina : public Organizm
{
//Klasa Roslina dziedziczaca po klasie Organizm.
public:
    int akcja();
    int kolizja(int);
};

class Zwierze : public Organizm
{
//Klasa Zwierze dziedziczaca po klasie Organizm.
public:
    int akcja();
    int kolizja(int);
};

#endif /* Liczba_h */
