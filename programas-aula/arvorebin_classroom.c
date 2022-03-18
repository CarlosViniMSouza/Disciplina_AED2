/*
Benevaldo Pereira Gonçalves
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
#include <windows.h>
#include <locale.h>

// Criar a estrutura NO
typedef struct TNO
{
  // Dado do NO
  int numero;
  // Ponteiro para o próximo NO da sub-arvore esquerda
  struct TNO *esquerda;
  // Ponteiro para o próximo NO da sub-arvore direita
  struct TNO *direita;
  // Somente para vizualizar melhor a exibição dos elementos da árvore binária
  int coluna;
  int linha;
} NO; // NO: criação de um novo tipo de dado chamado NO

// ATENÇÃO
// *  : Significa um ponteiro.
// ** : Significa um ponteiro que aponta
//      para outro ponteiro.

// OBS: A árvore será chamada pelo seu NÓ principal: raiz
void criarArvore(NO **p_raiz);
void inserir(NO **p_raiz, int p_elemento, int coluna, int linha);
void exibirPreOrdem(NO *p_raiz, int p_coluna);
void exibirEmOrdem(NO *p_raiz);
void exibirPosOrdem(NO *p_raiz);
void obterDados(int *p_elemento);
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

// Processa a opção selecionada no Menu
void menu()
{
  int opcao;
  // Declarar um ponteiro para a estrutura de
  // uma árvore binária do tipo NO chamada raiz.
  NO *raiz;
  int elemento = 0;

  // Inicializar o ponteiro da árvore binária
  criarArvore(&raiz);

  for (;;)
  { // Indica uma repetição (loop) INFINITO
    // Limpa a tela
    system("cls");
    opcao = ObterOpcaoMenu();
    switch (opcao)
    {
    case 1:
      // Obter o valor de um novo dado: elemento
      // Parâmetro passado por Referência: &elemento
      obterDados(&elemento);
      inserir(&raiz, elemento, 60, 2);
      break;

    case 2:
      // Limpa a tela
      system("cls");
      // Exite todos os dados da árvore binaria em Pré-ordem.
      exibirPreOrdem(raiz, 2);
      limparLinha(25);
      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
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
      limparLinha(20);
      gotoxy(5, 20);
      printf("Mensagem: Programa Finalizado.");
      // Finaliza o programa com Sucesso.
      exit(EXIT_SUCCESS);

    default:
      limparLinha(20);
      gotoxy(5, 20);
      printf("Mensagem: Opção Inválida.");
    } // switch

  } // for
}

// Monta o Menu e obtem a opção selecionada
int ObterOpcaoMenu()
{
  int opcao;
  gotoxy(40, 5);
  printf("************************************");
  gotoxy(40, 6);
  printf("*         Árvore Binária           *");
  gotoxy(40, 7);
  printf("************************************");
  gotoxy(40, 8);
  printf("*             Menu                 *");
  gotoxy(40, 9);
  printf("************************************");
  gotoxy(40, 10);
  printf("* [1] - Inserir                    *");
  gotoxy(40, 11);
  printf("* [2] - Exibir Pré-ordem           *");
  gotoxy(40, 12);
  printf("* [3] - Exibir Em Ordem            *");
  gotoxy(40, 13);
  printf("* [4] - Exibir Pós-Ordem           *");
  gotoxy(40, 14);
  printf("* [5] - Sair                       *");
  gotoxy(40, 15);
  printf("************************************");
  gotoxy(40, 16);
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

/*
Procedimento criarArvore: Inicializa uma árvore binária vazia
Parâmetros:
           1 - **p_raiz  : Parâmetro passado por referência de ponteiro para ponteiro.
                           Representa o NO raiz da árvore binária.
*/
void criarArvore(NO **p_raiz)
{
  // OBS: NULL é um valor que indica
  // um endereço de memória vazio válido.
  *p_raiz = NULL;
}

/*
Procedimento inserir: insere um novo elemento na árvore binária recursivamente.
Parâmetros:
           1 - **p_raiz  : Parâmetro passado por referência de ponteiro para ponteiro.
                           Representa o NO raiz da árvore binária.
           2 - p_elemento: Parâmetro passado por valor que representa o NOVO elemento
                           a ser inserido na árbore binária.
*/
void inserir(NO **p_raiz, int p_elemento, int coluna, int linha)
{
  if (*p_raiz == NULL) // Verifica se a árvore está vazia
  {
    // Aloca memória para a estrutura NO.
    *p_raiz = (NO *)malloc(sizeof(NO));
    // Atribui os valores para os campos da estrutura NO da árvore.
    (*p_raiz)->esquerda = NULL;
    (*p_raiz)->direita = NULL;
    (*p_raiz)->numero = p_elemento;
    // Somente para visualizar os elementos da árvore binária na tela
    (*p_raiz)->coluna = coluna;
    (*p_raiz)->linha = linha;
  }
  else
  {
    if (p_elemento < ((*p_raiz)->numero))
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

/*
Procedimento exibirPreOrdem: Exibe todos os elementos da árvore binária recursivamente
                             na ordem: Pré-ordem.
Parâmetros:
           **p_raiz  : Parâmetro passado por valor que indica o ponteiro
                       para o NO RAIZ da árvore binária.
*/
void exibirPreOrdem(NO *p_raiz, int p_coluna)
{
  if (p_raiz != NULL)
  {
    // Montar a árvore binária
    gotoxy(p_raiz->coluna, p_raiz->linha);
    printf("(%d)", p_raiz->numero);
    // Exibir os elementos Pré-ordem
    // gotoxy(p_coluna,28);
    // printf("(%d)", p_raiz->numero);
    exibirPreOrdem(p_raiz->esquerda, p_coluna + 4);
    exibirPreOrdem(p_raiz->direita, p_coluna + 4);
  }
}

/*
Procedimento exibirPreOrdem: Exibe todos os elementos da árvore binária recursivamente
                             na ordem: Em Ordem.
Parâmetros:
           **p_raiz  : Parâmetro passado por valor que indica o ponteiro
                       para o NO RAIZ da árvore binária.
*/
void exibirEmOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    exibirEmOrdem(p_raiz->esquerda);
    printf("\n%d", p_raiz->numero);
    exibirEmOrdem(p_raiz->direita);
  }
}

/*
Procedimento exibirPreOrdem: Exibe todos os elementos da árvore binária recursivamente
                             na ordem: Pós-ordem.
Parâmetros:
           **p_raiz  : Parâmetro passado por valor que indica o ponteiro
                       para o NO RAIZ da árvore binária.
*/
void exibirPosOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    exibirPosOrdem(p_raiz->esquerda);
    exibirPosOrdem(p_raiz->direita);
    printf("\n%d", p_raiz->numero);
  }
}

//****************************************
//** Funções e Procedimentos Auxiliares **
//****************************************

// Procedimento para configuar o
// ambiente do programa
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
  for (i = 0; i < 80; i++)
  {
    gotoxy(i, linha);
    printf(" ");
  }
}