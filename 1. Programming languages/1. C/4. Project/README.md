# Descrição do Projeto

Neste projeto, você criará um programa em C que permite ao usuário gerenciar uma lista de tarefas (tipo um Todo list). O programa deve permitir a adição e remoção de tarefas, a exibição da lista de tarefas e a marcação de tarefas como concluídas ou não concluidas.

## Fluxo do Programa (usuário)

1. O programa inicia e carrega a lista de tarefas de um arquivo (se o usuário quiser).
2. Exibe um menu com opções para o usuário, que pode escolher entre adicionar, remover, editar e mostrar tarefas.
3. Ao sair do programa, as alterações são salvas no arquivo (se o usuário quiser).

## Fluxo do Programa (desenvolvedor)

1. No início do programa o arquivo que armazena as listas será lido (cada linha não vazia do arquivo é uma tarefa e cada tarefa é mapeada para uma struct que então pode ficar aramzenada em uma linked list de structs - adição no inicio da lista pra ter O(1)).
2. Com a lista de structs em mãos é possivel adicionar, remover, ver e modificar tarefas dessa lista (linked list). Ao final do programa o conteúdo atual da lista sobreescreve o conteúdo que estava no arquivo (tipo, apaga todas as linhas do arquivo e escreve toda a lista).

## Lista de requerimentos

- Struct que serve para representar uma tarefa. Deve conter campos para o título (`title`) com tamanho máx de 32 chars, para a descrição (`desc`) com max size de 256 chars, para o campo enum `status` que é 0 ou 1 (flag booleana para saber se está concluida) e um campo `id` para poder fazer modificações e deleção.

- Linked list simplificada para armazenar as tarefas na memória do programa. A adição de tarefas será feita no início da linked list fornencendo O(1). Será O(n) para deletar/modificar, utilzando o id da struct como parâmetro de procura.

- Outra struct que serve para representar o arquivo e mapear o texto do arquivo para objetos e vice-versa. Como estamos usando linked lists ela também vai conter o Head da linked list que representa as tarefas em memória. Cada linha do arquivo vai possuir os 4 campos da struct separados por ";"

- Função para gerar ids aleatórios para cada struct

## Estrutura do projeto

```
.
└── Project/
    ├── include/
    │   ├── core/
    │   │   └── main.h
    │   ├── task/
    │   │   └── task.h
    │   ├── tasklist/
    │   │   └── tasklist.h
    │   ├── workbook/
    │   │   └── workbook.h
    │   ├── id/
    │   │   └── id.h
    │   └── lib/
    │       ├── types.h
    │       ├── input.h
    │       └── consts.h
    ├── src/
    │   ├── core/
    │   │   └── main.c
    │   ├── task/
    │   │   └── task.c
    │   ├── tasklist/
    │   │   └── tasklist.c
    │   ├── workbook/
    │   │   └── workbook.c
    │   ├── id/
    │   │   └── id.c
    │   └── lib/
    │       └── input.c
    ├── data.txt
    └── program.exe
```

Dentro da pasta do `include` estão todas os arquivos de cabeçalho (headers), que são onde fazemos a declaração de structs, enums e assinaturas de funções. Dentro de `src` está o código fonte/implementação. O arquivo `main.c` é o principal, inglobando/usando/importando todos os outros arquivos. Para rodar o programa você deve primeiro, antes de qualquer coisa, cria um arquivo de texto (preferencialmente com um nome sem espaços), ir até `workbook.c` e nas funções `mapFromFileToList` e `mapFromListToFile` colocar o `path` de onde o arquivo de texto está.
compilar ele usando o comando:

Depois disso você deve abir o terminal, ir/andar até o diretório onde `main.c` está e então rodar o comando:

```bash
gcc ./main.c ../lib/input.c ../id/id.c ../task/task.c ../tasklist/tasklist.c ../workbook/workbook.c -o ../../program.exe
```

Após isso é só executar "program.exe" que apareceu no path que vc deu (depois do `-o` é onde vc coloca o path de para onde seu programa vai ser gerado)

## Limitações/Problemas

1. O texto escrito em `title` e `desc` tem que ser ASCII, ou seja, nada de acentos, emojis ou etc.
2. O texto escrito em `title` e `desc` não pode ser multilinha (conter \n - quebras de linha)
3. O texto escrito em `title` e `desc` não pode usar o caractere ";". Como alternativa vc poderia usar outro tipo de arquivo (ao invés .txt poderia ser .csv, por exemplo)
4. Como uma task não tem precendencia ou ordem em relação a outra, a linked list não é o melhor data type para se usar (além de que demora O(n) para iterar)
5. Toda adição de tasks é feita no inicio da lista, que para o nosso caso é bom (O(1)), mas se vc quiser manter uma ordem vai ter que fazer algum paranauê (trocar a data structure ou usar uma função para ordenar com base em algum critério, tipo data de criação)
6. Toda vez que for salvar o arquivo vc deleta todas as linhas e reescreve tudo dnv (o q é ridiculamente custoso). Como alternativa vc pode adicionar no campo struct o número da task no arquivo, assim vc talvez consiguiria modificar só linhas especificas ao invés do arquivo todo
7. Como n estou usando makefiles se um único arquivo mudar de lugar todo o programa dá pau (teria que mudar manualmente todos os includes)

## E oq vc tem haver com isso?

Na minha humilde opnião vc só tem 2 motivos minimante válidos para estar lendo esse README:

1. Vc está me avaliando. Nesse caso, agradeço pela atenção e aguardo humildemente meu aumento.
2. Vc quer aprender. Nesse caso existem duas abordagens que recomendo:
   - tente criar o projeto vc mesmo. Pode ser com ajuda do google, chatgpt ou qqqr outra coisa, mas tente fazer sozinho.
   - leia o código, corrija os erros (que com certeza existem) e crie comentarios. Para provar q vc entendeu, faça comentarios para cada uma das funções, explicando oq elas fazem

## Conclusão

Esse projeto me levou 3 dias, 3h/dia em média. Hasta la vista.
