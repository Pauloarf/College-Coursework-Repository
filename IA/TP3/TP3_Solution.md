# Ficha 3

## Formulação de Problemas

### Exercício 1.

#### Formule o jogo, como um problema de procura, indicando: (Tipo de Problema),(Estado Inical),(Estado Final ou Condição Objetivo),(Operadores de mudança de estado),(Custo)

- *Tipo:* Problema de estado único, Determinístico. 
- *Representação:* Árvore/Grafo.
- *Estado inicial:* Aeroporto.
- *Estado Objetivo:* Lumiar.
- *Operadores:* Transições entre estados, avançar, recuar, trocar de linha.
- *Custo:* Custo do Algoritmo, Temporal.

### Exercício 2.

#### Formule o jogo como um problema de procura, indicando o tipo, a representação do estado, o estado inicial, o estado objetivo, os operadores e o custo.

- *Tipo:* Problema de estado único, Determinístico. 
- *Representação:* Árvore/Grafo.
- *Estado inicial:* Discos posicionados na torre C, ordenados.
- *Estado Objetivo:* Discos posicionados na torre A, ordenados.
- *Operadores:* Colocar disco noutra Torre, (*Pré-condições*) Só podemos colocar um disco onde não haja torres ou onde o disco existente seja maior que o que vai ser alterado.
- *Custo:* Custo da solução, cada ação soma um ao numero de movimentos.