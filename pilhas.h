typedef struct pilha_s{
    lista * prim;
}pilha;

void listaAdd(lista ** l, vertice * info);
void listaLibera(lista ** l);
pilha * criaPilha();
void push(pilha** pilha, vertice * newVertice);
vertice * pop(pilha** pilha);
void liberarPilha(pilha** pilha);