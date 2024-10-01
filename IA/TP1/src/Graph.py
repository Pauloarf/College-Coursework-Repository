import math
from audioop import error
from collections import deque
from queue import Queue

import networkx as nx  # biblioteca de tratamento de grafos necessária para desnhar graficamente o grafo
import matplotlib.pyplot as plt  # idem
from networkx.algorithms.shortest_paths.dense import reconstruct_path
from numpy.ma.core import append

from Node import Node


# Constructor
# Number of edges
# Adjacancy matrix, adjacency list, list of edges

# Methods for adding edges

# Methods for removing edges

# Methods for searching a graph
# BFS, DFS,


class Graph:
    def __init__(self, directed=False):
        self.m_nodes = []
        self.m_directed = directed
        self.m_graph = {}  # dicionario para armazenar os nodos e arestas

    #############
    #    escrever o grafo como string
    #############
    def __str__(self):
        out = ""
        for key in self.m_graph.keys():
            out = out + "node" + str(key) + ": " + str(self.m_graph[key]) + "\n"
            return out

    ################################
    #   encontrar nodo pelo nome
    ################################

    def get_node_by_name(self, name):
        search_node = Node(name)
        for node in self.m_nodes:
            if node == search_node:
                return node
            else:
                return None

    ##############################3
    #   imprimir arestas
    ############################333333

    def imprime_aresta(self):
        listaA = ""
        lista = self.m_graph.keys()
        for nodo in lista:
            for (nodo2, custo) in self.m_graph[nodo]:
                listaA = listaA + nodo + " ->" + nodo2 + " custo:" + str(custo) + "\n"
        return listaA

    ################
    #   adicionar   aresta no grafo
    ######################

    def add_edge(self, node1, node2, weight):
        n1 = Node(node1)
        n2 = Node(node2)
        if (n1 not in self.m_nodes):
            n1_id = len(self.m_nodes)  # numeração sequencial
            n1.setId(n1_id)
            self.m_nodes.append(n1)
            self.m_graph[node1] = []

        if (n2 not in self.m_nodes):
            n2_id = len(self.m_nodes)  # numeração sequencial
            n2.setId(n2_id)
            self.m_nodes.append(n2)
            self.m_graph[node2] = []

        self.m_graph[node1].append((node2, weight))
        if(self.m_directed == False):
            self.m_graph[node2].append((node1, weight))
        #############################

    # devolver nodos
    ##########################

    def getNodes(self):
        return self.m_nodes

    #######################
    #    devolver o custo de uma aresta
    ##############3

    def get_arc_cost(self, node1, node2):
        custoT = math.inf
        a = self.m_graph[node1]  # lista de arestas para aquele nodo
        for (nodo, custo) in a:
            if nodo == node2:
                custoT = custo

        return custoT

    ##############################
    #  dado um caminho calcula o seu custo
    ###############################

    def calcula_custo(self, caminho):
        # caminho é uma lista de nodos
        teste = caminho
        custo = 0
        i = 0
        while i + 1 < len(teste):
            custo = custo + self.get_arc_cost(teste[i], teste[i + 1])
            # print(teste[i])
            i = i + 1
        return custo

    ################################################################################
    #     procura DFS -- TO DO
    ####################################################################################

    def procura_DFS_Rec(self, inicio, fim, path, visited):
        visited.add(inicio)
        path.append(inicio)

        if inicio == fim:
            return path,self.calcula_custo(path)

        for vizinho, peso in self.getNeighbours(inicio):
            if vizinho not in visited:
                resultado = self.procura_DFS_Rec(vizinho, fim, path, visited)
                if resultado:
                    return resultado

        path.pop()
        return None

    def procura_DFS_iterativa(self, inicio, fim):
        stack = [(inicio, [inicio])]
        visited = set()

        while stack:
            nodo, path = stack.pop()

            if nodo in visited:
                continue

            visited.add(nodo)

            if nodo == fim:
                return path, self.calcula_custo(path)

            for vizinho, peso in self.getNeighbours(nodo):
                if vizinho not in visited:
                    stack.append((vizinho, path + [vizinho]))
        return None

    #####################################################
    # Procura BFS  -- TO DO
    ######################################################

    def procura_BFS(self, inicio, fim):
        visited = set()
        queue = [(inicio)]
        parent = {inicio: None}

        while queue:
            vertex = queue.pop(0)
            if vertex == fim:
                returnValue = self.reconstroi_caminho(parent, inicio, fim)
                return returnValue, self.calcula_custo(returnValue)

            if vertex not in visited:
                visited.add(vertex)

                for vizinho, peso in self.getNeighbours(vertex):
                    if vizinho not in visited and vizinho not in queue:
                        queue.append(vizinho)
                        parent[vizinho] = vertex
        return None

    def reconstroi_caminho(self, pai, inicio, fim):
        path = []
        while fim is not None:
            path.append(fim)
            fim = pai[fim]
        path.reverse()  # Reverse the path to get it from start to target
        return path

    ####################
    # função  getneighbours, devolve vizinhos de um nó
    ##############################

    def getNeighbours(self, nodo):
        lista = []
        for (adjacente, peso) in self.m_graph[nodo]:
            lista.append((adjacente, peso))
        return lista

    ###########################
    # desenha grafo  modo grafico
    #########################

    def desenha(self):
        ##criar lista de vertices
        lista_v = self.m_nodes
        lista_a = []
        g = nx.Graph()
        for nodo in lista_v:
            n = nodo.getName()
            g.add_node(n)
            for (adjacente, peso) in self.m_graph[n]:
                lista = (n, adjacente)
                # lista_a.append(lista)
                g.add_edge(n, adjacente, weight=peso)

        pos = nx.spring_layout(g)
        nx.draw_networkx(g, pos, with_labels=True, font_weight='bold')
        labels = nx.get_edge_attributes(g, 'weight')
        nx.draw_networkx_edge_labels(g, pos, edge_labels=labels)

        plt.draw()
        plt.show()
