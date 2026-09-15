#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 50

void mostrarPolinomio(int p[], int grau) {
    printf("P(x) = ");

    for (int i = 0; i <= grau; i++) {
        int exp = grau - i;

        if (p[i] != 0) {

            if (i > 0 && p[i] > 0)
                printf(" + ");
            if (p[i] < 0)
                printf(" - ");

            int coef = abs(p[i]);

            if (coef != 1 || exp == 0)
                printf("%d", coef);

            if (exp > 0)
                printf("x");

            if (exp > 1)
                printf("^%d", exp);
        }
    }
    printf("\n");
}

int calcularValor(int p[], int grau, int x) {
    int resultado = 0;

    for (int i = 0; i <= grau; i++) {
        int exp = grau - i;
        resultado += p[i] * pow(x, exp);
    }

    return resultado;
}

void soma(int p[], int grauP, int q[], int grauQ, int r[], int *grauR) {

    if (grauP > grauQ)
        *grauR = grauP;
    else
        *grauR = grauQ;

    for (int i = 0; i <= *grauR; i++)
        r[i] = 0;

    for (int i = 0; i <= *grauR; i++) {

        int coefP = 0;
        int coefQ = 0;

        if (i >= *grauR - grauP)
            coefP = p[i - (*grauR - grauP)];

        if (i >= *grauR - grauQ)
            coefQ = q[i - (*grauR - grauQ)];

        r[i] = coefP + coefQ;
    }
}

void multiplicacao(int p[], int grauP, int q[], int grauQ, int r[], int *grauR) {

    *grauR = grauP + grauQ;

    for (int i = 0; i <= *grauR; i++)
        r[i] = 0;

    for (int i = 0; i <= grauP; i++) {
        for (int j = 0; j <= grauQ; j++) {

            int expP = grauP - i;
            int expQ = grauQ - j;

            int pos = *grauR - (expP + expQ);

            r[pos] += p[i] * q[j];
        }
    }
}

void lerPolinomio(int p[], int *grau) {

    printf("Digite o grau do polinomio: ");
    scanf("%d", grau);

    for (int i = 0; i <= *grau; i++) {
        printf("Coeficiente de x^%d: ", *grau - i);
        scanf("%d", &p[i]);
    }
}

int main() {

    int p[MAX], q[MAX], r[MAX];
    int grauP, grauQ, grauR;
    int op;

    do {
        printf("\n-> MENU <-\n");
        printf("1 - Calcular valor do polinomio\n");
        printf("2 - Somar polinomios\n");
        printf("3 - Multiplicar polinomios\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &op);

        switch (op) {

            case 1: {
                int x;

                lerPolinomio(p, &grauP);

                printf("Digite o valor de x: ");
                scanf("%d", &x);

                int resultado = calcularValor(p, grauP, x);

                mostrarPolinomio(p, grauP);
                printf("Resultado = %d\n", resultado);
                break;
            }

            case 2:
                printf("\n--- Polinomio P ---\n");
                lerPolinomio(p, &grauP);

                printf("\n--- Polinomio Q ---\n");
                lerPolinomio(q, &grauQ);

                soma(p, grauP, q, grauQ, r, &grauR);

                printf("\nResultado da soma:\n");
                mostrarPolinomio(r, grauR);
                break;

            case 3:
                printf("\nPolinomio P\n");
                lerPolinomio(p, &grauP);

                printf("\nPolinomio Q\n");
                lerPolinomio(q, &grauQ);

                multiplicacao(p, grauP, q, grauQ, r, &grauR);

                printf("\nResultado da multiplicacao:\n");
                mostrarPolinomio(r, grauR);
                break;

            case 0:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (op != 0);

    return 0;
}
