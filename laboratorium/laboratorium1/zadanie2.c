//Beata Markevic. Student
//Obliczyc funkcja y = ax^2 znaczenia, 
//gdy a - stale. x - zmieniase z x0 do xn, 
//krokiem hx
//2022-10-11

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void obl_(float, float, float, int);
int validacja(float, float, float, int);

int main() {
  int x = 0, xn = 0;
  float a = 0, hx = 0;
  do{
    printf("wprowadz liczba a=");
    scanf(" %f", &a);
    printf("wprowadz liczba x=");
    scanf(" %d", &x);
    printf("wprowadz liczba hx=");
    scanf(" %f", &hx);
    printf("wprowadz liczba nx=");
    scanf(" %d", &xn);
    }
    while (1 != validacja(x, a, hx, xn));
    obl_(x, a, hx, xn);
    return 0;
}

int validacja(float x, float a, float hx, int xn) {
  if (x <= xn) {
    printf("wrong: ");
    return 0;
  } 
  else if (a == 0) {
    printf("wrong: ");
    return 0;
  } 
  else if (hx + x > xn) {
    printf("wrong: ");
    return 0;
  } 
  else {
    printf("200OK");
    return 1;
  }
}

void obl_(float x, float a, float hx, int xn) {
  float y;
  while (x <= xn) {
    printf("x=%.1f a=%.1f ", x, a);
    y = a * pow(x, 2);
    x = x + hx;
    printf("y=%.1f\n", y);
  }
  
} 
