#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

nodo_t *criaNodo(int valor) {

    nodo_t *nodo = (nodo_t *) malloc(sizeof(nodo_t));
    nodo->valor = valor;
    nodo->prox = NULL;
    nodo->ant = NULL;
    return nodo;

}

int listaVazia(lista_t *lista) {

    return lista->inicio == NULL ? 1 : 0;

}

int inicializarLista(lista_t *lista) {

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    return 1;

}

int alocarNodoListaPrimeiro(lista_t *lista, int valor) {

    if (listaVazia(lista)) {
        lista->inicio = criaNodo(valor);
        lista->fim = lista->inicio;
        lista->tamanho++;
        return 1;
    }

    nodo_t *aux = criaNodo(valor);
    aux -> prox = lista->inicio;
    lista->inicio->ant = aux ;
    lista->inicio = aux;
    aux->valor = valor;
    lista->tamanho++;
    return 1;
}

int alocarNodoListaUltimo(lista_t *lista, int valor) {

    if (listaVazia(lista)){
        lista->inicio = criaNodo(valor);
        lista->fim = lista->inicio;
        lista->tamanho++;
        return 1;

    }

    nodo_t *aux = criaNodo(valor);
    aux -> ant = lista->fim;
    lista->fim->prox = aux;
    lista->fim = aux;
    aux->valor = valor;
    lista->tamanho++;
    return 1;

}

int removerPrimeiraAparicaoValor(lista_t *lista, int valor) {

    nodo_t *aux = lista->inicio;
    while (aux != NULL && aux->valor != valor) {
        aux = aux->prox;
    }
    if (aux == NULL) {
        printf("Valor não encontrado\n");
        return 0;
    }

    if (lista->inicio->valor == aux->valor) {
        lista->inicio = lista->inicio->prox;
        lista->tamanho--;
        free(aux);
        return 1;

    }

    if (lista->fim->valor == aux->valor) {
        lista->fim = lista->fim->ant;
        lista->tamanho--;
        free(aux);
        return 1;
    }

    aux->prox->ant = aux->ant;
    aux->ant->prox = aux->prox;
    free(aux);
    return 1;

}

int limparLista(lista_t *lista) {

    if (listaVazia(lista)) {
        return listaVazia(lista);
    }
    nodo_t *aux = lista->inicio;
    nodo_t *prox;

    while(aux != NULL){
        prox = aux->prox;
        free(aux);
        aux = prox;
    }

    lista->inicio = NULL;
    lista->fim = NULL;
    return 0;


}

void imprimirLista(lista_t *lista) {

    printf("Lista:\n");

    printf("NULL->");
    for (nodo_t *aux = lista->inicio; aux != NULL; aux = aux->prox) {
        printf("%d->", aux->valor);
    }
    printf("NULL\n");

}
void imprimirListaContrario(lista_t *lista) {

    printf("Lista ao contrario:\n");
    printf("NULL->");
    for (nodo_t *aux = lista->fim; aux != NULL; aux = aux->ant) {
        printf("%d->", aux->valor);
    }
    printf("NULL\n");

}

void troca (nodo_t *nodo1, nodo_t *nodo2) {

    int valor = nodo1->valor;
    nodo1->valor = nodo2->valor;
    nodo2->valor = valor;

}

void ordenarLista(lista_t *lista) {

    int flagTroca = 1;
    nodo_t *ultimaTroca = lista -> fim;
    nodo_t *posicao = lista -> inicio;
    while (flagTroca) {
        flagTroca = 0;
        for (nodo_t *aux = lista->inicio; aux != ultimaTroca; aux = aux->prox) {
            if (aux->valor > aux->prox->valor) {
                troca(aux, aux->prox);
                posicao = aux;
                flagTroca = 1;
            }
        }
        ultimaTroca = posicao;
    }

}