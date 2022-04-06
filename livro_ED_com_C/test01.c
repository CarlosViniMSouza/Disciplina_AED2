#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ponto
{
  float coordX;
  float coordY;
};

void main()
{
  struct Ponto p;

  printf("Digite o ponto p(x, y) = ");
  scanf("%f %f", &p.coordX, &p.coordY);
  printf("\nPonto inserido = (%.2f, %.2f)", p.coordX, p.coordY);
}
