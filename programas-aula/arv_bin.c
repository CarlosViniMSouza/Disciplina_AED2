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
#include <windows.h>
#include <locale.h>

typedef struct TNO
{
  int numero;      // Dados armazenado no 'NO'
  struct TNO *esq; // Ponteiro que levará o numero para o prox. No da sub-arvore esquerda;
  struct TNO *dir; // Ponteiro que levará o numero para o prox. No da sub-arvore direita;
  int coluna, linha;
} NO;

// OBS: A árvore será chamada pelo seu NÓ principal: raiz

// declarando procedimentos e funcoes:
void criarArv(NO **p_raiz);
void inserir(NO **p_raiz, int elem, int coluna, int linha);
void exibirPreOrdem(NO *p_raiz, int p_coluna);
void menu();
void configurarAmbiente();

/* Iremos desenvolver as outras partes no decorrer da caminhada */
