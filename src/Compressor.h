#ifndef COMPRESSOR_H
#define COMPRESSOR_H
//Bibliotecas
#include "Structures.h"

//PreProcessamento
#define FILAPRIORIDADE filaPrioridade

//Variaveis globais
extern No *filaPrioridade;
extern No *arvoreBinaria;

//Prototipos
void compress(char caminho[]);
void criarArvoreBinaria(No **raiz);
void criarDicionario(No *raiz, char dicionario[256][256]);
void MapearArvoreBinaria(No *atual, char dicionario[256][256], char codigo[256]);

#endif