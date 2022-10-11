//Beata Markevic. Student
//Obliczyc funkcja y = ax^2 znaczenia, 
//gdy a - stale. x - zmieniase z x0 do xn, 
//krokiem hx
//2022-10-11

#include <stdio.h>
#include <math.h>


  void main(void) {
    double a, x, xn, hx=0;
    
    printf("Podaj dodatnia zmienna a= ");
    scanf("%d", &a);
    printf("Podaj dodatnia zmienna x0= ");
    scanf("%d", &x0);
    printf ("Podaj dodatnia zmienna xn= ");
    scanf("%d", &xn);


    while(hx=0) {
     printf("Podaj dodatni krok hx= ");
      scanf("%d", &hx);
    }
   // printf("Podaj zmienna hx, ktora >0 ");
    //scanf("%d", &hx);

    while (x<=xn){
      printf("%d=%d*%d^2"\n, (a*x*x), a, x);

        x=x+hx;
      
    }
    return
  }
    
