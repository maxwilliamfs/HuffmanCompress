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
No* criarNoPai(int frequencia, No *esquerda, No *direita){
    No *novo = malloc(sizeof(No));
    novo->frequencia = frequencia;
    novo->caractere = '*';
    novo->direita = direita;
    novo->esquerda = esquerda;
    novo->prox = NULL;
    return novo;
}
void addNoFilaPrioridade(No **inicio, unsigned char carac, int freq){
    No *novo = criarNo(carac, freq);
    if(*(inicio) == NULL){
        *(inicio) = novo;
    } else if ((*inicio)->prox == NULL) {
        if (novo->frequencia >= (*inicio)->frequencia) {
            (*inicio)->prox = novo;
        } else {
            novo->prox = *(inicio);
            *(inicio) = novo;
        }
    } else {
        No *atual = *(inicio);
        if (atual->frequencia > novo->frequencia) {
            novo->prox = *(inicio);
            *(inicio) = novo;
            return;
        }
        while (atual->prox != NULL && atual->prox->frequencia < novo->frequencia) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }
}
void addNoPaiFilaPrioridade(No **inicio, int freq, No *esquerda, No *direita){
    No *novo = criarNoPai(freq, esquerda, direita);
    if(*(inicio) == NULL){
        *(inicio) = novo;
    } else if ((*inicio)->prox == NULL) {
        if (novo->frequencia >= (*inicio)->frequencia) {
            (*inicio)->prox = novo;
        } else {
            novo->prox = *(inicio);
            *(inicio) = novo;
        }
    } else {
        No *atual = *(inicio);
        if (atual->frequencia > novo->frequencia) {
            novo->prox = *(inicio);
            *(inicio) = novo;
            return;
        }
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
        printNoFilaPrioridade(atual);
        if (atual->esquerda != NULL) {
            printf("Esquerda: %c\n", atual->esquerda->caractere);
        }
        if (atual->direita != NULL) {
            printf("Direita: %c\n", atual->direita->caractere);
        }
        atual = atual->prox;
    }
}
void printNoFilaPrioridade(No *no) {
    printf("Caractere: %c, Frequencia: %d\n", no->caractere, no->frequencia);
}
void deletarPrimeiroFilaPrioridade(No **inicio) {
    No *deletar = *inicio;
    *inicio = (*inicio)->prox;
    free(deletar);
}