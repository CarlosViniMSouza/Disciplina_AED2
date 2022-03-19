#include <stdio.h>
#include <conio.h>

long int numerador(int n);
long int denominador(int p);

int main(void)
{
  long int comb;
  int n, p;

  printf("Digite um numero inteiro p/ N = ");
  scanf("%d", &n);

  printf("Digite um numero inteiro p/ P = ");
  scanf("%d", &p);

  comb = numerador(n) / denominador(p);

  printf("O resultado de (%d!)/(%d!) eh = %ld", n, p, comb);

  return 0;
}

long int numerador(int n)
{
  if (n <= 1)
  {
    return 1;
  }
  else
  {
    return (n * numerador(n - 1));
  }
}

long int denominador(int p)
{
  int mult;

  if (p <= 1)
  {
    return 1;
  }
  else
  {
    return (p * denominador(p - 1));
  }
}