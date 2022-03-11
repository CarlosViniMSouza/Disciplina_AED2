#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

// Criando a Estrutura Node
typedef struct TNO
{
  // Dado do Node
  int num;

  // Ponteiro para o Node esquedo
  struct TNO *esq;

  // Ponteiro para o Node direito
  struct TNO *dir;

} Node; // Criamos um novo tipo de dado denominado 'Node'

Node *raiz;

// Iniciando Arv. Binaria vazia.
// p_raiz é Ponteiro de ponteiro e é paramentro.
void criarArv(Node **p_raiz)
{
  *p_raiz = NULL;
}

void inserir(Node **p_raiz, int p_elem)
{
  if (*p_raiz == NULL)
  {
    *p_raiz = (Node *)malloc(sizeof(Node));
    (*p_raiz)->esq = NULL;
    (*p_raiz)->dir = NULL;
    (*p_raiz)->num = p_elem;
  }
  else
  {
    if (p_elem < ((*p_raiz)->num))
    {
      inserir(&((*p_raiz)->esq), p_elem);
    }
    else
    {
      inserir(&((*p_raiz)->dir), p_elem);
    }
  }
}
