//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compressor.h"
#include "Descompressor.h"

//Prototipos
void menuPrincipal();

int main(){
    while (1) {
        menuPrincipal();
    }    
}

void menuPrincipal(){
    printf("Bem Vindo ao HuffmanCompress!!!\n");
    printf("Informe um comando valido ou help para visualizar os comandos\n");
    char entrada[100],caminhocompleto[100],*comando,*argumento;
    fgets(entrada,100,stdin);

    if(strcmp(entrada,"\n") == 0){
        printf("\nERRO: Informe um comando valido ou help para visualizar os comandos\n");

    } else {
        entrada[strcspn(entrada,"\n")] = '\0';
        comando = strtok(entrada," ");

        //Comandos
        if(strcmp(comando,"-c") == 0){
            argumento = strtok(NULL," ");
            sprintf(caminhocompleto,"Input/%s.txt",argumento);
            compress(caminhocompleto);
        } else if(strcmp(comando,"-d") == 0){
            argumento = strtok(NULL," ");
            sprintf(caminhocompleto,"Input/%s.huff",argumento);
            descompress(caminhocompleto);
        } else if(strcmp(comando,"help") == 0){
            printf("%s","\n-c nome_do_arquivo - Comprime o arquivo .txt da pasta Input em .huff para a pasta Output \n");
            printf("%s","-d nome_do_arquivo - Descomprime o arquivo .huff da pasta Input em .txt para a pasta Output\n");
            printf("%s","help - Lista os comandos validos\n");
            printf("%s","clear - Limpa o console\n");
            printf("%s", "exit - Fechar programa\n\n");
        } else if(strcmp(comando,"exit") == 0){
            exit((0));
        } else if(strcmp(comando,"clear") == 0){
            system("clear");
        } else {
            printf("\nERRO: Informe um comando valido...\n");
        }
    }
    
}