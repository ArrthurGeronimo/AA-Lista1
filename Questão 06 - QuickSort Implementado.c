#include<stdio.h>
#include <locale.h> // Permite Linguagem Pt-Br
#include <stdlib.h> // Necess�rio para as fun��es rand() e srand()
#include <time.h> // Necess�rio para a fun��o time()
#define msg_aguarde "\nPressione a tecla ENTER para continuar\n"

/*
Autor: Arthur de Melo Ger�nimo
URI: artha.net.br
*/

void quickSort(int* vet, int esquerda, int direita) {
  int pivo, j;

  if (direita > esquerda) {

     pivo = esquerda;
     for (j = esquerda + 1; j <= direita; j++) {
       if (vet[j] < vet[esquerda]) {
          pivo++;
          troca(&vet[pivo], &vet[j]);
       }
     }

     troca(&vet[esquerda], &vet[pivo]);

     quickSort(vet, esquerda, pivo - 1);
     quickSort(vet, pivo + 1, direita);
  }
}

void troca(int* a, int* b) {
     int aux;
     aux = *a;
     *a = *b;
     *b = aux;
}

void aguarde(char* msg){

	printf("%s",msg);
    char x;

    scanf("%c%*c", &x);

    /* %c = especifica um caracter
       %*c = a utiliza��o do sinal de * (asterisco) antes do sinal de % (porcentagem) indica que o restante das informa��es lidas ser� validada mas n�o armazendada

     * Fonte:
     *    http://www.vivaolinux.com.br/dica/Limpando-a-sujeirinha-no-buffer-do-teclado/
     *    http://qualadoce.blogspot.com/2008/02/o-scanf-engana.html
    */
}

int main()
{
    setlocale(LC_ALL,"portuguese");
    int maior = 0, menor = 0, quantidade, *vetor, i, maximo;

    printf("Defina a quantidade de n�meros que ser�o gerados:");
    scanf("%d",&quantidade);

    printf("Defina o n�mero m�ximo:");
    scanf("%d",&maximo);

    vetor = (int *)malloc(quantidade * sizeof(int));

    for (i = 0; i < quantidade; ++i) {
         vetor[i] = rand() % maximo;
    }

    system("cls");

    printf("---------- N�meros Antes da Ordena��o ----------\n\n");
    for (i = 0; i < quantidade; ++i) {
        printf("Posi��o %d - Valor: %d \n",i, vetor[i]);
    }

    aguarde("\n Pressione a tecla ENTER para continuar\n\n");

    system("cls");

    quickSort(vetor,0,quantidade-1);

    printf("---------- N�meros Depois da Ordena��o ----------\n\n");
    for (i = 0; i < quantidade; ++i) {
        printf("Posi��o %d - Valor: %d \n",i, vetor[i]);
    }

    free(vetor);
  return 0;

}
