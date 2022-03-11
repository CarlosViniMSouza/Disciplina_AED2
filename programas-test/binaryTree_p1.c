// link for article https://www.cprogramming.com/tutorial/c/lesson18.html (I'll translate for Portuguese)

/*
1. A árvore binária é uma estrutura de dados fundamental usada em ciência da computação. A árvore binária é uma estrutura de dados útil para armazenar rapidamente dados classificados e recuperar dados armazenados rapidamente.

2. Uma árvore binária é composta de nós pais (ou folhas), cada um dos quais armazena dados e também se conecta a até dois outros nós filhos (folhas) que podem ser visualizados espacialmente como abaixo do primeiro nó com um colocado à esquerda e outro à direita.

3. É a relação entre as folhas vinculadas e a folha de ligação, também conhecida como nó pai, o que torna a árvore binária uma estrutura de dados tão eficiente. É a folha à esquerda que tem um valor de chave menor (ou seja, o valor usado para procurar uma folha na árvore), e a folha à direita que tem um valor de chave igual ou maior. Como resultado, as folhas mais à esquerda da árvore têm os valores mais baixos, enquanto as folhas à direita da árvore têm os maiores valores.

4. Mais importante, como cada folha se conecta a duas outras folhas, é o início de uma nova árvore binária menor. Devido a esta natureza, é possível acessar e inserir dados facilmente em uma árvore binária usando funções de busca e inserção recursivamente chamadas em folhas sucessivas.


5. A representação gráfica típica de uma árvore binária é essencialmente a de uma árvore invertida. Ele começa com um nó raiz, que contém o valor da chave original. O nó raiz tem dois nós filhos; cada nó filho pode ter seus próprios nós filhos.

6. Idealmente, a árvore seria estruturada de forma a ser uma árvore perfeitamente equilibrada, com cada nó tendo o mesmo número de nós filhos à sua esquerda e à sua direita. Uma árvore perfeitamente balanceada permite a inserção média mais rápida de dados ou recuperação de dados.

7. O pior cenário é uma árvore em que cada nó tem apenas um nó filho, então fica como se fosse uma lista encadeada em termos de velocidade. A representação típica de uma árvore binária se parece com o seguinte:

         10
      /    \
    6       14
  /  \    /  \
5     8  11  18

8. O nó que armazena o 10, representado aqui apenas como 10, é o nó raiz, ligando aos nós filho esquerdo e direito, com o nó esquerdo armazenando um valor menor que o nó pai e o nó à direita armazenando um valor maior que o nó pai. Observe que, se alguém removeu o nó raiz e os nós filhos direitos, que o nó armazenando o valor 6 seria o equivalente a uma nova árvore binária menor.

9. A estrutura de uma árvore binária torna as funções de inserção e busca simples de implementar usando recursão. Na verdade, as duas funções de inserção e pesquisa também são muito semelhantes.

10. Inserir dados em uma árvore binária envolve uma função procurando por um nó não utilizado na posição apropriada na árvore na qual inserir o valor da chave. A função insert é geralmente uma função recursiva que continua descendo os níveis de uma árvore binária até que haja uma folha não utilizada em uma posição que segue as regras de colocação de nós.

11. As regras são que um valor menor deve estar à esquerda do nó e um valor maior ou igual deve estar à direita. Seguindo as regras, uma função de inserção deve verificar cada nó para ver se está vazio, se estiver, inseriria os dados a serem armazenados junto com o valor da chave (na maioria das implementações, um nó vazio será simplesmente um ponteiro NULL de um nó pai, então a função também teria que criar o nó).

12. Se o nó já estiver preenchido, a função insert deve verificar se o valor da chave a ser inserido é menor que o valor da chave do nó atual e, em caso afirmativo, a função insert deve ser chamada recursivamente no nó filho esquerdo, ou se o valor da chave a ser inserido for maior ou igual ao valor da chave do nó atual, a função insert deve ser chamada recursivamente no nó filho direito.

13. A função de pesquisa funciona de maneira semelhante. Ele deve verificar se o valor da chave do nó atual é o valor a ser pesquisado. Caso contrário, deve-se verificar se o valor a ser procurado é menor que o valor do nó, caso em que deve ser chamado recursivamente no nó filho esquerdo, ou se é maior que o valor do nó, ele deve ser chamado recursivamente no nó filho direito.

14. Obviamente, também é necessário verificar se o nó filho esquerdo ou direito realmente existe antes de chamar a função no nó. Como as árvores binárias têm 'log (base 2) n' camadas, o tempo médio de busca para uma árvore binária é 'log (base 2) n'.

15. Para preencher uma árvore binária inteira, ordenada, leva aproximadamente 'log (base 2) n' * n. Vamos dar uma olhada no código necessário para uma implementação simples de uma árvore binária.

--> Implementando uma árvore binária:
*/

// Primeiro, é necessário ter uma estrutura, ou classe, definida como um nó (OBS.: Node = nó).

struct node
{
  int id;
  struct node *left;
  struct node *right;
};

/*
16. A estrutura tem a capacidade de armazenar o id e contém os dois nós filhos que definem o nó raiz como parte de uma árvore. Na verdade, o próprio nó é muito semelhante ao nó em uma lista vinculada. E ponteiros são necessários para permitir a criação arbitrária de novos nós na árvore.

17. Há várias operações importantes: Inserir/Buscar/Remover elementos, e Excluir Árvore.

18. Também precisaremos acompanhar o nó raiz da árvore binária, que nos dará acesso ao restante dos dados:
*/

struct node *root = 0;

// 19. É necessário inicializar o root com 0, para que as outras funções possam reconhecer que a árvore ainda não existe. O 'destroy_tree' mostrado abaixo, liberará todos os nós da árvore armazenada sob a folha do nó: árvore (OBS.: leaf = folha).

void destroy_tree(struct node *leaf)
{

  if (leaf != 0)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    free(leaf);
  }
}

/*
20. A função 'destroy_tree' vai para a parte inferior de cada parte da árvore, ou seja, pesquisando enquanto há um nó não nulo, exclui essa folha e depois volta para cima.

21. A função exclui o nó mais à esquerda, depois o nó filho direito do nó pai do nó mais à esquerda e, em seguida, exclui o nó pai, em seguida, volta a excluir o outro nó filho do pai do nó que acabou de excluir e continua essa exclusão, trabalhando até o nó da árvore na qual delete_tree foi originalmente chamado.

22. Na árvore de exemplo acima, a ordem de exclusão dos nós seria 5 8 6 11 18 14 10. Observe que é necessário excluir todos os nós filhos para evitar o desperdício de memória.
*/

// 23. A função de inserção criará uma nova árvore, se necessário; ele depende de ponteiros para ponteiros para lidar com o caso de uma árvore inexistente (a raiz apontando para NULL). Ao levar um ponteiro a outro ponteiro, é possível alocar memória se o ponteiro raiz for NULL.

insert(int key, struct node **leaf)
{
  if (*leaf == 0)
  {
    // inicializando a árvore binária.
    *leaf = (struct node *)malloc(sizeof(struct node));
    (*leaf)->id = key;

    // inicializando os filhos para null.
    (*leaf)->left = 0;
    (*leaf)->right = 0;
  }

  // caso o valor inserido seja menor que o nó raiz, ele será direcionado á sub-arvore esquerda.
  else if (key < (*leaf)->id)
  {
    insert(key, &(*leaf)->left);
  }

  // caso o valor inserido seja maior que o nó raiz, ele será direcionado á sub-arvore direita.
  else if (key > (*leaf)->id)
  {
    insert(key, &(*leaf)->right);
  }
}

/*
24. A função insert busca, descendo a árvore de nós filhos, seguindo as regras prescritas, à esquerda para um valor menor ser inserido e à direita para um valor maior, até chegar a um nó NULL - um nó vazio - ao qual aloca memória e inicializa com o valor da chave enquanto define os ponteiros de nó filho do novo nó como NULL.

25. Depois de criar o novo nó, a função de inserção não chamará mais a si mesma. Observe, também, que se o elemento já estiver na árvore, ele não será adicionado duas vezes.
*/