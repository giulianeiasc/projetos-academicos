#include <stdio.h>

/* ---------------------------------------------------------
 * Questão 1: Busca binária recursiva
 * Recebe um valor x e um vetor ordenado v[i..f].
 * Devolve o índice de x no vetor, ou -1 se não existir.
 * --------------------------------------------------------- */
int busca(int x, int v[], int i, int f) {
    if (i > f) {
        return -1; // não encontrou
    }

    int m = (i + f) / 2;

    if (v[m] == x) {
        return m; // encontrou
    } else if (x < v[m]) {
        return busca(x, v, i, m - 1); // busca na esquerda
    } else {
        return busca(x, v, m + 1, f); // busca na direita
    }
}

/* ---------------------------------------------------------
 * Questão 2: Potência recursiva (a elevado a n)
 * Versão simples: O(n) chamadas
 * --------------------------------------------------------- */
int potencia(int a, int n) {
    if (n == 1) {
        return a; // caso base
    }
    return a * potencia(a, n - 1); // chamada recursiva
}

/* Versão otimizada: O(log n) chamadas, usando exponenciação rápida */
int potenciaOtimizada(int a, int n) {
    if (n == 0) return 1;

    int half = potenciaOtimizada(a, n / 2);

    if (n % 2 == 0) {
        return half * half;
    } else {
        return a * half * half;
    }
}

/* ---------------------------------------------------------
 * Questão 3a: Busca linear recursiva
 * Devolve o índice de x no vetor v[0..n-1], ou -1 se não existir.
 * --------------------------------------------------------- */
int buscaLinear(int v[], int n, int x, int i) {
    if (i >= n) {
        return -1; // não encontrou
    }

    if (v[i] == x) {
        return i; // encontrou
    }

    return buscaLinear(v, n, x, i + 1);
}

/* ---------------------------------------------------------
 * Questão 3b: Menor elemento da sequência (recursivo)
 * --------------------------------------------------------- */
int menor(int v[], int n) {
    if (n == 1) {
        return v[0]; // caso base
    }

    int menorResto = menor(v, n - 1);

    if (v[n - 1] < menorResto) {
        return v[n - 1];
    } else {
        return menorResto;
    }
}

/* ---------------------------------------------------------
 * Questão 3c: Soma dos elementos da sequência (recursivo)
 * --------------------------------------------------------- */
int soma(int v[], int n) {
    if (n == 0) {
        return 0; // caso base
    }

    return v[n - 1] + soma(v, n - 1);
}

/* ---------------------------------------------------------
 * main: testes simples de cada função
 * --------------------------------------------------------- */
int main() {
    int v[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(v) / sizeof(v[0]);

    printf("--- Questao 1: Busca binaria ---\n");
    printf("Indice de 7: %d\n", busca(7, v, 0, n - 1));
    printf("Indice de 10: %d\n", busca(10, v, 0, n - 1));

    printf("\n--- Questao 2: Potencia ---\n");
    printf("2^10 (simples) = %d\n", potencia(2, 10));
    printf("2^10 (otimizada) = %d\n", potenciaOtimizada(2, 10));

    printf("\n--- Questao 3a: Busca linear ---\n");
    printf("Indice de 9: %d\n", buscaLinear(v, n, 9, 0));
    printf("Indice de 100: %d\n", buscaLinear(v, n, 100, 0));

    printf("\n--- Questao 3b: Menor elemento ---\n");
    printf("Menor: %d\n", menor(v, n));

    printf("\n--- Questao 3c: Soma dos elementos ---\n");
    printf("Soma: %d\n", soma(v, n));

    return 0;
}
