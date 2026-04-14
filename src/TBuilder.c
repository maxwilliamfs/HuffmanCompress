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
        addNoFilaPrioridade(&FILAPRIORIDADE,'*',atual->frequencia+atual->prox->frequencia);
        deletarPrimeiroFilaPrioridade(&FILAPRIORIDADE);
        deletarPrimeiroFilaPrioridade(&FILAPRIORIDADE);
    }
    printFilaPrioridade(FILAPRIORIDADE);
}


