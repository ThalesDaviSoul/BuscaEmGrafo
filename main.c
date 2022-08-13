#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"
#include "pilhas.h"

#define SUCESSO (0)

int main(void){
    /* Variáveis */
    grafo * gr = NULL;
    int escolha = 1;
    int minV, maxV;
    tipoGrafo tp;
    retornoBusca_t * menorCaminho = NULL;
    int vOrigin, vDestiny;
    lista * aux;
    
    // Criando um grafo base
    criaGrafo(&gr, 8, grafoNaoDirecionado);
    verticeAddAresta(&gr, 0, 1, 3);
    verticeAddAresta(&gr, 0, 2, 2);
    verticeAddAresta(&gr, 0, 3, 1);
    verticeAddAresta(&gr, 1, 4, 2);
    verticeAddAresta(&gr, 4, 5, 3);
    verticeAddAresta(&gr, 5, 6, 1);
    verticeAddAresta(&gr, 6, 7, 1);
    verticeAddAresta(&gr, 2, 5, 1);
    verticeAddAresta(&gr, 3, 6, 6);
    menorCaminho = buscaLargura(&gr, 0, 7);

    do{
        (void)printf("Problema: \"Estamos Morrendo de forme\"\n");
        (void)printf("Escolha uma das acoes que deseja realizar:\n");
        (void)printf("[1] - Criar grafo\n");
        (void)printf("[2] - Imprimir grafo\n");
        (void)printf("[3] - Imprimir o custo minimo para um caminho\n");
        (void)printf("[4] - Imprimir o menor caminho entre dois pontos\n");
        (void)printf("[0] - Fechar o programa\n");
        (void)scanf("%d%*c", &escolha);
        switch(escolha){
            case 1:
                if(gr != NULL){
                    (void)printf("Ja existe um grafo.\nTem certeza que deseja criar outro?\n");
                    (void)printf("[1] - Sim\n[2] - Nao\n");
                    (void)scanf("%d%*c", &escolha);
                    if(escolha == 1){
                        liberaGrafo(&gr);
                    }else{
                        break;
                    }
                }
                (void)printf("Insira o tamanho min: ");
                (void)scanf("%d%*c", &minV);
                (void)printf("Insira o tamanho max: ");
                (void)scanf("%d%*c", &maxV);
                (void)printf("Insira o tipo do grafo:\n");
                (void)printf("[1] - Direcionando\n[2] - Nao direcionado\n");
                (void)scanf("%d%*c", &escolha);

                if(escolha == 1){
                    tp = grafoDirecionado;
                }else{
                    tp = grafoNaoDirecionado;
                }

                grafoCriaRandom(&gr, minV, maxV, tp);
                
                break;

            case 2:
                if(gr != NULL){
                    grafoImprime(&gr);
                    (void)printf("\n\nInsira qualquer coisa pra continuar...\n");
                    (void)scanf("%*c");
                }else{
                    (void)printf("Grafo nao foi criado\n");
                }
                break;

            case 3:
                if(gr != NULL){
                    (void)printf("Insira o vertice de origem: \n");
                    (void)scanf("%d%*c", &vOrigin);
                    vOrigin;
                    if(vOrigin > gr->numVertices || vOrigin < 0){
                        (void)printf("Entrada invalida\n");
                        break;
                    }
                    (void)printf("Insira o vertice de destino: \n");
                    (void)scanf("%d%*c", &vDestiny);
                    if(vDestiny > gr->numVertices || vDestiny < 0){
                        (void)printf("Entrada invalida\n");
                        break;
                    }

                    if(menorCaminho != NULL){
                        listaLibera(&menorCaminho->path);
                        free(menorCaminho);
                    }

                    menorCaminho = buscaLargura(&gr, vOrigin, vDestiny);
                    if(menorCaminho != NULL){
                        (void)printf("Custo: %d\n", menorCaminho->custo);
                    }else{
                        (void)printf("Nao ha caminho entre os dois vertices;\n");
                    }
                }
                break;

            case 4:
                if(gr != NULL){
                    (void)printf("Insira o vertice de origem: \n");
                    (void)scanf("%d%*c", &vOrigin);
                    if(vOrigin > gr->numVertices || vOrigin < 0){
                        (void)printf("Entrada invalida\n");
                        break;
                    }
                    (void)printf("Insira o vertice de destino: \n");
                    (void)scanf("%d%*c", &vDestiny);
                    if(vDestiny > gr->numVertices || vDestiny < 0){
                        (void)printf("Entrada invalida\n");
                        break;
                    }

                    if(menorCaminho != NULL){
                        listaLibera(&menorCaminho->path);
                        free(menorCaminho);
                    }

                    menorCaminho = buscaLargura(&gr, vOrigin, vDestiny);
                    if(menorCaminho->path != NULL){
                        aux = menorCaminho->path;
                        while(aux->prox != NULL){
                            (void)printf("%2d --> %-2d\n", aux->info->info, aux->prox->info->info);
                            aux = aux->prox;
                        }
                        (void)printf("Enfim: %d\n", aux->info->info);
                    }else{
                        (void)printf("Nao ha caminho entre os dois vertices;\n");
                    }
                }
                break;

            case 0:
                (void)printf("Fechando o programa...\n");
                break;
            default:
                (void)printf("Opcao invalida!\n");
                break;
        }
    }while(escolha != 0);

    if(gr != NULL){
        liberaGrafo(&gr);
    }
    if(menorCaminho != NULL){
        listaLibera(&menorCaminho->path);
        free(menorCaminho);
    }

    return SUCESSO;
}
