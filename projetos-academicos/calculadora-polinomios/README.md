# Calculadora de Polinômios

Programa em C que manipula polinômios representados por vetores de coeficientes, com menu interativo no terminal.

## Funcionalidades

- **Calcular valor do polinômio**: lê um polinômio e um valor de `x`, e calcula `P(x)`
- **Somar polinômios**: soma dois polinômios de graus diferentes
- **Multiplicar polinômios**: multiplica dois polinômios e mostra o resultado
- Exibição formatada do polinômio (ex: `P(x) = 2x^3 - x^2 + 5`)

## Como compilar

```bash
gcc polinomios.c -o polinomios -lm
```

> A flag `-lm` é necessária por causa da função `pow()` da biblioteca math.h

## Como executar

```bash
./polinomios
```

## Exemplo de uso

```
-> MENU <-
1 - Calcular valor do polinomio
2 - Somar polinomios
3 - Multiplicar polinomios
0 - Sair
Opção: 1
Digite o grau do polinomio: 2
Coeficiente de x^2: 1
Coeficiente de x^1: -3
Coeficiente de x^0: 2
Digite o valor de x: 5
P(x) = x^2 - 3x + 2
Resultado = 12
```

## Estrutura do código

- `mostrarPolinomio`: exibe o polinômio formatado
- `calcularValor`: calcula P(x) para um valor de x
- `soma`: soma dois polinômios de graus diferentes
- `multiplicacao`: multiplica dois polinômios
- `lerPolinomio`: lê os coeficientes do polinômio via teclado
