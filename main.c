#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"
#include "pilhas.h"

#define SUCESSO (0)

int main(void){
    grafo * gr;
    lista * MenorDistancia;
    lista * aux;
    // criaGrafo(&gr, 8, grafoNaoDirecionado);
    // verticeAddAresta(&gr, 0, 1, 3);
    // verticeAddAresta(&gr, 0, 2, 2);
    // verticeAddAresta(&gr, 0, 3, 1);
    // verticeAddAresta(&gr, 1, 4, 2);
    // verticeAddAresta(&gr, 4, 5, 3);
    // verticeAddAresta(&gr, 5, 6, 1);
    // verticeAddAresta(&gr, 6, 7, 1);
    // verticeAddAresta(&gr, 2, 5, 1);
    // verticeAddAresta(&gr, 3, 6, 6);
    grafoCriaRandom(&gr, 2, 8, grafoNaoDirecionado);
    MenorDistancia = buscaLargura(&gr, 0, gr->numVertices-1);
    grafoImprime(&gr);

    aux = MenorDistancia;
    (void)printf("Menor distancia:\n");
    while(aux->prox != NULL){
        printf("%2d --> %-2d\n", aux->info->info, aux->prox->info->info);
        aux = aux->prox;
    }
    printf("Enfim: %d\n", aux->info->info);

    listaLibera(&MenorDistancia);
    liberaGrafo(&gr);
    return SUCESSO;
}