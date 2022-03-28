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
int removerArvBin(ArvBin *raiz, int valor);

// Referente aos elementos (NOs)
int inserir(ArvBin *raiz, int valor);
int remover(struct NO *atual);
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

int removerArvBin(ArvBin *raiz, int valor)
{
  if (raiz == NULL)
  {
    return 0;
  }

  struct NO *ant = NULL;
  struct NO *atual = NULL;

  while (atual != NULL)
  {
    if (valor == atual->info)
    {
      if (atual == *raiz)
      {
        *raiz = remover(atual);
      }
      else
      {
        if (ant->dir == atual)
        {
          ant->dir = remover(atual);
        }
        else
        {
          ant->esq = remover(atual);
        }
      }

      return 1;
    }

    ant = atual;
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

int remover(struct NO *atual)
{
  struct NO *no1, *no2;

  if (atual->esq == NULL)
  {
    no2 = atual->dir;
    free(atual);
    return no2;
  }

  no1 = atual;
  no2 = atual->esq;

  while (no2->dir != NULL)
  {
    no1 = no2;
    no2 = no2->dir;
  }

  if (no1 != atual)
  {
    no1->dir = no2->esq;
    no2->esq = atual->esq;
  }

  no2->dir = atual->dir;
  free(atual);
  return no2;
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
