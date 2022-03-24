/*
Carlos Souza
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// Criar a estrutura NO
typedef struct TNO
{
  int numero;           // Dado do NO
  struct TNO *esquerda; // Ponteiro para o próximo NO da sub-arvore esquerda
  struct TNO *direita;  // Ponteiro para o próximo NO da sub-arvore direita
} NO;                   // NO: criação de um novo tipo de dado chamado NO

// OBS: A árvore será chamada pelo seu NÓ principal: raiz

void criarArvore(NO **p_raiz);
void inserir(NO **p_raiz, int p_elemento);
void exibirPreOrdem(NO *p_raiz);
void exibirEmOrdem(NO *p_raiz);
void exibirPosOrdem(NO *p_raiz);
void obterDados(int *p_elemento);
void menu();
void configurarAmbiente();
void limparLinha(int linha);
int ObterOpcaoMenu();

int main()
{
  configurarAmbiente();
  menu();
}

void menu()
{
  int opcao;
  NO *raiz;
  int elemento = 0;

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
      limparLinha(25);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();

      break;

    case 3:;
      system("cls");
      // Exite todos os dados da árvore binaria Em ordem.
      exibirEmOrdem(raiz);
      limparLinha(25);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 4:
      system("cls");
      // Exite todos os dados da árvore binaria em Pré-ordem.
      exibirPosOrdem(raiz);
      limparLinha(25);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 5:
      // Para sair do programa deve-se desalocar toda memória alocada.
      limparLinha(20);
      printf("Mensagem: Programa Finalizado.");
      exit(EXIT_SUCCESS); // Finaliza o programa com Sucesso.

    default:
      limparLinha(20);
      printf("Mensagem: Opção Inválida.");
    } // switch

  } // for
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
  printf("* [5] - Sair                       *\n");
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

/*
Procedimento criarArvore: Inicializa uma árvore binária vazia. Parâmetros:

1 - **p_raiz  : Parâmetro passado por referência de ponteiro para ponteiro.
                Representa o NO raiz da árvore binária.
*/

void criarArvore(NO **p_raiz)
{
  *p_raiz = NULL;
}

/*
Procedimento inserir: insere um novo elemento na árvore binária recursivamente. Parâmetros:

1 - **p_raiz  : Parâmetro passado por referência de ponteiro para ponteiro.
                Representa o NO raiz da árvore binária.

2 - p_elemento: Parâmetro passado por valor que representa o NOVO elemento
                a ser inserido na árbore binária.
*/

void inserir(NO **p_raiz, int p_elemento)
{
  if (*p_raiz == NULL) // Verifica se a árvore está vazia
  {
    *p_raiz = (NO *)malloc(sizeof(NO)); // Aloca memória para a estrutura NO.
    // Atribui os valores para os campos da estrutura NO da árvore.
    (*p_raiz)->esquerda = NULL;
    (*p_raiz)->direita = NULL;
    (*p_raiz)->numero = p_elemento;
  }
  else
  {
    if (p_elemento < ((*p_raiz)->numero))
    {
      // Inserir o novo elemento na sub-arvore a esquerda recursivamente.
      inserir(&((*p_raiz)->esquerda), p_elemento);
    }
    else
    {
      // Inserir o novo elemento na sub-arvore a direita recursivamente.
      inserir(&((*p_raiz)->direita), p_elemento);
    }
  }
}

/*
Procedimento exibirPreOrdem: Exibe todos os elementos da árvore binária recursivamente na ordem: Pré-ordem.

Parâmetros:

1 - **p_raiz  : Parâmetro passado por valor que indica o ponteiro para o NO RAIZ da árvore binária.
*/

void exibirPreOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    printf("(%d)", p_raiz->numero);
    exibirPreOrdem(p_raiz->esquerda);
    exibirPreOrdem(p_raiz->direita);
  }
}

/*
Procedimento exibirPreOrdem: Exibe todos os elementos da árvore binária recursivamente na ordem: Em Ordem.

Parâmetros:

1 - **p_raiz: Parâmetro passado por valor que indica o ponteiro para o NO RAIZ da árvore binária.
*/

void exibirEmOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    exibirEmOrdem(p_raiz->esquerda);
    printf("(%d)", p_raiz->numero);
    exibirEmOrdem(p_raiz->direita);
  }
}

/*
Procedimento exibirPreOrdem: Exibe todos os elementos da árvore binária recursivamente na ordem: Pós-ordem.

Parâmetros:

1 - **p_raiz  : Parâmetro passado por valor que indica o ponteiro para o NO RAIZ da árvore binária.
*/

void exibirPosOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    exibirPosOrdem(p_raiz->esquerda);
    exibirPosOrdem(p_raiz->direita);
    printf("(%d)", p_raiz->numero);
  }
}

// Procedimento para configuar o ambiente do programa
void configurarAmbiente()
{
  system("cls");
  system("color 2F"); // Alterar a cor do fundo da tela e a cor da fonte (fundo verde e fonte branca).
}

// Limpa o texto de uma determinada linha da tela
void limparLinha(int linha)
{
  int i;
  for (i = 0; i < 80; i++)
  {
    printf(" ");
  }
}