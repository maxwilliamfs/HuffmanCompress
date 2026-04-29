//Bibliotecas
#include "BytesIO.h"
#include <stdio.h>
#include <string.h>
#include "BinaryTree.h"

//Variaveis Globais
int qBits = 0;
unsigned char byte = 0;

//Funcoes
void gerarArquivoCompresso(char dicionario[256][256], char caminho[]) {
    FILE *arquivoEntrada = fopen(caminho,"r");

    char *nomeArquivo = strtok(caminho,"/"), caminhoSaida[256];
    nomeArquivo = strtok(NULL,".");
    sprintf(caminhoSaida,"Compressed/%s.huff",nomeArquivo);

    FILE *arquivoSaida = fopen(caminhoSaida,"wb");

    int buffer;
    while ((buffer = fgetc(arquivoEntrada)) != EOF) {
        for (int i = 0; i < strlen(dicionario[buffer]); i++) {
            escreverBit(arquivoSaida,dicionario[buffer][i]);
        }
    }
    if (qBits != 0) {
        int qLixo = 8 - qBits;
        for (int i = 0; i < qLixo; i++) {
            byte = byte << 1;
        }
        fwrite(&byte,sizeof(unsigned char),1,arquivoSaida);
    }
    fclose(arquivoEntrada);
    fclose(arquivoSaida);
    printf("%s","\nArquivo Compresso com sucesso!\n\n");
}
void escreverBit(FILE *arquivo, unsigned char valor) {
    byte = byte << 1;
    if (valor == '1') {
        byte = byte | 1;
    }
    qBits++;
    if (qBits == 8) {
        fwrite(&byte,sizeof(unsigned char),1,arquivo);
        byte = 0;
        qBits = 0;
    }
}