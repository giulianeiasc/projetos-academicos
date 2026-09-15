# POO: Hierarquia de Veículos

Exercício de Programação Orientada a Objetos em Java, implementando herança e polimorfismo com uma classe base `Veiculo` e três subclasses especializadas.

## Estrutura das classes

**`Veiculo`** — classe base com atributos comuns:
- `fabricante`, `modelo`, `anoFabricacao`, `ligado`
- Getters e setter para os atributos
- Método `getInfo()` que retorna os dados formatados

**`Carro extends Veiculo`**
- Atributos: `numeroPortas`, `quantidadeLugares`
- Métodos: `ligaCarro()`, `desligaCarro()`

**`Caminhao extends Veiculo`**
- Atributos: `numeroEixos`, `capacidadeMaxima`, `cargaAtual`
- Métodos: `ligaCaminhao()`, `desligaCaminhao()`, `insereCarga()`, `removeCarga()` (com validação de limite de carga)

**`Moto extends Veiculo`**
- Atributos: `volumeCompartimento`, `volumeEmUso`, `cor`
- Métodos: `ligaMoto()`, `desligaMoto()`, `insereCarga()`, `removeCarga()` (com validação de limite de volume)

Todas as subclasses sobrescrevem `getInfo()` para incluir seus atributos específicos.

## Como compilar e executar

```bash
javac *.java
java Main
```

## Arquivo de teste

`Main.java` cria uma instância de cada subclasse e testa os métodos de ligar/desligar e inserir/remover carga, incluindo os casos de erro (ultrapassar capacidade máxima).
