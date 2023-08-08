## O que é uma Stack:

Uma stack (ou pilha) é uma estrutura de dados que segue o princípio de "último a entrar, primeiro a sair" (LIFO - Last In, First Out). Isso significa que o elemento mais recentemente inserido na stack é o primeiro a ser removido. A stack é como uma pilha de pratos, onde você coloca um prato em cima do outro e pega sempre o último prato que foi colocado.

## Funcionamento:

Uma stack possui duas principais operações:

- Push: Adiciona um elemento ao topo da stack.
- Pop: Remove e retorna o elemento no topo da stack.

## Tipos de Stacks:

### Static Stack (Pilha Estática):

Nesse tipo de stack, o tamanho máximo é fixo e determinado previamente. Isso implica que uma vez que a pilha esteja cheia, não é possível adicionar mais elementos.

### Dynamic Stack (Pilha Dinâmica):

Nesse tipo, a pilha pode crescer ou diminuir dinamicamente à medida que novos elementos são adicionados ou removidos. É mais flexível em comparação com a pilha estática, mas também pode demandar mais recursos.

## Implementações:

### Usando Arrays (Vetores):

Em linguagens como C, C++, Java e Python, você pode implementar uma pilha usando um array. A posição do topo da pilha é rastreada através de um índice.

### Usando Linked List (Lista Encadeada):

Nessa implementação, você usa uma estrutura de lista encadeada onde cada elemento possui um ponteiro para o próximo elemento na pilha. O topo da pilha é o primeiro elemento da lista.

### Implementações Internas:

Muitas linguagens de programação possuem bibliotecas ou classes que implementam stacks, tornando mais fácil o uso desse tipo de estrutura. Por exemplo, em C++ temos a classe std::stack, em Java há a classe java.util.Stack e em Python podemos usar listas como pilhas.

## Aplicações:

As stacks são amplamente utilizadas em muitos campos da programação, incluindo:

- Gerenciamento de chamadas de função.
- Avaliação de expressões matemáticas.
- Navegação de histórico em navegadores.
- Implementação de algoritmos como o Depth-First Search (DFS) em grafos.
- Gerenciamento de operações de desfazer e refazer em editores de texto.
- Análise sintática (parsing) em linguagens de programação.
