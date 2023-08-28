# Descrição do Projeto

Neste projeto, você criará um programa em C que permite ao usuário gerenciar uma lista de tarefas (tipo um Todo list). O programa deve permitir a adição e remoção de tarefas, a exibição da lista de tarefas e a marcação de tarefas como concluídas ou não concluidas.

## Fluxo do Programa (usuário)

1. O programa inicia e carrega a lista de tarefas de um arquivo.
2. Exibe um menu com opções para o usuário.
3. O usuário pode escolher entre adicionar, remover, editar e mostrar tarefas.
4. Ao sair do programa, as alterações são salvas no arquivo.

## Fluxo do Programa (desenvolvedor)

1. No início do programa o arquivo que armazena as listas será lido (cada linha não vazia do arquivo é uma tarefa e cada tarefa é mapeada para uma struct que então pode ficar aramzenada em um array ou linked list de structs).
2. Com a lista de structs em mãos é possivel adicionar ou remover tarefas dessa lista. Ao final do programa o conteúdo atual da lista sobreescreve o conteúdo anterior que estava no arquivo com o conteúdo novo.
3. Além disso, enquanto o programa está rodando, é possivel ver (fazer o printf) de todas as tarefas além de poder pesquisar por uma tarefa em específico e mudar seu status (de completa para imcompleta ou vice-versa).

## Lista de requerimentos

- Struct que serve para representar uma tarefa. Deve conter campos para o título (`title`) com tamanho máx de 32 chars, para a descrição (`desc`) com max size de 256 chars, para o campo enum `status` que é 0 ou 1 (flag booleana para saber se está concluida) e um campo `id` para poder fazer modificações e deleção.

- Linked list simplificada para armazenar as tarefas na memória do programa. A adição de tarefas será feita no início da linked list fornencendo O(1). Será O(n) para deletar/modificar, utilzando o id da struct como parâmetro de procura.

- Outra struct que serve para representar o arquivo e mapear o texto do arquivo para objetos e vice-versa. Como estamos usando linked lists ela também vai conter o Head da linked list que representa as tarefas em memória. Cada linha do arquivo vai possuir os 4 campos da struct separados por ";-;"

- Função para gerar ids para cada struct

- [Descartado] Usar uma stacks para salvar o estado da linked list e implementar a funcionalidade undo e redo (fique a vontade para tentar fazer, n é dificil, mas só salvar o head da lista na stack n é o sufuciente)

## Como executar

Mova/abra o terminal no diretório do main.c e execute o comando:

`gcc ./main.c ../lib/input.c ../id/id.c ../task/task.c ../tasklist/tasklist.c ../workbook/workbook.c -o ../../program.exe`

Após isso é só executar "program.exe" que apareceu no root do programa.

## Limitações

1. O texto escrito em title e desc tem que ser ASCII, ou seja, nada de acentos, emojis ou etc.

## Problemas

- Segmentation fault ao tentar salvar no arquivo
- se a task é feita dentro do programa title e desc n aceitam espaços (mas se carrega do arquivo funciona just fine)
