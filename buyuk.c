#include <stdio.h>

int main() {
    int n, i;
    printf("Dizinin boyutunu girin: ");
    scanf("%d", &n);

    int dizi[n];
    printf("Dizinin elemanlarını girin:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &dizi[i]);
    }

    // Başlangıçta en büyük sayıyı dizinin ilk elemanı olarak kabul edelim
    int enBuyuk = dizi[0];

    // Diziyi tarayarak en büyük sayıyı bulalım
    for (i = 1; i < n; i++) {
        if (dizi[i] > enBuyuk) {
            enBuyuk = dizi[i];
        }
    }

    // En büyük sayıyı ekrana yazdıralım
    printf("En büyük sayı: %d\n", enBuyuk);

    return 0;
}