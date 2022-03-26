#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
  int info;
  struct NO *esq;
  struct NO *dir;
} ArvBin;

ArvBin *criarArvore();

int inserir(ArvBin *raiz, int valor);
int remover(ArvBin *raiz, int valor);
int consultar(ArvBin *raiz, int valor);
int altura(ArvBin *raiz);
int totalNO(ArvBin *raiz);

void ExibirPreOrdem(ArvBin *raiz);
void ExibirEmOrdem(ArvBin *raiz);
void ExibirPosOrdem(ArvBin *raiz);

int main()
{
  // Comentario
}
