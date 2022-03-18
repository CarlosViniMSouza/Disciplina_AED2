#include <stdio.h>
#include <conio.h>

// protótipo da função fatorial
double fatorial(int n);

int main(void)
{
  int numero;
  double fat;

  printf("Digite um numero inteiro: ");
  scanf("%d", &numero);

  // chamada da função fatorial
  fat = fatorial(numero);

  printf("Fatorial de %d = %.0lf", numero, fat);

  getch();

  return 0;
}

// Função recursiva que calcula o fatorial de um numero inteiro n
double fatorial(int n)
{
  double vfat;

  if (n <= 1)
    return (1);

  else
  {
    vfat = n * fatorial(n - 1);
    return (vfat);
  }
}