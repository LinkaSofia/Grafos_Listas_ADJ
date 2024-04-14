#ifndef GRAFO_H
#define GRAFO_H

#include "Aresta.h"
#include <list>

class Grafo {
public:
    Grafo(int num_vertices);

    void insere_aresta(Aresta e);
    void remove_aresta(Aresta e);
    int num_arestas();
    bool eh_clique(const std::list<int>& vertices);
    bool existe_caminho_restrito(int vertice_origem, int vertice_destino, Aresta aresta);
    void imprime_graus();
    void imprime();

private:
    int num_vertices_;
    std::list<int>* lista_adj_;
    void valida_vertice(int v);
    void valida_aresta(Aresta e);
};

#endif /* GRAFO_H */
