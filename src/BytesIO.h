#ifndef BYTESIO_H
#define BYTESIO_H

//Bibliotecas
#include <stdio.h>

//Prototipos
void gerarArquivoCompresso(char dicionario[256][256], char caminho[]);
void escreverBit(FILE *arquivo, unsigned char valor);
void finalizarCabecalho(int qLixo, int qArvoreBinaria, FILE *arquivo);
#endif