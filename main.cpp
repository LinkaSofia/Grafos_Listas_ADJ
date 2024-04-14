#include "Aresta.h"
#include "Grafo.h"
#include <iostream>
#include <list>
#include <vector>

int main() {
    int V, O;
    char op;
    int X, Y, N, W, Z;
    std::vector<int> vertices;

    std::cin >> V >> O;

    try {
        Grafo g(V);

        for (int i = 0; i < O; ++i) {
            std::cin >> op;

            switch (op) {
                case 'I':
                    std::cin >> X >> Y;
                    g.insere_aresta(Aresta(X, Y));
                    break;
                case 'R':
                    std::cin >> X >> Y;
                    g.remove_aresta(Aresta(X, Y));
                    break;
                case 'E':
                    std::cout << g.num_arestas() << std::endl;
                    break;
                case 'Q':
                    std::cin >> N;
                    vertices.resize(N);
                    for (int j = 0; j < N; ++j) {
                        std::cin >> vertices[j];
                    }
                    std::cout << (g.eh_clique(std::list<int>(vertices.begin(), vertices.end())) ? "SIM" : "NAO") << std::endl;
                    break;
                case 'C':
                    std::cin >> X >> Y >> W >> Z;
                    std::cout << (g.existe_caminho_restrito(X, Y, Aresta(W, Z)) ? "SIM" : "NAO") << std::endl;
                    break;
                case 'P':
                    g.imprime_graus();
                    break;
                case 'G':
                    g.imprime();
                    break;
                default:
                    std::cerr << "Operacao invalida: " << op << std::endl;
                    break;
            }
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}
