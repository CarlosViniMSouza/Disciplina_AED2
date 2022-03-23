/*
Carlos Souza

Assunto: Árvore Binária
    1 - Estrutura do NO de uma árvore binária
    2 - Criação da Árvore Binária
    3 - Operação Incluir
    4 - Operação Exibir: Pré-ordem
    5 - Operação Exibir: Em Ordem
    6 - Operação Exibir: Pós-ordem
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// Criar a estrutura NO
typedef struct TNO
{
  // Dado do NO
  int numero;
  // Ponteiro para o próximo NO da sub-arvore esquerda
  struct TNO *esquerda;
  // Ponteiro para o próximo NO da sub-arvore direita
  struct TNO *direita;
} NO; // NO: criação de um novo tipo de dado chamado NO

// Declarando os procedimentos e funções:
void criarArvore(NO **p_raiz);
void inserir(NO **p_raiz, int p_elemento);
void exibirPreOrdem(NO *p_raiz);
void exibirEmOrdem(NO *p_raiz);
void exibirPosOrdem(NO *p_raiz);
void obterDados(int *p_elemento);
void menu();
int ObterOpcaoMenu();

// Programa Principal
int main()
{
  menu();
} // Fim programa.

// Processa a opção selecionada no Menu
void menu()
{
  int opcao;
  int elemento = 0;

  // OBS: A árvore será chamada pelo seu NÓ principal: raiz.
  // Declarar um ponteiro para a estrutura de uma árvore binária do tipo NO chamada raiz.
  NO *raiz;

  // Inicializar o ponteiro da árvore binária
  criarArvore(&raiz);

  for (;;)
  { // Indica uma repetição (loop) INFINITO
    // Limpa a tela
    opcao = ObterOpcaoMenu();
    switch (opcao)
    {
    case 1:
      // Obter o valor de um novo dado: elemento
      // Parâmetro passado por Referência: &elemento
      getchar();
      obterDados(&elemento);
      inserir(&raiz, elemento);
      break;

    case 2:
      // Limpa a tela

      // Exite todos os dados da árvore binaria em Pré-ordem.
      exibirPreOrdem(raiz);
      printf("Pressione uma tecla para continuar.");
      getchar();

      break;

    case 3:
      // Exite todos os dados da árvore binaria em Pré-ordem.
      exibirEmOrdem(raiz);
      break;

    case 4:
      // Exite todos os dados da árvore binaria em Pré-ordem.
      exibirPosOrdem(raiz);
      break;

    case 5:
      // Para sair do programa deve-se
      // desalocar toda memória alocada.
      printf("Mensagem: Programa Finalizado.");
      // Finaliza o programa com Sucesso.
      exit(EXIT_SUCCESS);

    default:
      printf("Mensagem: Opcao Invalida.");
    } // switch
  }   // for
}

// Monta o Menu e obtem a opção selecionada
int ObterOpcaoMenu()
{
  int opcao;
  system("cls");
  printf("************************************\n");
  printf("*         Arvore Binaria           *\n");
  printf("************************************\n");
  printf("*             Menu                 *\n");
  printf("************************************\n");
  printf("* [1] - Inserir                    *\n");
  printf("* [2] - Exibir Pre-ordem           *\n");
  printf("* [3] - Exibir Em Ordem            *\n");
  printf("* [4] - Exibir Pos-Ordem           *\n");
  printf("* [5] - Sair                       *\n");
  printf("************************************\n");
  printf("\nEntre com a opcao = ");
  scanf("%d", &opcao);
  return opcao;
}

/*
Procedimento obterDados: Obtem o valor de um dado (elemento). Parâmetros:

1 - p_elemento : Parâmetro passado por referência para obter o valor de um elemento.
*/

void obterDados(int *p_elemento)
{
  system("cls");
  printf("************************************\n");
  printf("*       Entrada de Dados           *\n");
  printf("************************************\n");
  printf("\nEntre com o valor do Elemento: ");
  scanf("%d", p_elemento);
}

/*
Procedimento criarArvore: Inicializa uma árvore binária vazia. Parâmetros:

1 - **p_raiz  : Parâmetro passado por referência de ponteiro para ponteiro.

Representa o NO raiz da árvore binária.
*/

void criarArvore(NO **p_raiz)
{
  // OBS: NULL é um valor que indica um endereço de memória vazio válido.
  *p_raiz = NULL;
}

/*
Procedimento inserir: insere um novo elemento na árvore binária recursivamente.

Parâmetros:

1 - **p_raiz  : Parâmetro passado por referência de ponteiro para ponteiro. Representa o NO raiz da árvore binária.

2 - p_elemento: Parâmetro passado por valor que representa o NOVO elemento a ser inserido na árbore binária.
*/
void inserir(NO **p_raiz, int p_elemento)
{
  if (*p_raiz == NULL) // Verifica se a árvore está vazia
  {
    // Aloca memória para a estrutura NO.
    *p_raiz = (NO *)malloc(sizeof(NO));
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
Procedimento exibirPreOrdem:

Exibe todos os elementos da árvore binária recursivamente na ordem: Pré-ordem.

Parâmetros:

1 - **p_raiz  : Parâmetro passado por valor que indica o ponteiro para o NO RAIZ da árvore binária.
*/

void exibirPreOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    getchar();
    // Montar a árvore binária
    printf("(%d)", p_raiz->numero);
    // Exibir os elementos Pré-ordem
    // gotoxy(p_coluna,28);
    // printf("(%d)", p_raiz->numero);
    exibirPreOrdem(p_raiz->esquerda);
    exibirPreOrdem(p_raiz->direita);
  }
}

/*
Procedimento exibirPreOrdem:

Exibe todos os elementos da árvore binária recursivamente na ordem: Em Ordem.

Parâmetros:

1 - **p_raiz  : Parâmetro passado por valor que indica o ponteiro para o NO RAIZ da árvore binária.
*/

void exibirEmOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    getchar();
    exibirEmOrdem(p_raiz->esquerda);
    printf("\n%d", p_raiz->numero);
    exibirEmOrdem(p_raiz->direita);
  }
}

/*
Procedimento exibirPreOrdem:

Exibe todos os elementos da árvore binária recursivamente na ordem: Pós-ordem.

Parâmetros:

1 - **p_raiz  : Parâmetro passado por valor que indica o ponteiro para o NO RAIZ da árvore binária.
*/

void exibirPosOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    getchar();
    exibirPosOrdem(p_raiz->esquerda);
    exibirPosOrdem(p_raiz->direita);
    printf("\n%d", p_raiz->numero);
  }
}
