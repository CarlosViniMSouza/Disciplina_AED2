/*

Tipo Abstrato de Dados (TAD):

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

*/
