#ifndef BINARYTREE_H
#define BINARYTREE_H

//Bibliotecas
#include "stdio.h"
#include "Structures.h"

//Variaveis Globais
extern No *arvoreBinaria;

//Prototipos
     //Compressao
void criarArvoreBinaria(No **raiz);
void criarDicionario(No *raiz, char dicionario[256][256]);
void MapearArvoreBinaria(No *atual, char dicionario[256][256], char codigo[256]);
int serializarArvoreBinaria(No *raiz, FILE *arquivo);
void serializandoArvoreBinariaRecursiva(No *atual, FILE *arquivo,int *tArvoreBinaria);
     //Descompressao

#endif
