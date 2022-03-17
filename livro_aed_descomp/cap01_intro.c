/*

1.2 Estrutura de Dados:

É uma forma de armazenar e organizar os dados de modo que possam ser usados de forma eficiente.

1.3 Alocação de Memória:

Temos 2 tipos de alocação de memória:

  1. Alocação Estática => O programador não precisa se preocupar com a reserva de memória para os dados.

  Pois a quant. de memória necessária é armazenada automaticamente pela STACK(pilha) ou em outras partições do programa.

  STACK -> guarda dados alocados dentro dos escopos de funções: variáveis locais, parâmetros, retorno de funções, endereços de outras partes, etc.

  Aqui, os dados são organizados sequencialmente na memória do PC (como arrays). Conhecemos a quantidade de memória utilizada, e não podemos altera-la. Além de ter a possibilidade de armazenar memória que não será utilizada na execução do programa.

  2. Alocação Dinâmica => O programador tem total controle sobre a quantidade de memória e o tempo de vida das posições de memória dos dados.

  A memória em reservada na HEAP. Lá, as variaveis não dependem de escopo e devem ser liberadas manualmente; caso contrário, pode ocorrer um vazamento de memória.

  HEAP -> é uma seção de memória que supera a STACK; ideal para armazenar muitos objetos (de diversos portes); e alocamos memória utilizando a função 'malloc()'. É mais lenta que a STACK, e usamos ponteiros para acessa-la.

  Vejamos um exemplo:

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

  int num1 = 10;
  int *num2 = malloc(10);
  int *num3 = malloc(20);

  free(num2);
  free(num3);

  printf("\nMemoria liberada");

  return 0;
}