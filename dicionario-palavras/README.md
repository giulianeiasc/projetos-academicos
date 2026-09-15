# Dicionário de Palavras com Busca Binária Recursiva

Programa em C que lê um texto e uma lista de stop words, constrói um dicionário ordenado com a frequência de cada palavra distinta (ignorando as stop words), usando busca binária recursiva e inserção ordenada em vetor.

## Requisitos atendidos

- Palavras são sequências de letras (maiúsculas ou minúsculas), incluindo palavras de 1 letra
- Case insensitive: tudo é armazenado em minúsculo
- Filtro de stop words: palavras da lista de stop words são descartadas
- Busca binária recursiva: usada para verificar se a palavra já está no dicionário
- Inserção ordenada: quando a palavra é nova, ela é inserida na posição correta do vetor (sem usar sort no final)
- Capacidade para até 1000 palavras diferentes

## Como compilar

```bash
gcc dicionario.c -o dicionario
```

## Como executar

O programa recebe dois arquivos por linha de comando: o arquivo de stop words e o arquivo de texto base.

```bash
./dicionario stopwords.txt texto.txt
```

## Arquivos de teste incluídos

- `stopwords_teste.txt`: lista de stop words de exemplo (`the`, `in`, `to`, `a`)
- `texto_teste.txt`: texto base de exemplo (piada das duas loiras na Disneyland)

Rodando com esses arquivos:

```bash
./dicionario stopwords_teste.txt texto_teste.txt
```

A saída bate com o esperado do enunciado: 18 palavras diferentes no dicionário, ordenadas alfabeticamente, com a contagem de frequência de cada uma.

## Estrutura do código

- `Item`: struct com a palavra e sua frequência
- `buscaBinaria`: busca recursiva no vetor ordenado
- `inserirOrdenado`: insere a palavra na posição correta, deslocando os elementos maiores
- `isStopWord`: verifica se a palavra está na lista de stop words
- `processaPalavra`: decide se ignora, incrementa frequência ou insere a palavra
- `main`: lê os arquivos, separa as palavras do texto (por caracteres não alfabéticos) e imprime o resultado final
