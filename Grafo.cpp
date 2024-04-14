#include "Grafo.h"
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <iostream>

Grafo::Grafo(int num_vertices) {
    if (num_vertices <= 0) {
        throw std::invalid_argument("Erro no construtor Grafo(int): o numero de vertices eh invalido!");
    }

    num_vertices_ = num_vertices;
    lista_adj_ = new std::list<int>[num_vertices];
}

void Grafo::insere_aresta(Aresta e) {
    valida_aresta(e);

    if (e.v1 != e.v2 && std::find(lista_adj_[e.v1].begin(), lista_adj_[e.v1].end(), e.v2) == lista_adj_[e.v1].end()) {
        lista_adj_[e.v1].push_back(e.v2);
        lista_adj_[e.v2].push_back(e.v1);
    }
}

void Grafo::remove_aresta(Aresta e) {
    valida_aresta(e);

    lista_adj_[e.v1].remove(e.v2);
    lista_adj_[e.v2].remove(e.v1);
}

int Grafo::num_arestas() {
    int count = 0;
    for (int v = 0; v < num_vertices_; ++v) {
        count += lista_adj_[v].size();
    }
    // O total de arestas é a metade da soma dos graus dos vértices
    return count / 2;
}

bool Grafo::eh_clique(const std::list<int>& vertices) {
    for (int v : vertices) {
        for (int u : vertices) {
            if (v != u && std::find(lista_adj_[v].begin(), lista_adj_[v].end(), u) == lista_adj_[v].end()) {
                return false;
            }
        }
    }
    return true;
}

bool Grafo::existe_caminho_restrito(int vertice_origem, int vertice_destino, Aresta aresta) {
    // Implementação necessária
    return false;
}

void Grafo::imprime_graus() {
    for (int v = 0; v < num_vertices_; ++v) {
        std::cout << "Grau do vertice " << v << ": " << lista_adj_[v].size() << std::endl;
    }
}

void Grafo::imprime() {
    for (int v = 0; v < num_vertices_; ++v) {
        std::cout << v << ":";
        for (int u : lista_adj_[v]) {
            std::cout << " " << u;
        }
        std::cout << std::endl;
    }
}

void Grafo::valida_vertice(int v) {
    if (v < 0 || v >= num_vertices_) {
        throw std::out_of_range("Indice de vertice invalido: " + std::to_string(v));
    }
}

void Grafo::valida_aresta(Aresta e) {
    valida_vertice(e.v1);
    valida_vertice(e.v2);
}
