// Problem Statement: Implement a hash table using quadratic probing with formula: (hash(key) + i^2) % table_size
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define DELETED -1
#define EMPTY -2

struct HashTable {
    int table[MAX];
    int size;
};

void initHashTable(struct HashTable* ht, int size) {
    ht->size = size;
    for(int i = 0; i < size; i++) {
        ht->table[i] = EMPTY;
    }
}

int hash(int key, int size) {
    return key % size;
}

void insert(struct HashTable* ht, int key) {
    int index = hash(key, ht->size);
    int i = 1;
    while(ht->table[index] != EMPTY && ht->table[index] != DELETED) {
        index = (hash(key, ht->size) + i * i) % ht->size;
        i++;
        if(i >= ht->size) {
            printf("Hash table full\n");
            return;
        }
    }
    ht->table[index] = key;
}

int search(struct HashTable* ht, int key) {
    int index = hash(key, ht->size);
    int i = 0;
    while(ht->table[index] != EMPTY) {
        if(ht->table[index] == key) {
            return index;
        }
        i++;
        index = (hash(key, ht->size) + i * i) % ht->size;
        if(i >= ht->size) {
            break;
        }
    }
    return -1;
}

void delete(struct HashTable* ht, int key) {
    int index = search(ht, key);
    if(index != -1) {
        ht->table[index] = DELETED;
    }
}

void display(struct HashTable* ht) {
    for(int i = 0; i < ht->size; i++) {
        if(ht->table[i] == EMPTY) {
            printf("EMPTY ");
        } else if(ht->table[i] == DELETED) {
            printf("DELETED ");
        } else {
            printf("%d ", ht->table[i]);
        }
    }
    printf("\n");
}

int main() {
    struct HashTable ht;
    int size = 10;
    initHashTable(&ht, size);
    insert(&ht, 5);
    insert(&ht, 15);
    insert(&ht, 25);
    insert(&ht, 35);
    display(&ht);
    printf("Search 15: %d\n", search(&ht, 15));
    delete(&ht, 15);
    display(&ht);
    printf("Search 15: %d\n", search(&ht, 15));
    return 0;
}
