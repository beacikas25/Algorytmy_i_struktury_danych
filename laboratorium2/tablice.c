// Beata Markevic
// Tablica
// 2022-10-25

#include <stdio.h>
#include <stdlib.h>


int find(float item, float *arr);

void insert(float item, int pos, float *arr);

//void remove_a(float pos, float *arr);

int size(float *arr);

float findMax(float *arr);

float findMin(float *arr);

void printTable(float *arr);

void main(void) {
  float arr[100] = {3.3, 4.4, 5.5, 6.6, 7.7, 8.8};

  int pozycja = find(4.4, arr);
  printf("Pozycja: %d\n", pozycja);
  float max = findMax(arr);
  printf("Maks: %f\n", max);
  float min = findMin(arr);
  printf("Min: %f\n", min);
  printTable(arr);
  
  return;
}

int find(float item, float *arr){
  for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
    if(item == arr[i]){
      return i;
    }
  }
  return -2;
}

void insert(float item, int pos, float *arr){
  arr[pos] = item;
}

//void remove(float pos, float *arr);

int size(float *arr){
  int i = (sizeof(arr)/sizeof(arr[0]));
  printf("\n%d",i);
  return i;
}

float findMax(float *arr){
  float max = arr[0];
  for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
    if(max < arr[i]){
      max = arr[i];
    }
  }
  return max;
}

float findMin(float *arr){
  float min = arr[0];
  for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
    if(min > arr[i]){
      min = arr[i];
    }
  }
  return min;
}

void printTable(float *arr){
  for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
    printf(" %.2f ", arr[i]);
  }
}
