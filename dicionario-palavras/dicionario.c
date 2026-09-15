#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LEN 50

typedef struct {
    char palavra[MAX_LEN];
    int freq;
} Item;

Item dicionario[MAX_WORDS];
int tamanho = 0;

int buscaBinaria(char *word, int inicio, int fim) {
    if (inicio > fim)
        return -1;

    int meio = (inicio + fim) / 2;
    int cmp = strcmp(word, dicionario[meio].palavra);

    if (cmp == 0)
        return meio;
    else if (cmp < 0)
        return buscaBinaria(word, inicio, meio - 1);
    else
        return buscaBinaria(word, meio + 1, fim);
}

void inserirOrdenado(char *word) {
    int i = tamanho - 1;

    while (i >= 0 && strcmp(dicionario[i].palavra, word) > 0) {
        dicionario[i + 1] = dicionario[i];
        i--;
    }

    strcpy(dicionario[i + 1].palavra, word);
    dicionario[i + 1].freq = 1;
    tamanho++;
}

int isStopWord(char *word, char stop[][MAX_LEN], int nStop) {
    for (int i = 0; i < nStop; i++) {
        if (strcmp(word, stop[i]) == 0)
            return 1;
    }

    return 0;
}

void processaPalavra(char *word, char stop[][MAX_LEN], int nStop) {
    if (strlen(word) == 0)
        return;

    if (isStopWord(word, stop, nStop))
        return;

    int pos = buscaBinaria(word, 0, tamanho - 1);

    if (pos != -1)
        dicionario[pos].freq++;
    else
        inserirOrdenado(word);
}

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Uso: ./projeto_exec stopwords.txt texto.txt\n");
        return 1;
    }

    FILE *fstop = fopen(argv[1], "r");
    FILE *ftexto = fopen(argv[2], "r");

    if (!fstop || !ftexto) {
        printf("Erro ao abrir arquivos\n");
        return 1;
    }

    char stop[100][MAX_LEN];
    int nStop = 0;

    while (fscanf(fstop, "%s", stop[nStop]) != EOF) {
        nStop++;
    }

    char linha[1000];
    char palavra[MAX_LEN];
    int idx = 0;

    while (fgets(linha, sizeof(linha), ftexto)) {

        for (int i = 0; linha[i]; i++) {

            if (isalpha(linha[i])) {
                palavra[idx++] = tolower(linha[i]);
            }
            else {
                palavra[idx] = '\0';

                processaPalavra(palavra, stop, nStop);

                idx = 0;
            }
        }
    }

    palavra[idx] = '\0';
    processaPalavra(palavra, stop, nStop);

    for (int i = 0; i < tamanho; i++) {
        printf("%s, %d\n",
               dicionario[i].palavra,
               dicionario[i].freq);
    }

    printf("\ntotal de palavras diferentes no dicionario = %d\n", tamanho);

    fclose(fstop);
    fclose(ftexto);

    return 0;
}
