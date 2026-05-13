//Bibliotecas
#include "Descompressor.h"
#include <stdio.h>
#include "BinaryTree.h"
#include "Compressor.h"

//Funcoes
void descompress(char caminho[]) {
    FILE *arquivo = fopen(caminho,"r");
    if (arquivo == NULL) {
        printf("%s\n\n","Erro, caminho de arquivo invalido!");
        return;
    }

    int qLixo, qTamanhoArvore;
    lerCabecalho(&qLixo,&qTamanhoArvore, arquivo);
    int atualarvore = 0;
    FILAPRIORIDADE = criarNoVazio();
    reeconstruirArvoreBinaria(qTamanhoArvore,&atualarvore,arquivo,FILAPRIORIDADE);
    printFilaPrioridade(FILAPRIORIDADE);
}
void lerCabecalho(int *qLixo, int *qArvore, FILE *arquivo) {
    unsigned char byte = fgetc(arquivo), byte2 = fgetc(arquivo);
    *qLixo = byte >> 5;
    *qArvore = (byte & 31) << 8 | byte2;
}