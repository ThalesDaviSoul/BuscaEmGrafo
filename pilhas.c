#include "grafos.h"
#include "filas.h"
#include "pilhas.h"
#include <stdio.h>
#include <stdlib.h>

// void listaAdd(lista ** l, vertice * info){
//     lista * new = (lista*)malloc(sizeof(lista));
//     lista * aux;
    
//     new->info = info;
//     new->prox = NULL;
    

//     if((*l) != NULL){
//         aux = (*l);
//         while(aux->prox != NULL){
//             aux = aux->prox;
//         }
//         aux->prox = new;
//     }else{
//         (*l) = new;
//     }
// }

// void listaLibera(lista ** l){
//     lista * aux = (*l);

//     while(aux != NULL){
//         aux = (*l)->prox;
//         free(*l);
//         (*l) = aux;
//     }
// }

pilha * criaPilha(){
    pilha * new = (pilha*)malloc(sizeof(pilha));
    new->prim = NULL;

    return new;
}

void push(pilha** pilha, vertice * newVertice){
    lista * new = NULL;

    if((*pilha) != NULL){
        new = (lista*)malloc(sizeof(lista));
        new->info = newVertice;
        
        if((*pilha)->prim == NULL){
            (*pilha)->prim = new;
            new->prox = NULL;
        }else{
            new->prox = (*pilha)->prim;
            (*pilha)->prim = new;
        }
    }
}


vertice * pop(pilha** pilha){
    lista * aux;
    vertice * retorno;


    if((*pilha) != NULL){
        aux = (*pilha)->prim;
        retorno = aux->info;
        (*pilha)->prim = aux->prox;
        
        free(aux);
        return retorno;
    }

    return NULL;
}

void liberarPilha(pilha** pilha){
    lista * aux;

    if((*pilha) != NULL){
        aux = (*pilha)->prim;
        
        while((*pilha)->prim != NULL){
            aux = aux->prox;
            free((*pilha)->prim);
            (*pilha)->prim = aux;
        }

        free((*pilha));
    }
}