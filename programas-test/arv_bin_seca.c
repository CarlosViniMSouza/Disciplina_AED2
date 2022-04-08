/*
Carlos Souza

Matricula: 2021002252

Turma III - Engenharia de Software
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct TNO
{
  int numero;           // Informacao do NO
  struct TNO *esquerda; // Ponteiro p/ o prox. NO da sub-arvore esquerda.
  struct TNO *direita;  // Ponteiro p/ o prox. NO da sub-arvore direita.
} NO;                   // Tipo de Dado Abstrato chamado 'NO'

// Funcoes chamadas no 'menu()'
void menu();
void inserir(NO **p_raiz, int p_elemento);
void obterDados(int *p_elemento);
void criarArvore(NO **p_raiz);
void exibirEmOrdem(NO *p_raiz);
void exibirPreOrdem(NO *p_raiz);
void exibirPosOrdem(NO *p_raiz);
char maiorValor(int v1, int v2);
int calcularAltura(NO *p_raiz);
int contarFolha(NO *p_raiz);
int contarNo(NO *p_raiz);
NO *deletarArvore(NO *p_raiz);

// Procedimentos auxiliares
void configAmb();
int ObterOpcaoMenu();
void limparLinha(int linha);

int main()
{
  configAmb();
  menu();
}

void menu()
{
  int opcao;
  int qtdNO = 0;
  int qtdFolha = 0;
  int altura = 0;
  int elemento = '0';

  NO *raiz; // Ponteiro pra Estrutura da Arvore do tipo NO chamada raiz.

  // Inicializar o ponteiro da Arvore binaria
  criarArvore(&raiz);

  for (;;)
  { // Indica uma repeticao (loop) INFINITO

    system("cls");
    opcao = ObterOpcaoMenu();
    switch (opcao)
    {
    case 1:
      system("cls");
      getchar();

      // Obter o valor de um novo dado: elemento
      // Parametro passado por Referencia: &elemento
      obterDados(&elemento);
      inserir(&raiz, elemento);
      break;

    case 2:
      system("cls");
      exibirPreOrdem(raiz);
      limparLinha(25);
      printf("\nPressione uma tecla para continuar.");
      getchar();
      getchar();

      break;

    case 3:;
      system("cls");
      // Exite todos os dados da arvore binaria Em ordem.
      exibirEmOrdem(raiz);
      limparLinha(25);
      printf("\nPressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 4:
      system("cls");
      // Exite todos os dados da arvore binaria em Pre-ordem.
      exibirPosOrdem(raiz);
      limparLinha(25);
      printf("\nPressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 5:
      system("cls");
      // Exibe a quant. de NOs existentes na arvore
      qtdNO = contarNo(raiz);
      limparLinha(25);
      printf("\nA quantidade de NOs = %d", qtdNO);
      getchar();
      getchar();
      break;

    case 6:
      system("cls");
      // Exibe a altura da nossa arvore
      altura = calcularAltura(raiz);
      limparLinha(25);
      printf("\nA altura da arvore = %d", altura);
      getchar();
      getchar();
      break;

    case 7:
      system("cls");
      // Exibe a quantidade de folhas existentes na arvore
      qtdFolha = contarFolha(raiz);
      limparLinha(25);
      printf("\nA quantidade de folhas = %d", qtdFolha);
      getchar();
      getchar();
      break;

    case 8:
      // Para sair do programa deve-se desalocar toda memoria alocada.
      system("cls");
      printf("Mensagem: Programa Finalizado.");
      exit(EXIT_SUCCESS); // Finaliza o programa com Sucesso.

    default:
      system("cls");
      printf("Mensagem: Opcao Invalida.");
    }
  }
}

// Monta o Menu e obtem a opcao selecionada
int ObterOpcaoMenu()
{
  int opcao;
  printf("************************************\n");
  printf("*             Menu                 *\n");
  printf("************************************\n");
  printf("* [1] - Inserir                    *\n");
  printf("* [2] - Exibir Pre-ordem           *\n");
  printf("* [3] - Exibir Em Ordem            *\n");
  printf("* [4] - Exibir Pos-Ordem           *\n");
  printf("* [5] - Calcular quant NOs         *\n");
  printf("* [6] - Calcular altura            *\n");
  printf("* [7] - Calcular quant Folhas      *\n");
  printf("* [8] - Sair                       *\n");
  printf("************************************\n");
  printf("Entre com a opcao = ");
  scanf("%d", &opcao);
  return opcao;
}

/*
Procedimento obterDados: Obtem o valor de um dado (elemento)

Parametros:

    1 - p_elemento : Parametro passado por referencia para obter o valor de um elemento.
*/

void obterDados(int *p_elemento)
{
  // Limpar a tela
  system("cls");
  printf("************************************\n");
  printf("*       Entrada de Dados           *\n");
  printf("************************************\n");
  printf("Entre com o valor do Elemento: ");
  scanf("%c", p_elemento);
}

void criarArvore(NO **p_raiz)
{
  *p_raiz = NULL;
}

void inserir(NO **p_raiz, int p_elemento)
{
  if (*p_raiz == NULL)
  {
    *p_raiz = (NO *)malloc(sizeof(NO));
    (*p_raiz)->esquerda = NULL;
    (*p_raiz)->direita = NULL;
    (*p_raiz)->numero = p_elemento;
  }
  else
  {
    if (p_elemento < ((*p_raiz)->numero))
    {
      inserir(&((*p_raiz)->esquerda), p_elemento);
    }
    else
    {
      inserir(&((*p_raiz)->direita), p_elemento);
    }
  }
}

void exibirPreOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    printf("(%c)", p_raiz->numero);
    exibirPreOrdem(p_raiz->esquerda);
    exibirPreOrdem(p_raiz->direita);
  }
}

void exibirEmOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    exibirEmOrdem(p_raiz->esquerda);
    printf("(%c)", p_raiz->numero);
    exibirEmOrdem(p_raiz->direita);
  }
}

void exibirPosOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    exibirPosOrdem(p_raiz->esquerda);
    exibirPosOrdem(p_raiz->direita);
    printf("(%c)", p_raiz->numero);
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

char maiorValor(int v1, int v2)
{
  if (v1 > v2)
    return v1;
  else
    return v2;
}

int calcularAltura(NO *p_raiz)
{
  if ((p_raiz == NULL) || (p_raiz->esquerda == NULL && p_raiz->direita == NULL))
  {
    return 0;
  }

  else
  {
    return 1 + maiorValor(calcularAltura(p_raiz->esquerda), calcularAltura(p_raiz->direita));
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
    if (p_raiz == NULL || (p_raiz->esquerda) == NULL && (p_raiz->direita) == NULL)
    {
      return 1;
    }
    else
    {
      return contarFolha(p_raiz->esquerda) + contarFolha(p_raiz->direita);
    }
  }
}

NO *deletarArvore(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    deletarArvore(p_raiz->direita);  // libera NOs da sub-arvore direita
    deletarArvore(p_raiz->esquerda); // libera NOs da sub-arvore esquerda
    free(p_raiz);                    // libera raiz da Arvore
  }

  return NULL;
}

void configurarAmbiente()
{
  system("cls");
  setlocale(LC_ALL, "Portuguese");
  system("color 1F");
}

void limparLinha(int linha)
{ // Limpar a tela
  int i;
  for (i = 0; i < 100; i++)
  {
    printf(" ");
  }
}

void configAmb()
{
  system("cls");
  setlocale(LC_ALL, "Portuguese");
  system("color 1F");
}
