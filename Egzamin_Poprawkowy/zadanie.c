//Beata Markevic

#include <iostream>
#include <climits>

int main() {
    int arr[5] = {1, 2, 3, 4, 5}; // tablica testowa
    int minSum = INT_MAX, maxSum = INT_MIN; // zmienne przechowujace minimalna i maksymalna sume
    int minNum, maxNum; // zmienne przechowujace indeksy minimalnej i maksymalnej sumy

    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 5; j++) {
            if (i != j) {
                sum += arr[j];
            }
        }
        if (sum < minSum) {
            minSum = sum;
            minNum = i;
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxNum = i;
        }
    }

    std::cout << minSum << " " << maxSum << std::endl;

    return 0;
}



//1. Utwórz tablicę 5-elementową i wypełnij ją liczbami całkowitymi.
//2. Zainicjuj zmienne: minSum, maxSum, minNum, maxNum.
//3. Dla każdego elementu i w tablicy (1 <= i <= 5):
//   a. Zsumuj wartości elementów o indeksach różnych od i i zapisz sumę w zmiennej sum.
//   b. Jeśli sum jest mniejsze od minSum, przypisz wartość sum do minSum i zapamiętaj indeks i jako minNum.
//   c. Jeśli sum jest większe od maxSum, przypisz wartość sum do maxSum i zapamiętaj indeks i jako maxNum.
//4. Wypisz minSum i maxSum oddzielone spacj



//Udowodnienie: Złożoność czasowa powyższego algorytmu wynosi O(n^2), ponieważ dla każdego elementu w tablicy wykonujemy pętlę 
//sumującą wartości pozostałych elementów, co daje złożoność czasową O(n^2). Jednakże, ponieważ rozmiar tablicy jest stały (wynosi 5), 
//to złożoność czasowa tego algorytmu jest ograniczona stałą wartością, co oznacza, że algorytm działa w czasie stałym względem rozmiaru 
//tablicy. Algorytm jest poprawny, ponieważ dla każdej pary elementów w tablicy, które sumują się do minimalnej lub maksymalnej wartości, 
//przynajmniej jeden z tych elementów jest wykorzystywany w obliczeniu sumy.


