# Ficha 1

## Formulação de Problemas de Pesquisa e Resolução de Problemas utilizando Pesquisa não Informada.

### i. Formule o problema como um problema de pesquisa indicando o tipo, a representação do estado, inicial(atual), estado/teste objetivo, os operadores(nome, pré-condições, efeitos) e custo da solução.

- *Tipo:* Problema de estado unico. 
- *Estado inicial:* Nodo s.
- *Estado Objetivo:* Nodo t.
- *Operadores:* Precorrer o grafo até chegar ao estado objetivo.
- *Custo:* Distâncias entre arestas.

### ii. Resolva este problema utilizando a estratégia da pesquisa em profundidade.
- *Exploração:* s->a->b->c->d->t. 
- *Caminho:* s->a->b->c->d->t.
- *Custo:* 12.

### iii. Resolva este problema utilizando a estratégia da pesquisa em largura.
- *Exploração:* s->a->e->b->f->c->g->d->t. 
- *Caminho:* s->e->f->g->t.
- *Custo:* 12.

### iv. Compare os resultados entre as alíneas ii. e iii.
- O resultado obtido com DFS não assegura uma solução ótima, diferente do BFS. No entanto o primeiro ocupa muita menos mesmória do que o segundo, sendo preferivel para procuras onde a solução se encontra em nodos muito profundos da àrvore.