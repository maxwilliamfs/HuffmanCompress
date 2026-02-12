//Bibliotecas
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//Prototipos
void menuPrincipal();

int main(){
    while (1) {
        menuPrincipal();
    }    
}

void menuPrincipal(){
    printf("Informe um comando valido...\n");
    char entrada[100],caminhocompleto[100],*comando,*argumento;
    fgets(entrada,100,stdin);

    if(strcmp(entrada,"\n") == 0){
        printf("\nERRO: Informe um comando valido...\n");

    } else {
        entrada[strcspn(entrada,"\n")] = '\0';
        comando = strtok(entrada," ");

        //Comandos
        if(strcmp(comando,"-c") == 0){
            argumento = strtok(NULL," ");
            sprintf(caminhocompleto,"Archives/%s.txt",argumento);
            
        } else if(strcmp(comando,"-d") == 0){
            
        } else if(strcmp(comando,"help") == 0){
            
        } else if(strcmp(comando,"exit") == 0){
            
        }else {
            printf("\nERRO: Informe um comando valido...\n");
        }
    }
    
}