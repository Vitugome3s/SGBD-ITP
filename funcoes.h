#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

typedef struct {
    char data[30][30][30];
    int numRows;
    int numCols;
} Table;

void criar_tabela(void);

char ajustar_nome(void);

void listar_tabelas(void);

void criar_linha(void);

void listar_dados(void);

void pesquisar_valor(void);

void apagar_tupla(void);

void apagar_tabela(void);

void menu(void);

#endif // FUNCOES_H_INCLUDED