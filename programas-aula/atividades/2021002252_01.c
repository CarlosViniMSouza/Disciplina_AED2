/* Carlos Souza */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

// Criar a estrutura NO
typedef struct TNO
{
  // Dado do NO
  char letra;
  // Ponteiro para o proximo NO da sub-arvore esquerda
  struct TNO *esquerda;
  // Ponteiro para o proximo NO da sub-arvore direita
  struct TNO *direita;
  // Somente para vizualizar melhor a exibicao dos elementos da arvore binaia
  int coluna;
  int linha;
} NO; // NO: criacao de um novo tipo de dado chamado NO

// OBS: A Arvore sera chamada pelo seu NO principal: raiz
void criarArvore(NO **p_raiz);
void inserir(NO **p_raiz, char p_elemento, int coluna, int linha);
void exibirPreOrdem(NO *p_raiz, int p_coluna);
void exibirEmOrdem(NO *p_raiz);
void exibirPosOrdem(NO *p_raiz);
void obterDados(char *p_elemento);
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

// Processa a opcao selecionada no Menu
void menu()
{
  int opcao;
  // Declarar um ponteiro para a estrutura de
  // uma Arvore binaria do tipo NO chamada raiz.
  NO *raiz;
  char elemento = '.';

  // Inicializar o ponteiro da Arvore binaria
  criarArvore(&raiz);

  for (;;)
  { // Indica uma repeticao (loop) INFINITO
    // Limpa a tela
    system("cls");
    opcao = ObterOpcaoMenu();
    switch (opcao)
    {
    case 1:
      // Obter o valor de um novo dado: elemento
      // Parametro passado por Referencia: &elemento
      getchar();
      obterDados(&elemento);
      inserir(&raiz, elemento, 60, 2);
      break;

    case 2:
      // Limpa a tela
      system("cls");
      // Exite todos os dados da arvore binaria em Pre-ordem.
      exibirPreOrdem(raiz, 2);
      limparLinha(25);
      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();

      break;

    case 3:
      // Exite todos os dados da arvore binaria em Pre-ordem.
      exibirEmOrdem(raiz);
      break;

    case 4:
      // Exite todos os dados da arvore binaria em Pre-ordem.
      exibirPosOrdem(raiz);
      break;

    case 5:
      // Para sair do programa deve-se
      // desalocar toda memï¿½ria alocada.
      limparLinha(20);
      gotoxy(5, 20);
      printf("Mensagem: Programa Finalizado.");
      // Finaliza o programa com Sucesso.
      exit(EXIT_SUCCESS);

    default:
      limparLinha(20);
      gotoxy(5, 20);
      printf("Mensagem: Opcao Invalida.");
    } // switch

  } // for
}

// Monta o Menu e obtem a opï¿½ï¿½o selecionada
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
Parï¿½metros:
           1 - p_elemento : Parï¿½metro passado por referï¿½ncia para obter o valor de

                            um elemento.
*/
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

/*
Procedimento criarArvore: Inicializa uma ï¿½rvore binï¿½ria vazia
Parï¿½metros:
           1 - **p_raiz  : Parï¿½metro passado por referï¿½ncia de ponteiro para ponteiro.
                           Representa o NO raiz da ï¿½rvore binï¿½ria.
*/
void criarArvore(NO **p_raiz)
{
  // OBS: NULL ï¿½ um valor que indica
  // um endereï¿½o de memï¿½ria vazio vï¿½lido.
  *p_raiz = NULL;
}

/*
Procedimento inserir: insere um novo elemento na ï¿½rvore binï¿½ria recursivamente.
Parï¿½metros:
           1 - **p_raiz  : Parï¿½metro passado por referï¿½ncia de ponteiro para ponteiro.
                           Representa o NO raiz da ï¿½rvore binï¿½ria.
           2 - p_elemento: Parï¿½metro passado por valor que representa o NOVO elemento
                           a ser inserido na ï¿½rbore binï¿½ria.
*/
void inserir(NO **p_raiz, char p_elemento, int coluna, int linha)
{
  if (*p_raiz == NULL) // Verifica se a ï¿½rvore estï¿½ vazia
  {
    // Aloca memï¿½ria para a estrutura NO.
    *p_raiz = (NO *)malloc(sizeof(NO));
    // Atribui os valores para os campos da estrutura NO da ï¿½rvore.
    (*p_raiz)->esquerda = NULL;
    (*p_raiz)->direita = NULL;
    (*p_raiz)->letra = p_elemento;
    // Somente para visualizar os elementos da ï¿½rvore binï¿½ria na tela
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

/*
Procedimento exibirPreOrdem: Exibe todos os elementos da ï¿½rvore binï¿½ria recursivamente na ordem: Prï¿½-ordem.
Parï¿½metros:
           **p_raiz  : Parï¿½metro passado por valor que indica o ponteiro para o NO RAIZ da ï¿½rvore binï¿½ria.
*/

void exibirPreOrdem(NO *p_raiz, int p_coluna)
{
  if (p_raiz != NULL)
  {
    // Montar a ï¿½rvore binï¿½ria
    gotoxy(p_raiz->coluna, p_raiz->linha);
    printf("%c", p_raiz->letra);
    // Exibir os elementos Prï¿½-ordem
    // gotoxy(p_coluna,28);
    // printf("(%d)", p_raiz->numero);
    exibirPreOrdem(p_raiz->esquerda, p_coluna + 4);
    exibirPreOrdem(p_raiz->direita, p_coluna + 4);
  }
}

/*
Procedimento exibirPreOrdem: Exibe todos os elementos da ï¿½rvore binï¿½ria recursivamente
                             na ordem: Em Ordem.
Parï¿½metros:
           **p_raiz  : Parï¿½metro passado por valor que indica o ponteiro
                       para o NO RAIZ da ï¿½rvore binï¿½ria.
*/
void exibirEmOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    exibirEmOrdem(p_raiz->esquerda);
    printf("\n%c", p_raiz->letra);
    exibirEmOrdem(p_raiz->direita);
  }
}

/*
Procedimento exibirPreOrdem: Exibe todos os elementos da ï¿½rvore binï¿½ria recursivamente
                             na ordem: Pï¿½s-ordem.
Parï¿½metros:
           **p_raiz  : Parï¿½metro passado por valor que indica o ponteiro
                       para o NO RAIZ da ï¿½rvore binï¿½ria.
*/
void exibirPosOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    exibirPosOrdem(p_raiz->esquerda);
    exibirPosOrdem(p_raiz->direita);
    printf("\n%c", p_raiz->letra);
  }
}

//****************************************
//** Funï¿½ï¿½es e Procedimentos Auxiliares **
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
