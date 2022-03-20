#include <stdio.h>
#include <conio.h>

// 1. Declaramos as funcoes:
long int numerador(int n);
long int denominador(int p);
long int combinatoria(int n, int p);
void main();

// 2. chamamos nossa funcao principal
void main()
{
  long int comb, combi;
  int n, p;

  printf("Digite um numero inteiro p/ N = ");
  scanf("%d", &n);

  printf("Digite um numero inteiro p/ P = ");
  scanf("%d", &p);

  // 3. invocamos as 2 funcoes recursivas
  comb = numerador(n) / denominador(p);
  combi = combinatoria(n, p);

  printf("O resultado de (%d!)/(%d!) eh = %ld", n, p, comb);
  printf("Sera que deu certo? = %ld", combi);
}

// Primeira funcao recursiva
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

// Segunda funcao recursiva
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

long int combinatoria(int n, int p)
{
  int mult;

  if (p <= 1)
  {
    return 1;
  }
  else
  {
    mult = combinatoria(n * n - 1, p * p - 1);
    // aqui terei que estudar mais para desenvolver ...
  }
}