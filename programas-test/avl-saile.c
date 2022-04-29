#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <math.h>

typedef struct TNO
{
    char letra;
    struct TNO *esquerda;
    struct TNO *direita;
} NO;

// Procedimentos Vitais pra Arvore
void criarArvore(NO **p_raiz);
void obterDados(char *p_elemento);
void inserir(NO **p_raiz, char p_elemento);

// Funcoes Basicas
int contarNO(NO *p_raiz);
int contarFolhas(NO *p_raiz);
int maior(int valor1, int valor2);
int alturaArvore(NO *p_raiz);
NO **buscar(NO **raiz, char elemento);

// Funcoes de Remocao
void remover(NO **raiz);
NO *desalocarArvore(NO *p_raiz);

// Funcoes para Arvore AVL
NO *rotacaoSimplesEsquerda(NO *raiz);
NO *rotacaoSimplesDireita(NO *raiz);
NO *balancear(NO *raiz);

// Exibir Arvore em Determinada Ordem
void exibirPreOrdem(NO *p_raiz);
void exibirEmOrdem(NO *p_raiz);
void exibirPosOrdem(NO *p_raiz);

// Exibir todos os elementos da Arvore binaria de forma hierarquica.
void exibirArvore(NO *p_raiz, int p_coluna, int p_linha);
void exibirArvoreForm(NO *p_raiz, int p_coluna, int p_linha, int n);

// Procedimentos Auxiliares
void menu();
void configurarAmbiente();
void gotoxy(int coluna, int linha);
void limparLinha(int linha);
int ObterOpcaoMenu();

int main()
{
    configurarAmbiente();
    menu();
}

void menu()
{
    NO *raiz;
    char elemento = '.';
    int opcao = 0;

    criarArvore(&raiz);

    for (;;)
    {
        system("cls");
        opcao = ObterOpcaoMenu();
        switch (opcao)
        {

        case 11:
            inserir(&raiz, 'a');
            inserir(&raiz, 'b');
            inserir(&raiz, 'c');
            inserir(&raiz, 'd');
            inserir(&raiz, 'e');
            inserir(&raiz, 'f');
            inserir(&raiz, 'g');
            inserir(&raiz, 'h');
            inserir(&raiz, 'i');
            inserir(&raiz, 'j');
            inserir(&raiz, 'l');
            inserir(&raiz, 'm');
            inserir(&raiz, 'n');
            inserir(&raiz, 'o');
            inserir(&raiz, 'p');
            inserir(&raiz, 'q');
            inserir(&raiz, 'r');
            inserir(&raiz, 's');
            inserir(&raiz, 't');
            inserir(&raiz, 'u');
            inserir(&raiz, 'v');
            inserir(&raiz, 'x');
            inserir(&raiz, 'y');
            inserir(&raiz, 'z');
            inserir(&raiz, '1');
            inserir(&raiz, '2');
            inserir(&raiz, '3');
            inserir(&raiz, '4');
            inserir(&raiz, '5');
            inserir(&raiz, '6');
            inserir(&raiz, '7');
            inserir(&raiz, '8');
            inserir(&raiz, '9');
            inserir(&raiz, '0');

            break;

        case 1:
            obterDados(&elemento);
            inserir(&raiz, elemento);
            break;

        case 2:
            system("cls");
            exibirArvore(raiz, 60, 2);

            limparLinha(25);
            gotoxy(3, 25);
            printf("Pr�-Ordem:");
            exibirPreOrdem(raiz);

            limparLinha(30);
            gotoxy(5, 30);
            printf("Pressione uma tecla para continuar.");
            getchar();
            getchar();
            break;

        case 3:
            system("cls");
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
            system("cls");
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
            limparLinha(25);
            gotoxy(5, 25);
            printf("Quantidade de NO da Arvore binaria: %d", contarNO(raiz));
            gotoxy(5, 30);
            printf("Pressione uma tecla para continuar.");
            getchar();
            getchar();
            break;

        case 6:
            limparLinha(25);
            gotoxy(5, 25);
            printf("Altura da Arvore binaria: %d", alturaArvore(raiz));
            gotoxy(5, 30);
            printf("Pressione uma tecla para continuar.");
            getchar();
            getchar();
            break;

        case 7:
            limparLinha(25);
            gotoxy(5, 25);
            printf("Quantidade de Folha(s) da Arvore binaria: %d", contarFolhas(raiz));
            gotoxy(5, 30);
            printf("Pressione uma tecla para continuar.");
            getchar();
            getchar();
            break;

        case 8:
            obterDados(&elemento);
            remover(buscar(&raiz, elemento));
            raiz = balancear(raiz);
            break;

        case 9:
            obterDados(&elemento);
            gotoxy(5, 25);
            if (buscar(&raiz, elemento) != NULL)
            {
                NO **aux = buscar(&raiz, elemento);
                printf("O valor [%c] foi encontrado na arvore", (*aux)->letra);
            }
            else
            {
                printf("O valor NAO foi encontrado na arvore");
            }
            gotoxy(5, 30);
            printf("Pressione uma tecla para continuar.");
            getchar();
            getchar();
            break;

        case 10:
            raiz = desalocarArvore(raiz);
            limparLinha(20);
            gotoxy(5, 20);
            printf("Mensagem: Programa Finalizado.");
            exit(EXIT_SUCCESS);

        default:
            limparLinha(20);
            gotoxy(5, 20);
            printf("Mensagem: Opcao Invalida.");
            getchar();
            getchar();
        }
    }
}

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
    printf("* [9] - Buscar                        *");
    gotoxy(40, 19);
    printf("* [10] - Sair                         *");
    gotoxy(40, 20);
    printf("***************************************");
    gotoxy(40, 21);
    printf("Entre com a opcao = ");
    scanf("%d", &opcao);
    return opcao;
}

void criarArvore(NO **p_raiz)
{
    *p_raiz = NULL;
}

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
    fflush(stdin);
    scanf("%c", p_elemento);
}

// Alteracoes AVL
void inserir(NO **raiz, char elemento)
{
    if (*raiz == NULL)
    {
        *raiz = (NO *)malloc(sizeof(NO));
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
        (*raiz)->letra = elemento;
    }
    else
    {
        if (elemento < ((*raiz)->letra))
        {
            inserir(&((*raiz)->esquerda), elemento);
        }
        else
        {
            inserir(&((*raiz)->direita), elemento);
        }
    }

    (*raiz) = balancear(*raiz);
}

void remover(NO **raiz)
{
    if (raiz != NULL)
    {
        NO *aux = (*raiz);
        if ((*raiz)->esquerda == NULL && (*raiz)->direita == NULL)
        {
            free(*raiz);
            (*raiz) = NULL;
        }
        else if ((*raiz)->esquerda == NULL)
        {
            (*raiz) = (*raiz)->direita;
            free(aux);
        }
        else if ((*raiz)->direita == NULL)
        {
            (*raiz) = (*raiz)->esquerda;
            free(aux);
        }
        else
        {
            aux = (*raiz)->esquerda;
            char elemento = (*raiz)->letra;

            while (aux->direita != NULL)
            {
                aux = aux->direita;
            }
            elemento = aux->letra;
            remover(buscar(&(*raiz), aux->letra));
            (*raiz)->letra = elemento;
            free(aux);
        }
    }
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

NO *balancear(NO *raiz)
{
    if (raiz != NULL)
    {
        if (alturaArvore(raiz->esquerda) - alturaArvore(raiz->direita) == 2)
        {
            if (alturaArvore(raiz->esquerda->esquerda) - alturaArvore(raiz->esquerda->direita) == -1)
            {
                raiz->esquerda = rotacaoSimplesEsquerda(raiz->esquerda);
            }
            raiz = rotacaoSimplesDireita(raiz);
        }
        else if (alturaArvore(raiz->esquerda) - alturaArvore(raiz->direita) == -2)
        {
            if (alturaArvore(raiz->direita->esquerda) - alturaArvore(raiz->direita->direita) == 1)
            {
                raiz->direita = rotacaoSimplesDireita(raiz->direita);
            }
            raiz = rotacaoSimplesEsquerda(raiz);
        }
        else if (raiz->esquerda != NULL && raiz->direita != NULL)
        {
            raiz->esquerda = balancear(raiz->esquerda);
            raiz->direita = balancear(raiz->direita);
        }
    }
    return raiz;
}

// Fucoes para Rotacionar os nos em: R.S.E.; R.S.D.; R.D.E. e R.D.D.
NO *rotacaoSimplesEsquerda(NO *raiz)
{
    NO *auxDir, *auxEsq;

    auxDir = raiz->direita;
    auxEsq = auxDir->esquerda;

    raiz->direita = auxEsq;
    auxDir->esquerda = raiz;

    return auxDir;
}

NO *rotacaoSimplesDireita(NO *raiz)
{
    NO *auxDir, *auxEsq;

    auxEsq = raiz->esquerda;
    auxDir = auxEsq->direita;

    raiz->esquerda = auxDir;
    auxEsq->direita = raiz;
    return auxEsq;
}

// Funcoes para Operacoes Basicas

// retorna maior valor;
int maior(int valor1, int valor2)
{
    return valor1 >= valor2 ? valor1 : valor2;
}

// Calcular a altura da �rvore
int alturaArvore(NO *p_raiz)
{
    return (p_raiz == NULL) ? -1 : 1 + maior(alturaArvore(p_raiz->esquerda), alturaArvore(p_raiz->direita));
}

// Contar NO da Arvore binaria
int contarNO(NO *p_raiz)
{
    if (p_raiz == NULL)
        return 0;
    else
        return 1 + contarNO(p_raiz->esquerda) + contarNO(p_raiz->direita);
}

int contarFolhas(NO *raiz)
{
    if (raiz->esquerda == NULL && raiz->direita == NULL)
    {
        return 1;
    }
    else
    {
        return contarFolhas(raiz->esquerda) + contarFolhas(raiz->direita);
    }
}

// buscar valor
NO **buscar(NO **raiz, char elemento)
{
    if ((*raiz) == NULL)
    {
        return NULL;
    }
    else
    {
        if ((*raiz)->letra == elemento)
        {
            return &(*raiz);
        }
        else if ((*raiz)->letra > elemento)
        {
            return buscar(&(*raiz)->esquerda, elemento);
        }
        else if ((*raiz)->letra <= elemento)
        {
            return buscar(&(*raiz)->direita, elemento);
        }
        else
        {
            return NULL;
        }
    }
}

// Funcoes para exibir a Arvore AVL detalhadamente
void exibirPreOrdem(NO *p_raiz)
{

    if (p_raiz != NULL)
    {
        printf(" [%c] ", p_raiz->letra);
        exibirPreOrdem(p_raiz->esquerda);
        exibirPreOrdem(p_raiz->direita);
    }
}

void exibirEmOrdem(NO *p_raiz)
{
    if (p_raiz != NULL)
    {
        exibirEmOrdem(p_raiz->esquerda);
        printf(" [%c] ", p_raiz->letra);
        exibirEmOrdem(p_raiz->direita);
    }
}

void exibirPosOrdem(NO *p_raiz)
{
    if (p_raiz != NULL)
    {
        exibirPosOrdem(p_raiz->esquerda);
        exibirPosOrdem(p_raiz->direita);
        printf(" [%c] ", p_raiz->letra);
    }
}

// Exibi graficamente
void exibirArvore(NO *p_raiz, int p_coluna, int p_linha)
{
    if (p_raiz != NULL)
    {
        gotoxy(p_coluna, p_linha);
        printf(" [%c] ", p_raiz->letra);
        exibirArvoreForm(p_raiz->esquerda, (p_coluna - (p_coluna / 2)), p_linha + 3, 1);
        exibirArvoreForm(p_raiz->direita, (p_coluna + (p_coluna / 2)), p_linha + 3, 1);
    }
    else
    {
        gotoxy(50, 5);
        printf("Arvore Binaria vazia!!!");
    }
}

void exibirArvoreForm(NO *p_raiz, int p_coluna, int p_linha, int n)
{

    if (p_raiz != NULL)
    {
        gotoxy(p_coluna, p_linha);
        printf(" [%c] ", p_raiz->letra);
        n += 1;
        if (n < 5)
        {
            exibirArvoreForm(p_raiz->esquerda, p_coluna - 13 / (n - 1), p_linha + 2, n);
            exibirArvoreForm(p_raiz->direita, p_coluna + 13 / (n - 1), p_linha + 2, n);
        }
        else
        {
            exibirArvoreForm(p_raiz->esquerda, p_coluna - 1.5, p_linha + 2, n);
            exibirArvoreForm(p_raiz->direita, p_coluna + 1.5, p_linha + 2, n);
        }
    }
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
    system("color 9F");
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

/*

Problema: O 'Remover' esta dando EXIT_SUCESS quando queremos retirar algum elemento da arvore.

*/