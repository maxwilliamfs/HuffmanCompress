#ifndef DESCOMPRESSOR_H
#define DESCOMPRESSOR_H
//Bibliotecas
#include <stdio.h>

//Prototipos
void descompress(char caminho[]);
void lerCabecalho(int *qLixo, int *qArvore, FILE *arquivo);
#endif