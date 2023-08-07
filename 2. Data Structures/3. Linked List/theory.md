# Linked Lists

## Definição

Uma linked list é uma estrutura de armazenamento de dados que se parece com arrays porém não tem tamanho fixo e os items não ficam aramzenados em um espaço contiguo de memória. Devido a essa forma de armazenar os dados os elementos do final da lista só podem ser acessados através de outros elementos, ou seja, você não acesso direto a eles, de modo que se você perder o "caminho" que leva até esse elemento, você o perdeu.

A caractéristica dessa estrutura de dados é que ela composta por dois componentes: o dado que se quer armazenar e um ponteiro para o próximo elemento da sequência. Cada elemento da lista é chamado de _node_ e pode armazenar qualquer tipo de dado (até mesmo outras linked lists).

As principais funcionalidades que uma linked list tem são:

- inserção: quando feita no início da lista tem O(1) e em qualquer outro lugar O(n);
- recuperação: Diferente de arrays que tem O(1), para todos os casos a linked list tem O(n);
- exclusão: linked lists demoram O(n) mas o fazem de com complexidade de espaço constante ao mesmo em que re-organizam a sequecia, diferente de arrays que, se o faz, precisa de outra variável com no mínimo o mesmo tamanho da array atual.

## Tipos

Existem vários tipos de linked lists. Entre as principais temos:

- Singly linked list: Cada elemento guarda o endereço de memória do elemento que vem depois de si na sequência. Para denotar o início da lista cria-se a variável **head** que sempre fica no início da lista (sem esssa variável todos os outros participantes da lista ficariam "soltos" na memória, pois a única forma de chegar até eles é através do elemento que vem antes.). Nas anotações vamos implementa com `Javascript`.

- Doubly linked list: Cada elemento guarda o endereço de memória tanto do elemento que vem antes quando do elemento que vem depois de si. Além do **head** também é criada por conveniência a variável **tail** que sempre fica no final da lista. Dessa forma você pode percorrer a lista em ambas as direções com mais facilidade. Nas anotações vamos implementa com `C`.

- Circular linked list: É linked list onde o elemento do final (tail) está ligado ao elemento do início (head) da lista. Linked lists circulares podem ser tanto Singly quando doubly. Nas anotações vamos implementa com `python`.

- Skip list: Nas anotações vamos implementa com `Java`.

## Implementação

Existem duas formas básicas: usando arrays e usando objetos. A implementação usando objetos varia de linguagem para linguagem. Por exemplo, em C usamos o conceito de structs e alocação "manual" de memória enquanto que no javascript usamos classes e constructors.

A implementação usando arrays consiste emarmazenar os elementos em espaços contiguos na memória. Já a implementação usando objetos consiste em criar espaços em locais "aleatórios" da memória e integra-los/interliga-los através do enderço de memória que eles tem para o próximo elemento. Aqui vamos usar a implementação usando objetos.
