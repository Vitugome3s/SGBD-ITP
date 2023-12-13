#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "funcoes.h"
#include "funcoes_aux.h"

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
           "0 - Fechar\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        criar_tabela();
        menu();
        break;
    case 2:
        listar_tabelas();
        menu();
        break;
    case 3:
        criar_linha();
        menu();
        break;
    case 4:
        listar_dados();
        menu();
        break;
    case 5:
        pesquisar_valor();
        menu();
        break;
    case 6:
        apagar_tupla();
        menu();
        break;
    case 7:
        apagar_tabela();
        menu();
        break;
    case 0:
        break;
    default:
        printf("Escolha inválida.\n");
        menu();
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
    printf("Escolha o nome de sua tabela: ");
    scanf("%s", &name);
    while(check_tablename(name)==1){
        printf("Erro! Ja existe uma tabela com esse nome.\n");
        printf("Escolha o nome de sua tabela: ");
        scanf("%s", &name);
        check_tablename(name);
    }
    // Abre pasta e arquivo
    char drctry[20] = "arquivos/";
    strcat(name, ".txt");
    strcat(drctry, name);
    file = fopen(drctry, "w");
    // Verifica se o arquivo foi aberto com sucesso
    if (file == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        printf("\n");
        menu();
    }
    else
    {
        // Imprimir o número de colunas no cabeçalho
        num_column = 0;
        fprintf(file, "Número de colunas:%d\n",num_column);

        fprintf(file, "PK  ", key); // Escreve no arquivo

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
                menu();
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
}

void listar_tabelas()
{
    struct dirent *dirp;
    directory = opendir("arquivos");
    if (directory == NULL)
    {
        printf("\nNão há nenhuma tabela registrada.\n");
        printf("\n");
        menu();
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

    if (file == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
    }
    else
    {

        fseek(file, 0, SEEK_SET); // Ir para a parte inicial do arquivo

        fscanf(file, "Número de colunas:%d", &num_column); // Ler o número de colunas

        char name[num_column][30];
        char type[num_column][30];
        fscanf(file, " PK ");
        for (int i = 0; i < num_column; i++)
        {
            fscanf(file, " | %s (%s)", name[i], type[i]);
        }
        while (aux == 's')
        {
            fseek(file, 0, SEEK_END); // ir para o final do documento

            // Chave primária da linha
            char new_line[30];
            printf("Qual a chave primaria?");
            scanf("%d", &key);
            while(check_linepk(new_table_line, key) == 0){
                printf("Erro! Chave primaria ja utilizada.\n");
                printf("Qual a chave primaria?");
                scanf("%d", &key);
            }
            fprintf(file, "\n%*d ", 4, key);

            // Loop para pegar e escrever os dados na tabela
            for (int i = 0; i < num_column; i++)
            {
                int len_cell = strlen(name[i]) + strlen(type[i]) + 2;
                char new_line[len_cell];
                printf("Digite um(a) %s do tipo (%s): ", name[i], type[i]);
                scanf("%s", new_line);
                fprintf(file, " | %*s", len_cell, new_line); // Adiciona o valor no arquivo
            }
            printf("Deseja adicionar outra linha? s ou n?\n");
            scanf("%s", &aux);
        }
    }

    fclose(file);
    printf("\n");
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

void pesquisar_valor(){
    int num_column;
    char table_line[30];
    int choice;
    char choice_2;
    printf("Qual tabela voce deseja pesquisar os dados? ");
    scanf("%s", table_line);
    char new_table_line[30] = "arquivos/";
    strcat(table_line, ".txt");
    strcat(new_table_line, table_line);
    file = fopen(new_table_line, "r");

    if (file == NULL){
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        printf("\n");
        menu();
    }
    else{
        fseek(file,0, SEEK_SET);

        fscanf(file, "Número de colunas:%d", &num_column);     //Ler o número de colunas 

        char name[num_column][30];
        char type[num_column][30];

        fscanf(file,"%*d");
        
        for(int i=0;i<num_column;i++){
            fscanf(file, " | %s (%s)", name[i], type[i]);
        }
        printf("Colunas disponiveis para pesquisa:\n");
        for (int i = 0; i < num_column; i++) {
            int count = i+1;
            printf("%d - %s\n", count, name[i]);
        }

        int choice_column;
        printf("Digite o numero da coluna desejada: ");
        scanf("%d", &choice_column);
        char data_c[30];
        char data_s[30][30];
        int tempora;
        int data_i[30];
        float data_f[30];
        double data_lf[30];
        int count_c = 0; int count_s = 0; int count_i = 0; int count_f = 0; int count_lf = 0;
        char linha[1000]; 
        while(fgets(linha, sizeof(linha), file) != NULL){
            fscanf(file,"%*d ");
            for(int i=0;i<(choice_column-1);i++){
                fscanf(file, "| %*s");   
            }
            int k = choice_column - 1;
            switch(type[k][0]){
                    case 'c' : fscanf(file, "| %c ",   data_c[count_c]); count_c++; break;
                    case 's' : fscanf(file, "| %s ",   data_s[count_s]); count_s++; break;
                    case 'i' : fscanf(file, "| %s ",   data_s[count_i]);  count_i++; break;
                    case 'f' : fscanf(file, "| %s ",   &data_f[count_f]); count_f++; break;
                    case 'd' : fscanf(file, "| %lf ",  &data_lf[count_lf]); count_lf++; break;
                 }
                 
            int d = num_column - choice_column;
            for(int j=0;j<d;j++){
                fscanf(file, "|%*s");
            }
            printf("%s",data_s[0]);
            printf("%s",data_s[1]);
            printf("%s",data_s[2]);
            printf("%s",data_s[3]);
            printf("%s",data_s[4]);
        }

        printf("\n  ===== Escolha uma das opcoes de pesquisa =====\n"
               "1 - maior que o valor informado\n"
               "2 - maior ou igual que o valor informado\n"
               "3 - igual o valor informado\n" 
               "4 - menor que o valor informado\n"
               "5 - menor ou igual que o valor informado\n"
               "6 - proximo ao valor informado (apenas para strings)\n");
        printf("Escolha: ");
        scanf("%d", &choice);
        
        int a = choice_column - 1;
        if(strcmp(type[a], "char)") == 0){
            char search[30];
            printf("\nDigite o valor desejado: ");
            scanf("%s", &search);
    
        }
        else{
            if (choice == 6){
                printf("Erro! Opcao valida apenas para pesquisa com dados do tipo string");
                pesquisar_valor();
            }
            else{
            double search;
            printf("\nDigite o valor desejado: ");
            scanf("%lf", &search);
            }
        }
    }
}

void apagar_tupla()
{
    FILE *file, *temp;

    // Pegar o nome da tabela que deseja abrir.
    char Table_name[30];
    printf("Em qual tabela deseja apagar uma tupla?");
    scanf("%s", &Table_name);
    char new_table_name[30] = "arquivos/";
    strcat(Table_name, ".txt");
    strcat(new_table_name, Table_name);

    // Perguntar qual chave primária deseja apagar.
    printf("Qual chave primaria deseja apagar? ");
    int chavePrimaria;
    scanf("%d", &chavePrimaria);

    // Abre o arquivo no modo leitura e escrita
    char linha[1000];
    file = fopen(new_table_name, "r");
    if (file == NULL){
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    // Cria um arquivo temporário no modo escrita
    temp = fopen("temp.txt", "w");
    if (temp == NULL){
        printf("Erro ao criar arquivo temporario");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Lê e escreve linha por linha, ignorando a linha com a chave primária
    int pkLida;
    while (fgets(linha, sizeof(linha), file) != NULL){
        sscanf(linha, "%d", &pkLida);

        // Se a linha não contiver a chave primária, escreva no arquivo temporário
        if (pkLida != chavePrimaria){
            fputs(linha, temp);
        }
    }

    // Fecha os arquivos abertos
    fclose(file);
    fclose(temp);

    // Remove o arquivo original e renomear o arquivo temporário
    remove(new_table_name);
    rename("temp.txt", new_table_name);

    printf("Tupla com chave primaria %d removida com sucesso.\n", chavePrimaria);
    printf("\n\n");
}

void apagar_tabela(){
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
        menu();
    }
}
