
Pytanie testowe / 28) 'Złożoność sortowania binarnego (binary sort):': 
Odpowiedzi: 
        h) wszystko nieprawidłowe 


Pytanie testowe / 24) 'Złożoność sortowania przez wymiana (selection sort):': 
Odpowiedzi: 
        a) 
A(n)=Θ(n2)


Pytanie testowe / 18) 'Jakie z podanych operacji niemozliwe w liscie dwukierunkowej.': 
Odpowiedzi: 
        g) wszystko prawidłowe 


Pytanie testowe / 15) 'Jaka z podanych definicji jest definicja chciwego algorytmu.': 
Odpowiedzi: 
        a) Algorytm, który wybiera najlepszy wybór na każdym kroku, zamiast uwzględnienie wszystkich sekwencji kroków, które mogą prowadzić do optymalnego rozwiązania. 


Pytanie testowe / 14) 'Jaki kroki nieprzepisowe jest w metoda indukcji pętli przy udowodnieniu poprawności algorytmu?': 
Odpowiedzi: 
        a) użyć indukcji, aby pokazać resztę 
d) znajdź p, niezmiennik pętli 
e) pokazać przypadek podstawowy dla p 


Pytanie testowe / 13) 'Jaki warunek odpowiada niezmienniku pętli?': 
Odpowiedzi: 
        b) jeśli predykat jest spełniony przed wejściem w pewną (dowolną) iterację pętli to jest także spełniony po wyjściu z tej iteracji pętli 


Pytanie testowe / 12) 'Jaka z notacji asymptotycznych jest ze złożonością pod-wykładniczna?': 
Odpowiedzi: 
        g) 
A(n)=Θ(2n)


Pytanie testowe / 7) 'W jakiej postaci możliwa reprezentacji algorytmu?': 
Odpowiedzi: 
        a) pseudokod 
c) schemat blokowy 


Pytanie testowe / 3) 'Jaka z podanych definicji jest definicja złożoności czasowej algorytmu?': 
Odpowiedzi: 
        c) liczba operacji dominujących jakie wykona algorytm jako funkcja rozmiaru danych. 


Pytanie testowe / 1) 'Jaka z podanych definicji jest definicja algorytmu?': 
Odpowiedzi: 
        a) dokładny opis, przepis, np. w postaci listy kolejnych kroków, jak coś wykonać, etc. (nie tylko zadania obliczeniowe, np. przepis wykonania pewnej potrawy albo dokonania pewnej procedury prawnej, etc. 


Pytanie zlozonosc / 5) 'Mamy funkcja
T(n)=log2(3)n
. Jaka jest złożoność asymptotyczna ?': 
Odpowiedz: 
        e) 
Θ(n)


Pytanie poprawnosc / 4) 'Czy wskazany algorytm jest całkowicie poprawny?': 
Pseudokod: 
```c
findMax(array, len) {
    i = 0, max = array[0];
    
    while (i < len) {
      if (max < array[i]) {
        max = array[i];
      }
      i = i + 1;
    }
    
    return max;
}
```
Odpowiedz: 
        a) Tak 


Pytanie rekursja / 2) 'Obliczyć następne rekurencja, w której
T(1)=1
i
T(n)=3T(n/3)+n2
dla
n>=2
 jest rowny': 
Odpowiedzi: 
        a) 
Θ(n2)

