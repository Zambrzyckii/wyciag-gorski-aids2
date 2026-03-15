Celem zadania jest znalezienie najkrótszej trasy przez dany teren. Teren podzielony jest na pola. Każde pole ma pewną wysokość, wyrażoną nieujemną liczbą całkowitą. Przejście na pole o wysokości A z pola o wysokości B zajmuje:
A - B + 1 minut, jeżeli A > B,
1 minutę, jeżeli A ≤ B.
Możemy przechodzić tylko na pola sąsiadujące ze sobą jednym z boków, czyli z danego pola możemy przejść na co najwyżej cztery sąsiednie. Nie możemy opuścić terenu opisanego przez mapę.

W obszarze może znajdować się pewna liczba wyciągów. Wyciąg umożliwia dotarcie z jego punktu startowego wyciągu do punktu docelowego wyciągu (jest jednokierunkowy). Skorzystanie z wyciągu zajmuje pewną liczbę minut. Dodatkowo, wyciągi kursują w określonych minutach -- jeżeli znajdujemy się w polu startowym wyciągu w minucie 8 i wiemy, że punktem docelowym wyciągu jest (12, 12), kursuje on co 5 minut i skorzystanie z niego zajmuje 3 minuty, to w punkcie (12, 12) będziemy w 13 minucie (13 = 8 + 2 + 3; 2 minuty oczekiwania plus trzy minuty jazdy).

Rozwiązanie zadania nie wymaga korzystania z liczb przekraczających zakres typu int.

Wejście
Na wejściu podane będą kolejno:

    szerokość i wysokość mapy
    pozycja startowa (kolumna i wiersz)
    pozycja docelowa (kolumna i wiersz)
    liczba wyciągów
    opis wyciągów – dla każdego wyciągu kolejno:
        pozycja startowa (kolumna i wiersz),
        pozycja docelowa (kolumna i wiersz),
        czas trwania podróży w minutach,
        minuty odjazdu – z wyciągu można skorzystać w minutach będących wielokrotnością tej wartości,
    wysokości kolejnych pól mapy.

Wszystkie wartości są nieujemne. 

Wyjście
Na wyjście należy wypisać najkrótszy czas, jaki potrzebny jest na dotarcie z punktu startowego do punktu docelowego. 
