//Bibliotecas
#include "Compressor.h"
#include <stdio.h>
#include "Structures.h"
#include <string.h>
#include "BytesIO.h"

//Variaveis Globais
No *filaPrioridade = NULL;
No *arvoreBinaria = NULL;

//Funcoes
void compress(char caminho[]){
    FILE *arquivo;
    int dicionario[256] = {0}, leitura;
    arquivo = fopen(caminho,"r");
    if (arquivo == NULL) {
        printf("%s\n\n","Erro, caminho de arquivo invalido!");
        return;
    }
    while ((leitura = fgetc(arquivo)) != EOF){
        dicionario[leitura]++;
    }
    fclose(arquivo);
    for (int i = 0; i < 256; i++) {
        if (dicionario[i] != 0) {
            addNoFilaPrioridade(&FILAPRIORIDADE,i,dicionario[i]);
        }
    }
    criarArvoreBinaria(&FILAPRIORIDADE);
    char dicionarioFinal[256][256] = {{0}};
    criarDicionario(FILAPRIORIDADE,dicionarioFinal);
    gerarArquivoCompresso(dicionarioFinal, caminho);
}
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