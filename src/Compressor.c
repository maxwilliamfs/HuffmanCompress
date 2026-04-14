//Bibliotecas
#include "Compressor.h"
#include <stdio.h>
#include <stdlib.h>
#include "Structures.h"
#include "TBuilder.h"

//Variaveis
FILE *arquivo;

//Funcoes
void compress(char caminho[]){
    int dicionario[256] = {0}, leitura;
    arquivo = fopen(caminho,"r");
    if (arquivo == NULL) {
        printf("%s\n\n","Erro, caminho de arquivo invalido!");
        return;
    }
    while ((leitura = fgetc(arquivo)) != EOF){
        dicionario[leitura]++;
    }
    fclose(arquivo);
    for (int i = 0; i < 256; i++) {
        if (dicionario[i] != 0) {
            addNoFilaPrioridade(&FILAPRIORIDADE,i,dicionario[i]);
        }
    }
    //criarArvoreBinaria(FILAPRIORIDADE);
}