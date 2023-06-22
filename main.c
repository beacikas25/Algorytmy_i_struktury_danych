/*
 * Imie: Edvinas
 * Opis: Szukanie słów z hash table o tej samej sumie, tworzenie trie tree z
 * nich, i wyprowadzenie do pliku. Nazwa Pliku: 
 * Egzamin.c 
 * Data: 2023-06-22
 */

// Zadanie na egzamin

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_SIZE 1000
#define ALPHABET_SIZE 52
#define COUNT 5

typedef struct TrieNode {
  char key;
  int is_end;
  struct TrieNode *children[ALPHABET_SIZE];
} TrieNode;

const char *CHAR_MAP = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Structure to hold key-value pair
struct hash_node {
  char *key;
  int value;
  struct hash_node *next;
};

// Hash table structure
struct hash_table {
  int size;
  struct hash_node **table;
};

// Hash function to map keys to indices in the table
int hash(char *key, int tableSize);

// Function to create a new hash table
struct hash_table *create_hash_table(int size);

// Function to insert a key-value pair into the hash table
void insert(struct hash_table *table, char *key, int value);

// Function to destroy the hash table and free all memory
void destroy_hash_table(struct hash_table *table);

// Function to traverse the hash table
void traverse(struct hash_table *table);

// Create a new TrieNode with the given key value
TrieNode *create_node(char key);

// Initialize the Trie with the given keys
TrieNode *init_trie(char **keys, int num_keys);

// Clear memory
void clear(struct TrieNode *);

// Display Trie
void display_trie(TrieNode *root, int level);

// Szukamy w hash_table wszystkie kolizji o określonej sumy
char *findTraverse(struct hash_table *table, int sum);

// Output do faila
void output_trie(TrieNode *root, int level, FILE *file);

int main(void) {
  int indeks[COUNT] = {8, 3, 2, 4, 1};
  int sum = 0;
  clock_t t;

  FILE *wordsFile = fopen("words.txt", "r");
  if (wordsFile == NULL) {
    printf("Error opening words file.\n");
    return 1;
  }
  t = clock();
  printf("odczytanie slow start \n");
  struct hash_table *ht;
  ht = create_hash_table(TABLE_SIZE);

  char wordBuffer[100];
  while (fgets(wordBuffer, sizeof(wordBuffer), wordsFile)) {
    wordBuffer[strcspn(wordBuffer, "\n")] = '\0';
    insert(ht, wordBuffer, (int)strlen(wordBuffer));
  }
  fclose(wordsFile);
  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC;

  printf("odczytanie slow trwalo %f seconds \n", time_taken);

  printf("\n----\n");

  for (int i = 0; i < COUNT; i++) {
    sum += indeks[i];
  }

  // Tworzymy array z znajdzionymi kolizjami z hash_table o określonej sumie
  char **resultArray = (char **)findTraverse(ht, sum);

  // Szukamy długość tablicy
  int num_keys = 0;
  for (int i = 0; resultArray[i] != NULL; i++) {
    printf("%s\n", resultArray[i]);
    num_keys++;
  }

  TrieNode *root = init_trie(resultArray, num_keys);

  FILE *outputFile = fopen("output.txt", "w");
  if (wordsFile == NULL) {
    printf("Error opening output file.\n");
    return 1;
  }

  display_trie(root, 0);

  output_trie(root, 0, outputFile);

  destroy_hash_table(ht);

  clear(root);

  for (int i = 0; resultArray[i] != NULL; i++) {
    free(resultArray[i]);
  }

  free(resultArray);

  return 0;
}

int hash(char *key, int tableSize) {
  int hash_value = 0;
  for (int i = 0; i < strlen(key); i++) {
    hash_value += key[i];
  }
  return hash_value % tableSize;
}

struct hash_table *create_hash_table(int size) {
  struct hash_table *new_table =
      (struct hash_table *)malloc(sizeof(struct hash_table));
  new_table->size = size;
  new_table->table = (struct hash_node **)malloc((long unsigned int)size *
                                                 sizeof(struct hash_node *));
  for (int i = 0; i < size; i++) {
    new_table->table[i] = NULL;
  }
  return new_table;
}

void insert(struct hash_table *table, char *key, int value) {
  int index = hash(key, table->size);

  struct hash_node *new_node =
      (struct hash_node *)malloc(sizeof(struct hash_node));
  new_node->key = strdup(key);
  new_node->value = value;
  new_node->next = NULL;

  struct hash_node *current = table->table[index];

  while (current != NULL) {
    if (strcmp(current->key, key) == 0) {
      current->value = value;
      free(new_node->key);
      free(new_node);
      return;
    }
    current = current->next;
  }

  new_node->next = table->table[index];
  table->table[index] = new_node;
}

void destroy_hash_table(struct hash_table *table) {
  for (int i = 0; i < table->size; i++) {
    struct hash_node *current = table->table[i];
    while (current != NULL) {
      struct hash_node *temp = current;
      current = current->next;
      free(temp);
    }
  }
  free(table->table);
  free(table);
}

void traverse(struct hash_table *table) {
  for (int i = 0; i < table->size; i++) {
    struct hash_node *current = table->table[i];
    while (current != NULL) {
      printf("%s: %d\n", current->key, current->value);
      current = current->next;
    }
  }
}

char *findTraverse(struct hash_table *table, int sum) {
  char **result = NULL; // Array do trzymania słow
  int count = 0;

  for (int i = 0; i < table->size; i++) {
    struct hash_node *current = table->table[i];
    while (current != NULL) {
      if (current->value == sum) {
        result = realloc(result,
                         sizeof(char *) *
                             (count + 1)); // Alokujemy pamięć dla nowego słowa
        result[count] = strdup(current->key); // Kopiujemy słowo
        count++;
      }
      current = current->next;
    }
  }

  result = realloc(result,
                   sizeof(char *) * (count + 1)); // Alokujemy element dla NULL
  result[count] = NULL; // Ustawiamy ustatni element jako NULL

  return (char *)result;
}

// Create a new TrieNode with the given key value
TrieNode *create_node(char key) {
  TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
  node->key = key;
  node->is_end = 0;
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    node->children[i] = NULL;
  }
  return node;
}

TrieNode *init_trie(char **keys, int num_keys) {
  TrieNode *root = create_node(' ');
  for (int i = 0; i < num_keys; i++) {
    TrieNode *node = root;
    char *key = keys[i];
    for (int j = 0; key[j] != '\0'; j++) {
      char c = key[j];
      int index = c - 'a';
      if (node->children[index] == NULL) {
        node->children[index] = create_node(key[j]);
      }
      node = node->children[index];
    }
    node->is_end = 1;
  }
  return root;
}

void clear(struct TrieNode *root) {
  if (root == NULL) {
    return;
  }

  for (int i = 0; i < ALPHABET_SIZE; i++) {
    clear(root->children[i]);
  }
  free(root);
}

void display_trie(TrieNode *root, int level) {
  if (root == NULL) {
    return;
  }
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    if (root->children[i] != NULL) {
      for (int j = 0; j < level; j++) {
        printf("  ");
      }
      printf("[%c]", 'a' + i);
      if (root->children[i]->is_end == 1) {
        printf("*");
      }
      printf("\n");
      display_trie(root->children[i], level + 1);
    }
  }
}

void output_trie(TrieNode *root, int level, FILE *file) {
  if (root == NULL) {
    return;
  }
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    if (root->children[i] != NULL) {
      for (int j = 0; j < level; j++) {
        fprintf(file, "  ");
      }
      fprintf(file, "[%c]", 'a' + i);
      if (root->children[i]->is_end == 1) {
        fprintf(file, "*");
      }
      fprintf(file, "\n");
      output_trie(root->children[i], level + 1, file);
    }
  }
}
