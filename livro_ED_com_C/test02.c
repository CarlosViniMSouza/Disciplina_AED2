#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ponto
{
  float coordX;
  float coordY;
};

void imprime(struct Ponto *pp);
void captura(struct Ponto *pp);

int main(void)
{
  struct Ponto p;

  captura(&p);
  imprime(&p);

  return 0;
}

void captura(struct Ponto *pp)
{
  printf("Entre com as coordenadas de p(x, y) = ");
  scanf("%f %f", &pp->coordX, &pp->coordY);
}

void imprime(struct Ponto *pp)
{
  printf("Coordenadas do ponto p(x, y) = (%.2f, %.2f)", pp->coordX, pp->coordY);
}
