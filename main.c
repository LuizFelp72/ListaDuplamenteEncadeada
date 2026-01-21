#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//Feito por Luiz Felipe Cola Bortolanza

void options(void) {
    printf("================OPÇÕES================\n");
    printf("1-Add Valor a Lista no inicio\n");
    printf("2-Add Valor a Lista no fim\n");
    printf("3-Remover Valor da Lista (Primeira aparição do valor)\n");
    printf("4-Imprimir Lista\n");
    printf("5-Imprimir Lista ao Contrario\n");
    printf("6-Ordenar Lista\n");
    printf("7-Limpar Lista!\n");
    printf("8-Sair\n");
    printf("======================================\n");
}

int main() {

    lista_t lista;
    inicializarLista(&lista);
    int opcao;
    int flag = 1;
    while(flag) {
        options();
        scanf("%d", &opcao);
        system("clear");
        switch(opcao) {
            case 1:
                int valor;
                printf("\nDigite um valor para ser adicionado ao incio da lista: ");
                scanf("%d", &valor);
                alocarNodoListaPrimeiro(&lista, valor);
                break;
            case 2:
                int valorFim;
                printf("\nDigite um valor para ser adicionado ao fim da lista: ");
                scanf("%d", &valorFim);
                alocarNodoListaUltimo(&lista, valorFim);
                break;
            case 3:
                int remover;
                printf("\nDigite um valor para remover: ");
                scanf("%d", &remover);
                removerPrimeiraAparicaoValor(&lista, remover);
                break;
            case 4:
                imprimirLista(&lista);
                break;
            case 5:
                imprimirListaContrario(&lista);
                break;
            case 6:
                ordenarLista(&lista);
                imprimirLista(&lista);
                break;
            case 7:
                if (limparLista(&lista)) {
                    printf("\nLista vazia!\n");
                }
                break;
            case 8:
                flag = !flag; //para finalizar o programa
                printf("Fim da operação!");
                break;
            default:
                printf("Opção invalida! Digite uma opção valida!");
                break;
        }
    }
    limparLista(&lista);

    return 0;
}
