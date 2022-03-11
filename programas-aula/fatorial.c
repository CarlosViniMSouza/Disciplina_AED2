#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

double fatorial(int n)
{
  double vfat;

  if (n <= 1)
  {
    return (1);
  }
  else
  {
    vfat = n * fatorial(n - 1);
    return (vfat);
  }
}

int main(void)
{
  int num;
  double fat;

  printf("Digite um numero: ");
  scanf("%d", &num);

  fat = fatorial(num);
  printf("Fatorial de %d = %0.1f", num, fat);

  return 0;
}