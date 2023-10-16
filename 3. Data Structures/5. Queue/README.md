## O que é uma fila (_queue_)?

Uma fila é uma estrutura de dados que segue a ordem "primeiro a entrar, primeiro a sair" (_FIFO - First-In-First-Out_). Isso significa que o elemento que foi adicionado primeiro à fila será o primeiro a ser removido. Filas são comuns em situações onde é importante manter a ordem de chegada dos elementos.

## Tipos de filas:

1. **Fila simples**: Uma fila básica onde os elementos são adicionados na parte traseira (_back_) e removidos da parte frontal (_front_).

2. **Deque (_Double-Ended Queue_)**: Permite a adição e remoção de elementos tanto na parte frontal quanto na parte traseira da fila. Essa estrutura é útil para casos em que você precisa acessar elementos na frente e atrás da fila (veremos na próxima "pasta").

3. **Priority Queue (_Fila de Prioridade_)**: Uma fila onde cada elemento possui uma prioridade associada. Elementos são removidos com base em suas prioridades, não necessariamente na ordem em que foram adicionados.

## Implementações de filas:

1. **Implementação usando Arrays (_Vetores_)**: Uma abordagem simples é usar um array para armazenar os elementos da fila. A parte frontal e traseira da fila são controladas por índices. Porém, essa implementação pode causar desperdício de espaço, pois o array precisa ser redimensionado quando a fila cresce.

2. **Implementação usando Linked List (_Lista Encadeada_)**: Nessa abordagem, cada elemento da fila é um nó na lista encadeada. Isso permite adicionar e remover elementos de forma eficiente, sem desperdício de espaço.

## Algoritmos e situações de uso de filas:

1. **Breadth-First Search (_Busca em Largura_)**: Usada para percorrer grafos de maneira ordenada, explorando todos os vértices vizinhos de um vértice antes de avançar para os próximos níveis.

2. **Gerenciamento de Tarefas**: Em sistemas operacionais, filas são usadas para gerenciar processos e threads em execução, garantindo a justiça e a ordem das tarefas.

3. **Print Queue (_Fila de Impressão_)**: Em sistemas de impressão, os trabalhos de impressão são enfileirados para serem impressos na ordem em que foram solicitados.

4. **Algoritmos de Scheduling (_Escalonamento_)**: Em sistemas de tempo compartilhado, as tarefas podem ser agendadas usando filas para garantir que cada tarefa tenha uma chance justa de execução.

5. **Buffering**: Em sistemas de comunicação, filas são usadas para armazenar dados temporariamente enquanto estão sendo transferidos entre diferentes partes do sistema.

6. **Trabalho por Lotes (_Batch Processing_)**: Em processamento em lote, os trabalhos são enfileirados e executados sequencialmente, mantendo a ordem de chegada.

7. **Solução de problemas de "Sliding Window"**: Em algoritmos de janelas deslizantes, as filas podem ser usadas para manter elementos relevantes dentro de uma janela móvel.

Lembrando que o uso de uma fila depende da necessidade específica do problema. Elas são particularmente úteis em situações onde a ordem de chegada ou prioridade são importantes.
