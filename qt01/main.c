#include <stdio.h>
#include <stdlib.h>

//Escreva um programa que leia um sequência de números informados pelo usuário. A quantidade de números a ser lido deve ser previamente informada pelo usuário e não pode ser superior a 100. Se programa deve descobrir a subsequência consecutiva de números de soma máxima. EX: Na sequência 5, 2, -2, -7,3, 14, 10, -3, 9, -6, 4, 1, a soma do segmento é 33 (3, 14, 10, -3, 9)

int main() {
    int *vetor, qtdN,i, maiorSoma, somaAtual, inicioMelhor=0, fimMelhor=0,j;

    printf("Informe a quantidade de numeros: ");
    scanf("%d", &qtdN);
    if (qtdN <=0 || qtdN > 100) {
        printf("Error! Informe um valor valido");
        exit(1);
    }

    //Alocação dinâmica
    vetor = malloc(qtdN * sizeof(int));
    if (vetor == NULL) {
        printf("Error! Sem memoria");
        exit(1);
    }

    printf("Informe os valores:\n");
    for (i=0; i<qtdN; i++) {
        scanf("%d", &vetor[i]);
    }

    maiorSoma = vetor[0];

    for (i = 0; i < qtdN; i++) {
        somaAtual = 0;
        for (j = i; j < qtdN; j++) {
            somaAtual += vetor[j];
            if (somaAtual > maiorSoma) {
                maiorSoma = somaAtual;
                inicioMelhor = i;
                fimMelhor = j;
            }
        }
    }

    printf("\nMaior soma: %d\n", maiorSoma);

    for (i=inicioMelhor; i<=fimMelhor; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor);


    return 0;
}