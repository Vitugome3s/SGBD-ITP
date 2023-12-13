#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "funcoes_aux.h"

FILE *file;     // arquivo para escrita da tabela
DIR *directory; // pasta com todos os arquivos de tabelas

int check_tablename(char tablename[30])
{
    struct dirent *dirp;
    int count = 0;
    directory = opendir("arquivos");
    if (directory == NULL) return 1;
    else{
        while (dirp = readdir(directory)){
            if (strcmp(dirp->d_name, ".") != 0 && strcmp(dirp->d_name, "..") != 0){
                char *table_name = strtok(dirp->d_name, ".");
                if(strcmp(tablename, table_name)==0){
                    count++;
                }
            }
        }
        closedir(directory);
        if(count != 0) return 1;
        else return 0;
    } 
}

int check_linepk(char name[30], int key){
    FILE *file = fopen(name, "r");
    if (file == NULL) {
        // Tratar erro ao abrir o arquivo, se necessário
        perror("Erro ao abrir o arquivo");
        return -1; 
    }

    int pkLida;
    char linha[1000];
    
    while (fgets(linha, sizeof(linha), file) != NULL) {
        sscanf(linha, "%d", &pkLida);

        // Se a PK for igual 
        if (pkLida == key) {
            fclose(file);
            return 0;
        }
    }

    fclose(file);
    return 1;
}

void listar_dados_p(char nome[30])
{
    char caractere;
    file = fopen(nome, "r+");

    if (file == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
    }
    else
    {
        fseek(file, 21, SEEK_CUR);
        while ((caractere = fgetc(file)) != EOF)
        {
            printf("%c", caractere);
        }
    }
    fclose(file);
    printf("\n\n");
}