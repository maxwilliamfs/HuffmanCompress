//Bibliotecas
#include "TBuilder.h"
#include "Structures.h"

//Variaveis globais
No *filaPrioridade = NULL;
No *arvoreBinaria = NULL;

//Funcoes
void criarArvoreBinaria(No* raiz) {
    No *atual = raiz;
    while (atual->prox != NULL) {
        printFilaPrioridade(FILAPRIORIDADE);
        printf("Atual: %d\n", atual->frequencia);
        addNoFilaPrioridade(&FILAPRIORIDADE,'*',atual->frequencia+atual->prox->frequencia);
        printFilaPrioridade(FILAPRIORIDADE);
        deletarPrimeiroFilaPrioridade(&FILAPRIORIDADE);
        deletarPrimeiroFilaPrioridade(&FILAPRIORIDADE);
        printFilaPrioridade(FILAPRIORIDADE);
    }
}


