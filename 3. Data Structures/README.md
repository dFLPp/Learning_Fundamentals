## Considerações iniciais

Essas anotações são referentes as conceitos fundamentais/basicos sobre data structures. Uma vez que você conseguiu o dominio sobre as funcionalidades básicas de uma linguagem de programação e já consegue resolver problemas sozinhos (desenvolveu a "visão computacional"), você está pronto para aprender sobre como os dados são guardados.
Nesse mundo tecnológico tudo são dados, seja de texto (encriptado ou não-encriptado) da nota fiscal de um super-mercado até uma imagem específica de um video pego em uma camera de segurança.

As grandes companias e a tecnologia no geral precisa desenvolver métodos para obter, armazenar e acessar esses dados eficientemente.
Por exemplo, como um computador que tem não interface gŕafica vai mostrar ou armazenar imagens? Ou então, como eu consigo trocar a foto de perfil de um usuário (dentro milhões de usuarios) que já foi vista por milhares de pessoas? Perguntas como essas trazem a tona Data Structures. Cada dado, cada informação que precisa ser armazenada, Deve ser armazena do melhor jeito possivel, ou seja, existem diferentes jeitos de se armazenar e Acessar diferentes tipos de dados. Também não vamos esquecer que, só guardamos o que precisamos, e se precisamos de algo é porque vamos usar novamente, dessa forma, o ato de busca um dado específico dentre vários outros também é um fator relevante na hora de escolher um modo de arrumar os dados (ou seja, escolher a data struc [ds]).

Nessas anotações vou fazer a apresentação das data structs mais importantes e usadas em situações reais. Isso vai ser feito com a liguagem C. Disclaimer: Aprender data Structs pode ser feito com qualquer linguagem, pois está alheia as linguagens (funciona em qualquer lugar e é do mesmo jeito, mudando a implementação). Vou fazer C por que, além do nível de dificuldade elevado, o aprendizado "nas piores circunstâncias" torna os problemas médios e faceis, muito mais faceis. Locais úteis para estudar: https://www.javatpoint.com/data-structure-tutorial e chatGPT.

## Estrutura e terminologia

Uma data structure é um ou vários algoritimos que emplementam o armazenamento os dados na memória (efetivamente guarda na memória). Esses varios algoritimos/modos de armazenar os dados são chamados de abstract data types (**ADT**) e, como os ADT == algoritimos, cada ADT tem um conjunto de regras/logica que permite o seu funcionamento.
É importante deixar claro que data structs estão completamente ligadas à algoritimos. Algoritimo é um conjunto de instruções finitas que pegam um input e transforma ele em um output desejado. Nesse aspecto se você trata os inputs como "raw data" e o output como os dados organizados em DS's, então existe algoritimo inerente/pertencente à Data structure.

Existem 2 tipos de DS's:

- Primitive: DS's primitivos são os data types primitivos, ou seja, int, char, float, etc.
- Non-primitive: É dividido em 2 tipos: - Lineares: armazenam os dados de maneira contígua na memória, ou seja, um elemento está conectado a um único outro elemento, em uma forma linear - Não lineares: Quando um elemento está conectado a outros 'n' elementos de uma maneira aleatória/não linear. Ex: trees, graphs.
  D's também podem ser classficadas como estáticas (o tamanho máximo é pre definido, antes do programa rodar), como as arrays/vectors e Dinâmicos (o tamanho máximo varia durante a execução do programa), como as linked list, queue e stack.

Como DS's são implementações de algoritimos, existem algumas funcionalidades/caracteristicas gerais que encontramos:

1. Searching (podemos procurar/verificar se um elemento existe/está contido na DS)
2. Sorting (podemos ordenar os elementos)
3. Insertion (podemos adicionar elementos)
4. Deletion (podemos retirar elementos)
5. Updation (podemos trocar um elemento por outro)
6. Merging (juntar duas ADT's (do mesmo tipo) em uma)

## Asymptotic Analysis

Um jeito de saber qual DS é a melhor é ao analisar o seu consumo de tempo e seu consumo de espaço de memória. Imagine que você quer colocar um elemento no inicio de uma array. Você precisaria mexer/empurar todos os "n" elementos que já existem, dessa forma tendo uma complexidade definida por uma função f(n). É interranste usar as funções como base porque dessa forma podemos levar esse conceito de análise de gastos para outras áreas (sem ser necessáriamente programação).

No geral podemos analisar 3 casos:

- O pior cenário (mais gasto) --> Big O Notation
- O melhor cenário (menos gasto) --> Omega Notation
- O cenário comum(gasto intermediário) --> Theta notation

Existe um conceito/base matemática por trás, porém ela é irrelevante. O mais importante é saber definir o Big O de uma data structure.
No geral, sempre que você vai comparar DS's, você testa o quanto elas gastam de tempo ao fazer a mesma atividade, sendo essas atividades as funções básicas de um algoritimo, ou seja, adicionar um elemento, remover um elemento, iterar, procurar, juntar duas ADT iguais e etc.

### Exemplo de análise

**Comparação entre Arrays e Linked Lists**

| Operação            | Complexidade de Tempo (Linked List) | Complexidade de Espaço (Linked List) | Complexidade de Tempo (Array) | Complexidade de Espaço (Array) |
| ------------------- | ----------------------------------- | ------------------------------------ | ----------------------------- | ------------------------------ |
| Acesso (por índice) | O(n)                                | O(1)                                 | O(1)                          | O(n)                           |
| Inserção no início  | O(1)                                | O(1)                                 | O(n)                          | O(n)                           |
| Inserção no fim     | O(n)                                | O(1)                                 | O(1)                          | O(n)                           |
| Inserção no meio    | O(n)                                | O(1)                                 | O(n)                          | O(n)                           |
| Remoção no início   | O(1)                                | O(1)                                 | O(n)                          | O(n)                           |
| Remoção no fim      | O(n)                                | O(1)                                 | O(1)                          | O(n)                           |
| Remoção no meio     | O(n)                                | O(1)                                 | O(n)                          | O(n)                           |
| Busca               | O(n)                                | O(1)                                 | O(n)                          | O(1)                           |

> Repare portanto que cada DS é boa/útil em certas circunstâncias, sendo necessário analisar o que você quer fazer, em que escala você quer fazer e o porque você quer fazer.

## Infix, postfix e prefix

São jeitos de Se escrever operações, na maioria matemáticas. São aplicações de stack para analise de expressões arimitéticas. Basicamente, quando você escreve (2+3)\*5, primeiro a soma entre parenteses deve ser feita, ou seja, ela é adicionada a stack e a multiplicação só é feita quando a stack for esvaziada.

- No Infix: <operando><operator><operando>. Infix é a operação matematica "Normal" só que aplicada no compudador. Seguimos a ordem PEMDAS e usamos parenteses, chaves e colchetes para estrututar a ordem das operações.
- No Prefix: <operator><operando><operando>. Ou seja, a operação infix "2+3" seria escrita como "+ 2 3", ou a operação "a + b*c" seria escrita como "+ a * bc"
- No postfix: <operando><operando><operator>. Ou seja, a operação infix "2+3" seria escrita como "2 3 +" ou a operação "a + b\*c" seria escrita como "abc \* +"

Do ponto de vista humano não faz sentido nenhum fazer essas conversões, entretanto os computadores entendem e funcionam melhor com essas abordagens alternativas (aparentemente).

Existem algoritimos que leem expressões em postfix ou prefix e que apartir dai calculam o resultado. A ideia básica para ambos os casos é, você cria uma stack e itera sobre uma string/expressão. Se o elem. for um número você coloca ele na stack, se for uma operação, você usa os dois ultimos(primeiros) elementos da stack, faz a operação em ordem correta (depende do tipo) e então faz o pop desses dois números.

Também existem algortimos que leem a expressão em infix e convertem para postfix e prefix, mudando a implementação dependendo do caso, mas no geral a ideia é: você cria uma stack e itera sobre a expressão. Se o elemento atual for um número você adiciona ele na string/resultado. Se o elemento for uma operação, ele vai para a stack e espera que o operando da direita(ou esquerda) apareça. Além disso é necessário iterar sobre toda a stack e analisar a precedencia do operador a ser "Pushado" e os operadores que já existem.
