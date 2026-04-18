//Bibliotecas
#include "TBuilder.h"
#include "Structures.h"

//Variaveis globais
No *filaPrioridade = NULL;
No *arvoreBinaria = NULL;

//Funcoes
void criarArvoreBinaria(No** raiz) {
    while ((*raiz)->prox != NULL) {
        addNoPaiFilaPrioridade(&FILAPRIORIDADE,(*raiz)->frequencia+(*raiz)->prox->frequencia, (*raiz), (*raiz)->prox);
        deletarPrimeiroFilaPrioridade(&FILAPRIORIDADE);
        deletarPrimeiroFilaPrioridade(&FILAPRIORIDADE);
    }
}


