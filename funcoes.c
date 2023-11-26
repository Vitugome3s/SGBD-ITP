#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "funcoes.h"

void menu()
{  
}


int criar_tabela()
{
    //Escolhe o nome da tabela 
    char name[30];
    printf("Escolha o nome de sua tabela:");
    scanf("%s", name);
    strcat(name, ".txt");
    int key;
    int count = 0;
    FILE *arquivo;
    // Abre o arquivo para escrita (w)
    arquivo = fopen(name, "w");
    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return 1;
    }
    else
    {
        char aux = 's';
        while (aux == 's')
        {
            count++;
            printf("Qual a chave primária?");
            scanf("%d", &key);

            // Escreve no arquivo
            fprintf(arquivo, "%d\n", key);

            printf("Deseja adicionar outra chave? s ou n?");
            scanf("%s", &aux);
        }
    }
    // Fecha o arquivo
    fclose(arquivo);
    return 0;
}
