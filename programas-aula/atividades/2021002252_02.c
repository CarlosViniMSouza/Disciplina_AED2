/*
Carlos Souza
Matricula: 2021002252
Turma III - Algoritmo e Estrutura de Dados II
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
} NO; // NO: criacao de um novo tipo de dado chamado NO

// OBS: A arvore sera chamada pelo seu No principal: raiz

void criarArvore(NO **p_raiz);
void inserir(NO **p_raiz, char p_elemento, int coluna, int linha);
void exibirPreOrdem(NO *p_raiz, int p_coluna);
void exibirEmOrdem(NO *p_raiz, int p_coluna);
void exibirPosOrdem(NO *p_raiz, int p_coluna);
void obterDados(char *p_elemento);
void gotoxy(int coluna, int linha);
void limparLinha(int linha);
int contarNo(NO *p_raiz);
int maior(int valor1, int valor2);
int calcularAltura(NO *p_raiz);
int contarFolha(NO *p_raiz);
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
  int qtdNO = 0;
  int qtdFolha = 0;
  int altura = 0;
  // Declarar um ponteiro para a estrutura de
  // uma arvore binaria do tipo NO chamada raiz.
  NO *raiz;
  char elemento = '0';

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
      inserir(&raiz, elemento, 60, 2);
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
      limparLinha(25);
      gotoxy(40, 16);
      printf("Quantidade de NOs = %d", qtdNO);
      gotoxy(40, 18);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 6:
      system("cls");
      altura = calcularAltura(raiz);
      limparLinha(25);
      gotoxy(40, 16);
      printf("A altura da arvore = %d", altura);
      gotoxy(40, 18);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 7:
      system("cls");
      folha = contarFolha(raiz);
      limparLinha(25);
      gotoxy(40, 16);
      printf("Quantidade de Folhas = %d", folha);
      gotoxy(40, 18);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 8:
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
  printf("* [5] - Contagem de Nos            *");
  gotoxy(40, 15);
  printf("* [6] - Calcular Altura            *");
  gotoxy(40, 16);
  printf("* [7] - Contagem de Folhas         *");
  gotoxy(40, 17);
  printf("* [8] - Sair                       *");
  gotoxy(40, 18);
  printf("************************************");
  gotoxy(40, 20);
  printf("Entre com a opcao = ");
  scanf("%d", &opcao);
  return opcao;
}

/*
Procedimento obterDados: Obtem o valor de um dado (elemento)
Parametros:
           1 - p_elemento : Parametro passado por referencia para obter o valor de um elemento.
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

void inserir(NO **p_raiz, char p_elemento, int coluna, int linha)
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
  }
  else
  {
    if (p_elemento < ((*p_raiz)->letra))
    {
      // Inserir o novo elemento na sub-arvore a esquerda recursivamente.
      inserir(&((*p_raiz)->esquerda), p_elemento, coluna - 15, linha + 2);
    }
    else
    {
      // Inserir o novo elemento na sub-arvore a direita recursivamente.
      inserir(&((*p_raiz)->direita), p_elemento, coluna + 15, linha + 2);
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

int maior(int valor1, int valor2)
{
  if (valor1 > valor2)
  {
    return valor1;
  }
  else
  {
    return valor2;
  }
}

int calcularAltura(NO *p_raiz)
{
  if (p_raiz == NULL || (p_raiz->esquerda) == NULL && (p_raiz->direita) == NULL)
  {
    return 0;
  }
  else
  {
    return 1 + maior(calcularAltura(p_raiz->esquerda), calcularAltura(p_raiz->direita));
  }
}

int contarFolha(NO *p_raiz)
{
  if (p_raiz == NULL)
  {
    return 0;
  }
  else
  {
    if ((p_raiz->esquerda) == NULL && (p_raiz->direita) == NULL)
    {
      return 1;
    }
    else
    {
      return contarFolha(p_raiz->esquerda) + contarFolha(p_raiz->direita);
    }
  }
}

// Procedimento para configurar o ambiente do programa
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

// Atividade 03 -> feita
