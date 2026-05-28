//Bibliotecas
#include "Descompressor.h"
#include <stdio.h>
#include <string.h>
#include "BinaryTree.h"
#include "Compressor.h"
#include "BytesIO.h"

//Funcoes
void descompress(char caminho[]) {
    FILE *arquivo = fopen(caminho,"rb");
    if (arquivo == NULL) {
        printf("%s\n\n","Erro, caminho de arquivo invalido!");
        return;
    }

    int qLixo, qTamanhoArvore;
    lerCabecalho(&qLixo,&qTamanhoArvore, arquivo);
    int atualarvore = 0;
    FILAPRIORIDADE = criarNoVazio();
    reeconstruirArvoreBinaria(qTamanhoArvore,&atualarvore,arquivo,FILAPRIORIDADE);

    char *nomearquivo = strtok(caminho,"/"), caminhosaida[256];
    nomearquivo = strtok(NULL,".");
    sprintf(caminhosaida,"Output/%s.txt",nomearquivo);

    descompressartexto(arquivo,qLixo,caminhosaida);
    fclose(arquivo);
    printf("%s","\nArquivo Descompresso com sucesso!\n\n");
}
void lerCabecalho(int *qLixo, int *qArvore, FILE *arquivo) {
    unsigned char byte = fgetc(arquivo), byte2 = fgetc(arquivo);
    *qLixo = byte >> 5;
    *qArvore = (byte & 31) << 8 | byte2;
}
void descompressartexto(FILE *arquivo, int qLixo, char caminhosaida[]) {
    FILE *arquivosaida = fopen(caminhosaida,"a");
    int bufferatual = fgetc(arquivo), bufferproximo;
    No *atual = FILAPRIORIDADE;
    int byteint[8];
    while ((bufferproximo = fgetc(arquivo)) != EOF){
        byteemint(byteint,bufferatual);
        for (int i = 0; i < 8; i++) {
            if (atual->caractere == '*') {
                int byteintatual = byteint[i];
                if (byteint[i] == 0) {
                    atual = atual->esquerda;
                } else {
                    atual = atual->direita;
                }
            } else {
                fputc(atual->caractere,arquivosaida);
                i--;
                atual = FILAPRIORIDADE;
            }
            bufferatual = bufferproximo;
        }
    }
    byteemint(byteint,bufferatual);
    for (int i = 0; i < 9-qLixo; i++) {
        if (atual->caractere == '*') {
            int byteintatual = byteint[i];
            if (byteint[i] == 0) {
                atual = atual->esquerda;
            } else {
                atual = atual->direita;
            }
        } else {
            fputc(atual->caractere,arquivosaida);
            i--;
            atual = FILAPRIORIDADE;
        }
    }
    fclose(arquivosaida);
}