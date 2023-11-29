#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "funcoes.h"

FILE *file;//arquivo para escrita da tabela 
FILE *table;//arquivo com nome de todas as tabelas

void menu()
{
    int choice;

    printf("================= MENU ================= \n"
           "       Escolha a função desejada: \n"
           "1 - Criar uma tabela\n"
           "2 - Listar todas as tabelas\n"
           "3 - Criar uma linha\n"
           "4 - Listar dados de uma tabela\n"
           "5 - Pesquisar valor em uma tabela\n"
           "6 - Apagar uma tupla (registro ou linha) de uma tabela\n"
           "7 - Apagar uma tabela\n"
           "0 - Sair do menu\n");

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

int criar_tabela(){
    //Variáveis
    char name[30];
    int key;
    int count = 0;
    char aux = 's';
    char column[50];
    int *choice[20];

    //Nome da tabela
    printf("Escolha o nome de sua tabela:");
    scanf("%s", name); 

    //Abre arquivos e insere nome da tabela
    table = fopen("tabelas.txt", "a");
    fprintf(table, "%s\n", name);
    fclose(table);
    strcat(name, ".txt");
    file = fopen(name, "w");  

    //Verifica se o arquivo foi aberto com sucesso
    if (file == NULL){
        fprintf(stderr, "Erro ao abrir o file.\n");
        return 1;
    }
    else{
        //Chave primária da tabela
        printf("Qual a chave primária?");
        scanf("%d", &key);    
        fprintf(file, "%d  ", key);  //Escreve no arquivo

        while (aux == 's'){
            printf("Digite o nome da coluna:");
            choice[count] = (int *)malloc(sizeof(int));
            scanf("%29s", &column);
            fprintf(file, "| %s ", column);
            printf("Qual o tipo dos dados da coluna?\n"
                    "1 - int\n"
                    "2 - float\n"
                    "3 - char\n"
                    "4 - double\n"
                    "5 - string\n");
            scanf("%d", choice[count]);
            switch (*choice[count]){
                case 1: fprintf(file, "(int) "); break;
                case 2: fprintf(file, "(float) "); break;
                case 3: fprintf(file, "(char) "); break;
                case 4: fprintf(file, "(double) "); break;
                case 5: fprintf(file, "(string) "); break;
                default:printf("Erro! Opção não disponível\n"); break;
            }
            count++; //Conta colunas
            printf("Deseja adicionar outra coluna? s ou n?");
            scanf("%s", &aux);
        }
        for (int i = 0; i < count; i++) {
            free(choice[i]); 
        }
    }
    //Fecha o file
    fclose(file);
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
