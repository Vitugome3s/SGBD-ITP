#include <stdio.h>

int main() {
    int linhas, inicial = 1;

//definir a quantidade de linhas

    scanf("%d", &linhas);
    
    if(linhas== 0){
        printf("Você entrou com 1, tente de novo na próxima");
    }

//construção do triangulo de floyd

    for (int i = 1; i <= linhas; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%2d ", inicial);
            inicial++;
        }
        printf("\n");
    }

    return 0;
}
