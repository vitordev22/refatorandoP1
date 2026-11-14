#include <stdio.h>
#include <stdlib.h>

//Elas pedem que você faça um programa que permita lançar as contas pagas pela mulher
//1 e pela mulher 2, calcule quem tem que devolver valor para quem, ou se não é
//necessário, e informe isto na tela. Cada pagamento é lançado com o valor e quem
//pagou (mulher 1 ou mulher 2).

// Utilizando ponteiros e alocação dinâmica

int main() {
    float *vetor1, *vetor2;
    int qtd_contas1, qtd_contas2, i;
    float soma1=0, soma2=0, diferenca=0, totalIndividual=0;

    printf("Informe a quantidade de contas pagas pela mulher 1: ");
    scanf("%d", &qtd_contas1);
    printf("Informe a quantidade de contas pagas pela mulher 2: ");
    scanf("%d", &qtd_contas2);

    if (qtd_contas1 > 1000 || qtd_contas2 > 1000 || qtd_contas1 <= 0 || qtd_contas2 <= 0) {
        printf("Error! Quantidade invalida.");
        exit(1);
    }

    printf("\n");

    vetor1 = malloc(qtd_contas1 * sizeof(float));
    if (vetor1 == NULL) {
        printf("Error! Sem memoria");
        exit(1);
    }
    vetor2 = malloc(qtd_contas2 * sizeof(float));
    if (vetor2 == NULL) {
        printf("Error! Sem memoria");
        free(vetor1);
        exit(1);
    }

    printf("Informe os valores da mulher 1:\n");
    for (i=0; i<qtd_contas1; i++) {
        scanf("%f", &vetor1[i]);
        soma1 += vetor1[i];
    }

    printf("Total pago pela mulher 1: R$ %.2f\n\n", soma1);

    printf("Informe os valores da mulher 2:\n");
    for (i=0; i<qtd_contas2; i++) {
        scanf("%f", &vetor2[i]);
        soma2 += vetor2[i];
    }

    printf("Total pago pela mulher 2: R$ %.2f\n\n", soma2);

    totalIndividual = (soma1 + soma2) / 2;

    if (soma1 > soma2) {
        diferenca = soma1 - totalIndividual;
        printf("A mulher 2 esta devendo R$ %.2f para mulher 1.", diferenca);
    } else if (soma2 > soma1) {
        diferenca = soma2 - totalIndividual;
        printf("A mulher 1 esta devendo R$ %.2f para mulher 2.", diferenca);
    } else {
        printf("Os valores pagos foram iguais!");
    }

    free(vetor1);
    free(vetor2);


    return 0;
}