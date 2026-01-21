#ifndef UNTITLED_LISTA_H
#define UNTITLED_LISTA_H

typedef struct nodo {

    int valor;
    struct nodo *prox;
    struct nodo *ant;

}nodo_t;

typedef struct lista {

    nodo_t *inicio;
    nodo_t *fim;
    int tamanho;

} lista_t;

nodo_t *criaNodo(int valor);
int listaVazia(lista_t *lista);
int inicializarLista(lista_t *lista);
int alocarNodoListaPrimeiro(lista_t *lista, int valor);
int alocarNodoListaUltimo(lista_t *lista, int valor);
int removerPrimeiraAparicaoValor(lista_t *lista, int valor);
int limparLista(lista_t *lista);
void imprimirLista(lista_t *lista);
void imprimirListaContrario(lista_t *lista);
void troca (nodo_t *nodo1, nodo_t *nodo2);
void ordenarLista(lista_t *lista);

#endif //UNTITLED_LISTA_H