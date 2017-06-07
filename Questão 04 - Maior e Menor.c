#include<stdio.h>
#include <locale.h> // Permite Linguagem Pt-Br
#include <stdlib.h> // Necess�rio para as fun��es rand() e srand()
#include <time.h> // Necess�rio para a fun��o time()

/*
Autor: Arthur de Melo Ger�nimo
URI: artha.net.br
*/
int main()
{
    setlocale(LC_ALL,"portuguese");
    int maior = 0, menor = 0, quantidade, *vetor, i, maximo;

    printf("Defina a quantidade de n�meros que ser�o analisados:");
    scanf("%d",&quantidade);

    printf("Defina o n�mero m�ximo:");
    scanf("%d",&maximo);

    vetor = (int *)malloc(quantidade * sizeof(int));

    for (i = 0; i < quantidade; ++i) {
         vetor[i] = rand() % maximo;
         if(vetor[i] > maior) maior = vetor[i];
         if(vetor[i] < menor) menor = vetor[i];
    }

    system("cls");

    printf("N�meros Analisados:\n");
    for (i = 0; i < quantidade; ++i) {
        printf("Posi��o %d - Valor: %d \n",i, vetor[i]);
    }

    printf("\n\n\nMaior N�mero Encontrado: %d \n", maior);
    printf("\nMenor N�mero Encontrado: %d \n\n\n", menor);

    free(vetor);
  return 0;

}
