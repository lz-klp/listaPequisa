#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int buscaBinaria(int N, int* vet, int key) {
    int e, m, d;
    e = 0;
    d = N - 1;

    while (e <= d) {
        m = (e + d) / 2;
        if (vet[m] == key)
            return m;
        if (vet[m] < key)
            e = m + 1;
        else
            d = m - 1;
    }
    return -1; // Chave não encontrada
}

int sequencial(int N, int* vet, int key) {
    for (int i = 0; i < N; i++) {
        if (key == vet[i])
            return i;
    }
    return -1; // Chave não encontrada
}

int main() {
    int vetor[10], res;
    clock_t t1, t2, t3, t4;

    // Preenchendo o vetor com valores de 1 a 10
    for (int i = 0; i < 10; i++) {
        vetor[i] = i + 1;
    }

    // Testando a busca sequencial
    t1 = clock();
    res = sequencial(10, vetor, 0); // Testando com um valor que não existe
    t2 = clock();

    // Testando a busca binária
    t3 = clock();
    res = buscaBinaria(10, vetor, 0); // Testando com um valor que não existe
    t4 = clock();

    printf("Tempo Sequencial: %lf ms\n", ((double)(t2 - t1) / CLOCKS_PER_SEC) * 1000);
    printf("Tempo Binária: %lf ms\n", ((double)(t4 - t3) / CLOCKS_PER_SEC) * 1000);

    return 0;
}
