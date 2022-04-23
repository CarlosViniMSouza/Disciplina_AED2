/*
Benevaldo Pereira Gonçalves
*/

/*
Assunto: Árvore Binária
    01 - Estrutura do NO de uma árvore binária
    02 - Criação da Árvore Binária
    03 - Operação Incluir
    04 - Operação Exibir: Pré-ordem
    05 - Operação Exibir: Em Ordem
    06 - Operação Exibir: Pós-ordem
    07 - Contar Nro de NO
    08 - Calcular altura da arvore
    09 - Calcular quantidade de Folhas
    10 - Remover
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
  // Dado de Altura da arvore binaria AVL
  int alt;
} NO; // Criação de um novo tipo de dado chamado: NO

// OBS.: struct Node = NO

// ATENÇÃO
// *  : Significa declaração de um ponteiro.
// ** : Significa declaração de um ponteiro que aponta
//      para outro ponteiro, isto é, ponteiro de ponteiro.

// OBS: A árvore será chamada pelo seu NÓ principal: raiz

// Principais funcoes da arvore binaria
void criarArvore(NO **p_raiz);
void obterDados(int *p_elemento);
NO *inserir(NO **p_raiz, int p_elemento);
int contarNO(NO *p_raiz);
int contarFolhas(NO *p_raiz);
int alturaArvore(NO *p_raiz);
int maior(int valor1, int valor2);
int pesquisar(NO *p_raiz, int p_elemento);

//*** Para Remover NO *****
NO *remover(NO *p_raiz, int p_elemento);
NO *desalocarArvore(NO *p_raiz);
//*************************

// Para definir a ordem de exibicao da arvore binaria:
void exibirPreOrdem(NO *p_raiz);
void exibirEmOrdem(NO *p_raiz);
void exibirPosOrdem(NO *p_raiz);

// Exibir todos os elementos da árvore binária de forma hierarquica.
void exibirArvore(NO *p_raiz, int p_coluna, int p_linha);
void exibirArvoreEsquerda(NO *p_raiz, int p_coluna, int p_linha);
void exibirArvoreDireita(NO *p_raiz, int p_coluna, int p_linha);

// Funcoes extras para AVL:
NO *girarPraEsquerda(NO *p_raiz);
NO *girarPraDireita(NO *p_raiz);
int obterFB(NO *p_raiz);

// Funcoes complementares para melhor funcionamento.
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
  // Declarar um ponteiro para a estrutura de
  // uma árvore binária do tipo NO chamada raiz.
  NO *raiz;

  int opcao;
  int qtdNO = 0;
  int qtdFolha = 0;
  int altura = 0;
  int elemento = 0;
  char pesquisa = '0';

  // Inicializar o ponteiro da árvore binária
  criarArvore(&raiz);

  for (;;) // Indica uma repetição (loop) INFINITO
  {
    // Limpa a tela
    system("cls");
    opcao = ObterOpcaoMenu();
    switch (opcao)
    {
    case 1:
      // Obter o valor de um novo dado: elemento
      // Parâmetro passado por Referência: &elemento
      obterDados(&elemento);

      // Inserir um NOVO elmento na árvore binária
      inserir(&raiz, elemento);
      break;

    case 2:
      // Limpa a tela
      system("cls");
      // Exibir árvore de forma hierárquica
      exibirArvore(raiz, 60, 2);

      limparLinha(25);
      gotoxy(3, 25);
      printf("Pré-Ordem:");
      exibirPreOrdem(raiz);

      limparLinha(30);
      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 3:
      // Limpa a tela
      system("cls");
      // Exibir árvore de forma hierárquica
      exibirArvore(raiz, 60, 2);

      limparLinha(25);
      gotoxy(3, 25);
      printf("Em Ordem:");
      exibirEmOrdem(raiz);

      limparLinha(30);
      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 4:
      // Limpa a tela
      system("cls");
      // Exibir árvore de forma hierárquica
      exibirArvore(raiz, 60, 2);

      limparLinha(25);
      gotoxy(3, 25);
      printf("Pós-Ordem:");
      exibirPosOrdem(raiz);

      limparLinha(30);
      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 5:
      // Contar número de NO da árvore.
      qtdNO = contarNO(raiz);
      limparLinha(25);
      gotoxy(5, 25);
      printf("Quantidade de NO da arvore binaria: %d", qtdNO);
      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 6:
      // Contar número de NO da árvore.
      altura = alturaArvore(raiz);
      limparLinha(25);
      gotoxy(5, 25);
      printf("Altura da arvore binaria: %d", altura);
      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 7:
      // Contar número de NO Folha da árvore.
      qtdFolha = contarFolhas(raiz);
      limparLinha(25);
      gotoxy(5, 25);
      printf("Quantidade de Folha(s) da arvore binaria: %d", qtdFolha);
      gotoxy(5, 30);
      printf("Pressione uma tecla para continuar.");
      getchar();
      getchar();
      break;

    case 8:
      // Obter o valor a ser removido: elemento
      // Parâmetro passado por Referência: &elemento
      obterDados(&elemento);
      // Remover um elmento na árvore binária

      raiz = remover(raiz, elemento);
      break;

    case 9:
      system("cls");
      getchar();

      // Obter o valor a ser pesquisado: elemento
      // Parametro passado por Referencia: &elemento
      obterDados(&elemento);

      // Pesquisando elemento na arvore binaria
      pesquisa = pesquisar(raiz, elemento);
      limparLinha(20);

      if (pesquisa > 0)
      {
        gotoxy(5, 20);
        printf("Elemento encontrado!");
      }
      else
      {
        gotoxy(5, 20);
        printf("Elemento NAO encontrado!");
      }
      getchar();
      getchar();
      break;

    case 10:
      // Para sair do programa deve-se
      // desalocar toda memória alocada.
      raiz = desalocarArvore(raiz);

      limparLinha(20);
      gotoxy(5, 20);
      printf("Mensagem: Programa Finalizado.");
      // Finaliza o programa com Sucesso.
      exit(EXIT_SUCCESS);

    default:
      limparLinha(20);
      gotoxy(5, 20);
      printf("Mensagem: Opcao Invalida.");
      getchar();
      getchar();
    } // switch

  } // for
}

// Monta o Menu e obtem a opção selecionada
int ObterOpcaoMenu()
{
  int opcao;
  gotoxy(40, 5);
  printf("***************************************");
  gotoxy(40, 6);
  printf("*         Arvore Binaria              *");
  gotoxy(40, 7);
  printf("***************************************");
  gotoxy(40, 8);
  printf("*             Menu                    *");
  gotoxy(40, 9);
  printf("***************************************");
  gotoxy(40, 10);
  printf("* [1] - Inserir                       *");
  gotoxy(40, 11);
  printf("* [2] - Exibir Pre-ordem              *");
  gotoxy(40, 12);
  printf("* [3] - Exibir Em Ordem               *");
  gotoxy(40, 13);
  printf("* [4] - Exibir Pos-Ordem              *");
  gotoxy(40, 14);
  printf("* [5] - Contar Nro de NO              *");
  gotoxy(40, 15);
  printf("* [6] - Calcular altura da arvore     *");
  gotoxy(40, 16);
  printf("* [7] - Calcular quantidade de Folhas *");
  gotoxy(40, 17);
  printf("* [8] - Remover                       *");
  gotoxy(40, 18);
  printf("* [9] - Pesquisar                     *");
  gotoxy(40, 19);
  printf("* [10] - Sair                         *");
  gotoxy(40, 20);
  printf("***************************************");
  gotoxy(40, 21);
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
NO *inserir(NO **p_raiz, int p_elemento)
{
  if (*p_raiz == NULL)
  {
    // Aloca memória para a estrutura NO.
    *p_raiz = (NO *)malloc(sizeof(NO));
    // Atribui os valores para os campos da estrutura NO da árvore.
    (*p_raiz)->numero = p_elemento;
    (*p_raiz)->esquerda = NULL;
    (*p_raiz)->direita = NULL;
    (*p_raiz)->alt = 0;
  }
  if (p_elemento < ((*p_raiz)->numero))
  {
    // Inserir o novo elemento na sub-arvore esquerda recursivamente.
    (*p_raiz)->esquerda = inserir(&((*p_raiz)->esquerda), p_elemento);
  }
  else if (p_elemento > ((*p_raiz)->numero))
  {
    // Inserir o novo elemento na sub-arvore direita recursivamente.
    (*p_raiz)->direita = inserir(&((*p_raiz)->direita), p_elemento);
  }
  else
  {
    return (*p_raiz);
  }

  // Atualizar altura do No raiz
  (*p_raiz)->alt = alturaArvore((*p_raiz));

  // Obtenha o fator de equilíbrio do No raiz para
  // Verificar se este No se tornou desequilibrado
  int fb = obterFB((*p_raiz));
  // fb = fator de balanceamento

  // Se este nó ficar desbalanceado, então existem 4 casos

  // 1 - Caso Esquerda Esquerda
  if (fb > 1 && p_elemento < ((*p_raiz)->esquerda)->numero)
  {
    return girarPraDireita((*p_raiz));
  }

  // 2 - Caso Direita Direita
  if (fb < -1 && p_elemento > ((*p_raiz)->direita)->numero)
  {
    return girarPraEsquerda((*p_raiz));
  }

  // 3 - Caso Esquerda Direita
  if (fb > 1 && p_elemento > ((*p_raiz)->esquerda)->numero)
  {
    (*p_raiz)->esquerda = girarPraEsquerda((*p_raiz)->esquerda);
    return girarPraDireita((*p_raiz));
  }

  // 4 - Caso Direita Esquerda
  if (fb < -1 && p_elemento < ((*p_raiz)->direita)->numero)
  {
    (*p_raiz)->direita = girarPraDireita((*p_raiz)->direita);
    return girarPraEsquerda((*p_raiz));
  }

  // retornar o ponteiro do No (inalterado)
  return (*p_raiz);
}

/*
Procedimento exibirPreOrdem: Exibe todos os elementos da árvore binária recursivamente
                             na ordem: Pré-ordem.
Parâmetros:
            *p_raiz  : Parâmetro passado por valor que indica o ponteiro
                       para o NO RAIZ da árvore binária.
*/
void exibirPreOrdem(NO *p_raiz)
{

  if (p_raiz != NULL)
  {
    printf(" (%d) ", p_raiz->numero);
    exibirPreOrdem(p_raiz->esquerda);
    exibirPreOrdem(p_raiz->direita);
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
    printf(" (%d) ", p_raiz->numero);
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
    printf(" (%d) ", p_raiz->numero);
  }
}

/*
Procedimento exibirArvore: Exibe todos os elementos da árvore binária de forma hierarquica.
Parâmetros:
           *p_raiz  : Parâmetro passado por valor que indica o ponteiro
                       para o NO RAIZ da árvore binária.
           p_coluna : Coordenada da coluna para a função gotoxy()
           p_linha  : Coordenada da linha  para a função gotoxy()
*/
void exibirArvore(NO *p_raiz, int p_coluna, int p_linha)
{

  if (p_raiz != NULL)
  {
    // Exibi o NO raiz da árvore binária
    gotoxy(p_coluna, p_linha);
    printf("(%d)", p_raiz->numero);
    exibirArvoreEsquerda(p_raiz->esquerda, (p_coluna - (p_coluna / 2)), p_linha + 3);
    exibirArvoreDireita(p_raiz->direita, (p_coluna + (p_coluna / 2)), p_linha + 3);
  }
  else
  {
    gotoxy(50, 5);
    printf("Árvore Binária vazia!!!");
  }
}

/*
Procedimento exibirArvoreEsquerda:
   Exibe todos os elementos da Sub-árvore Esquerda da Árvore Binária.
Parâmetros:
           *p_raiz  : Parâmetro passado por valor que indica o ponteiro
                       para a sub-árvore esquerda.
           p_coluna : Coordenada da coluna para a função gotoxy()
           p_linha  : Coordenada da linha  para a função gotoxy()
*/
void exibirArvoreEsquerda(NO *p_raiz, int p_coluna, int p_linha)
{

  if (p_raiz != NULL)
  {
    // Exibir Sub-Árvore Esquerda
    gotoxy(p_coluna, p_linha);
    printf("(%d)", p_raiz->numero);
    exibirArvoreEsquerda(p_raiz->esquerda, p_coluna - 10, p_linha + 3);
    exibirArvoreEsquerda(p_raiz->direita, p_coluna + 10, p_linha + 3);
  }
}

/*
Procedimento exibirArvoreDireita:
   Exibe todos os elementos da Sub-árvore Direita da Árvore Binária.
Parâmetros:
           *p_raiz  : Parâmetro passado por valor que indica o ponteiro
                       para a sub-árvore direita.
           p_coluna : Coordenada da coluna para a função gotoxy()
           p_linha  : Coordenada da linha  para a função gotoxy()
*/
void exibirArvoreDireita(NO *p_raiz, int p_coluna, int p_linha)
{

  if (p_raiz != NULL)
  {
    // Exibir Sub-Árvore Direita
    gotoxy(p_coluna, p_linha);
    printf("(%d)", p_raiz->numero);
    exibirArvoreDireita(p_raiz->esquerda, p_coluna - 10, p_linha + 3);
    exibirArvoreDireita(p_raiz->direita, p_coluna + 10, p_linha + 3);
  }
}

// Contar NO da árvore binária
int contarNO(NO *p_raiz)
{
  if (p_raiz == NULL)
    return 0;
  else
    return 1 + contarNO(p_raiz->esquerda) + contarNO(p_raiz->direita);
}

int maior(int valor1, int valor2)
{
  if (valor1 > valor2)
    return valor1;
  else
    return valor2; // Retorna maior ou igual
} // maior

// Calcular a altura da árvore
int alturaArvore(NO *p_raiz)
{
  if ((p_raiz == NULL) || (p_raiz->esquerda == NULL && p_raiz->direita == NULL))
    return 0;
  else
    return 1 + maior(alturaArvore(p_raiz->esquerda), alturaArvore(p_raiz->direita));
}

int pesquisar(NO *p_raiz, int p_elemento)
{
  if (p_raiz == NULL)
  {
    return 0;
  }
  else if (p_raiz->numero > p_elemento)
  {
    return pesquisar(p_raiz->esquerda, p_elemento);
  }
  else if (p_raiz->numero < p_elemento)
  {
    return pesquisar(p_raiz->direita, p_elemento);
  }
  else
  {
    return 1;
  }
}

int contarFolhas(NO *p_raiz)
{
  if (p_raiz == NULL)
    return 0;
  if (p_raiz->esquerda == NULL && p_raiz->direita == NULL)
  {
    return 1;
  }

  return contarFolhas(p_raiz->esquerda) + contarFolhas(p_raiz->direita);
}

//****************************************
//** Remover NO                         **
//****************************************

NO *remover(NO *p_raiz, int p_elemento)
{
  if (p_raiz == NULL)
    return NULL;
  else if (p_raiz->numero > p_elemento)
    p_raiz->esquerda = remover(p_raiz->esquerda, p_elemento);
  else if (p_raiz->numero < p_elemento)
    p_raiz->direita = remover(p_raiz->direita, p_elemento);
  else
  { /* achou o nó a remover */
    /* nó sem filhos */
    if (p_raiz->esquerda == NULL && p_raiz->direita == NULL)
    {
      free(p_raiz);
      p_raiz = NULL;
    }
    /* nó só tem filho à direita */
    else if (p_raiz->esquerda == NULL)
    {
      NO *t = p_raiz;
      p_raiz = p_raiz->direita;
      free(t);
    }
    /* só tem filho à esquerda */
    else if (p_raiz->direita == NULL)
    {
      NO *t = p_raiz;
      p_raiz = p_raiz->esquerda;
      free(t);
    }
    /* nó tem os dois filhos */
    else
    {
      NO *f = p_raiz->esquerda;
      while (f->direita != NULL)
      {
        f = f->direita;
      }
      p_raiz->numero = f->numero; /* troca as informações */
      f->numero = p_elemento;
      p_raiz->esquerda = remover(p_raiz->esquerda, p_elemento);
    }
  }
  return p_raiz;
}

// Libera toda memória alocada para a arvore binária
NO *desalocarArvore(NO *p_raiz)
{
  if (p_raiz != NULL)
  {
    desalocarArvore(p_raiz->esquerda); /* libera subarvore esquerda */
    desalocarArvore(p_raiz->direita);  /* libera subarvore direita  */
    free(p_raiz);                      /* libera raiz */
  }
  return NULL;
}

// Funcoes que irao balancear a Arvore Binaria (AVL):

NO *girarPraDireita(NO *p_raiz)
{ // aqui, y = p_raiz
  NO *x = p_raiz->esquerda;
  NO *T2 = x->direita;

  // Pra executar rotacao
  x->direita = p_raiz;
  p_raiz->esquerda = T2;

  // Atualizar alturas
  p_raiz->alt = alturaArvore(p_raiz);
  x->alt = alturaArvore(x);

  // Retornar nova raiz
  return x;
}

NO *girarPraEsquerda(NO *p_raiz)
{ // Aqui, x = p_raiz
  NO *y = p_raiz->direita;
  NO *T2 = y->esquerda;

  // Pra executar a rotacao
  y->esquerda = p_raiz;
  p_raiz->direita = T2;

  // Atualizar alturas
  p_raiz->alt = alturaArvore(p_raiz);
  y->alt = alturaArvore(y);

  // Retornar nova raiz
  return y;
}

int obterFB(NO *p_raiz)
{
  if (p_raiz == NULL)
  {
    return 0;
  }
  else
  {
    return alturaArvore(p_raiz->esquerda) - alturaArvore(p_raiz->direita);
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
  for (i = 0; i < 100; i++)
  {
    gotoxy(i, linha);
    printf(" ");
  }
}
