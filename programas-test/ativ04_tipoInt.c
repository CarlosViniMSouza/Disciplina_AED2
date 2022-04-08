/*
Carlos Souza

Matricula: 2021002252

Turma III - Engenharia de Software
*/

/*
Assunto: Arvore Binaria
    01 - Estrutura do NO de uma arvore binaria
    02 - Criacao da arvore Binaria
    03 - Operacao Incluir
    04 - Operacao Exibir: Pre-ordem
    05 - Operacao Exibir: Em Ordem
    06 - Operacao Exibir: Pos-ordem
    07 - Contar Num de NO
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
    char letra;
    // Ponteiro para o proximo NO da sub-arvore esquerda
    struct TNO *esquerda;
    // Ponteiro para o proximo NO da sub-arvore direita
    struct TNO *direita;
} NO; // Criacao de um novo tipo de dado chamado: NO

// ATENCAO
// *  : Significa declaracao de um ponteiro.
// ** : Significa declaracao de um ponteiro que aponta
// para outro ponteiro, isto eh, ponteiro de ponteiro.

// OBS: A arvore sera chamada pelo seu NO principal: raiz
void criarArvore(NO **p_raiz);
void inserir(NO **p_raiz, char p_elemento);
void exibirPreOrdem(NO *p_raiz);
void exibirEmOrdem(NO *p_raiz);
void exibirPosOrdem(NO *p_raiz);
int contarNO(NO *p_raiz);
int contarFolhas(NO *p_raiz);
char maior(char valor1, char valor2);
int alturaArvore(NO *p_raiz);
NO* pesquisar(NO* p_raiz, int p_elemento);
void obterDados(char *p_elemento);

//*** Para Remover NO ***
NO *remover(NO *p_raiz, char p_elemento);
NO *desalocarArvore(NO *p_raiz);
//***********************

// Exibir todos os elementos da arvore binaria de forma hierarquica.
void exibirArvore(NO *p_raiz, int p_coluna, int p_linha);
void exibirArvoreEsquerda(NO *p_raiz, int p_coluna, int p_linha);
void exibirArvoreDireita(NO *p_raiz, int p_coluna, int p_linha);

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
    int qtdNO = 0;
    int qtdFolha = 0;
    int altura = 0;
    // Declarar um ponteiro para a estrutura de
    // uma arvore binaria do tipo NO chamada raiz.
    NO *raiz;
    char elemento = '0';
    NO *elemPesq = NULL;

    // Inicializar o ponteiro da arvore binaria
    criarArvore(&raiz);

    for (;;) // Indica uma repeticao (loop) INFINITO
    {
        // Limpa a tela
        system("cls");
        opcao = ObterOpcaoMenu();
        switch (opcao)
        {
        case 1:
            // Limpa a tela
            system("cls");
            getchar();
            // Obter o valor de um novo dado: elemento
            // Parametro passado por Referencia: &elemento
            obterDados(&elemento);
            // Inserir um NOVO elmento na arvore binaria
            inserir(&raiz, elemento);
            break;

        case 2:
            // Limpa a tela
            system("cls");
            // Exibir arvore de forma hierarquica
            exibirArvore(raiz, 60, 2);

            limparLinha(25);
            gotoxy(3, 25);
            printf("Pre-Ordem:");
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
            // Exibir arvore de forma hierarquica
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
            // Exibir arvore de forma hierarquica
            exibirArvore(raiz, 60, 2);

            limparLinha(25);
            gotoxy(3, 25);
            printf("P?s-Ordem:");
            exibirPosOrdem(raiz);

            limparLinha(30);
            gotoxy(5, 30);
            printf("Pressione uma tecla para continuar.");
            getchar();
            getchar();
            break;

        case 5:
            // Contar numero de NO da arvore.
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
            // Contar numero de NO da arvore.
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
            // Contar numero de NO Folha da arvore.
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
            // Limpa a tela
            system("cls");
            getchar();
            // Obter o valor a ser removido: elemento
            // Parametro passado por Referencia: &elemento
            obterDados(&elemento);
            // Remover um elmento na arvore binaria

            raiz = remover(raiz, elemento);
            getchar();
			getchar();
            break;
            
        case 9:
        	// Obter o valor a ser pesquisado: elemento
            // Parâmetro passado por Referência: &elemento
            obterDados(&elemento);
            
            // Pesquisar um elmento na árvore binária
            elementoPesquisa = pesquisar(raiz,elemento);
            limparLinha(20);
            
            if (elementoPesquisa){
                gotoxy(5,20);
                printf("Elemento Encontrado: (%d)",elementoPesquisa->numero);
            }else{
                gotoxy(5,20);
                printf("Elemento NÃO Encontrado!!!");
            }
            getchar();
			getchar();
            break;

        case 10:
            // Para sair do programa deve-se
            // desalocar toda memoria alocada.
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

// Monta o Menu e obtem a opcao selecionada
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
    printf("* [9] - Remover                       *");
    gotoxy(40, 19);
    printf("* [10] - Sair                          *");
    gotoxy(40, 20);
    printf("***************************************");
    gotoxy(40, 21);
    printf("Entre com a opcao = ");
    scanf("%d", &opcao);
    return opcao;
}

/*
Procedimento obterDados: Obtem o valor de um dado (elemento)
Parametros:
           1 - p_elemento : Parametro passado por referencia para obter o valor de
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
Procedimento criarArvore: Inicializa uma arvore binaria vazia
Parametros:
           1 - **p_raiz  : Parametro passado por referencia de ponteiro para ponteiro.
                           Representa o NO raiz da arvore binaria.
*/
void criarArvore(NO **p_raiz)
{
    // OBS: NULL eh um valor que indica
    // um endereco de memoria vazio valido.
    *p_raiz = NULL;
}

/*
Procedimento inserir: insere um novo elemento na arvore binaria recursivamente.
Parametros:
           1 - **p_raiz  : Parametro passado por referencia de ponteiro para ponteiro.
                           Representa o NO raiz da arvore binaria.
           2 - p_elemento: Parametro passado por valor que representa o NOVO elemento
                           a ser inserido na arvore binaria.
*/
void inserir(NO **p_raiz, char p_elemento)
{
    if (*p_raiz == NULL)
    {
        // Ponteiro *p_raiz esta apontando para NULL
        // Aloca memoria para a estrutura NO.
        *p_raiz = (NO *)malloc(sizeof(NO));
        // Atribui os valores para os campos da estrutura NO da Arvore.
        (*p_raiz)->esquerda = NULL;
        (*p_raiz)->direita = NULL;
        (*p_raiz)->letra = p_elemento;
    }
    else
    {

        if (p_elemento < ((*p_raiz)->letra))
        {
            // Inserir o novo elemento na sub-arvore esquerda recursivamente.
            inserir(&((*p_raiz)->esquerda), p_elemento);
        }
        else
        {
            // Inserir o novo elemento na sub-arvore direita recursivamente.
            inserir(&((*p_raiz)->direita), p_elemento);
        }
    }
}

/*
Procedimento exibirPreOrdem: Exibe todos os elementos da arvore binaria recursivamente
                             na ordem: Pre-ordem.
Parametros:
            *p_raiz  : Parametro passado por valor que indica o ponteiro
                       para o NO RAIZ da arvore binaria.
*/
void exibirPreOrdem(NO *p_raiz)
{

    if (p_raiz != NULL)
    {
        printf(" (%c) ", p_raiz->letra);
        exibirPreOrdem(p_raiz->esquerda);
        exibirPreOrdem(p_raiz->direita);
    }
}

/*
Procedimento exibirPreOrdem: Exibe todos os elementos da arvore binaria recursivamente
                             na ordem: Em Ordem.
Parametros:
           **p_raiz  : Parametro passado por valor que indica o ponteiro
                       para o NO RAIZ da arvore binaria.
*/
void exibirEmOrdem(NO *p_raiz)
{
    if (p_raiz != NULL)
    {
        exibirEmOrdem(p_raiz->esquerda);
        printf(" (%c) ", p_raiz->letra);
        exibirEmOrdem(p_raiz->direita);
    }
}

/*
Procedimento exibirPreOrdem: Exibe todos os elementos da arvore binaria recursivamente
                             na ordem: Pos-ordem.
Parametros:
           **p_raiz  : Parametro passado por valor que indica o ponteiro
                       para o NO RAIZ da arvore binaria.
*/
void exibirPosOrdem(NO *p_raiz)
{
    if (p_raiz != NULL)
    {
        exibirPosOrdem(p_raiz->esquerda);
        exibirPosOrdem(p_raiz->direita);
        printf(" (%c) ", p_raiz->letra);
    }
}

/*
Procedimento exibirArvore: Exibe todos os elementos da arvore binaria de forma hierarquica.
Parametros:
           *p_raiz  : Parametro passado por valor que indica o ponteiro
                       para o NO RAIZ da arvore binaria.
           p_coluna : Coordenada da coluna para a funcao gotoxy()
           p_linha  : Coordenada da linha  para a funcao gotoxy()
*/
void exibirArvore(NO *p_raiz, int p_coluna, int p_linha)
{

    if (p_raiz != NULL)
    {
        // Exibi o NO raiz da arvore binaria
        gotoxy(p_coluna, p_linha);
        printf("(%c)", p_raiz->letra);
        exibirArvoreEsquerda(p_raiz->esquerda, (p_coluna - (p_coluna / 2)), p_linha + 3);
        exibirArvoreDireita(p_raiz->direita, (p_coluna + (p_coluna / 2)), p_linha + 3);
    }
    else
    {
        gotoxy(50, 5);
        printf("Arvore Binaria vazia!!!");
    }
}

/*
Procedimento exibirArvoreEsquerda:
   Exibe todos os elementos da Sub-Arvore Esquerda da Arvore Binaria.
Parametros:
           *p_raiz  : Parametro passado por valor que indica o ponteiro
                       para a sub-arvore esquerda.
           p_coluna : Coordenada da coluna para a funcao gotoxy()
           p_linha  : Coordenada da linha  para a funcao gotoxy()
*/
void exibirArvoreEsquerda(NO *p_raiz, int p_coluna, int p_linha)
{

    if (p_raiz != NULL)
    {
        // Exibir Sub-Arvore Esquerda
        gotoxy(p_coluna, p_linha);
        printf("(%c)", p_raiz->letra);
        exibirArvoreEsquerda(p_raiz->esquerda, p_coluna - 10, p_linha + 3);
        exibirArvoreEsquerda(p_raiz->direita, p_coluna + 10, p_linha + 3);
    }
}

/*
Procedimento exibirArvoreDireita:
   Exibe todos os elementos da Sub-Arvore Direita da Arvore Binaria.
Parametros:
           *p_raiz  : Parametro passado por valor que indica o ponteiro
                       para a sub-arvore direita.
           p_coluna : Coordenada da coluna para a funcao gotoxy()
           p_linha  : Coordenada da linha  para a funcao gotoxy()
*/
void exibirArvoreDireita(NO *p_raiz, int p_coluna, int p_linha)
{

    if (p_raiz != NULL)
    {
        // Exibir Sub-Arvore Direita
        gotoxy(p_coluna, p_linha);
        printf("(%c)", p_raiz->letra);
        exibirArvoreDireita(p_raiz->esquerda, p_coluna - 10, p_linha + 3);
        exibirArvoreDireita(p_raiz->direita, p_coluna + 10, p_linha + 3);
    }
}

// Contar NO da arvore binaria
int contarNO(NO *p_raiz)
{
    if (p_raiz == NULL)
        return 0;
    else
        return 1 + contarNO(p_raiz->esquerda) + contarNO(p_raiz->direita);
}

char maior(char valor1, char valor2)
{
    if (valor1 > valor2)
        return valor1;
    else
        return valor2; // Retorna maior ou igual
} // maior

// Calcular a altura da arvore
int alturaArvore(NO *p_raiz)
{
    if ((p_raiz == NULL) || (p_raiz->esquerda == NULL && p_raiz->direita == NULL))
        return 0;
    else
        return 1 + maior(alturaArvore(p_raiz->esquerda), alturaArvore(p_raiz->direita));
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

NO *remover(NO *p_raiz, char p_elemento)
{
    if (p_raiz == NULL)
        return NULL;
    else if (p_raiz->letra > p_elemento)
        p_raiz->esquerda = remover(p_raiz->esquerda, p_elemento);
    else if (p_raiz->letra < p_elemento)
        p_raiz->direita = remover(p_raiz->direita, p_elemento);
    else
    { /* achou o no para remover */
        /* no sem filhos */
        if (p_raiz->esquerda == NULL && p_raiz->direita == NULL)
        {
            free(p_raiz);
            p_raiz = NULL;
        }
        /* no soh tem filho a direita */
        else if (p_raiz->esquerda == NULL)
        {
            NO *t = p_raiz;
            p_raiz = p_raiz->direita;
            free(t);
        }
        /* soh tem filho a esquerda */
        else if (p_raiz->direita == NULL)
        {
            NO *t = p_raiz;
            p_raiz = p_raiz->esquerda;
            free(t);
        }
        /* no tem os dois filhos */
        else
        {
            NO *f = p_raiz->esquerda;
            while (f->direita != NULL)
            {
                f = f->direita;
            }
            p_raiz->letra = f->letra; /* troca as informacoes */
            f->letra = p_elemento;
            p_raiz->esquerda = remover(p_raiz->esquerda, p_elemento);
        }
    }
    return p_raiz;
}

// Libera toda memoria alocada para a arvore binaria
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

//****************************************
//** Funcoes e Procedimentos Auxiliares **
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

// Atividade 4 -> quase completa
