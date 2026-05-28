//Bibliotecas
#include "Compressor.h"
#include <stdio.h>
#include "Structures.h"
#include <string.h>
#include "BytesIO.h"
#include "BinaryTree.h"

//Variaveis Globais
No *filaPrioridade = NULL;

//Funcoes
void compress(char caminho[]){
    FILE *arquivo;
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
    criarArvoreBinaria(&FILAPRIORIDADE);
    char dicionarioFinal[256][256] = {{0}};
    criarDicionario(FILAPRIORIDADE,dicionarioFinal);
    gerarArquivoCompresso(dicionarioFinal, caminho);
    deletarFilaPrioridade(&FILAPRIORIDADE);
}
