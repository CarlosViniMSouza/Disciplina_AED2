/*
Carlos Souza
*/

/*
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

typedef struct TNO
{
  int numero;      // Dados armazenado no 'NO'
  struct TNO *esq; // Ponteiro que levará o numero para o prox. No da sub-arvore esquerda;
  struct TNO *dir; // Ponteiro que levará o numero para o prox. No da sub-arvore direita;
} NO;

// OBS: A árvore será chamada pelo seu NÓ principal: raiz

// declarando procedimentos e funcoes:
void criarArvore(NO **p_raiz);
void inserir(NO **p_raiz, int elem);
void exibirEmOrdem(NO *p_raiz);
void exibirPosOrdem(NO *p_raiz);
void exibirPreOrdem(NO *p_raiz);
void obterDados(int *elem);
int ObterOpcaoMenu();
void menu();
void configurarAmbiente();

/* Iremos desenvolver as outras partes no decorrer da caminhada */

int main()
{
  void configurarAmbiente();
  void menu();
}

void menu()
{
  int op;
  int elem = 0;
  NO *raiz;

  // Iniciar Arvore Binaria
  criarArvore(&raiz);

  // Iniciar no sistema de MENU da tela
  for (;;)
  { // Indica uma repetição (loop) INFINITO

    op = ObterOpcaoMenu();
    switch (op)
    {
    case 1:
      // Obter o valor de um novo dado: elemento
      // Parâmetro passado por Referência: &elemento
      obterDados(&elem);
      inserir(&raiz, elem, 60, 2);
      break;

    case 2:
      // Exite todos os dados da árvore binaria em Pré-ordem.
      exibirPreOrdem(raiz, 2);
      printf("Pressione uma tecla para continuar.");
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
      printf("Mensagem: Opção Inválida.");
    } // switch
  }   // for
}

int ObterOpcaoMenu()
{
  int opcao;
  printf("\n");
  printf("*         Árvore Binária           *");
  printf("\n");
  printf("*             Menu                 *");
  printf("\n");
  printf("* [1] - Inserir                    *");
  printf("* [2] - Exibir Pré-ordem           *");
  printf("* [3] - Exibir Em Ordem            *");
  printf("* [4] - Exibir Pós-Ordem           *");
  printf("* [5] - Sair                       *");
  printf("\n");
  printf("Entre com a opcao = ");
  scanf("%d", &opcao);
  return opcao;
}

void obterDados(int *elem)
{
  // Limpar a tela
  printf("\n");
  printf("*       Entrada de Dados           *");
  printf("\n");
  printf("Entre com o valor do Elemento: ");
  scanf("%d", elem);
}
