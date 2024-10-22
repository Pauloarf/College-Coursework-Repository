# Problema dos baldes
# dois baldes  a-> 4 litros e b -> 3 litros
# começar do estado (0,0)  e chegar a (2,0)
# estados possiveis-> tuplos com qualquer combinaçao (x,y) pertencendo  x e y {0,1,2,3,4}

# ações
# encher totalmente um balde
# esvaziar totalmente um balde
# despejar um balde no outro ate que o ultimo fique cheio
# despejar um balde no outro ate que o primeiro fique vazio


# Utilizar a classe grafo para resolver o problema
# Necessário modelar o problema como um grafo


from nodo import Node
from Graph import Grafo
from queue import Queue

class Balde():


    # start deve ser a capacidade dos dois baldes no inicio ex (0,0) "estado inicial"
    # goal deve ser o objectivo ex (2,0).  " estado final"
    # os estados são representados por "(x,y)" como string, em que x e y representam
    # as quantidades de agua nos jarros

    def __init__(self, start="(0,0)", goal="(2,0)", cap1=4, cap2=3):
        self.g=Grafo(directed=True)
        self.start=start
        self.goal=goal
        self.balde1=cap1   # capacidade do balde 1
        self.balde2=cap2   # capacidade do balde 2


    # Partindo do estado inicial, utilizando as ações possíveis como transições
    # construir o grafo
    def cria_grafo(self):
        estados = []
        estados.append(self.start)
        visitados = []
        visitados.append(self.start)

        while estados != []:
            estado=estados.pop()
            expansao=self.expande(estado)
            for e in expansao:
                self.g.add_edge(estado,e,1)
                if e not in visitados:
                    estados.append(e)
                    visitados.append(e)


    # Dado um estado, expande para outros mediante as açoes possiveis
    def expande(self,estado):
        balde1 = int(estado[1])
        balde2 = int(estado[3])
        listaNodosAdjacentes = []

        if balde1 > 0:
            listaNodosAdjacentes.append(self.esvazia1(estado))
        if balde2 > 0:
            listaNodosAdjacentes.append(self.esvazia2(estado))
        if balde1 < self.balde1:
            listaNodosAdjacentes.append(self.enche1(estado))
        if balde2 < self.balde2:
            listaNodosAdjacentes.append(self.enche2(estado))
        if balde1 > 0 and balde2 < self.balde2:
            listaNodosAdjacentes.append(self.despeja12(estado))
        if balde1 < self.balde1 and balde2 > 0:
            listaNodosAdjacentes.append(self.despeja21(estado))

        return listaNodosAdjacentes

    # Devolve o estado resultante de esvaziar o primeiro balde
    def esvazia1(self, nodo):
        return "(0,"+nodo[3]+")"

    # Devolve o estado resultante de esvaziar o segundo balde
    def esvazia2(self, nodo):
        return "("+nodo[1]+",0)"

    # Devolve o estado resultante de encher totalmente o primeiro balde da torneira
    def enche1(self, nodo):
        return "("+str(self.balde1)+","+nodo[3]+")"

    # Devolve o estado resultante de encher totalmente o segundo balde da torneira
    def enche2(self, nodo):
        return "("+nodo[1]+","+str(self.balde2)+")"


    # Devolve o estado resultante de despejar o balde 1 no balde 2
    def despeja12(self, nodo):
        quantidade1 = int(nodo[1])
        quantidade2 = int(nodo[3])
        while (quantidade1 < 0 and quantidade2 < self.balde2):
            quantidade1 -= 1
            quantidade2 += 1

        return "(" + str(quantidade1) + "," + str(quantidade2) + ")"


    # Devolve o estado resultante de despejar o balde 2 no balde 1
    def despeja21(self, nodo):
        quantidade1 = int(nodo[1])
        quantidade2 = int(nodo[3])
        while (quantidade1 < self.balde1 and quantidade2 > 0):
            quantidade2 -= 1
            quantidade1 += 1

        return "("+ str(quantidade1) +","+ str(quantidade2) +")"



    # Encontra a solução utilizando DFS (recorre à classe grafo e node implementada antes
    def solucaoDFS(self,start,goal):
        res=self.g.procura_DFS(start,goal,path=[], visited=set())
        return (res)

    # Encontra a solução utilizando BFS (recorre à classe grafo e node implementada antes
    def solucaoBFS(self,start,goal):
        return self.g.procura_BFS(start,goal)

    ##################################################################################
    # Dados dois estados e1 e e2, devolve a ação que origina a transição de e1 para e2
    ##################################################################################
    def mostraA(self,e1,e2):
        e1_x = int(str(e1)[1])
        e1_y = int(str(e1)[3])
        e2_x = int(str(e2)[1])
        e2_y = int(str(e2)[3])

        if e1_x> 0 and e2_x==0 and e1_y==e2_y:
            # Despejar balde1
            return "Despejar balde 1"
        elif e1_y> 0 and e2_y==0 and e1_x==e2_x:
            # Despejar balde2
            return "Despejar balde2"
        elif e1_y==e2_y and e1_x<e2_x:
            # Encher balde 1
            return "Encher balde 1"
        elif e1_x==e2_x and e1_y < e2_y:
            # Encher balde 2
            return "Encher balde 2"
        elif e1_x > e2_x and e2_y > e2_x:
             # Despejar balde 1 no balde 2
            return "Despejar balde 1 no balde 2"
        elif e2_x > e1_x and e1_x < e2_x:
             # Despejar balde 2 no balde 1
            return "Despejar balde 2 no balde 1"

    ########################################################
    # Imprimir sequência de ações para um caminho encontrado
    ########################################################
    def imprimeA(self,caminho):
        lista_acoes=[]

        i=0
        while i+1 < len(caminho):
            lista_acoes.append(self.mostraA(caminho[i], caminho[i+1]))
            i=i+1
        return lista_acoes
