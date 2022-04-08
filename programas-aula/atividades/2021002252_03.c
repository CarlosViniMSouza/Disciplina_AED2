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
    // Ponteiro para o proximo NO da sub-arvore esquerda
    struct TNO *esquerda;
    // Ponteiro para o proximo NO da sub-arvore direita
    struct TNO *direita;
} NO; // Criacao de um novo tipo de dado chamado: NO

// ATENÇÃO
// *  : Significa declaracao de um ponteiro.
// ** : Significa declaracao de um ponteiro que aponta
//      para outro ponteiro, isto eh, ponteiro de ponteiro.

// OBS: A arvore sera chamada pelo seu NO principal: raiz
void criarArvore(NO **p_raiz);
void inserir(NO **p_raiz, int p_elemento);
void exibirPreOrdem(NO *p_raiz);
void exibirEmOrdem(NO *p_raiz);
void exibirPosOrdem(NO *p_raiz);
int contarNO(NO *p_raiz);
int contarFolhas(NO *p_raiz);
int maior(int valor1, int valor2);
int alturaArvore(NO *p_raiz);
void obterDados(int *p_elemento);
NO *pesquisar(NO *p_raiz, int p_elemento);
//*** Para Remover NO ***
NO *remover(NO *p_raiz, int p_elemento);
NO *desalocarArvore(NO *p_raiz);
//***********************

// Exibir todos os elementos da árvore binária de forma hierarquica.
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
    int elemento = 0;
    NO *elementoPesquisa = NULL;

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
            // Exibir árvore de forma hierarquica
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
            // Exibir árvore de forma hierarquica
            exibirArvore(raiz, 60, 2);

            limparLinha(25);
            gotoxy(3, 25);
            printf("Pos-Ordem:");
            exibirPosOrdem(raiz);

            limparLinha(30);
            gotoxy(5, 30);
            printf("Pressione uma tecla para continuar.");
            getchar();
            getchar();
            break;

        case 5:
            // Contar numero de NO da Arvore.
            qtdNO = contarNO(raiz);
            limparLinha(25);
            gotoxy(5, 25);
            printf("Quantidade de NOs da arvore binaria: %d", qtdNO);
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
            // Contar numero de NO Folha da Arvore.
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
            // Parametro passado por Referencia: &elemento
            obterDados(&elemento);
            // Remover um elmento na arvore binaria

            raiz = remover(raiz, elemento);
            break;

        case 9:
            // Obter o valor a ser pesquisado: elemento
            // Parametro passado por Referencia: &elemento
            obterDados(&elemento);
            // Pesquisar um elemento na arvore binaria
            elementoPesquisa = pesquisar(raiz, elemento);
            limparLinha(20);
            if (elementoPesquisa)
            {
                gotoxy(5, 20);
                printf("Elemento Encontrado: (%d)", elementoPesquisa->numero);
            }
            else
            {
                gotoxy(5, 20);
                printf("Elemento NAO Encontrado!!!");
            }
            getchar();
            getchar();
            break;

        case 10:
            // Para sair do programa deve-se
            // desalocar toda memoria alocada.
            raiz = desalocarArvore(raiz);

            limparLinha(30);
            gotoxy(5, 30);
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
    printf("****************************************");
    gotoxy(40, 6);
    printf("*          Arvore Binaria              *");
    gotoxy(40, 7);
    printf("****************************************");
    gotoxy(40, 8);
    printf("*               Menu                   *");
    gotoxy(40, 9);
    printf("****************************************");
    gotoxy(40, 10);
    printf("* [01] - Inserir                       *");
    gotoxy(40, 11);
    printf("* [02] - Exibir Pre-ordem              *");
    gotoxy(40, 12);
    printf("* [03] - Exibir Em Ordem               *");
    gotoxy(40, 13);
    printf("* [04] - Exibir Pos-Ordem              *");
    gotoxy(40, 14);
    printf("* [05] - Contar Nro de NO              *");
    gotoxy(40, 15);
    printf("* [06] - Calcular altura da arvore     *");
    gotoxy(40, 16);
    printf("* [07] - Calcular quantidade de Folhas *");
    gotoxy(40, 17);
    printf("* [08] - Remover                       *");
    gotoxy(40, 18);
    printf("* [09] - Pesquisar                     *");
    gotoxy(40, 19);
    printf("* [10] - Sair                          *");
    gotoxy(40, 20);
    printf("****************************************");
    gotoxy(40, 21);
    printf("Entre com a opcao = ");
    scanf("%d", &opcao);
    return opcao;
}

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

void criarArvore(NO **p_raiz)
{
    *p_raiz = NULL;
}

void inserir(NO **p_raiz, int p_elemento)
{
    if (*p_raiz == NULL)
    {
        // Ponteiro *p_raiz esta apontando para NULL
        // Aloca memoria para a estrutura NO.
        *p_raiz = (NO *)malloc(sizeof(NO));
        
        // Atribui os valores para os campos da estrutura NO da Arvore.
        (*p_raiz)->esquerda = NULL;
        (*p_raiz)->direita = NULL;
        (*p_raiz)->numero = p_elemento;
    }
    else
    {

        if (p_elemento < ((*p_raiz)->numero))
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

void exibirPreOrdem(NO *p_raiz)
{

    if (p_raiz != NULL)
    {
        printf(" (%d) ", p_raiz->numero);
        exibirPreOrdem(p_raiz->esquerda);
        exibirPreOrdem(p_raiz->direita);
    }
}

void exibirEmOrdem(NO *p_raiz)
{
    if (p_raiz != NULL)
    {
        exibirEmOrdem(p_raiz->esquerda);
        printf(" (%d) ", p_raiz->numero);
        exibirEmOrdem(p_raiz->direita);
    }
}

void exibirPosOrdem(NO *p_raiz)
{
    if (p_raiz != NULL)
    {
        exibirPosOrdem(p_raiz->esquerda);
        exibirPosOrdem(p_raiz->direita);
        printf(" (%d) ", p_raiz->numero);
    }
}

NO *pesquisar(NO *p_raiz, int p_elemento)
{
    // Verifica se existe elemento na arvore binaria
    if (p_raiz != NULL)
    {
        if (p_elemento == p_raiz->numero)
        {
            // Elemento existe na arvore binaria
            return p_raiz;
        }
        else if (p_elemento < p_raiz->numero)
        {
            // Pesquisar na sub-arvore esquerda
            return pesquisar(p_raiz->esquerda, p_elemento);
        }
        else
        {
            // Pesquisar na sub-arvore direita
            return pesquisar(p_raiz->direita, p_elemento);
        }
    }
    // NAO Existe elemento na arvore binaria
    return NULL;
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
        // Exibir o NO raiz da arvore binaria
        gotoxy(p_coluna, p_linha);
        printf(" (%d) ", p_raiz->numero);
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
Procedimento exibirArvoreEsquerda: Exibe todos os elementos da Sub-Arvore Esquerda.
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
        printf(" (%d) ", p_raiz->numero);
        exibirArvoreEsquerda(p_raiz->esquerda, p_coluna - 10, p_linha + 3);
        exibirArvoreEsquerda(p_raiz->direita, p_coluna + 10, p_linha + 3);
    }
}

/*
Procedimento exibirArvoreDireita: Exibe todos os elementos da Sub-Arvore Direita.
Parametros:
           *p_raiz  : Parametro passado por valor que indica o ponteiro
                      para a sub-arvore direita.
           p_coluna : Coordenada da coluna para a função gotoxy()
           p_linha  : Coordenada da linha  para a função gotoxy()
*/
void exibirArvoreDireita(NO *p_raiz, int p_coluna, int p_linha)
{

    if (p_raiz != NULL)
    {
        // Exibir Sub-Arvore Direita
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
    {   /* achou o nó a remover */
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

// Procedimento para configurar o ambiente do programa
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

// Atividade 04 -> program atualizado!
