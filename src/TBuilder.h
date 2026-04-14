#ifndef TBUILDER_H
#define TBUILDER_H

//Bibliotecas
#include "Structures.h"
#include <stdio.h>

//PreProcessamento
#define FILAPRIORIDADE filaPrioridade

//Variaveis globais
extern No *filaPrioridade;
extern No *arvoreBinaria;

//Prototipos
void criarArvoreBinaria(No* raiz);

#endif