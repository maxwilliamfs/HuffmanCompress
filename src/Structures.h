#ifndef STRUCTURES_H
#define STRUCTURES_H

//structs
typedef struct No {
    unsigned char caractere;
    int frequencia;
    struct No *prox;
    struct No *esquerda;
    struct No *direita;
} No;

//prototipos
No* criarNo(unsigned char caractere, int frequencia);
void addNoFilaPrioridade(No **inicio, unsigned char carac, int freq);
void printFilaPrioridade(No *inicio);
#endif