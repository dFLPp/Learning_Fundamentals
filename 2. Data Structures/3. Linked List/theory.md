# Linked Lists (Listas Encadeadas):

Uma linked list é uma estrutura de dados linear composta por elementos chamados de "nós". Cada nó contém um valor e um ponteiro (ou referência) para o próximo nó na sequência. O último nó da lista aponta para null, indicando o final da lista.

## Tipos:

Existem diferentes tipos de linked lists, cada um com suas próprias características e usos:

### Singly Linked List (Lista Encadeada Simples):

- Cada nó possui um valor e um ponteiro para o próximo nó.
- Acesso direto ao elemento anterior não é eficiente, pois a iteração é feita de forma linear.
- Inserções e remoções na frente da lista são eficientes (O(1)), mas inserções/remoções no meio exigem busca (O(n)).

### Doubly Linked List (Lista Encadeada Dupla):

- Cada nó possui um valor, um ponteiro para o próximo nó e um ponteiro para o nó anterior.
- Permite iteração em ambas as direções (frente e trás).
- Inserções e remoções no meio são mais eficientes (O(1)) em comparação com singly linked lists.

### Circular Linked List (Lista Encadeada Circular):

- Similar à singly/doubly linked list, mas o último nó aponta de volta ao primeiro nó (ou ao primeiro nó com um doubly linked list circular).
- Útil quando a lista precisa ser percorrida em um loop contínuo.

## Implementação:

As linked lists podem ser implementadas de várias maneiras, mas a abordagem comum envolve a criação de classes para representar os nós e a lista em si. Em linguagens de programação, você pode usar classes, estruturas ou registros para criar essa estrutura. As operações principais incluem inserção, remoção e busca.

No entanto, lembre-se de que as linked lists têm desvantagens em comparação com outras estruturas de dados, como arrays dinâmicos (vectors) ou arrays estáticos. As linked lists têm um overhead de memória maior devido aos ponteiros adicionais e podem ter um desempenho pior em termos de acesso aleatório aos elementos.

## Comparação:

| Operação          | Linked List                    | Array (Dynamic)                | Array (Static)       |
| ----------------- | ------------------------------ | ------------------------------ | -------------------- |
| Acesso (índice)   | O(n) - Busca linear            | O(1) - Acesso direto           | O(1) - Acesso direto |
| Inserção (início) | O(1) - Inserção direta         | Amortizado O(n) - Deslocamento | N/A - Tamanho fixo   |
| Inserção (meio)   | O(n) - Busca + Inserção        | Amortizado O(n) - Deslocamento | N/A - Tamanho fixo   |
| Inserção (fim)    | O(n) - Busca linear + Inserção | Amortizado O(1) - Adição       | N/A - Tamanho fixo   |
| Remoção (início)  | O(1) - Remoção direta          | O(n) - Deslocamento            | N/A - Tamanho fixo   |
| Remoção (meio)    | O(n) - Busca + Remoção         | O(n) - Deslocamento            | N/A - Tamanho fixo   |
| Remoção (fim)     | O(n) - Busca linear + Remoção  | O(1) - Remoção direta          | N/A - Tamanho fixo   |
