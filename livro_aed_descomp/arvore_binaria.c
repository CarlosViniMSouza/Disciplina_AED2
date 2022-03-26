#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
  int info;
  struct NO *no; // necessario para a funcao liberarNO()
  struct NO *esq;
  struct NO *dir;
} ArvBin;

// Referente a Arvore como um todo
ArvBin *criarArvore();
void destruirArvore(ArvBin *raiz);

// Referente aos elementos (NOs)
void liberarNO(ArvBin *no);
int inserir(ArvBin *raiz, int valor);
int remover(ArvBin *raiz, int valor);
int consultar(ArvBin *raiz, int valor);
int altura(ArvBin *raiz);
int totalNO(ArvBin *raiz);

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
    // O ponteiro da nossa raiz irá apontar p/ endereco NULL
    // Nossa raiz terá um local para onde apontar apos ser criada
    *raiz = NULL;
  }
  return raiz;
}

void liberarNO(ArvBin *no)
{
  if (no == NULL)
  {
    return 0;
  }
  // Aqui, as funcoes recursivas irao chamar
  // todos os elementos para serem liberados
  // da memoria, e o 'no == NULL' para a funcao
  liberarNO(raiz->esq);
  liberarNO(raiz->dir);
  free(no);
  no == NULL;
}

void destruirArvore(ArvBin *raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  liberarNO(*raiz); // libera cada NO inserido
  free(raiz);       // remove a raiz da memória
}

int totalNO(ArvBin *raiz)
{
  if (raiz == NULL || *raiz == NULL)
  {
    return 0;
  }
  int total_esq = totalNO(&((*raiz)->esq));
  int total_dir = totalNO(&((*raiz)->dir));
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
