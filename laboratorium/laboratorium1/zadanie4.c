//Beata Markevic. Student
//Obliczyc funkcja y = ax^2 znaczenia, gdy a - stale, x jest wybierany z tablicy X(n), wyniki funckji zapisywac Y(n)
//2022-10-11

#include <stdio.h>
#include <math.h>

int main(void){
	
    int n;
    printf("Podaj dlugosc tablicy:");
    scanf("%d", &n);
    double a, x[n], y[n];
    
    printf("Podaj a:");
    scanf("%lf", &a);
    
    for(int i=0; i < n; i++)
    {
        printf("Podaj x%d:", i+1);
        scanf("%lf", &x[i]);
    }
    for(int i=0; i < n; i++)
    {
        y[i] = (a*x[i]*x[i]); //zapisuji do tablicy
        printf("y = %.lf , a = %.lf , x = %.lf \n", y[i], a, x[i]);
    }
    }
