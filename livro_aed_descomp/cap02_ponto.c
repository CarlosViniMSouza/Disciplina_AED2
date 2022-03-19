#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Criando um tipo de dado chamado 'Ponto':
typedef struct ponto Ponto;

// Procedimento p/ criar um novo elemento 'ponto':
Ponto *pontoCriar(float x, float y);

// Procedimento p/ liberar um elemento 'ponto':
void pontoLiberar(Ponto *p);

// Procedimento p/ acessar o conteudo de um 'ponto':
int pontoAcessar(Ponto *p, float *x, float *y);

// Procedimento p/ atribuir conteudo em um ponto':
int pontoAtribuir(Ponto *p, float *x, float *y);

// Calcular distância entre 2 pontos:
float pontoDistancia(Ponto *p1, Ponto *p2);

struct ponto
{ // Definimos o tipo de dados
  float x, y;
};

// Nossa funcao principal
int main()
{
  printf("Em construcao!");
}

// Vamos desenvolver nossos procedimentos:

// 1. Criando um ponto:
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

// 2. Liberando um ponto da nossa memória:
void pontoLiberar(Ponto *p)
{
  free(p);
}

// 3. Acessando conteúdo do ponto:
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
int pontoAtribuir(Ponto *p, float *x, float *y)
{
  if (p == NULL)
  {
    return 0;
  }

  p->x = x;
  p->y = y;
  return 1;
}
