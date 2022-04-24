/*
Carlos Souza
Matricula: 2021002252
Turma III - Engenharia de Software
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>

typedef struct TNO
{
  char letra;
  struct TNO *esquerda;
  struct TNO *direita;
} NO; // Criacao de um novo tipo de dado chamado: NO

// Principais Funcoes
void criarArvore(NO **p_raiz);
void inserir(NO **p_raiz, char p_elemento);
int contarNO(NO *p_raiz);
int contarFolhas(NO *p_raiz);
int alturaArvore(NO *p_raiz);
int pesquisar(NO *p_raiz, char p_elemento);

// Fucoes complementares para as principais
void obterDados(char *p_elemento);
char maior(char valor1, char valor2);

//*** Para Remover NO ***
NO *remover(NO *p_raiz, char p_elemento);
NO *desalocarArvore(NO *p_raiz);
//***********************

// Exibir elementos em alguma ordem
void exibirPreOrdem(NO *p_raiz);
void exibirEmOrdem(NO *p_raiz);
void exibirPosOrdem(NO *p_raiz);

// Exibir todos os elementos da arvore binaria de forma hierarquica.
void exibirArvore(NO *p_raiz, int p_coluna, int p_linha);
void exibirArvoreEsquerda(NO *p_raiz, int p_coluna, int p_linha);
void exibirArvoreDireita(NO *p_raiz, int p_coluna, int p_linha);

// para Arvore em AVL
int calcFB(NO *p_raiz);
NO *balancearArvore(NO *p_raiz);
NO *girarPraEsquerda(NO *p_raiz);
NO *girarPraDireita(NO *p_raiz);

// Programas para configurar sistema
void menu();
void configurarAmbiente();
void gotoxy(int coluna, int linha);
void limparLinha(int linha);
int ObterOpcaoMenu();

// Programa Principal
int main()
{
  configurarAmbiente();
  menu();
} // Fim programa.

void menu()
{
  NO *raiz;
  int opcao;

  int fb = 0;
  int qtdNO = 0;
  int altura = 0;
  int qtdFolha = 0;
  char elemento = '0';
  char elemPesq = '0';

  // Inicializar o ponteiro da arvore binaria
  criarArvore(&raiz);

  for (;;) // Indica uma repeticao (loop) INFINITO
  {
    system("cls");
    opcao = ObterOpcaoMenu();
    switch (opcao)
    {
    case 1:
      system("cls");
      getchar();
      obterDados(&elemento);
      inserir(&raiz, elemento);
      break;

    case 2:
      system("cls");
      exibirArvore(raiz, 60, 2);

      limparLinha(25);
      gotoxy(3, 25);
      printf("Pre-Ordem:");
      exibirPreOrdem(raiz);

      limparLinha(30);
      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 3:
      system("cls");
      exibirArvore(raiz, 60, 2);

      limparLinha(25);
      gotoxy(3, 25);
      printf("Em Ordem:");
      exibirEmOrdem(raiz);

      limparLinha(30);
      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 4:
      system("cls");
      exibirArvore(raiz, 60, 2);

      limparLinha(25);
      gotoxy(3, 25);
      printf("P?s-Ordem:");
      exibirPosOrdem(raiz);

      limparLinha(30);
      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 5:
      qtdNO = contarNO(raiz);
      limparLinha(25);
      gotoxy(5, 25);
      printf("Quantidade de NO da arvore binaria: %d", qtdNO);
      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 6:
      altura = alturaArvore(raiz);
      limparLinha(25);
      gotoxy(5, 25);
      printf("Altura da arvore binaria: %d", altura);
      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 7:
      qtdFolha = contarFolhas(raiz);
      limparLinha(25);

      gotoxy(5, 25);
      printf("Quantidade de Folha(s) da arvore binaria: %d", qtdFolha);

      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 8:
      // Limpa a tela
      system("cls");
      getchar();

      obterDados(&elemento);
      raiz = remover(raiz, elemento);
      break;

    case 9:
      system("cls");
      getchar();

      obterDados(&elemento);
      elemPesq = pesquisar(raiz, elemento);
      limparLinha(20);

      if (elemPesq > 0)
      {
        gotoxy(5, 20);
        printf("Elemento Encontrado");
      }
      else
      {
        gotoxy(5, 20);
        printf("Elemento NAO Encontrado!!!");
      }
      getchar();
      getchar();
      break;

    case 10:
      system("cls");
      getchar();
      fb = calcFB(raiz);
      gotoxy(5, 25);
      printf("Valor do FB: %d", fb);
      gotoxy(5, 30);
      if (fb == 1 || fb == -1 || fb == 0)
      {
        printf("Essa arvore eh balanceada");
      }
      else
      {
        printf("Essa arvore Nao eh balanceada");
      }
      gotoxy(5, 35);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 11:
      system("cls");
      raiz = desalocarArvore(raiz);

      limparLinha(20);
      gotoxy(5, 20);
      printf("Mensagem: Programa Finalizado.");
      exit(EXIT_SUCCESS);

    default:
      limparLinha(20);
      gotoxy(5, 20);
      printf("Mensagem: Opcao Invalida.");
      getchar();
      getchar();
    } // switch
  }   // for
}

int ObterOpcaoMenu()
{
  int opcao;
  gotoxy(40, 5);
  printf("***************************************");
  gotoxy(40, 6);
  printf("*         Arvore Binaria              *");
  gotoxy(40, 7);
  printf("***************************************");
  gotoxy(40, 8);
  printf("*             Menu                    *");
  gotoxy(40, 9);
  printf("***************************************");
  gotoxy(40, 10);
  printf("* [1] - Inserir                       *");
  gotoxy(40, 11);
  printf("* [2] - Exibir Pre-ordem              *");
  gotoxy(40, 12);
  printf("* [3] - Exibir Em Ordem               *");
  gotoxy(40, 13);
  printf("* [4] - Exibir Pos-Ordem              *");
  gotoxy(40, 14);
  printf("* [5] - Contar Nro de NO              *");
  gotoxy(40, 15);
  printf("* [6] - Calcular altura da arvore     *");
  gotoxy(40, 16);
  printf("* [7] - Calcular quantidade de Folhas *");
  gotoxy(40, 17);
  printf("* [8] - Remover                       *");
  gotoxy(40, 18);
  printf("* [9] - Pesquisar                     *");
  gotoxy(40, 19);
  printf("* [10] - Calcular FB                  *");
  gotoxy(40, 20);
  printf("* [11] - Sair                         *");
  gotoxy(40, 21);
  printf("***************************************");
  gotoxy(40, 22);
  printf("Entre com a opcao = ");
  scanf("%d", &opcao);
  return opcao;
}

void obterDados(char *p_elemento)
{
  // Limpar a tela
  system("cls");
  gotoxy(40, 5);
  printf("************************************");
  gotoxy(40, 6);
  printf("*       Entrada de Dados           *");
  gotoxy(40, 7);
  printf("************************************");
  gotoxy(40, 10);
  printf("Entre com o valor do Elemento: ");
  scanf("%c", p_elemento);
}

void criarArvore(NO **p_raiz)
{
  *p_raiz = NULL;
}

void inserir(NO **p_raiz, char p_elemento)
{
  if (*p_raiz == NULL)
  {
    // Aloca memoria para a estrutura NO.
    *p_raiz = (NO *)malloc(sizeof(NO));
    // Atribui os valores para os campos da estrutura NO da Arvore.
    (*p_raiz)->esquerda = NULL;
    (*p_raiz)->direita = NULL;
    (*p_raiz)->letra = p_elemento;
  }
  else
  {

    if (p_elemento < ((*p_raiz)->letra))
    {
      inserir(&((*p_raiz)->esquerda), p_elemento);
    }
    else
    {
      inserir(&((*p_raiz)->direita), p_elemento);
    }
  }

  (*p_raiz) = balancearArvore(*p_raiz);
}

int calcFB(NO *p_raiz)
{
  if (p_raiz == NULL)
  {
    return 0;
  }
  else
  {
    return alturaArvore(p_raiz->esquerda) - alturaArvore(p_raiz->direita);
  }
}

NO *balancearArvore(NO *p_raiz)
{
  if (p_raiz == NULL)
  {
    return NULL;
  }

  if (alturaArvore(p_raiz->esquerda) - alturaArvore(p_raiz->direita) == 2)
  {
    if (alturaArvore(p_raiz->esquerda->esquerda) - alturaArvore(p_raiz->esquerda->direita) == -1)
    {
      p_raiz->esquerda = girarPraEsquerda(p_raiz->esquerda);
    }
    p_raiz = girarPraDireita(p_raiz);
  }

  else if (alturaArvore(p_raiz->esquerda) - alturaArvore(p_raiz->direita) == -2)
  {
    if (alturaArvore(p_raiz->direita->esquerda) - alturaArvore(p_raiz->direita->direita) == 1)
    {
      p_raiz->direita = girarPraDireita(p_raiz->direita);
    }
    p_raiz = girarPraEsquerda(p_raiz);
  }

  else if (p_raiz->esquerda != NULL && p_raiz->direita != NULL)
  {
    p_raiz->esquerda = balancearArvore(p_raiz->esquerda);
    p_raiz->direita = balancearArvore(p_raiz->direita);
  }

  return p_raiz;
}

NO *girarPraEsquerda(NO *p_raiz)
{
  NO *y;
  NO *T2;

  // Pra executar a rotacao
  y = p_raiz->direita;
  T2 = y->esquerda;

  p_raiz->direita = T2;
  y->esquerda = p_raiz;

  // Retornar nova raiz
  return y;
}

NO *girarPraDireita(NO *p_raiz)
{
  NO *x;
  NO *T2;

  // Pra executar a rotacao
  T2 = p_raiz->esquerda;
  x = T2->direita;

  p_raiz->esquerda = x;
  T2->direita = p_raiz;

  // Retornar nova raiz
  return T2;
}

void exibirPreOrdem(NO *p_raiz)
{

  if (p_raiz != NULL)
  {
    printf(" (%c) ", p_raiz->letra);
    exibirPreOrdem(p_raiz->esquerda);
    exibirPreOrdem(p_raiz->direita);
  }
}

void exibirEmOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    exibirEmOrdem(p_raiz->esquerda);
    printf(" (%c) ", p_raiz->letra);
    exibirEmOrdem(p_raiz->direita);
  }
}

void exibirPosOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    exibirPosOrdem(p_raiz->esquerda);
    exibirPosOrdem(p_raiz->direita);
    printf(" (%c) ", p_raiz->letra);
  }
}

void exibirArvore(NO *p_raiz, int p_coluna, int p_linha)
{

  if (p_raiz != NULL)
  {
    gotoxy(p_coluna, p_linha);
    printf("(%c)", p_raiz->letra);
    exibirArvoreEsquerda(p_raiz->esquerda, (p_coluna - (p_coluna / 2)), p_linha + 3);
    exibirArvoreDireita(p_raiz->direita, (p_coluna + (p_coluna / 2)), p_linha + 3);
  }
  else
  {
    gotoxy(50, 5);
    printf("Arvore Binaria vazia!!!");
  }
}

void exibirArvoreEsquerda(NO *p_raiz, int p_coluna, int p_linha)
{

  if (p_raiz != NULL)
  {
    // Exibir Sub-Arvore Esquerda
    gotoxy(p_coluna, p_linha);
    printf("(%c)", p_raiz->letra);
    exibirArvoreEsquerda(p_raiz->esquerda, p_coluna - 10, p_linha + 3);
    exibirArvoreEsquerda(p_raiz->direita, p_coluna + 10, p_linha + 3);
  }
}

void exibirArvoreDireita(NO *p_raiz, int p_coluna, int p_linha)
{

  if (p_raiz != NULL)
  {
    gotoxy(p_coluna, p_linha);
    printf("(%c)", p_raiz->letra);
    exibirArvoreDireita(p_raiz->esquerda, p_coluna - 10, p_linha + 3);
    exibirArvoreDireita(p_raiz->direita, p_coluna + 10, p_linha + 3);
  }
}

int contarNO(NO *p_raiz)
{
  if (p_raiz == NULL)
    return 0;
  else
    return 1 + contarNO(p_raiz->esquerda) + contarNO(p_raiz->direita);
}

char maior(char valor1, char valor2)
{
  if (valor1 > valor2)
    return valor1;
  else
    return valor2; // Retorna maior ou igual
} // maior

int alturaArvore(NO *p_raiz)
{
  if ((p_raiz == NULL) || (p_raiz->esquerda == NULL && p_raiz->direita == NULL))
    return 0;
  else
    return 1 + maior(alturaArvore(p_raiz->esquerda), alturaArvore(p_raiz->direita));
}

int pesquisar(NO *p_raiz, char p_elemento)
{
  if (p_raiz == NULL)
  {
    return 0;
  }
  else if (p_raiz->letra > p_elemento)
  {
    return pesquisar(p_raiz->esquerda, p_elemento);
  }
  else if (p_raiz->letra < p_elemento)
  {
    return pesquisar(p_raiz->direita, p_elemento);
  }
  else
  {
    return 1;
  }
}

int contarFolhas(NO *p_raiz)
{
  if (p_raiz == NULL)
    return 0;
  if (p_raiz->esquerda == NULL && p_raiz->direita == NULL)
  {
    return 1;
  }

  return contarFolhas(p_raiz->esquerda) + contarFolhas(p_raiz->direita);
}

NO *remover(NO *p_raiz, char p_elemento)
{
  if (p_raiz == NULL)
    return NULL;
  else if (p_raiz->letra > p_elemento)
    p_raiz->esquerda = remover(p_raiz->esquerda, p_elemento);
  else if (p_raiz->letra < p_elemento)
    p_raiz->direita = remover(p_raiz->direita, p_elemento);
  else
  { /* achou o no para remover */
    /* no sem filhos */
    if (p_raiz->esquerda == NULL && p_raiz->direita == NULL)
    {
      free(p_raiz);
      p_raiz = NULL;
    }
    /* no soh tem filho a direita */
    else if (p_raiz->esquerda == NULL)
    {
      NO *t = p_raiz;
      p_raiz = p_raiz->direita;
      free(t);
    }
    /* soh tem filho a esquerda */
    else if (p_raiz->direita == NULL)
    {
      NO *t = p_raiz;
      p_raiz = p_raiz->esquerda;
      free(t);
    }
    /* no tem os dois filhos */
    else
    {
      NO *f = p_raiz->esquerda;
      while (f->direita != NULL)
      {
        f = f->direita;
      }
      p_raiz->letra = f->letra; /* troca as informacoes */
      f->letra = p_elemento;
      p_raiz->esquerda = remover(p_raiz->esquerda, p_elemento);
    }
  }
  return p_raiz;
}

NO *desalocarArvore(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    desalocarArvore(p_raiz->esquerda); /* libera subarvore esquerda */
    desalocarArvore(p_raiz->direita);  /* libera subarvore direita  */
    free(p_raiz);                      /* libera raiz */
  }
  return NULL;
}

void configurarAmbiente()
{
  system("cls");
  setlocale(LC_ALL, "Portuguese");
  system("color 1F");
}

void gotoxy(int coluna, int linha)
{
  COORD point;
  point.X = coluna;
  point.Y = linha;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void limparLinha(int linha)
{
  int i;
  for (i = 0; i < 100; i++)
  {
    gotoxy(i, linha);
    printf(" ");
  }
}