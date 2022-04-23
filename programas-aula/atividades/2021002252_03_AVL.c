/*
Carlos Souza - Modificando para AVL
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

typedef struct TNO
{
  int numero;
  int alt;
  struct TNO *esquerda;
  struct TNO *direita;
} NO;

// Principais funcoes da arvore binaria
void criarArvore(NO **p_raiz);
void obterDados(int *p_elemento);
int contarNO(NO *p_raiz);
int contarFolhas(NO *p_raiz);
int alturaArvore(NO *p_raiz);
int maior(int valor1, int valor2);
int pesquisar(NO *p_raiz, int p_elemento);
NO *inserir(NO **p_raiz, int p_elemento);

// Para Remover NO
NO *remover(NO *p_raiz, int p_elemento);
NO *desalocarArvore(NO *p_raiz);

// Para definir a ordem de exibicao da arvore binaria:
void exibirPreOrdem(NO *p_raiz);
void exibirEmOrdem(NO *p_raiz);
void exibirPosOrdem(NO *p_raiz);

// Exibir todos os elementos da árvore binária de forma hierarquica.
void exibirArvore(NO *p_raiz, int p_coluna, int p_linha);
void exibirArvoreEsquerda(NO *p_raiz, int p_coluna, int p_linha);
void exibirArvoreDireita(NO *p_raiz, int p_coluna, int p_linha);

// Funcoes extras para AVL:
NO *girarPraEsquerda(NO *x);
NO *girarPraDireita(NO *y);
int obterFB(NO *p_raiz);

// Funcoes complementares para melhor funcionamento.
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
  int qtdNO = 0;
  int qtdFolha = 0;
  int altura = 0;
  int elemento = 0;
  char pesquisa = '0';

  // Inicializar o ponteiro da árvore binária
  criarArvore(&raiz);

  for (;;) // Indica uma repetição (loop) INFINITO
  {
    // Limpa a tela
    system("cls");
    opcao = ObterOpcaoMenu();
    switch (opcao)
    {
    case 1:
      // Obter o valor de um novo dado: elemento
      // Parâmetro passado por Referência: &elemento
      obterDados(&elemento);
      inserir(&raiz, elemento);
      break;

    case 2:
      system("cls");
      exibirArvore(raiz, 60, 2);

      limparLinha(25);
      gotoxy(3, 25);
      printf("Pré-Ordem:");
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
      printf("Pós-Ordem:");
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
      obterDados(&elemento);
      // Remover um elmento na árvore binária
      raiz = remover(raiz, elemento);
      break;

    case 9:
      system("cls");
      getchar();
      obterDados(&elemento);

      pesquisa = pesquisar(raiz, elemento);
      limparLinha(20);

      if (pesquisa > 0)
      {
        gotoxy(5, 20);
        printf("Elemento encontrado!");
      }
      else
      {
        gotoxy(5, 20);
        printf("Elemento NAO encontrado!");
      }
      getchar();
      getchar();
      break;

    case 10:
      raiz = desalocarArvore(raiz);

      limparLinha(20);
      gotoxy(5, 20);
      printf("Mensagem: Programa Finalizado.");
      // Finaliza o programa com Sucesso.
      exit(EXIT_SUCCESS);

    default:
      limparLinha(20);
      gotoxy(5, 20);
      printf("Mensagem: Opcao Invalida.");
      getchar();
      getchar();
    } // switch

  } // for
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
  printf("* [10] - Sair                         *");
  gotoxy(40, 20);
  printf("***************************************");
  gotoxy(40, 21);
  printf("Entre com a opcao = ");
  scanf("%d", &opcao);
  return opcao;
}

void obterDados(int *p_elemento)
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
  scanf("%d", p_elemento);
}

void criarArvore(NO **p_raiz)
{
  *p_raiz = NULL;
}

// Funcoes que irao balancear a Arvore Binaria (AVL):
NO *girarPraEsquerda(NO *x)
{ // Aqui, x = p_raiz
  NO *y = x->direita;
  NO *T2 = y->esquerda;

  // Pra executar a rotacao
  y->esquerda = x;
  x->direita = T2;

  // Atualizar alturas
  x->alt = 1 + maior(alturaArvore(x->esquerda), alturaArvore(x->direita));
  y->alt = 1 + maior(alturaArvore(y->esquerda), alturaArvore(y->direita));

  // Retornar nova raiz
  return y;
}

NO *girarPraDireita(NO *y)
{ // aqui, y = p_raiz
  NO *x = y->esquerda;
  NO *T2 = x->direita;

  // Pra executar rotacao
  x->direita = y;
  y->esquerda = T2;

  // Atualizar alturas
  y->alt = 1 + maior(alturaArvore(y->esquerda), alturaArvore(y->direita));
  x->alt = 1 + maior(alturaArvore(x->esquerda), alturaArvore(x->direita));

  // Retornar nova raiz
  return x;
}

int obterFB(NO *p_raiz)
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

NO *inserir(NO **p_raiz, int p_elemento)
{
  if (*p_raiz == NULL)
  {
    // Aloca memória para a estrutura NO.
    *p_raiz = (NO *)malloc(sizeof(NO));
    // Atribui os valores para os campos da estrutura NO da árvore.
    (*p_raiz)->numero = p_elemento;
    (*p_raiz)->esquerda = NULL;
    (*p_raiz)->direita = NULL;
    (*p_raiz)->alt = 1;

    return (*p_raiz);
  }
  else
  {
    if (p_elemento < ((*p_raiz)->numero))
    {
      // Inserir o novo elemento na sub-arvore esquerda recursivamente.
      (*p_raiz)->esquerda = inserir(&((*p_raiz)->esquerda), p_elemento);
    }

    else if (p_elemento > ((*p_raiz)->numero))
    {
      // Inserir o novo elemento na sub-arvore direita recursivamente.
      (*p_raiz)->direita = inserir(&((*p_raiz)->direita), p_elemento);
    }

    else
    {
      return (*p_raiz);
    }
  }

  // Atualizar altura do No raiz
  (*p_raiz)->alt = 1 + maior(alturaArvore((*p_raiz)->esquerda), alturaArvore((*p_raiz)->direita));

  // Obtenha o fator de equilíbrio do No raiz para
  // Verificar se este No se tornou desequilibrado
  int fb = obterFB((*p_raiz));

  // Se este nó ficar desbalanceado, então existem 4 casos

  // 1 - Caso Esquerda Esquerda
  if (fb > 1 && p_elemento < ((*p_raiz)->esquerda)->numero)
  {
    return girarPraDireita((*p_raiz));
  }

  // 2 - Caso Direita Direita
  if (fb < -1 && p_elemento > ((*p_raiz)->direita)->numero)
  {
    return girarPraEsquerda((*p_raiz));
  }

  // 3 - Caso Esquerda Direita
  if (fb > 1 && p_elemento > ((*p_raiz)->esquerda)->numero)
  {
    (*p_raiz)->esquerda = girarPraEsquerda((*p_raiz)->esquerda);
    return girarPraDireita((*p_raiz));
  }

  // 4 - Caso Direita Esquerda
  if (fb < -1 && p_elemento < ((*p_raiz)->direita)->numero)
  {
    (*p_raiz)->direita = girarPraDireita((*p_raiz)->direita);
    return girarPraEsquerda((*p_raiz));
  }

  // retornar o ponteiro do No (inalterado)
  return (*p_raiz);
}

void exibirPreOrdem(NO *p_raiz)
{

  if (p_raiz != NULL)
  {
    printf(" (%d) ", p_raiz->numero);
    exibirPreOrdem(p_raiz->esquerda);
    exibirPreOrdem(p_raiz->direita);
  }
}

void exibirEmOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    exibirEmOrdem(p_raiz->esquerda);
    printf(" (%d) ", p_raiz->numero);
    exibirEmOrdem(p_raiz->direita);
  }
}

void exibirPosOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    exibirPosOrdem(p_raiz->esquerda);
    exibirPosOrdem(p_raiz->direita);
    printf(" (%d) ", p_raiz->numero);
  }
}

void exibirArvore(NO *p_raiz, int p_coluna, int p_linha)
{

  if (p_raiz != NULL)
  {
    // Exibir o NO raiz da árvore binária
    gotoxy(p_coluna, p_linha);
    printf("(%d)", p_raiz->numero);
    exibirArvoreEsquerda(p_raiz->esquerda, (p_coluna - (p_coluna / 2)), p_linha + 3);
    exibirArvoreDireita(p_raiz->direita, (p_coluna + (p_coluna / 2)), p_linha + 3);
  }
  else
  {
    gotoxy(50, 5);
    printf("Árvore Binária vazia!!!");
  }
}

void exibirArvoreEsquerda(NO *p_raiz, int p_coluna, int p_linha)
{

  if (p_raiz != NULL)
  {
    // Exibir Sub-Árvore Esquerda
    gotoxy(p_coluna, p_linha);
    printf("(%d)", p_raiz->numero);
    exibirArvoreEsquerda(p_raiz->esquerda, p_coluna - 10, p_linha + 3);
    exibirArvoreEsquerda(p_raiz->direita, p_coluna + 10, p_linha + 3);
  }
}

void exibirArvoreDireita(NO *p_raiz, int p_coluna, int p_linha)
{

  if (p_raiz != NULL)
  {
    // Exibir Sub-Árvore Direita
    gotoxy(p_coluna, p_linha);
    printf("(%d)", p_raiz->numero);
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

int maior(int valor1, int valor2)
{
  if (valor1 > valor2)
    return valor1;
  else
    return valor2; // Retorna maior ou igual
}

int alturaArvore(NO *p_raiz)
{
  if ((p_raiz == NULL) || (p_raiz->esquerda == NULL && p_raiz->direita == NULL))
    return 0;
  else
    return 1 + maior(alturaArvore(p_raiz->esquerda), alturaArvore(p_raiz->direita));
}

int pesquisar(NO *p_raiz, int p_elemento)
{
  if (p_raiz == NULL)
  {
    return 0;
  }
  else if (p_raiz->numero > p_elemento)
  {
    return pesquisar(p_raiz->esquerda, p_elemento);
  }
  else if (p_raiz->numero < p_elemento)
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

NO *remover(NO *p_raiz, int p_elemento)
{
  if (p_raiz == NULL)
    return NULL;
  else if (p_raiz->numero > p_elemento)
    p_raiz->esquerda = remover(p_raiz->esquerda, p_elemento);
  else if (p_raiz->numero < p_elemento)
    p_raiz->direita = remover(p_raiz->direita, p_elemento);
  else
  { /* achou o nó a remover */
    /* nó sem filhos */
    if (p_raiz->esquerda == NULL && p_raiz->direita == NULL)
    {
      free(p_raiz);
      p_raiz = NULL;
    }
    /* nó só tem filho à direita */
    else if (p_raiz->esquerda == NULL)
    {
      NO *t = p_raiz;
      p_raiz = p_raiz->direita;
      free(t);
    }
    /* só tem filho à esquerda */
    else if (p_raiz->direita == NULL)
    {
      NO *t = p_raiz;
      p_raiz = p_raiz->esquerda;
      free(t);
    }
    /* nó tem os dois filhos */
    else
    {
      NO *f = p_raiz->esquerda;
      while (f->direita != NULL)
      {
        f = f->direita;
      }
      p_raiz->numero = f->numero; /* troca as informações */
      f->numero = p_elemento;
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

// Outras funcoes
void configurarAmbiente()
{
  // Limpa a tela
  system("cls");
  // Define o idioma dos textos para Portugues
  setlocale(LC_ALL, "Portuguese");
  // Alterar a cor do fundo da tela
  // e a cor da fonte (fundo azul e fonte branca).
  system("color 1F");
}

// Procedimento para posicionar o cursor na coordenada X,Y
// (Coluna(X),Linha(Y)) da tela.
void gotoxy(int coluna, int linha)
{
  COORD point;
  point.X = coluna;
  point.Y = linha;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

// Limpa o texto de uma determinada linha da tela
void limparLinha(int linha)
{
  int i;
  for (i = 0; i < 100; i++)
  {
    gotoxy(i, linha);
    printf(" ");
  }
}