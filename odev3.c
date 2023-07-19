#include <stdio.h>
#include <stdbool.h>

// Sabit olarak tanımlanan hash tablosu boyutu
#define HASH_TABLE_SIZE 100

// Hash tablosu elemanını temsil eden düğüm yapısı
struct Node {
    int data;
    struct Node* next;
};

// Yeni bir düğüm oluşturur ve veriyi ekler
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Hash tablosu için hash fonksiyonu
int hashFunction(int key) {
    return key % HASH_TABLE_SIZE;
}

// Hash tablosuna eleman ekler
void insert(struct Node* hashTable[], int key) {
    int index = hashFunction(key);
    struct Node* newNode = newNode(key);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Dizi içinde tekrar eden elemanları bulur ve ekrana yazdırır
void findDuplicates(int arr[], int size) {
    struct Node* hashTable[HASH_TABLE_SIZE] = { NULL };

    for (int i = 0; i < size; i++) {
        int key = arr[i];
        int index = hashFunction(key);

        // Elemanın hash tablosunda olup olmadığını kontrol edelim
        struct Node* current = hashTable[index];
        while (current != NULL) {
            if (current->data == key) {
                printf("Tekrar eden eleman: %d\n", key);
                break;
            }
            current = current->next;
        }

        // Elemanı hash tablosuna ekleyelim
        insert(hashTable, key);
    }
}

int main() {
    int dizi[] = { 2, 4, 6, 8, 2, 10, 12, 6, 14, 16, 8 };
    int boyut = sizeof(dizi) / sizeof(dizi[0]);

    printf("Dizi içinde tekrar eden elemanlar:\n");
    findDuplicates(dizi, boyut);

    return 0;
}