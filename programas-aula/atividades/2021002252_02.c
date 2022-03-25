/*
Carlos Souza

Matricula: 2021002252
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

// Criar a estrutura NO
typedef struct TNO
{
  // Dado do NO
  char letra;
  // Ponteiro para o pr�ximo NO da sub-arvore esquerda
  struct TNO *esquerda;
  // Ponteiro para o pr�ximo NO da sub-arvore direita
  struct TNO *direita;
  // Somente para vizualizar melhor a exibi��o dos elementos da �rvore bin�ria
  int coluna;
  int linha;
  int alt;
} NO; // NO: criacao de um novo tipo de dado chamado NO

// ATEN��O
// *  : Significa um ponteiro.
// ** : Significa um ponteiro que aponta
//      para outro ponteiro.

// OBS: A �rvore ser� chamada pelo seu N� principal: raiz
void criarArvore(NO **p_raiz);
void inserir(NO **p_raiz, char p_elemento, int coluna, int linha, int alt);
void exibirPreOrdem(NO *p_raiz, int p_coluna);
void exibirEmOrdem(NO *p_raiz);
void exibirPosOrdem(NO *p_raiz);
void obterDados(char *p_elemento);
void menu();
void configurarAmbiente();
void gotoxy(int coluna, int linha);
void limparLinha(int linha);
int ObterOpcaoMenu();
int contarNo(NO *raiz);
int calcularAltura(NO *raiz, int *altAltura);

// Programa Principal
int main()
{
  configurarAmbiente();
  menu();
} // Fim programa.

// Processa a op��o selecionada no Menu
void menu()
{
  int opcao;
  NO *raiz;
  char elemento = '.';
  int qtdNO = 0;
  int altAltura = 0;
  criarArvore(&raiz);

  for (;;)
  { // Indica uma repeti��o (loop) INFINITO
    // Limpa a tela
    system("cls");
    opcao = ObterOpcaoMenu();
    switch (opcao)
    {
    case 1:
      // Obter o valor de um novo dado: elemento
      // Par�metro passado por Refer�ncia: &elemento
      getchar();
      obterDados(&elemento);
      inserir(&raiz, elemento, 60, 2, 0);
      break;

    case 2:
      // Limpa a tela
      system("cls");
      // Exite todos os dados da �rvore binaria em Pr�-ordem.
      exibirPreOrdem(raiz, 2);
      limparLinha(25);
      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();

      break;

    case 3:
      // Exite todos os dados da �rvore binaria em Pr�-ordem.
      exibirEmOrdem(raiz);
      break;

    case 4:
      // Exite todos os dados da �rvore binaria em Pr�-ordem.
      exibirPosOrdem(raiz);
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
      limparLinha(25);
      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 7:
      // Para sair do programa deve-se
      // desalocar toda mem�ria alocada.
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

    /*
    5 -> contarNo()
      6 -> calcularAlturaArvore()
      7 -> sair()
  */
  } // for
}

// Monta o Menu e obtem a op��o selecionada
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
  printf("* [5] - Contagem de Nos	         *");
  gotoxy(40, 15);
  printf("* [6] - Calcular Altura	         *");
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
Procedimento criarArvore: Inicializa uma �rvore bin�ria vazia
Par�metros:
           1 - **p_raiz  : Par�metro passado por refer�ncia de ponteiro para ponteiro.
                           Representa o NO raiz da �rvore bin�ria.
*/
void criarArvore(NO **p_raiz)
{
  // OBS: NULL � um valor que indica
  // um endere�o de mem�ria vazio v�lido.
  *p_raiz = NULL;
}

/*
Procedimento inserir: insere um novo elemento na �rvore bin�ria recursivamente.
Par�metros:
           1 - **p_raiz  : Par�metro passado por refer�ncia de ponteiro para ponteiro.
                           Representa o NO raiz da �rvore bin�ria.
           2 - p_elemento: Par�metro passado por valor que representa o NOVO elemento
                           a ser inserido na �rbore bin�ria.
*/
void inserir(NO **p_raiz, char p_elemento, int coluna, int linha, int alt)
{

  if (*p_raiz == NULL) // Verifica se a �rvore est� vazia
  {
    // Aloca mem�ria para a estrutura NO.
    *p_raiz = (NO *)malloc(sizeof(NO));
    // Atribui os valores para os campos da estrutura NO da �rvore.
    (*p_raiz)->esquerda = NULL;
    (*p_raiz)->direita = NULL;
    (*p_raiz)->letra = p_elemento;
    // Somente para visualizar os elementos da �rvore bin�ria na tela
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

/*
Procedimento exibirPreOrdem: Exibe todos os elementos da �rvore bin�ria recursivamente na ordem: Pr�-ordem.
Par�metros:
           **p_raiz  : Par�metro passado por valor que indica o ponteiro para o NO RAIZ da �rvore bin�ria.
*/

void exibirPreOrdem(NO *p_raiz, int p_coluna)
{
  if (p_raiz != NULL)
  {
    // Montar a �rvore bin�ria
    gotoxy(p_raiz->coluna, p_raiz->linha);
    printf("(%c)", p_raiz->letra);
    // Exibir os elementos Pr�-ordem
    // gotoxy(p_coluna,28);
    // printf("(%d)", p_raiz->numero);
    exibirPreOrdem(p_raiz->esquerda, p_coluna + 4);
    exibirPreOrdem(p_raiz->direita, p_coluna + 4);
  }
}

/*
Procedimento exibirPreOrdem: Exibe todos os elementos da �rvore bin�ria recursivamente
                             na ordem: Em Ordem.
Par�metros:
           **p_raiz  : Par�metro passado por valor que indica o ponteiro
                       para o NO RAIZ da �rvore bin�ria.
*/
void exibirEmOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    exibirEmOrdem(p_raiz->esquerda);
    printf("(%c)", p_raiz->letra);
    exibirEmOrdem(p_raiz->direita);
  }
}

/*
Procedimento exibirPreOrdem: Exibe todos os elementos da �rvore bin�ria recursivamente
                             na ordem: P�s-ordem.
Par�metros:
           **p_raiz  : Par�metro passado por valor que indica o ponteiro
                       para o NO RAIZ da �rvore bin�ria.
*/
void exibirPosOrdem(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    exibirPosOrdem(p_raiz->esquerda);
    exibirPosOrdem(p_raiz->direita);
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
    calcularAltura(p_raiz->esquerda, altAltura);
    calcularAltura(p_raiz->direita, altAltura);

    gotoxy(5, 25);
    printf("A altura da arvore eh = %d", (*altAltura));
  }
}

//****************************************
//** Fun��es e Procedimentos Auxiliares **
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
