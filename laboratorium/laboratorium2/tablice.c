// Beata Markevic
// Tablica
// 2022-10-25

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define arr_size 100 


int find(int item, int *arr);
void insert(int item, int possition, int *arr);
void remove_a(int possition, int *arr);
int size();
int findMax (int *arr);
int findMin(int *arr);
void printTable(int *arr);


int main ()
{
  int arr[arr_size];
  srand(time(NULL)); //generator liczb losowych, który działa w obecnym czasie
  for(int i=0; i<arr_size; i++){
    arr[i]=rand()%1000;
  }
  printTable(arr);//
  printf("\n");
  printf("max: %d\n", findMax(arr));
  printf("min: %d\n", findMin(arr));
  printf("size: %d\n", size());
  find(2, arr);//wykorzystana metoda find
  remove_a(1, arr);//metoda remove
  printTable(arr);//
}


int size(){
  return arr_size;
}
int findMax(int *arr){
  int max = arr[0];
      for (int i=0; i<arr_size; i++){
        if(max < arr[i]){
          max = arr[i];
        }
      }
      return max;
    }

int findMin(int *arr){
  int min = arr[0];
      for (int i=0; i<arr_size; i++){
        if(min > arr[i]){
          min = arr[i];
        }
      }
      return min;
}

void printTable(int *arr){
  printf("elementy tablicy:\n");
  printf("-------\n");
  for (int i=0; i<arr_size; i++){
    printf("element tablicy %d: %d\n", i, arr[i]);
  }  
  printf("-------\n");
}

int find(int item, int *arr){
  for(int i=0; i<arr_size; i++){
    if(item == arr[i]){
      printf("element jest w tablicy\n");
      return 1;
    }
  }
  printf("elementu nie ma w tablicy\n");
  return 0;
}

void insert(int item, int possition, int *arr){
  arr[possition] = item;
}

void remove_a(int possition, int *arr){
  int p_arr[size() - 1];
  for (int i=1; i<size(); i++) {
    if (i != possition) {
    } else {
      i++;
      p_arr[i--] = arr[i];
    }
  }
  *arr = *p_arr;
}
