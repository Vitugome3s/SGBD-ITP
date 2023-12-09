#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "funcoes.h"

FILE *file;     // arquivo para escrita da tabela
DIR *directory; // pasta com todos os arquivos de tabelas

void menu()
{ 
    int choice;

    printf("================= MENU ================= \n"
           "       Escolha a funcao desejada: \n"
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

void criar_tabela()
{
    // Variáveis
    char aux = 's';
    int key;
    char name[30];
    int num_column = 0;
    char column[50];
    int *choice[20];
    // Nome da tabela
    printf("Escolha o nome de sua tabela:");
    scanf("%s", &name);
    // Abre pasta e arquivo
    char drctry[20] = "arquivos/";
    strcat(name, ".txt");
    strcat(drctry, name);
    file = fopen(drctry, "w");
    // Verifica se o arquivo foi aberto com sucesso
    if (file == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
    }
    else
    {
        // Imprimir o número de colunas no cabeçalho
        num_column = 0;
        fprintf(file, "Número de colunas:%d\n",num_column);

        // Chave primária da tabela

        printf("Qual a chave primária?");
        scanf("%d", &key);
        fprintf(file, "%*d  ", 4, key); // Escreve no arquivo

        while (aux == 's')
        {
            printf("Digite o nome da coluna:");
            choice[num_column] = (int *)malloc(sizeof(int));
            scanf("%29s", &column);
            fprintf(file, "| %s ", column);
            // Tipo de dados da coluna
            printf("Qual o tipo dos dados da coluna?\n"
                   "1 - int\n"
                   "2 - float\n"
                   "3 - char\n"
                   "4 - double\n"
                   "5 - string\n");
            scanf("%d", choice[num_column]);
            switch (*choice[num_column])
            {
            case 1:
                fprintf(file, "(int) ");
                break;
            case 2:
                fprintf(file, "(float) ");
                break;
            case 3:
                fprintf(file, "(char) ");
                break;
            case 4:
                fprintf(file, "(double) ");
                break;
            case 5:
                fprintf(file, "(string) ");
                break;
            default:
                printf("Erro! Opção não disponível\n");
                break;
            }
            // Conta colunas
            num_column++;
            printf("Deseja adicionar outra coluna? s ou n?\n");
            scanf("%s", &aux);
        }
        for (int i = 0; i < num_column; i++)
        {
            free(choice[i]);
        }
    }
    //Atualizar o cabeçalho
    fseek(file, 0, SEEK_SET);
    fprintf(file, "Número de colunas:%d", num_column);
    // Fecha o file
    fclose(file);
    printf("\n");
    menu();
}

void listar_tabelas()
{
    struct dirent *dirp;
    directory = opendir("arquivos");
    if (directory == NULL)
    {
        printf("\nNão há nenhuma tabela registrada.\n");
    }
    else
    {
        printf("\nTabelas registradas:\n");
        while (dirp = readdir(directory))
        {
            if (strcmp(dirp->d_name, ".") != 0 && strcmp(dirp->d_name, "..") != 0)
            {
                char *table_name = strtok(dirp->d_name, ".");
                printf("%s\n", table_name);
            }
        }
    }
    closedir(directory);
    printf("\n");
    menu();
}

void criar_linha()
{   
    int key;
    int num_column;
    char table_line[30];
    char aux = 's';
        
    printf("Em qual tabela deseja criar uma linha?");
    scanf("%s", table_line);
    char new_table_line[30] = "arquivos/";
    strcat(table_line, ".txt");
    strcat(new_table_line, table_line);
    file = fopen(new_table_line, "r+");

        if (file == NULL){
            fprintf(stderr, "Erro ao abrir o arquivo.\n");

        }
        else{

            fseek(file,0, SEEK_SET);           //Ir para a parte inicial do arquivo

            fscanf(file, "Número de colunas:%d", &num_column);     //Ler o número de colunas 


            char name[num_column][30];
            char type[num_column][30];
            fscanf(file,"%*d");
            for(int i=0;i<num_column;i++){
                fscanf(file, " | %s (%s)", name[i], type[i]);
            }
            while (aux == 's')
            {
                fseek(file, 0, SEEK_END); // ir para o final do documento

                //Chave primária da linha
                char new_line[30];
                printf("Qual a chave primaria?");
                scanf("%d", &key);
                fprintf(file, "\n%*d ", 4, key);

                // Loop para pegar e escrever os dados na tabela
                for (int i = 0; i < num_column; i++) {
                    int len_cell = strlen(name[i]) + strlen(type[i]) + 2;
                    char new_line[len_cell];
                    printf("Digite um(a) %s do tipo (%s): ", name[i], type[i]);
                    scanf("%s", new_line);
                    fprintf(file, " | %*s",len_cell, new_line);  // Adiciona o valor no arquivo
            }
            printf("Deseja adicionar outra linha? s ou n?\n");
            scanf("%s", &aux);
        }
        }

    fclose(file);
    printf("\n");
    menu();
}

void listar_dados()
{   
    char caractere;
    char table_line[30];
    printf("Qual tabela você deseja imprimir os dados?");
    scanf("%s", table_line);
    char new_table_line[30] = "arquivos/";
    strcat(table_line, ".txt");
    strcat(new_table_line, table_line);
    file = fopen(new_table_line, "r+");

        if (file == NULL){
            fprintf(stderr, "Erro ao abrir o arquivo.\n");
            
        }
        else{  
            fseek(file,21, SEEK_CUR);
            while ((caractere = fgetc(file)) != EOF) {
            printf("%c", caractere);
            }
        }
    fclose(file);
    printf("\n\n");
    menu();
}

void pesquisar_valor()
{
}

void apagar_tupla()
{   
    char caractere;
    char table_line[30];
    printf("Qual tabela você deseja apagar uma tupla?");
    scanf("%s", table_line);
    char new_table_line[30] = "arquivos/";
    strcat(table_line, ".txt");
    strcat(new_table_line, table_line);
    file = fopen(new_table_line, "r+");

        if (file == NULL){
            fprintf(stderr, "Erro ao abrir o arquivo.\n");
        }
        else{
        
            fseek(file,21, SEEK_CUR);
            while ((caractere = fgetc(file)) != EOF) {
            printf("%c", caractere);
            }
        }
    fclose(file);
    printf("\n\n");
    menu();
}


void apagar_tabela()
{
    char table_removed[20];
    int count = 0;
    //Nome da tabela a ser removida
    printf("Qual tabela deseja apagar:");
    scanf("%s", table_removed); 
    strcat(table_removed, ".txt");
    //Abre pasta com as tabelas
    struct dirent *dirp;
    directory = opendir("arquivos");
    while(dirp = readdir(directory)){
        //Testa se pasta existe
        if (strcmp(dirp->d_name, table_removed) == 0 ) {
            char drctry[20] = "arquivos/";      
            strcat(drctry, table_removed);  
            remove(drctry);
            printf("\nTabela removida!");
            listar_tabelas();
            count++;
        }
    }
    if(count==0){
        printf("Tabela não existente.\n");
        listar_tabelas();
    }
}
