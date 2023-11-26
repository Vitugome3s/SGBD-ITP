#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "funcoes.h"

void menu()
{
    int choice;

    printf("================= MENU ================= \n"
           "Escolha qual função você quer digitando: \n"
           "1-Criar uma tabela\n"
           "2-Listar todas as tabelas\n"
           "3-Criar uma linha\n"
           "4-Listar dados de uma tabela\n"
           "5-Pesquisar valor em uma tabela\n"
           "6-Apagar uma tupla (registro ou linha) de uma tabela\n"
           "7-Apagar uma tabela\n"
           "0-Sair do menu\n");

    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        criar_tabela();
        break;
    case 2:
        listar_tabelas();
        break;
    case 3:
        criar_linha();
        break;
    case 4:
        listar_dados();
        break;
    case 5:
        pesquisar_valor();
        break;
    case 6:
        apagar_tupla();
        break;
    case 7:
        apagar_tabela();
        break;
    case 0:
        break;
    default:
        printf("Escolha inválida.\n");
        break;
    }
}

int criar_tabela()
{
    // Escolhe o nome da tabela
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

void listar_tabelas()
{
}

void criar_linha()
{
}

void listar_dados()
{
}

void pesquisar_valor()
{
}

void apagar_tupla()
{
}

void apagar_tabela()
{
}
