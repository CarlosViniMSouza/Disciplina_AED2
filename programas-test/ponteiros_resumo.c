#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *x, valor, y;

  printf("Digite um valor inteiro = ");
  scanf("%d", &valor);

  x = &valor; // recebe o end. de memoria da var 'valor'
  y = *x;     // recebe o conteudo apontado por x (no caso, o conteudo da var 'valor')

  printf("\nLendo o conteudo da variavel apontada por X = %d", *x); // Nesse caso, nos referimos ao conteudo da var 'valor', so que de forma indireta
  printf("\nLendo o conteudo do ponteiro X = %p", x);
  printf("\nLendo o endereco do ponteiro X = %p", &x);
  printf("\nLendo o endereco da variavel VALOR = %p", &valor);
  printf("\nLendo o conteudo da variavel Y = %d", y);

  free(x);
}
