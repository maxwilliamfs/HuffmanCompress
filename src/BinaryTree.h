#ifndef BINARYTREE_H
#define BINARYTREE_H

//Bibliotecas
#include "Structures.h"

//Variaveis Globais
extern No *arvoreBinaria;

//Prototipos
void criarArvoreBinaria(No **raiz);
void criarDicionario(No *raiz, char dicionario[256][256]);
void MapearArvoreBinaria(No *atual, char dicionario[256][256], char codigo[256]);

#endif
