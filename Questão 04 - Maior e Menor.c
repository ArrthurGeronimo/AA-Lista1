#include<stdio.h>
#include <locale.h> // Permite Linguagem Pt-Br
#include <stdlib.h> // Necessário para as funções rand() e srand()
#include <time.h> // Necessário para a função time()

/*
Autor: Arthur de Melo Gerônimo
URI: artha.net.br
*/
int main()
{
    setlocale(LC_ALL,"portuguese");
    int maior = 0, menor = 0, quantidade, *vetor, i, maximo;

    printf("Defina a quantidade de números que serão analisados:");
    scanf("%d",&quantidade);

    printf("Defina o número máximo:");
    scanf("%d",&maximo);

    vetor = (int *)malloc(quantidade * sizeof(int));

    for (i = 0; i < quantidade; ++i) {
         vetor[i] = rand() % maximo;
         if(vetor[i] > maior) maior = vetor[i];
         if(vetor[i] < menor) menor = vetor[i];
    }

    system("cls");

    printf("Números Analisados:\n");
    for (i = 0; i < quantidade; ++i) {
        printf("Posição %d - Valor: %d \n",i, vetor[i]);
    }

    printf("\n\n\nMaior Número Encontrado: %d \n", maior);
    printf("\nMenor Número Encontrado: %d \n\n\n", menor);

    free(vetor);
  return 0;

}
