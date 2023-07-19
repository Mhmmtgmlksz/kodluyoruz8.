#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Metin ağacı düğümü yapısı
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

// Yeni bir metin ağacı düğümü oluşturur
struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Metin ağacına kelimeyi ekler
void insert(struct TrieNode* root, const char* word) {
    int length = strlen(word);
    struct TrieNode* current = root;

    for (int i = 0; i < length; i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }

    current->isEndOfWord = true;
}

// Metin ağacında belirli bir metinden başlayan kelimeleri bulur ve ekrana yazdırır
void findWordsStartingWith(struct TrieNode* root, const char* prefix, char buffer[], int level) {
    if (root == NULL) {
        return;
    }

    if (root->isEndOfWord) {
        buffer[level] = '\0';
        printf("%s\n", buffer);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            buffer[level] = 'a' + i;
            findWordsStartingWith(root->children[i], prefix, buffer, level + 1);
        }
    }
}

int main() {
    // Metin listesi oluşturalım
    const char* words[] = {"apple", "application", "banana", "art", "ball", "cat"};
    int wordCount = sizeof(words) / sizeof(words[0]);

    // Metin ağacı kök düğümü oluşturalım ve metin listesini metin ağacına ekleyelim
    struct TrieNode* root = createNode();
    for (int i = 0; i < wordCount; i++) {
        insert(root, words[i]);
    }

    // Başlaması istenen metni belirleyelim
    const char* prefix = "app";

    // Metin ağacında belirli bir metinden başlayan kelimeleri bulalım ve ekrana yazdıralım
    printf("Metin listesinde '%s' ile baslayan kelimeler:\n", prefix);
    char buffer[100]; // Geçici bir tampon
    findWordsStartingWith(root, prefix, buffer, 0);

    return 0;
}