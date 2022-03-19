#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct ponto
{
  float x, y;
} Ponto; // Criando um tipo de dado chamado 'Ponto'

Ponto *pontoCriar(float x, float y); // Procedimento p/ criar um novo elemento 'ponto'

void pontoLiberar(Ponto *p); // Procedimento p/ liberar um elemento 'ponto'

int pontoAcessar(Ponto *p, float *x, float *y); // Procedimento p/ acessar o conteudo de um 'ponto'

int pontoAtribuir(Ponto *p, float x, float y); // Procedimento p/ atribuir conteudo em um ponto'

float pontoDistancia(Ponto *p1, Ponto *p2); // Procedimento p/ Calcular distância entre 2 pontos

// Nossa funcao principal
int main()
{
  float d, u1, u2, v1, v2; // Nossa variavel que tera o resultado do calculo
  Ponto *p, *q;

  printf("digite os valorres de X e Y do ponto 1 = ");
  scanf("%f %f", &u1, &u2);

  printf("digite os valorres de X e Y do ponto 2 = ");
  scanf("%f %f", &v1, &v2);

  p = pontoCriar(u1, u2);
  q = pontoCriar(v1, v2);
  d = pontoDistancia(p, q);

  printf("Distancia entre os pontos P e Q = %.2f", d);

  pontoLiberar(p);
  pontoLiberar(q);

  return 0;
}

// Vamos desenvolver nossos procedimentos:

// 1. Criando um ponto (aqui, precisamos alocar memoria p/ criar um ponto):
Ponto *pontoCriar(float x, float y)
{

  Ponto *p = (Ponto *)malloc(sizeof(Ponto));

  if (p != NULL)
  {
    p->x = x;
    p->y = y;
  }

  return p;
}

// 2. Liberando um ponto da nossa memória (Aqui, deletamos o espaço ocupado na memoria manualmente):
void pontoLiberar(Ponto *p)
{
  free(p);
}

// 3. Acessando conteúdo do ponto (P/ enviar o conteúdo das variaveis via-ponteiros):
int pontoAcessar(Ponto *p, float *x, float *y)
{
  if (p == NULL)
  {
    return 0;
  }

  *x = p->x;
  *y = p->y;
  return 1;
}

// 4. Atribuindo valor ao ponto:
int pontoAtribuir(Ponto *p, float x, float y)
{
  if (p == NULL)
  {
    return 0;
  }

  p->x = x;
  p->y = y;
  return 1;
}

// 5. Calcular a distância entre 2 pontos:
float pontoDistancia(Ponto *p1, Ponto *p2)
{
  if (p1 == NULL && p2 == NULL)
  { // Podemos trocar o && por ||
    return -1;
  }

  float dx = p1->x - p2->x;
  float dy = p1->y - p2->y;
  return sqrt(dx * dx + dy * dy);
}
