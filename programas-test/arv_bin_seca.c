/*
Carlos Souza

Matricula: 2021002252

Turma III - Algoritmo e Estrutura de Dados II
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TNO
{
  int numero;
  struct TNO *esquerda;
  struct TNO *direita;
} NO;

void criarArvore(NO **p_raiz);
void obterDados(int *p_elemento);
void inserir(NO **p_raiz, int p_elemento);
void exibirPreOrdem(NO *p_raiz);
void exibirEmOrdem(NO *p_raiz);
void exibirPosOrdem(NO *p_raiz);
int contarNo(NO *p_raiz);
int calcularAltura(NO *p_raiz);
void menu();
int ObterOpcaoMenu();

int main()
{
  menu();
}

void menu()
{
  int opcao;
  NO *raiz;
  int elemento, quantNo, altura = 0;

  // Inicializar o ponteiro da árvore binária
  criarArvore(&raiz);

  for (;;)
  { // Indica uma repetição (loop) INFINITO

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

    case 2:;
      system("cls");
      // Exite todos os dados da árvore binaria em Pré-ordem.
      exibirPreOrdem(raiz);
      printf("\nPressione uma tecla para continuar.");
      getchar();
      getchar();

      break;

    case 3:;
      system("cls");
      // Exite todos os dados da árvore binaria Em ordem.
      exibirEmOrdem(raiz);
      printf("\nPressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 4:
      system("cls");
      // Exite todos os dados da árvore binaria em Pre-ordem.
      exibirPosOrdem(raiz);
      printf("\nPressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 5:
      system("cls");
      // Exibe a quant. de NOs existentes na arvore
      quantNo = contarNo(raiz);
      printf("\nA quantidade de NOs = %d", quantNo);
      getchar();
      getchar();
      break;

    case 6:
      system("cls");
      // Exibe a altura da nossa arvore
      altura = calcularAltura(raiz);
      printf("\nA altura da arvore = %d", (altura - 1));
      getchar();
      getchar();
      break;

    case 7:
      // Para sair do programa deve-se desalocar toda memória alocada.
      system("cls");
      printf("Mensagem: Programa Finalizado.");
      exit(EXIT_SUCCESS); // Finaliza o programa com Sucesso.

    default:
      system("cls");
      printf("Mensagem: Opção Inválida.");
    } // switch
  }   // for
}

// Monta o Menu e obtem a opção selecionada
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
  printf("* [7] - Sair                       *\n");
  printf("************************************\n");
  printf("Entre com a opcao = ");
  scanf("%d", &opcao);
  return opcao;
}

/*
Procedimento obterDados: Obtem o valor de um dado (elemento)
Parâmetros:
           1 - p_elemento : Parâmetro passado por referência para obter o valor de
                            um elemento.
*/

void obterDados(int *p_elemento)
{
  // Limpar a tela
  system("cls");
  printf("************************************\n");
  printf("*       Entrada de Dados           *\n");
  printf("************************************\n");
  printf("Entre com o valor do Elemento: ");
  scanf("%d", p_elemento);
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
    printf("(%d)", p_raiz->numero);
    exibirPreOrdem(p_raiz->esquerda);
    exibirPreOrdem(p_raiz->direita);
  }
}

void exibirEmOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    exibirEmOrdem(p_raiz->esquerda);
    printf("(%d)", p_raiz->numero);
    exibirEmOrdem(p_raiz->direita);
  }
}

void exibirPosOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    exibirPosOrdem(p_raiz->esquerda);
    exibirPosOrdem(p_raiz->direita);
    printf("(%d)", p_raiz->numero);
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

int calcularAltura(NO *p_raiz)
{
  int altEsq, altDir;

  if (p_raiz == NULL)
  {
    return 0;
  }
  else
  {
    altEsq = 1 + calcularAltura(p_raiz->esquerda);
    altDir = 1 + calcularAltura(p_raiz->direita);

    if (altEsq >= altDir)
    {
      return altEsq;
    }
    else
    {
      return altDir;
    }
  }
}