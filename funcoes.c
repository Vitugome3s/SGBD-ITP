#include "funcoes.h"

void menu(){
    
}

void criar_tabela(){
    //nome da tabela
    char name[30];
    //chave primária
    int key;

    //nome da tabela
    printf("Qual será o nome de sua tabela?");
    scanf("%s",&name);

    //primeira chave primária
    printf()



    FILE *arquivo;
    // Abre o arquivo para escrita (w)
    arquivo = fopen("exemplo.txt", "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
    }
    // Escreve no arquivo
    fprintf(arquivo, "Olá, mundo!\n");

    // Fecha o arquivo
    fclose(arquivo);

    
}

