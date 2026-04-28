//Bibliotecas
#include "BinaryTree.h"
#include <stdio.h>

#include "Compressor.h"

//Variaveis Globais
No *arvoreBinaria = NULL;

//Funcoes de Compressao
void criarArvoreBinaria(No** raiz) {
    while ((*raiz)->prox != NULL) {
        addNoPaiFilaPrioridade(&FILAPRIORIDADE,(*raiz)->frequencia+(*raiz)->prox->frequencia, (*raiz), (*raiz)->prox);
        deletarPrimeiroFilaPrioridade(&FILAPRIORIDADE);
        deletarPrimeiroFilaPrioridade(&FILAPRIORIDADE);
    }
}
void criarDicionario(No *raiz, char dicionario[256][256]){
    MapearArvoreBinaria(raiz, dicionario, "");
}
void MapearArvoreBinaria(No *atual, char dicionario[256][256], char codigo[256]){
    char cod[256];
    if (atual->esquerda != NULL) {
        sprintf(cod, "%s0", codigo);
        MapearArvoreBinaria(atual->esquerda, dicionario, cod);
    }
    if (atual->direita != NULL) {
        sprintf(cod, "%s1", codigo);
        MapearArvoreBinaria(atual->direita, dicionario, cod);
    }
    if (atual->direita == NULL && atual->esquerda == NULL) {
        strcpy(dicionario[atual->caractere],codigo);
    }
}
void serializarArvoreBinaria(No *raiz) {
    
}

//Funcoes de Descompressao