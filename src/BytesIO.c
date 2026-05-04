//Bibliotecas
#include "BytesIO.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "BinaryTree.h"
#include "Compressor.h"

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

    //Iniciar Cabecalho
    fputc(0,arquivoSaida);
    fputc(0,arquivoSaida);
    int qArvoreBinaria = serializarArvoreBinaria(FILAPRIORIDADE,arquivoSaida);

    int buffer, qLixo;
    while ((buffer = fgetc(arquivoEntrada)) != EOF) {
        for (int i = 0; i < strlen(dicionario[buffer]); i++) {
            escreverBit(arquivoSaida,dicionario[buffer][i]);
        }
    }
    if (qBits != 0) {
        qLixo = 8 - qBits;
        for (int i = 0; i < qLixo; i++) {
            byte = byte << 1;
        }
        fwrite(&byte,sizeof(unsigned char),1,arquivoSaida);
    }
    finalizarCabecalho(qLixo,qArvoreBinaria,arquivoSaida);
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
void finalizarCabecalho(int qLixo, int qArvoreBinaria, FILE *arquivo) {
    rewind(arquivo);
    uint16_t qArvoreCerta = (uint16_t) qArvoreBinaria;
    unsigned char byte = (qLixo << 5) | (qArvoreCerta >> 8);
    unsigned char byte2 = (qArvoreCerta) & 255;
    fputc(byte,arquivo);
    fputc(byte2,arquivo);
}