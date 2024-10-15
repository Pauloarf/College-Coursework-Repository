# Ficha 3

## Formulação de Problemas de Pesquisa e Resolução de Problemas utilizando Pesquisa Não Informada

### Considerando o enunciado, identifique o tipo de problema que está em causa

- *Tipo:* Problema de estado único, Determinístico.

### Formule o Problema como um problema de pesquisa indicando a representação do estado, inicial (atual), estado/teste objetivo, os operadores (nome, pré-condições, efeitos) e custo da solução;

- *Representação:* Dois baldes, um de 4 litros e outro de 3, ambos vazios, e um tanque com capacidade ilimitada.
- *Estado inicial:* Ambos os baldes vazios.
- *Estado Objetivo:* Um dos baldes tem exatamente 2 litros.
- *Operadores:*
  - Encher o balde1 usando o tanque.
  - Encher o balde2 usando o tanque.
  - Esvaziar o balde1 para o tanque.
  - Esvaziar o balde2 para o tanque.
  - Passar  do balde1 para o balde2.
  - Passar liquido do balde2 para o balde1.
  - (pré-condição) O balde que recebe tem de ter espaço para o liquido ou nada se altera.
  - (pré-condição) O balde que tranfere tem de ter liquido dentro.
  - *IMPORTANTE(Exemplo mais completo)* (efeito) No caso de a pré-condição ser balde1 com mais espaço livre do que o espaço preenchido no balde2 então o efeito é o balde2 ficar vasio e o balde1 com liquido mas não cheio.
- *Custo:* Nº de Movimentos.

### Resolva o problema, à mão, utilizando uma pesquisa em árvore

Representando o problema como (x,y), onde x é o numero de litros do balde1 e y o numero de litros do balde2.
Sabemos que 0<=x<=4 e 0<=y<=3.

```
(0,0)
    (0,3)
        (4,3)
            (0.3) -> Nodo entra em repetição
            (4,0) -> Nodo entra em repetição
        (3,0)
            (0,0) -> Nodo entra em repetição
            (4,0) -> Nodo entra em repetição
            (0,3) -> Nodo entra em repetição
            (3,3)
                (3,0) -> Nodo entra em repetição 
                (0,3) -> Nodo entra em repetição
                (4,2) -> SOLUÇÃO FINAL
        (0,0)- > Nodo entra em repetição
    (4,0)
        (0,0) -> Nodo entra em repetição
        (1,3)
            (0,3) -> Nodo entra em repetição
            (1,0)
                (0,0) -> Nodo entra em repetição
                (4,0) -> Nodo entra em repetição
                (0,1)
                    (0,0) -> Nodo entra em repetição
                    (1,0) -> Nodo entra em repetição
                    (0,3) -> Nodo enra em repetição
                    (4,1)
                        (0,1) -> Nodo enra em repetição
                        (4,0) -> Nodo enra em repetição
                        (2,3) -> SOLUÇÃO FINAL
                        (4,3) -> Nodo enra em repetição
                (1,3) -> Nodo entra em repetição
            (4,0) -> Nodo entra em repetição
            (4,3) -> Nodo entra em repetição
        (4,3) -> Nodo entra em repetição
```

### Resolva este problema utilizando a estratégia “primeiro em profundidade”

### Resolva este problema utilizando a estratégia “primeiro em largura”