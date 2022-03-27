#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
  int info;
  struct NO *esq;
  struct NO *dir;
} ArvBin;

// Referente a Arvore como um todo
ArvBin *criarArvore();
void liberarArvBin(struct NO *no);
void destruirArvore(ArvBin *raiz);

// Referente aos elementos (NOs)
int inserir(ArvBin *raiz, int valor);
int remover(ArvBin *raiz, int valor);
int consultar(ArvBin *raiz, int valor);
int altura(ArvBin *raiz);
int totalArvBin(ArvBin *raiz);

// Visualizando a Arvore
void ExibirPreOrdem(ArvBin *raiz);
void ExibirEmOrdem(ArvBin *raiz);
void ExibirPosOrdem(ArvBin *raiz);

int main()
{
  // Comentario
}

ArvBin *criarArvore()
{
  // Alocando memoria para o endereco da raiz da Arvore:
  ArvBin *raiz = (ArvBin *)malloc(sizeof(ArvBin));
  if (raiz != NULL)
  {
    *raiz = NULL;
  }
  return raiz;
}

void liberarArvBin(struct NO *no)
{
  if (no == NULL)
  {
    return 0;
  }
  liberarArvBin(raiz->esq);
  liberarArvBin(raiz->dir);
  free(no);
  no == NULL;
}

void destruirArvore(ArvBin *raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  liberarArvBin(*raiz); // libera cada NO inserido
  free(raiz);           // remove a raiz da memória
}

int inserir(ArvBin *raiz, int valor)
{
  if (*raiz == NULL)
  {
    *raiz = (ArvBin *)malloc(sizeof(ArvBin)); // Aloca memória para a estrutura ArvBin.
    (*raiz)->esq = NULL;
    (*raiz)->dir = NULL;
    (*raiz)->valor = valor;
  }
  else
  {
    if (valor < ((*raiz)->valor))
    {
      inserir(&((*raiz)->esq), valor);
    }
    else
    {
      inserir(&((*raiz)->dir), valor);
    }
  }
}

int remover(ArvBin *raiz, int valor)
{
  return 0;
  // Sera dificil de implementar
}

int consultar(ArvBin *raiz, int valor)
{
  struct NO *atual = *raiz;

  if (raiz == NULL)
  {
    return 0;
  }
  while (atual != NULL)
  {
    if (valor == atual->info)
    {
      return 1;
    }
    if (valor > atual->info)
    {
      atual = atual->dir;
    }
    else
    {
      atual = atual->esq;
    }
  }

  return 0;
}

int altura(ArvBin *raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  if (*raiz == NULL)
  {
    return 0;
  }
  int alt_esq = altura(&((*raiz)->esq));
  int alt_dir = altura(&(*raiz)->dir);

  if (alt_esq > alt_dir)
  {
    return (alt_esq + 1);
  }
  else
  {
    return (alt_dir + 1);
  }
}

int totalArvBin(ArvBin *raiz)
{
  if (raiz == NULL || *raiz == NULL)
  {
    return 0;
  }
  int total_esq = totalArvBin(&((*raiz)->esq));
  int total_dir = totalArvBin(&((*raiz)->dir));
  return (1 + total_esq + total_dir);
}

void ExibirPreOrdem(ArvBin *raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  if (*raiz != NULL)
  {
    printf("(%d)\n", (*raiz)->info);
    ExibirPreOrdem(&((raiz)->esq));
    ExibirPreOrdem(&((*raiz)->dir));
  }
}

void ExibirEmOrdem(ArvBin *raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  if (*raiz != NULL)
  {
    ExibirEmOrdem(&((raiz)->esq));
    printf("(%d)\n", (*raiz)->info);
    ExibirEmOrdem(&((*raiz)->dir));
  }
}

void ExibirPosOrdem(ArvBin *raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  if (*raiz != NULL)
  {
    ExibirPosOrdem(&((raiz)->esq));
    ExibirPosOrdem(&((*raiz)->dir));
    printf("(%d)\n", (*raiz)->info);
  }
}
