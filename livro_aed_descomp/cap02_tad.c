/*

** Tipo Abstrato de Dados (TAD) **

Definição => Um 'tipo de dado' define o conjunto de valores e operações que uma variavel pode assumir!

Ex.: o tipo 'char': suporta valores entre -128 e +127; e suporta operações básicas de matemática.
Veja o código abaixo

*/

#include <stdio.h>

void operacoes(int num1, int num2);

int main()
{
  int a, b;

  printf("Digite um numero: ");
  scanf("%d", &a);

  printf("Digite outro numero: ");
  scanf("%d", &b);

  operacoes(a, b);

  return 0;
}

void operacoes(int num1, int num2)
{
  printf("Resultado da soma = %d\n", (num1 + num2));
  printf("Resultado da sub = %d\n", (num1 - num2));
  printf("Resultado da mult = %d\n", (num1 * num2));
  printf("Resultado da divi = %d\n", (num1 / num2));
}

/*

Estrutura de Dados consitem em um conjunto de tipos de dados em que existe algum tipo de relacionamento lógico estrutural.

Ex.: 'array', 'struct', 'union' e 'enum' -> todas foram criadas a partir dos tipos básicos de dados.

TAD => Conjunto de dados estruturados com operações que podem ser executadas sobre esses dados.

Constituido pelo tipos básicos(int, char, float) e pelos tipos estruturados('array', 'struct', 'union' e 'enum').

Usar um TAD tem algumas vantagens:

  1. Encapsulamento;
  2. Segurança;
  3. Flexibilidade;
  4. Reutilização;

Agora, vejamos alguns tipos e exemplos de TAD.

** tipo FILE **

FILE => estrutura que contém informações de um arquivo ou de um fluxo do texto necessário para realizarmos as operações de entrada ou de saída. Veja o exemplo:

*/

typedef struct
{
  /* data */
  int level;
  int bsize;
  char fd;
  unsigned flags;
  unsigned istemp;
  unsigned char hold;
  unsigned char *curp;
  unsigned char *buffer;
  short token;
} FILE;

// Agora, vamos declarar um ponteiro de arquivo para usarmos essa estrutura:
FILE *file;

// Assim, o usuário só tem acesso aos dados armazenados, e não pode acessa-los diretamente.

/*

Detalhes Importantes:

1. o tipo FILE é um tipo 'OPACO' para o usuário da biblioteca. Somente a lib sabe o conteúdo do tipo e que pode manipulá-lo.

2. E só pode ser dito do tipo 'OPACO', quando a estrutura é incompletamente definida na interface. Assim, somente funções especificas podem acessa-la.

** Operações Básicas **

  ° Criação do TAD
  ° Inserir novo elemento no TAD
  ° Remover um elemento do TAD
  ° Acessar um elemento do TAD
  ° Deletar o TAD

Daqui em diante, veremos mais sobre o 'typedef struct'

*/
