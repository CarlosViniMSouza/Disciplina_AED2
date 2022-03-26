/*
Carlos Souza

Matricula: 2021002252
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

typedef struct TNO
{
  char letra;
  struct TNO *esquerda;
  struct TNO *direita;
  int coluna;
  int linha;
  int alt;
} NO; // NO: criacao de um novo tipo de dado chamado NO

// OBS: A arvore sera chamada pelo seu No principal: raiz

void criarArvore(NO **p_raiz);
void inserir(NO **p_raiz, char p_elemento, int coluna, int linha, int alt);
void exibirPreOrdem(NO *p_raiz, int p_coluna);
void exibirEmOrdem(NO *p_raiz, int p_coluna);
void exibirPosOrdem(NO *p_raiz, int p_coluna);
void obterDados(char *p_elemento);
void gotoxy(int coluna, int linha);
void limparLinha(int linha);
int contarNo(NO *raiz);
int calcularAltura(NO *raiz, int *altAltura);
void menu();
int ObterOpcaoMenu();
void configurarAmbiente();

// Programa Principal
int main()
{
  configurarAmbiente();
  menu();
} // Fim programa.

void menu()
{
  int opcao;
  NO *raiz;
  char elemento = '.';
  int qtdNO = 0;
  int altAltura = 0;
  criarArvore(&raiz);

  for (;;)
  {
    system("cls");
    opcao = ObterOpcaoMenu();
    switch (opcao)
    {
    case 1:
      getchar();
      obterDados(&elemento);
      inserir(&raiz, elemento, 60, 2, 0);
      break;

    case 2:
      system("cls");
      exibirPreOrdem(raiz, 2);
      limparLinha(25);
      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 3:
      system("cls");
      exibirEmOrdem(raiz, 2);
      limparLinha(25);
      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 4:
      system("cls");
      exibirPosOrdem(raiz, 2);
      limparLinha(25);
      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 5:
      system("cls");
      qtdNO = contarNo(raiz);
      gotoxy(5, 25);
      printf("Quantidade de NOs = %d", qtdNO);
      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 6:
      system("cls");
      calcularAltura(raiz, &altAltura);
      gotoxy(5, 25);
      printf("A altura da arvore eh = %d", altAltura);
      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 7:
      limparLinha(20);
      gotoxy(5, 20);
      printf("Mensagem: Programa Finalizado.");
      exit(EXIT_SUCCESS); // Finaliza o programa com Sucesso.

    default:
      limparLinha(20);
      gotoxy(5, 20);
      printf("Mensagem: Opcao Invalida.");
    } // switch
  }   // for
}

int ObterOpcaoMenu()
{
  int opcao;
  gotoxy(40, 5);
  printf("************************************");
  gotoxy(40, 6);
  printf("*         Arvore Binaria           *");
  gotoxy(40, 7);
  printf("************************************");
  gotoxy(40, 8);
  printf("*             Menu                 *");
  gotoxy(40, 9);
  printf("************************************");
  gotoxy(40, 10);
  printf("* [1] - Inserir                    *");
  gotoxy(40, 11);
  printf("* [2] - Exibir Pre-ordem           *");
  gotoxy(40, 12);
  printf("* [3] - Exibir Em Ordem            *");
  gotoxy(40, 13);
  printf("* [4] - Exibir Pos-Ordem           *");
  gotoxy(40, 14);
  printf("* [5] - Contagem de Nos	           *");
  gotoxy(40, 15);
  printf("* [6] - Calcular Altura	           *");
  gotoxy(40, 16);
  printf("* [7] - Sair                       *");
  gotoxy(40, 17);
  printf("************************************");
  gotoxy(40, 18);
  printf("Entre com a opcao = ");
  scanf("%d", &opcao);
  return opcao;
}

/*
Procedimento obterDados: Obtem o valor de um dado (elemento)
Par�metros:
           1 - p_elemento : Par�metro passado por refer�ncia para obter o valor de

                            um elemento.
*/
void obterDados(char *p_elemento)
{
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
  // OBS: NULL eh um valor que indica um endereco de memoria vazio valido.
  *p_raiz = NULL;
}

void inserir(NO **p_raiz, char p_elemento, int coluna, int linha, int alt)
{

  if (*p_raiz == NULL) // Verifica se a arvore esta vazia
  {
    // Aloca memoria para a estrutura NO.
    *p_raiz = (NO *)malloc(sizeof(NO));

    // Atribui os valores para os campos da estrutura NO da arvore.
    (*p_raiz)->esquerda = NULL;
    (*p_raiz)->direita = NULL;
    (*p_raiz)->letra = p_elemento;

    // Somente para visualizar os elementos da arvore binaria na tela
    (*p_raiz)->coluna = coluna;
    (*p_raiz)->linha = linha;
    (*p_raiz)->alt = alt;
  }
  else
  {
    if (p_elemento < ((*p_raiz)->letra))
    {
      // Inserir o novo elemento na sub-arvore a esquerda recursivamente.
      inserir(&((*p_raiz)->esquerda), p_elemento, coluna - 15, linha + 2, alt + 1);
    }
    else
    {
      // Inserir o novo elemento na sub-arvore a direita recursivamente.
      inserir(&((*p_raiz)->direita), p_elemento, coluna + 15, linha + 2, alt + 1);
    }
  }
}

void exibirPreOrdem(NO *p_raiz, int p_coluna)
{
  if (p_raiz != NULL)
  {
    // Montar a arvore binaria
    gotoxy(p_raiz->coluna, p_raiz->linha);
    printf("(%c)", p_raiz->letra);
    exibirPreOrdem(p_raiz->esquerda, p_coluna + 4);
    exibirPreOrdem(p_raiz->direita, p_coluna + 4);
  }
}

void exibirEmOrdem(NO *p_raiz, int p_coluna)
{
  if (p_raiz != NULL)
  {
    // Montar a arvore binaria
    exibirEmOrdem(p_raiz->esquerda, p_coluna + 4);
    gotoxy(p_raiz->coluna, p_raiz->linha);
    printf("(%c)", p_raiz->letra);
    exibirEmOrdem(p_raiz->direita, p_coluna + 4);
  }
}

void exibirPosOrdem(NO *p_raiz, int p_coluna)
{
  if (p_raiz != NULL)
  {
    // Montar a arvore binaria
    exibirPosOrdem(p_raiz->esquerda, p_coluna + 4);
    exibirPosOrdem(p_raiz->direita, p_coluna + 4);
    gotoxy(p_raiz->coluna, p_raiz->linha);
    printf("(%c)", p_raiz->letra);
  }
}

int contarNo(NO *p_raiz)
{
  if (p_raiz == NULL)
  {
    return 0;
  }
  else
  {
    return 1 + contarNo(p_raiz->esquerda) + contarNo(p_raiz->direita);
  }
}

int calcularAltura(NO *p_raiz, int *altAltura)
{
  if (p_raiz == NULL)
  {
    return 0;
  }
  else
  {

    if (p_raiz->alt > (*altAltura))
    {
      (*altAltura) = p_raiz->alt;
    }

    if (p_raiz->esquerda >= p_raiz->direita)
    {
      return calcularAltura(p_raiz->esquerda, altAltura);
    }
    else
    {
      return calcularAltura(p_raiz->direita, altAltura);
    }
  }
}

// Procedimento para configuar o ambiente do programa
void configurarAmbiente()
{
  system("cls");
  system("color 2F");
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
  for (i = 0; i < 80; i++)
  {
    gotoxy(i, linha);
    printf(" ");
  }
}
