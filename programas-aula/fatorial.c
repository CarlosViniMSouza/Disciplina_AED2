#include <stdio.h>
#include <conio.h>

// protótipo da função fatorial
long long int fatorial(int num);

long long int main(void)
{
  int num;
  long long int fat;

  printf("Digite um numero inteiro: ");
  scanf("%d", &num);

  // chamada da função fatorial
  fat = fatorial(num);

  printf("Fatorial de %d = %lld", num, fat);

  return 0;
}

// Função recursiva que calcula o fatorial de um numero inteiro n
long long int fatorial(int num)
{
  float vfat;

  if (num <= 1)
    return 1;

  else
  {
    // a função fatorial se auto-chama até chegar em 1.
    // Assim, teremos: n * (n - 1) * (n - 2) * ... * 2 * 1
    vfat = num * fatorial(num - 1);
    return (vfat);
  }
}

/*

Alterei o tipo do procedimento fatorial() e da variavel 'fat' -> de float p/ long long int

*/