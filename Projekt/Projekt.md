## Projekt do przedmiotu "Algorytmy i struktury danych"
## Tytul: Algorytm sita Eratostenesa. Algorytm wyszukiwania najdłuższego wspólnego podłańcucha. Algorytm dołączania nowego elementu do końca listy dwukierunkowej
## Data 2023.02.14
## Praca wykonala Beata Markevic
Treść:

[Algorytm sita Eratostenesa](#Algorytm-sita-Eratostenesa)

[Algorytm wyszukiwania najdłuższego wspólnego podłańcucha](#Algorytm-wyszukiwania-najdłuższego-wspólnego-podłańcucha)

[Algorytm dołączania nowego elementu do końca listy dwukierunkowej](#Algorytm-dołączania-nowego-elementu-do-końca-listy-dwukierunkowej)

###<a name ="Algorytm-sita-Eratostenesa"></a>
# Algorytm sita Eratostenesa
### Opis algorytmu sita Eratostenesa
Algorytm sita Eratostenesa jest algorytmem numerycznym służącym do wyznaczania liczb pierwszych w zakresie od 2 do n. 
Jest to jeden z najprostszych i najszybszych algorytmów do tego celu.

Algorytm działa w następujący sposób:

    1. Tworzy się tablicę o długości n+1, gdzie n jest maksymalną liczbą do przeszukania. Wszystkie wartości są inicjowane jako "prawdziwe" (czyli potencjalne liczby pierwsze).
    2. Następnie ustawia się 0 i 1 jako nieprawdziwe (ponieważ 0 i 1 nie są liczbami pierwszymi).
    3. Dla każdej liczby i od 2 do sqrt(n), sprawdza się, czy i jest prawdziwe.
    4. Jeśli i jest prawdziwe, to dla każdej liczby j od i^2 do n z krokiem i, ustawia się j jako nieprawdziwe.
    5. Na koniec wszystkie pozostałe wartości w tablicy są uznawane za liczby pierwsze.
    
    Algorytm sita Eratostenesa jest bardzo efektywny i jego złożoność czasowa wynosi O(n log log n), co oznacza, że czas 
    wykonania jest proporcjonalny do n log log n. Jest to jeden z najszybszych algorytmów do wyznaczania liczb pierwszych i 
    jest często stosowany w różnych zastosowaniach, takich jak kryptografia, teoria liczb i wiele innych.

### - Pseudokod dla algorytmu sita Eratostenesa:

```
1. Stwórz tablicę o długości n+1, gdzie n jest maksymalnym liczbą do przeszukania
2. Zainicjuj wszystkie wartości w tablicy jako "prawdziwe" (czyli liczby pierwsze)
3. Ustaw 0 i 1 jako nieprawdziwe (ponieważ 0 i 1 nie są liczbami pierwszymi)
4. Dla i od 2 do sqrt(n) do:
   a. Jeśli i jest prawdziwe:
      i. Dla j od i^2 do n z krokiem i, ustaw j jako nieprawdziwe
5. Wszystkie pozostałe wartości w tablicy to liczby pierwsze

```
## Udowodnienie, że algorytm sita Eratostenesa jest końcowy
Algorytm sita Eratostenesa jest końcowy, ponieważ w każdym kroku ostatecznie ustawia wartość elementów tablicy jako 
"fałszywe" lub "prawdziwe" i nie dokonuje żadnych zmian po zakończeniu przebiegu pętli.

## Definicja Algorytmu sita Eratostenesa
Algorytm sita Eratostenesa jest algorytmem numerycznym służącym do wyznaczania liczb pierwszych w zakresie od 2 do n. 
Polega na iteracyjnym oznaczaniu liczb nie będących liczbami pierwszymi jako "fałszywe" i pozostawianiu liczb pierwszych 
jako "prawdziwych".

## Złożoność czasowa algorytmu sita Eratostenesa:
Złożoność czasowa algorytmu sita Eratostenesa to O(n log log n), co oznacza, że czas wykonania algorytmu jest proporcjonalny 
do n log log n.

## Przykład użycia algorytmu sita Eratostenesa:
Przykład użycia algorytmu sita Eratostenesa może być w znalezieniu wszystkich liczb pierwszych w zakresie od 2 do n (gdzie n 
jest zadaną liczbą).

### - Realizacja w C dla algorytmu sita Eratostenesa:
[Algorytm  sita Eratostenesa](https://github.com/beacikas25/Algorytm_sita_Eratostenesa/blob/main/Algorytm_sita_Eratostenesa.c)

### Jake dane na wejsciu w algorytm, jakie na wyjsciu:
| Wejscie  | 100 | 
| ------- | ------- |
| Wyjscie     |   2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 771, 73, 79, 83, 89, 97   |

###<a name ="Algorytm-wyszukiwania-najdłuższego-wspólnego-podłańcucha"></a>
# Algorytm wyszukiwania najdłuższego wspólnego podłańcucha
### Opis algorytmu wyszukiwania najdłuższego wspólnego podłańcucha
Algorytm wyszukiwania najdłuższego wspólnego podłańcucha (ang. Longest Common Subsequence, LCS) jest algorytmem, który służy do znajdowania najdłuższego podciągu dwóch lub więcej sekwencji, takiego że każdy element tego podciągu występuje w każdej z sekwencji i jest w tej samej kolejności. Algorytm jest często stosowany w różnych dziedzinach, takich jak bioinformatyka, redakcja tekstów i wiele innych.

Algorytm działa w następujący sposób:

    1. Tworzy się dwuwymiarową tablicę o wymiarach (m+1) x (n+1), gdzie m i n są długościami dwóch sekwencji, które chcemy porównać.
    2. Następnie wypełnia się pierwsze wiersze i kolumny tablicy zerami, ponieważ nie ma żadnego wspólnego podciągu dla pustych sekwencji.
    3. Dla każdej pary elementów (xi, yj) z obu sekwencji, sprawdza się, czy są równe.
    4. Jeśli są równe, to wartość w tablicy w wierszu i i kolumnie j jest ustawiana jako suma wartości w poprzednim wierszu i kolumnie (i-1, j-1) plus 1.
    5. Jeśli nie są równe, to wartość w tablicy w wierszu i i kolumnie j jest ustawiana jako maksymalna wartość z poprzedniego wiersza (i-1, j) i poprzedniej kolumny (i, j-1).
    6. Na koniec wartość w ostatnim wierszu i ostatniej kolumnie jest długością najdłuższego wspólnego podciągu.

Złożoność czasowa algorytmu wyszukiwania najdłuższego wspólnego podciągu wynosi O(mn), co oznacza, że czas wykonania jest proporcjonalny do iloczynu długości obu sekwencji. 
### - Pseudokod dla wyszukiwania najdłuższego wspólnego podłańcucha:

```
procedure LCS(A, B)
    n <- length of A
    m <- length of B
    C <- 2D array of size (n+1) x (m+1)
    for i <- 0 to n
        C[i][0] <- 0
    for j <- 0 to m
        C[0][j] <- 0
    for i <- 1 to n
        for j <- 1 to m
            if A[i-1] = B[j-1]
                C[i][j] <- C[i-1][j-1] + 1
            else
                C[i][j] <- max(C[i-1][j], C[i][j-1])
    return C[n][m]
```
## Udowodnienie, że algorytm wyszukiwania najdłuższego wspólnego podłańcucha jest końcowy
Algorytm kończy się, ponieważ w każdym kroku zmienia się liczba zmiennych. W każdym kroku obliczane są wartości dla kolejnych elementów tablicy C i w momencie, gdy wszystkie wartości zostaną wypełnione, algorytm kończy się i zwraca wynik.

## Definicja Algorytmu wyszukiwania najdłuższego wspólnego podłańcucha
Algorytm wyszukiwania najdłuższego wspólnego podłańcucha jest dynamicznym programowaniem, którego celem jest znalezienie najdłuższego podciągu, który jest jednocześnie podciągiem dwóch danych sekwencji.

## Złożoność czasowa algorytmu wyszukiwania najdłuższego wspólnego podłańcucha:
Złożoność czasowa algorytmu wynosi O(mn), gdzie m i n oznaczają długości dwóch sekwencji.

## Przykład użycia algorytmu wyszukiwania najdłuższego wspólnego podłańcucha:
Algorytm wyszukiwania najdłuższego wspólnego podłańcucha może być używany do porównywania dwóch sekwencji danych, takich jak ciągi DNA, pliki tekstowe lub kody źródłowe, aby znaleźć ich wspólne elementy.

### - Realizacja w C dla algorytmu wyszukiwania najdłuższego wspólnego podłańcucha:

[Algorytm wyszukiwania najdłuższego wspólnego podłańcucha](https://github.com/beacikas25/Algorytm_wyszukiwania_najduzszego_wspolnego_podancucha/blob/main/Algorytm_wyszukiwania_najduzszego_wspolnego_podancucha.c)

## Jake dane na wejsciu w algorytm, jakie na wyjsciu:
| Wejscie  | "Beata"  "Beataeae"|
| ------- | ------- |
| Wyjscie     |   5   |

###<a name ="Algorytm-dołączania-nowego-elementu-do-końca-listy-dwukierunkowej"></a>
# Algorytm dołączania nowego elementu do końca listy dwukierunkowej
### Opis algorytmu dołączania nowego elementu do końca listy dwukierunkowej
Algorytm dodawania nowego elementu do końca listy dwukierunkowej polega na następujących krokach:

    1. Tworzenie nowego elementu listy zawierającego wartość, którą chcemy dodawać.
    2. Przeszukiwanie listy dwukierunkowej w poszukiwaniu ostatniego elementu.
    3. Ustawienie wskaźnika next ostatniego elementu na nasz nowy element.
    4. Ustawienie wskaźnika prev naszego nowego elementu na ostatni element.
### Poniższy pseudokod opisuje powyższe kroki:
```
PROCEDURA dodaj_element(wartość)
    NOWY_ELEMENT = stwórz nowy element listy dwukierunkowej z wartością
    OSTATNI_ELEMENT = przeszukaj listę dwukierunkową w poszukiwaniu ostatniego elementu
    OSTATNI_ELEMENT.next = NOWY_ELEMENT
    NOWY_ELEMENT.prev = OSTATNI_ELEMENT
KONIEC PROCEDURY
```
W powyższym pseudokodzie, procedura dodaj_element przyjmuje jako argument wartość, którą chcemy dodawać do listy dwukierunkowej. Następnie tworzony jest nowy element z tą wartością i przeszukiwana jest lista w poszukiwaniu ostatniego elementu. Wskaźnik next ostatniego elementu ustawiany jest na nasz nowy element, a wskaźnik prev naszego nowego elementu ustawiany jest na ostatni element.

## Udowodnienie, że algorytm dołączania nowego elementu do końca listy dwukierunkowej jest końcowy
Algorytm dołączania nowego elementu do końca listy dwukierunkowej jest końcowy, ponieważ jest on bardzo prosty i składa się z kilku kroków, w których każdy krok jest dokładnie określony i nie prowadzi do nieskończonej sekwencji działań.

## Definicja Algorytmu dołączania nowego elementu do końca listy dwukierunkowej
Algorytm dołączania nowego elementu do końca listy dwukierunkowej jest to proces polegający na dodaniu nowego elementu na końcu listy dwukierunkowej, w której każdy element jest połączony z dwoma innymi elementami: poprzednikiem i następnikiem.

## Złożoność czasowa algorytmu dołączania nowego elementu do końca listy dwukierunkowej:
Złożoność czasowa algorytmu dołączania nowego elementu do końca listy dwukierunkowej jest stała i wynosi O(1), ponieważ operacje dołączania elementu do listy dwukierunkowej można wykonać w stałym czasie, niezależnie od długości listy.

## Przykład użycia algorytmu dołączania nowego elementu do końca listy dwukierunkowej:
Przykład użycia algorytmu dołączania nowego elementu do końca listy dwukierunkowej można znaleźć w programach, w których wymagane jest dynamiczne przechowywanie danych, takich jak systemy zarządzania bazami danych, systemy operacyjne i aplikacje do przeglądania stron internetowych. Algorytm może być używany do dodawania nowych elementów do listy oglądanych stron lub do dodawania nowych rekordów do bazy danych.

### - Realizacja w C dla algorytmu dołączania nowego elementu do końca listy dwukierunkowej:

[Algorytm dołączania nowego elementu do końca listy dwukierunkowej](https://github.com/beacikas25/Algorytm_doaczania_nowego_elementu_do_konca_listy_dwukierunkowej/blob/main/Algorytm_dolaczania_nowego_elementu_do_konca_listy_dwukierunkowej.c)

## Jake dane na wejsciu w algorytm, jakie na wyjsciu:
| Wejscie  | 1, 2, 3, 4, 5 |
| ------------- | ------------- |
| Lista dwukierunkowa  | 1, 2, 3, 4, 5 |

# Diagram

## Wejście: 
L 	 –  	zmienna obsługująca listę

v 	 – 	wartość wprowadzana do elementu

## Wyjście:
Lista z dołączonym na początku elementem o wartości v.

## Dane pomocnicze:
p 	 –  	wskazanie elementu list

## Lista kroków:
```
K01: 	Utwórz nowy element

K02: 	p  ← adres nowego elementu 

K03: 	( p→data  ) ← v 	      //umieszczamy dane w nowym elemencie

K04: 	( p→prev  ) ← nil 	      //pierwszy element nie posiada poprzednika

K05: 	( p→next  ) ← L.head 	      //następnikiem będzie obecny pierwszy element listy

K06: 	L.head  ← p 	              //dołączamy element do początku listy

K07 	L.count  ← L.count  + 1       //zwiększamy licznik elementów o 1

K08: 	Jeśli ( p→next  ) ≠ nil,

        to ( ( p→next  )→prev  ) ← p

        inaczej L.tail  ← p

K09: 	Zakończ
```

## Zródła
[Algorytm sita Eratostenesa](https://eduinf.waw.pl/inf/alg/001_search/0011.php)

[Algorytm wyszukiwania najdłuższego wspólnego podłańcucha](https://eduinf.waw.pl/inf/alg/001_search/0057.php)

[Algorytm dołączania nowego elementu do końca listy dwukierunkowej](https://eduinf.waw.pl/inf/alg/001_search/0087.php)


