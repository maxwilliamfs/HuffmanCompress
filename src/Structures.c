//Bibliotecas
#include "Structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funcoes
No* criarNo(unsigned char caractere, int frequencia){
    No *novo = malloc(sizeof(No));
    novo->frequencia = frequencia;
    novo->caractere = caractere;
    novo->direita = NULL;
    novo->esquerda = NULL;
    novo->prox = NULL;
    return novo;
}
void addNoFilaPrioridade(No **inicio, unsigned char carac, int freq){
    No *novo = criarNo(carac, freq);
    if(*(inicio) == NULL){
        *(inicio) = novo;
    } else {
        No *atual = *(inicio);
        while (atual->prox != NULL && atual->prox->frequencia < novo->frequencia) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }
}
void printFilaPrioridade(No *inicio){
    No *atual = inicio;
    while (atual != NULL) {
        printf("%d ", atual->frequencia);
        atual = atual->prox;
    }
    
}