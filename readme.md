# O programie

    Nazwa Programu: „Symulator świata wirtualnego”
    Język programu: C++
    Środowisko programistyczne: XCode

    Autor programu: Łukasz Gołojuch

## Opis programu 

Program symulujący działanie wirtualnego świata.

Program posiada klasy dla 5 różnych zwierząt i 3 roślin. Każde ze zwierząt i roślin posiada określony kolor pozwalający przedstawić go na ekranie. Do identyfikacji przedstawiciela danej klasy został użyty znak w kodzie ASCII. Dodatkowo każda z klas określająca dane zwierzę lub roślinę posiada metody określające akcje, a także kolizję danego obiektu.

## Klasy zwierząt

Zwierzęta rozmnażają się jeśli po wykonaniu akcji trafią na przedstawiciela tego samego gatunku (obiekt tej samej klasy).
Każde zwierze posiada także odwołanie do klasy wspolrzedne, okreslającej dokładne położenie (x y) danego obiektu.

    Nazwa: Wilk
    Siła: 9
    Inicjatywa: 5
    Znak: w 
    Akcja: brak
    Kolizja: brak

    Nazwa: Owca
    Siła: 4
    Inicjatywa: 4
    Znak: o
    Akcja: brak
    Kolizja: brak

    Nazwa: Żółw
    Siła: 2
    Inicjatywa: 1
    Znak: z
    Akcja: 25% szans na wykonanie ruchu
    Kolizja: odpiera ataki zwierząt o sile < 5

    Nazwa: Jeż
    Siła: 2
    Inicjatywa: 3
    Znak: j 
    Akcja: brak
    Kolizja: jego pogromca nie może wykonać ruchu przez trzy kolejne tury

    Nazwa: Leniwiec
    Siła: 2
    Inicjatywa: 1
    Znak: l 
    Akcja: nie może się przemieścić dwie tury pod rząd
    Kolizja: brak

## Klasy roślin

Rośliny rozmnażają się jeśli po wykonaniu akcji trafią na puste pole (trafią na obiekt klasy ziemia) - obiekt klasy ziemia zostaje zastąpiony nowym obiektem klasy danej rośliny.
Każda roślina posiada także odwołanie do klasy wspolrzedne, okreslającej dokładne położenie (x y) danego obiektu.

    Nazwa: Trawa
    Siła: 0
    Znak: t 
    Akcja: brak
    Kolizja: brak

    Nazwa: Guarana
    Siła: 0
    Znak: g
    Akcja: brak
    Kolizja: siła zwierzęcia które zje obiekt tej klasy zwiększa się o 3

    Nazwa: Wilcze jagody
    Siła: 0
    Znak: i
    Akcja: brak
    Kolizja: zwierzę, które zje obiekt tej klasy ginie 

## Komentator

Po uruchomieniu aplikcji w oknie konsoli otrzymujemy podgląd komentarzy (logów) informujących o rozmnożeniu danego zwierzęcia, lub jego śmierci. 

Ze względu na specyfikę rozmnażania roślin i ogólnie rozumianej częstotliwości destrukcji obiektów klas roślin nie została zaimplementowana metoda komentująca zachowania roślin. (zbyt duża ilość logów w jednej turze)


## Licencja
[Open Source]
