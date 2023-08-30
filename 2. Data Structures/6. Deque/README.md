# Deques

## Introdução

Na área de estruturas de dados, a eficiência e flexibilidade no armazenamento e manipulação de elementos são fundamentais. Os deques, ou "Double-Ended Queues" (filas de duas pontas), são uma estrutura que oferece uma combinação única de características que permitem inserção e remoção eficientes tanto no início quanto no final da estrutura. Neste artigo, exploraremos os conceitos, operações, aplicações e complexidade temporal dos deques, destacando suas vantagens em relação a outras estruturas de dados lineares.

## Conceito e Funcionamento

Um deque é uma estrutura de dados linear semelhante a uma fila (queue) ou pilha (stack), mas que permite a inserção e remoção de elementos tanto no início quanto no final da estrutura. Isso proporciona maior flexibilidade em situações onde a ordem de processamento é importante. De forma geral, um deque suporta as seguintes operações:

1. **Inserir no início (push_front):** Adiciona um elemento no início do deque.
2. **Inserir no final (push_back):** Adiciona um elemento no final do deque.
3. **Remover do início (pop_front):** Remove e retorna o elemento do início do deque.
4. **Remover do final (pop_back):** Remove e retorna o elemento do final do deque.
5. **Acesso ao início (front):** Retorna o elemento no início do deque, sem removê-lo.
6. **Acesso ao final (back):** Retorna o elemento no final do deque, sem removê-lo.
7. **Verificação de vazio:** Verifica se o deque está vazio.
8. **Tamanho:** Retorna a quantidade de elementos no deque.

## Implementações Possíveis

Existem várias formas de implementar um deque, cada uma com vantagens e desvantagens em termos de complexidade temporal e espaço. Duas abordagens comuns são:

1. **Usando um vetor redimensionável:** Basta vc criar uma array de tamanho x e só permitir inserções e removoções nas extremdidades. Se tentarem adicionar um elemento quando a array estiver cheia vc cria outra array (com tamanho maior), copia todos os dados para ela e então insere.

2. **Usando uma lista duplamente encadeada:** É literalmente oq fizemos no tópico de linked lists com C LMAO.

Levando em considerção a similaridade com outras estruturas que já vimos e a facilidade na implementação (praticamente igual a alguma coisa que já fizemos antes) n vou implementar aq.

## Aplicações

Os deques são úteis em várias situações, incluindo:

- **Algoritmos de busca em largura:** Deques podem ser usados para manter os nós a serem explorados em algoritmos de busca em largura, como a busca em largura de uma árvore ou grafo.
- **Janelas deslizantes:** Em problemas que envolvem processamento em janelas deslizantes, onde você precisa rastrear uma subsequência de elementos em uma janela que se move ao longo de uma estrutura de dados, os deques podem ser uma escolha eficiente.
- **Implementação de filas de prioridade dupla:** Em certos cenários, é necessário ter acesso rápido tanto ao maior quanto ao menor elemento, e um deque permite isso de forma eficiente.

## Complexidade Temporal

As operações nos deques têm as seguintes complexidades temporais em uma implementação baseada em vetor:

- Inserir no início: O(1) (amortizado, devido a realocações ocasionais)
- Inserir no final: O(1) (amortizado, devido a realocações ocasionais)
- Remover do início: O(1)
- Remover do final: O(1)
- Acesso ao início: O(1)
- Acesso ao final: O(1)
- Verificação de vazio: O(1)
- Tamanho: O(1)

OBS: Em uma implementação baseada em lista duplamente encadeada, todas as operações acima têm complexidade O(1).
