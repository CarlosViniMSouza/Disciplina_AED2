#include <stdio.h>
#include <stdlib.h>

typedef struct ArvBin
{
  int info;
  struct ArvBin *ArvBin; // necessario para a funcao liberarArvBin()
  struct ArvBin *esq;
  struct ArvBin *dir;
} ArvBin;

// Referente a Arvore como um todo
ArvBin *criarArvore();
void destruirArvore(ArvBin *raiz);

// Referente aos elementos (ArvBins)
void liberarArvBin(ArvBin *ArvBin);
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
    // O ponteiro da ArvBinssa raiz irá apontar p/ endereco NULL
    // ArvBinssa raiz terá um local para onde apontar apos ser criada
    *raiz = NULL;
  }
  return raiz;
}

void liberarArvBin(ArvBin *ArvBin)
{
  if (ArvBin == NULL)
  {
    return 0;
  }
  // Aqui, as funcoes recursivas irao chamar
  // todos os elementos para serem liberados
  // da memoria, e o 'ArvBin == NULL' para a funcao
  liberarArvBin(raiz->esq);
  liberarArvBin(raiz->dir);
  free(ArvBin);
  ArvBin == NULL;
}

void destruirArvore(ArvBin *raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  liberarArvBin(*raiz); // libera cada ArvBin inserido
  free(raiz);           // remove a raiz da memória
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