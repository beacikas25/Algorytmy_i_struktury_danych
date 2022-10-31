// Beata Markevic. Student
// Lista jednokierunkowa niesortowana
// 2022-10-31

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


    typedef struct Item {
      float value;
      struct Item *next;
    } 
    typ;

int find(float value, typ *head); 

int locate(float value, int *head);

int retrieve(typ *item, int *head); 

void insert(typ **head, float value, int possition); 

void deleteElement(typ **head, int possition); 
                                               
int size(typ *head);  

int findMax(typ **head); 

int findMin(typ **head); 

void printList(typ *head); 

int isEmpty(typ *head); 

void next(typ **head, int cyfra);       

void previous(typ **head, float value);  

void makeNull(typ **head);      

int main(void){
      typ *head;
      head = (typ*)malloc(sizeof(typ));
      head = NULL;
  
      previous(&head, 1); 
      previous(&head, 2);
      previous(&head, 3);
      printList(head);
      int i = size(head); 
      printf("%d \n", i);
      deleteElement(&head, 0); 
      printList(head);
      next(&head, 4); 
      printList(head);
      insert(&head, 6, 2); 
      printList(head);
      int a = isEmpty(head); 

      if (a == 1){
      printf("\nlista nie jest pusta: \n");
      } 
      else {
        printf("\nlista jest pusta: \n");
      }

      int index = find(5.0, head); 

      if (index == -1)
      printf("\nliczba nie znaleziona\n");
      else
      printf("\nliczba znaleziona na pozycji: %d \n", index + 1);

      int max = findMax(&head); 
      printf("\n max: %d \n", max);

      int min = findMin(&head); 
      printf("\n min: %d \n", min);

      makeNull(&head);    

      return 0;
    }

    // Funkcii


    int find(float value, typ *head){
      typ*current = head;
      int index = 0;
    
      while (current != NULL){
        if (current->value == value){
          return index;
        }
        current = current->next;
        index++;
      }
      return -1;
    }

    void insert(typ **head, float value, int possition){
      if (possition == 0)
        previous(head, value);
      else{
        if (possition == size(*head))
          next(head, value);
        else{
          typ*current = *head;
          typ*tmp;
          int i = 0;
          while (current->next != NULL && i < possition - 1){
            current = current->next;
            i++;
          }
    
          tmp = current->next;
          current->next = (typ *)malloc(sizeof(typ));
          current->next->value = value; 
          current->next->next = tmp;
        }
      }
    }

    void deleteElement(typ **head, int possition) {
      if (possition == 0){
        typ*tmp = NULL;
        if (*head != NULL){
          tmp = (*head)->next;
          free(*head);
          *head = tmp;
        }
      } 
      else{
        typ*current = *head;
        typ*tmp;
        int i = 0;
    
        while (current->next != NULL && i < possition - 1) {
          current = current->next;
          i++;
        }
        tmp = current->next;
        current->next = tmp->next;
        free(tmp);
      }
    }

    int size(typ *head){
    int counter = 0;
    if (head == NULL)
    return counter;
    else{
      typ*current = head;
      do{
        counter++;
        current = current->next;
      } 
      while (current != NULL);
      }
    return counter; 
    }

    int findMin(typ **head){
      typ*current;
      current = *head;
      int min = current->value;
    
      while (current != NULL){
        if (current->value < min){
          min = current->value;
        }
        current = current->next;
        }
      return min;
    }

    int findMax(typ **head){
      typ*current;
      current = *head;
      int max = current->value;
    
      while (current != NULL){
        if (current->value > max){
          max = current->value;
        }
        current = current->next;
      }
      return max;
    }

    void printList(typ *head){
      printf("\n");
      if (head == NULL) {
        printf("lista pusta");
      } 
      else{
        typ*current = head;
        do{
          printf("%.f", current->value);
          printf("\n");
          current = current->next;
        } while (current != NULL);
      }
    }

    int isEmpty(typ *head){
      if (head == NULL){
        return 0;
      } 
      else{
        return 1;
      }
    }

    void next(typ **head, int cyfra){
      if (*head == NULL){
        *head = (typ*)malloc(sizeof(typ));
        (*head)->value = cyfra;
        (*head)->next = NULL;
      } 
      else{
        typ*current = *head;
        while (current->next != NULL){
          current = current->next;
        }
        current->next = (typ*)malloc(sizeof(typ));
        current->next->value = cyfra;
        current->next->next = NULL;
      }
    }

    void previous(typ **head, float value){
      typ*current;
      current = (typ*)malloc(sizeof(typ));
    
      current->value = value;
      current->next = *head;
      *head = current;
    }

    void makeNull(typ **head){
      typ*temp = NULL;
    
      while (*head!=NULL){
          temp = (*head) -> next;
          free(*head);
          *head = temp;
        }
    }
    
