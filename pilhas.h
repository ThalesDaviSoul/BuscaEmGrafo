typedef struct pilha_s{
    lista * prim;
}pilha;

pilha * criaPilha();
void push(pilha** pilha, vertice * newVertice);
vertice * pop(pilha** pilha);
void liberarPilha(pilha** pilha);