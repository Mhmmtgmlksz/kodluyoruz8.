#include <stdio.h>
#include <stdlib.h>

// Bağlı listeyi temsil etmek için düğüm yapısı
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

// Bağlı listedeki eleman sayısını bulur
int elemanSayisi(struct Node* head) {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

int main() {
    // Örnek bağlı listeyi oluşturalım: 1 -> 2 -> 3 -> 4 -> 5
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    // Bağlı listedeki eleman sayısını bulalım ve ekrana yazdıralım
    int count = elemanSayisi(head);
    printf("Bağlı listedeki eleman sayısı: %d\n", count);

    return 0;
}