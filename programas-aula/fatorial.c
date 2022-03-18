#include <stdio.h>
#include <conio.h>

// protótipo da função fatorial
float fatorial(int n);

int main(void)
{
  int numero;
  float fat;

  printf("Digite um numero inteiro: ");
  scanf("%d", &numero);

  // chamada da função fatorial
  fat = fatorial(numero);

  printf("Fatorial de %d = %.0lf", numero, fat);

  return 0;
}

// Função recursiva que calcula o fatorial de um numero inteiro n
float fatorial(int num)
{
  float vfat;

  if (num <= 1)
    return (1);

  else
  {
    // a função fatorial se auto-chama até chegar em 1.
    // Assim, teremos: n * (n - 1) * (n - 2) * ... * 2 * 1
    vfat = num * fatorial(num - 1);
    return (vfat);
  }
}