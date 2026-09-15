# Laboratório: Recursão e Busca

Atividade prática de laboratório com implementação de funções recursivas clássicas: busca em vetores e operações sobre sequências numéricas.

## Questões implementadas

**1. Busca binária recursiva**
Recebe um valor `x` e um vetor ordenado `v[i..f]`. Devolve o índice de `x` no vetor, ou `-1` caso não exista.

**2. Potência recursiva**
Calcula `a^n` para inteiros positivos. Duas versões:
- Simples: recursão direta, O(n) chamadas
- Otimizada: exponenciação rápida, O(log n) chamadas

**3. Operações recursivas sobre sequências**
- a) Busca linear de um elemento
- b) Menor elemento da sequência
- c) Soma dos elementos da sequência

## Como compilar

```bash
gcc recursao_busca.c -o recursao_busca
```

## Como executar

```bash
./recursao_busca
```

A `main` já testa todas as funções com um vetor de exemplo e imprime os resultados no terminal.
