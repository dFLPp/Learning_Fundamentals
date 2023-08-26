# C - anotações

## Sumário

1. [Introdução](#introdução)
2. [Workflow de um programa](#workflow-de-um-programa)
3. [Layout de memória](#layout-de-memória)
4. [Indentificadores](#indentificadores)
5. [Tipos de dados](#tipos-de-dados)
6. [Declaração de variáveis](#declaração-de-variáveis)
7. [Escopos de variáveis](#escopos-de-variáveis)
8. [Classes de variáveis](#classes-de-variáveis)
9. [Operadores](#operadores)
10. [Estruturas de controle de fluxo](#estruturas-de-controle-de-fluxo)
11. [Funções](#functions)
12. [Macros e Header files](#macros-e-header-files)
13. [Pointers](#pointers)
14. [Alocação dinâmica](#alocação-dinâmica)
15. [Structs](#estruturas-structsstructures)
16. [Enums](#enumeradores-enums)
17. [Unions](#uniões-unions)
18. [Manipulação de arquivos](#manipulação-de-arquivos)
19. [Conclusão](#conclusão)

## Introdução

C é uma linguagem de programação compilada de propósito geral, estruturada, imperativa e procedural criada em 1972 por Dennis Ritchie na empresa AT&T Bell Labs para desenvolvimento do sistema operacional Unix.
Em 2022 fez 50 anos, sendo conhecida por ser a linguagem "mãe" de várias outras (python, rust, etc). Tem como característica a não existência de um garbage colector, sendo necessário fazer um controle de memória preciso.

## Workflow de um programa

C é uma linguagem compilada, ou seja, depois que você escreve o código (source code) ele precisa passar por um compilador. Em realidade existem alguns passos que são omitidos, por isso elenco o processo completo:

1.  Programa escrito em C é passado para o **preprocessor** que aplica as diretivas que o programador especificar.
2.  O preprocessor expande o código escrito em C (_source code_) e então manda o código para o **compiler**.
3.  O compiler transforma o source code em _assembly code_ e então manda ele para o **assembler**.
4.  O assembler transforma o codigo em _Object code_ então manda ele para o **linker**.
5.  O linker vai juntar o object code com as libraries e e outras funções e gera o código executvel (_.exe_).
6.  O .exe é carregado na memória pelo **loader** que então executa o programa.

## Layout de memória

Todas as variáveis, funções e estruturas de dados definidas no C são armazenadas na memória. Existe uma representação sobre como essa mémoria é organizada, sendo feita em 4 partes/áreas:

1. Data area: É área de "memoria permanente". Todas as static e external variables são armazenadas aí, mas só existem até o final da execução do programa.
2. Code area: É a parte da memória que só pode ser usada por pointers de funções. O tamanho dessa área é fixo.
3. Heap area: É a parte da memória que é acessada/usada durante a alocação dinâmica de memória, que é feita com malloc() e calloc(). O tamanho varia de acordo com a memória disponivel.
4. Stack area: Também chamada de "temporary memory area", é onde variaveis locais, constantes, funções, return de funções e parâmetros são armazenados. Os valores são excluidos assim que saem do seu respectivo escopo.

## Indentificadores

São os nomes que você dá para as variáveis. Você não pode usar caracteres especiais nem palavras reservadas. Para saber o que pode e o que não pode olhe [esse](https://learn.microsoft.com/pt-br/cpp/c-language/c-identifiers) artigo da Microsoft.

## Tipos de dados

Em C em existem 5 data types Básicos que definem que tipo de valor que pode ser armazenado em uma variável:

- char: armazena carateres e srings.
- int: armazena números inteiros.
- float: representa números reais "Sem" precisão nas casas decimais.
- double: representa números reais "Com" precisão nas casas decimais.
- void: representa a falta de conteúdo de uma variável.

OBS: Para os tipos de dados números é possivel usar algum dos modificadores a seguir para modificar o intervalo válido de valores aceitos pela variável: _signed_, _unsigned_, _long_ e _short_.

OBS: No C puro não existe o tipo booleano (true ou false), mas dá para adicionar com bibliotecas ou até msm criar esse tipo de dado com structs.

## Declaração de variáveis

Uma variável é uma posição indentificada pelo nome dado a ela (indentificador) e é usada para guardar um valor de uma determinado tipo. Cada tipo armazena valores de diferentes tamanhos. Variáveis podem trocar de valor desde que você use os sinais de atribuição e que os valores atribuidos sejam do mesmo tipo que o da variável.

```c
int a, b; // declaração de variáveis - valores aleatórios atribuidos
// atribuição de valores
a = 3;
b = a \* 7;
a += b;
b -= a;
```

Constantes são indentificadores que não podem ter seus valores alterados durante a execução do programa. Para declarar constantes você usa a diretriz `#define`.
Constantes declaradas com o #define tem escopo global. Outro modo de declarar uma constante é usar a keyword

```c
#define INTEIRO 12
#define STRING "o nome das constantes idealmente devem ser maiúsculos."

int main(){
	const char abacate = "wow";
	return 0;
}
```

## Escopos de variáveis

Variáveis locais são aquelas declaradas dentro de uma função ou dentro de um bloco de código separado. Se você declara uma variável local dentro de um bloco condicional, por exemplo, a memória só será alocada para ela se o bloco condicional for executado e só poderar acessar o valor dela dentro do bloco condicional.

Variáveis globais são aquelas declaradas fora de qualquer função (no começo do código) e que pode ser usada em qualquer parte do programa. O armazenamento de variáveis globais encotra-se em uma região "fixa" da memória, salvando seu valor durante toda a execução do programa, sendo úteis quando um mesmo dado é usado em muitas funções.

## Classes de variáveis

Além de seu escopo e de seu indentificador, uma variável também é classificada por classes.

- auto: São as variáveis que criamos normalmente. O valor padrão de uma variável "auto" é Garbage Value, ou seja, um valor qualquer/aleatório. Essas variáveis são armazenadas na RAM e elas só existem/podem ser utilizadas enquanto a função em que foram declaradas estiverem rodando/funcionando.

- static: São variáveis declaradas com a keyword _static_. Elas tem escopo local, são armazenadas na RAM e seu valor inicial é 0 ou null. Ela pode ser usada em qualquer momento antes do final da "main" e sua caracteristica é poder "reter"/manter seu valor depois de multiplas chamadas. Execute o exemplo abaixo duas vezes, uma com as keywords "static" e outra sem, para perceber a diferença.

  ```c
  #include<stdio.h>
  void sum(){
  	static int a = 10;
  	static int b = 24;
  	printf("%d %d \n",a,b);
  	a++;
  	b++;
  }

  void main(){
  	for(int i = 0; i < 3; i++) sum();
  }
  ```

- register: São variáveis declaradas com a keyword _register_. Elas tem escopo local, são armazenadas no "registrador" do CPU e seu valor inicial é 0 ou null, possuindo tempo de chamada e execução melhor. Contudo fica a critério do compilador se de fato são armazenados no registrador.

- extern: São variáveis declaradas com a keyword _extern_. Elas em escopo Global e são armazenadas na RAM. Sua caracteristica é poder ser declarada em qualquer lugar do programa, dentro ou fora da main.

## Operadores

- De atribuição: =;
- Aritiméticos: ++, --, -, \*, /, %, +, -; (em ordem de precedência/prioridade decrescente)
- relacional-logico: !(negação), >, <, >=, <=, ==(igual lógico), !=(diferente logico) &&, ||;
- Manipulação de pointers: & e \*.

## Estruturas de controle de fluxo

Existem 3: comandos de seleção, de repetição e de desvio. São usadas para controlar o fluxo de processamento do programa, tipo: "Se o pedido de soverte tem cobertura, adicione cobertura, senão passe para a proxima pergunta sem adicionar cobertura".

### Comandos de seleção (condicionais)

1.  If:

    ```c
    int x = 10;
    if(x > 10){
         x = 2;
    }
    else if(x < 10 && x > 0){
        x = 7;
    }
    else{
        x = 1;
        //esse bloco seria executado
    }
    ```

2.  Switch:

    ```c
    char c = "a";
    switch(c){

    case 'a':
    	printf("A");
    	break;

    case 's':
        return 1;
        //um return só funciona dentro de uma função ent suponha q esse trecho está dentro da main
    	break;

    default:
    	break;
    }
    ```

3.  Operador ternário:

    ```c
    int x = 10;
    int y = x > 9 ? 100 : 200;
    // se x for maior que 9, y = 100, senão y = 200
    ```

### Comandos de repetição (loops)

1.  while

    ```c
    int contador = 1; //variável de "controle" externa
    while (contador <= 100){
    printf("%d\n", contador);
    contador++; //sem isso teriamos um loop infinito
    }
    ```

2.  do ... while

    ```c
    int contador = 1;
    do{
        printf("%d\n", contador)
    } while (contador <= 100);
    // A diferença entre o while e o do-while é esse checa a condição Depois de cada execução.
    ```

3.  for
    ```c
    for(int contador = 1, contador <= 100, contador++){
        printf("%d\n", contador);
    }
    ```

### Comandos de desvio

O C tem 4 comandos que realizam "desvio incodicional", ou seja, trocam em que lugar o programa está sendo executado. Por exemplo, se você está dentro de um nested loop e já obteve o resultado que queria, pode usar algum desses comandos (dependendo da situação) e então sair desse loop. Os comandos são: return (para funções), goto, break e continue.

1.  return:
    Quando dentro de uma função, é usado para retomar ao ponto em que a função foi chamada. Se a função tiver algum valor associado a ela, ele é retornado. A função para de executar tão logo encontre o primeiro return, ou seja, todo código depois do return (dentro do msm bloco) é ignorado (em realidade nem é lido).0

2.  goto:
    É usado em raras situações. Ele funciona da seguinte forma: Você deve criar um checkpoint chamado de rótulo que vai ser o local onde o programa vai voltar quando o "goto" for chamado.
    O rótulo (ou label) tem um nome e é seguido por dois pontos. Todo o código que deve ser executado depois de "carregar o checkpoint" deve estar indentado. Entenda que o "goto" não é um bloco de código. Ele simplismente vai redirecionar o "leitor" até o checkpoint e entõ seguir com o código, linha à linha. Com ja dito, não é recomendando usar o goto, porém uma das situações onde ele é util é quando queremos sair de um nested loop de uma vez só.

    ```c
    #include <stdio.h>
    #define MAX_TRY 20

    void main(){
        double num, media, soma = 0.0;
        int i = 0;
        for(i = 0; i < MAX_TRY; i++){
            //OBS: O i que é acresido (++) é o fora de escopo.
            printf("%d. Diga um número: ", i);
            scanf("%lf", &num);
            if (num < 0.0) goto teleport;
            soma += num;
        }

        teleport:
        media = soma / (i - 1);
        printf("A soma é = %.2f\n", soma);
        printf("A média é = %.2f", media);
    }
    ```

3.  break:
    Normalmente é usado para terminar um "case" em um comando switch ou para forçar a finalização de um loop antes que ele cheque a condição. De modo semelhante ao break existe a função exit() da biblioteca padrão provoca o término imediato do programa inteiro (do main).

4.  Continue:
    Serve para pular uma iteração espcífica sem sair do loop completamente.

    ```c
    #include <stdio.h>
    int main(){
        char s[80], *str;
        int space = 0;

        printf("diga uma string: ");
        fgets(s, 80, stdin);

        str = s;
        for (; *str; str++){
            if (*str != 32) continue;
            else space += 1;
        }
        printf("%d espaços \n", space);
        return 0;

        //Pego string como input e armazeno numa array
        //Associo um pointer para a array
        //(em arrays em especifico n preciso usar & pq automaticamente ela me apontar para o primeiro elem.)
        //Itero pelo array através do pointer de modo a pegar o valor do caractere ASCII
        //Se o valor ASCII para tal posição é 32 (espaço em branco), somo ao contador
    }
    ```

## Functions

Funções são conjuntos de comandos agrupados em um bloco e que são executados como um único grande comando. A função main (obviamente) é uma função. Uma função deve ter tipo de retorno, nome e, possivelmente, parâmetros. Se você diz que o tipo de uma função é "int", então ela Pode retornar um número inteiro. No caso de você usar void como o tipo da função, você n precisa/pode fazer o return.

```c
#include <stdio.h>

int fat(int num){
    if (num > 1) return num * fat(num - 1);
    else return 1;
}

void main(){
    int x, y;
    x = 5;
    y = fat(x);
    printf("O fatorial de %d é %d", x, y);
}
```

### Bibliotecas

Pessoas mais inteligentes que nós criaram várias funções de uso geral para que os pobres mortais usem. Para acessar essas funções você importa (#include) a biblioteca (que tbm é um arquivo escrito em C).

```c
#include<stdio.h>
#include<ctype.h>

void main(void){

    char ch;
    printf("-----------------------------------------\n");
    printf("Digite algo || Digite um ponto para sair.\n");
    printf("-----------------------------------------\n");
    do{
    	ch = getchar(); //getchar serve para retornar cada tecla selecionada (no final retorna uma string).
    	if(islower(ch)) ch = toupper(ch);
    	putchar(ch); //putchar vai escrever caracteres. Nesse caso vai escrever uma string
    	//Repare que tanto putchar quanto getchar trabalham em torno de caracteres únicos, mas mesmo usando vários(strings) eles ainda funcionam em função do uso de matrizes(vetores)
    } while (ch != '.');

}
```

### Parâmetros

Parâmetro é uma variável genérica que é usada na função; Argumento é o valor passado para a função que será usado com parâmetro. Argumentos podem ser passados para funções de duas maneiras:

#### Chamada por valor

É quando o argumento passado não é alterado pela função.

```c
int sqr(int x){
    return x*x;
}
void main(){
    int t = 10;
    printf("a variável é %d e o resultado da função é %d", t, sqr(t));
}
// o valor da variável t não é alterado
```

#### Chamada por referência

É quando o argumento passado É alterado pela função. Acontece quando vc passa para função um endereço de memória ao invés de uma valor fixo. Dessa forma a função vai alterar o valor da variável através do endereço dela.
Como a função deve acessar a memória os parâmetros da função devem ser ponteiros (pointers) e os argumentos podem ser justamente os

```c
void swap(int *x, int *y){
    //x e y são os parâmetros
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void main(){
    int i, j;
    i = 10;
    j = 20;
    swap(&i, &j); // Os endereços de i e j são argumentos
    //as variáveis i e j foram alteradas
}
```

#### vetores/matrizes

Quando você passa um vetor ou uma matriz como argumento de uma função, vc está, em realidade passando como argumento o endereço de memória do primeiro elemento. Dada a natureza de vetores e sabendo o tamanho que um elemento ocupa você pode facilmente iterar sobre a array/matriz usando pointers.

#### Na função main

Há dois argumentos especiais que podem ser passados na função main:

1. argc

Contém o número de argumentos/coisas que você escreve na linha de comando. Você deve separar cada argumento por um espaço ou por um Tab. Deve ser iniciado como "int". No mínimo argc é 1 porque o nome do arquivo é considerado um argumento.

2. argv

É um ponteiro para uma matriz de ponteiros para caracteres. No bom português, é um indice para cada caractere em uma string (que é um vetor). Deve ser inciado como "char".

```c
#include<stdio.h>
#include<stdlib.h>

void main(int argc, char *argv[]){
    // O [] indica que vários argumentos (indeterminado) podem ser escritos
    if(argc != 2){
        printf("Você não escreveu nada\n");
        exit(1);
    }
    printf("Essa foi a primeira coisa que você escreveu no terminal %s\n ", argv[1]);
}
```

### Recursividade

Ocorre quando uma função chama a sí mesmo dentro dela.
Em um dos exemplos acima (sobre farorial) você conseguirá perceber o uso de recursividade.
Claro que a chamada recursiva deve acontecer de um modo especial, evitando a execução infinita.
Recursão gasta muita mémoria e com C é uma linguagem complicada, onde você tem que administrar a memória de maneira muito específica, você deve usar de maneira consisa e direcionada. Vamos rever o exemplo do calculo do fatorial dessa vez usando protótipos de função.

```c
#include<stdio.h>

long unsigned int Fat(long unsigned int n); //Esse é o protótipo da função.
//serve para garantir a consistência dos tipos.

void main(){
    int num;
    long int result;
    printf("Diga um número: ");
    scanf("%d", &num);
    result = Fat(num);
    printf("O fatorial de %d é %ld", num, result);
}

long unsigned int Fat(long unsigned int n){ //essa é a atribuição/criação propria da função.
    if (n <= 1) return 1;
    else return n * Fat(n-1);
}

```

## Macros e Header files

Macros são instruções que você pode passar para o compilador de modo a "personalizar" a criação do executável. Alguns macros são usados nas source files (.c) e outros são exclusivos das header files (.h). Header files é são arquivos auxiliares aos arquivos de código. Eles auxiliam no processo de compilação ao evitar recompilar arquivos que não foram modificados além de serem usados para estruturar o código de melhor forma. Vejamos alguns macros e seu uso com header files.

- #define é usado basicamente para criar constantes "globais".
- #include diz ao compliador que arquivo/bibilioteca abrir (possibilitando usar as funções desses arquivos)
- #if, #else, #elif e #endif são condicionais destinadas diretamente ao compilador. Só funcionam quando usam Constantes para fazer a lógica.
- #undef é o contrário de #define, servindo para "desativar" variáveis/macros criados com o define.

Exemplo de uso de header files: Crie 3 arquivos: `exemplo.h`, `exemplo.c` e `main.c`. `main.c` será nosso ponto de entrada do programa (o programa só inicia ao executar esse arquivo). Apartir dele vamos usar funções e variáveis declaradas em `exemplo.c` ao msm tempo que usamos `exemplo.h` para complicar ainda mais a nossa vida. Vejamos os 3 arquivos:

- `exemplo.h`:

  ```c
  #ifndef EXEMPLO_H
  #define EXEMPLO_H

  extern int res; // declaração de uma variável global
  int soma(int x, int y);
  #endif
  ```

- `exemplo.c`:

  ```c
  #include "exemplo.h"
  //aq vc implementa oq foi declrado na header file
  int res;

  int soma(int x, int y){
      return x+y;
  }
  ```

- `main.c`:

  ```c
  #include "exemplo.c"
  #include <stdio.c>

  int main() {
      res = 2;
      printf("%d\n", soma(res,-2));
  }
  ```

## Pointers

Pointers são o endereço na memória de uma variável. Uma variável de ponteiro é uma variável especificamente declarada para guardar um ponteiro para seu tipo especificado. Pointers são úteis porque com eles você pode se referenciar a um elemento de uma matriz, permite que funções alterem/modifiquem os parâmetros passados na chamada e ajudam na manipulação de linked lists e outros data types complexos, além de outras coisas.

"&" é usado para se referir ao ENDEREÇO de uma variável na memória. Por exmplo "m = &count;" pode ser lido como "m recebe o Endereço de memória da variável count". O endereço de count é completamente diferente do Valor de count.

"*" é usado para se referir ao VALOR de uma variável, dado o seu endereço. Por exemplo "q= *m;" pode ser lido com "q recebe o Valor que está no endereço de m". Mas como sabemos que "m" tem como valor o endereço de memória de "count", então "q" vai receber o valor de "count".

```c
#include<stdio.h>
void main(void){
    int target, source;
    int* m;
    source = 10;
    m = &source;
    target = *m;
    printf("O target é: %d\n", target);
    printf("O endereço é %d\n", m);
}
```

### Dangling Pointers

São ponteiros que estão apontando para um indereço de memória inválido. Por exemplo, se um ponteiro está apontando para uma variável dentro do escopo, quando o código sair do escopo a variável vai ser deletada e o ponteiro vai apontar para um endereço inválido (ele Não é redirecionado para o NULL, sendo necessário fazer isso "manualmente").

### Ponteiros e matrizes

C fornece dois métodos para acessar elementos de matrizes:

- Aritimética de ponteiros:

  Mais rapida. Consiste em usar atribuir um pointer a uma matriz. Ele vai se referir ao primeiro elemento dessa matriz. Apartir daí, para se referir a outros elementos em outras posições basta somar um inteiro até o index desse elemento.

  ```c
  char str[80], *p1;
  p1 = str; //refere-se ao primeiro elem de uma matriz
  printf("%d", *(p1+4)); // vai printar o 5 elemento pois *(p1+4) se refere ao 5 index.
  ```

- indexação de matrizes:
  É basicamente usar colchetes e o index do elemento. No caso do exemplo anterior, fariamos `printf("%d", str[4])`;

### Ponteiros e funções

Você já viu que um ponteiro pode armazenar o endereço de memória de uma variável, mas e quanto armazenar o de uma função? As funções, assim como as variáveis Possuem endereço na memória (stack e code area). Para obter o endereço de uma função precisamos criar um pointer na mesma estrutura da função que queremos e então igualar ele à função original:

```c
float *fp (int, int); // Declaration of a function pointer.
float func(int, int); // Declaration of function.
fp = func; // Assigning address of func to the fp pointer.
```

```c
#include <stdio.h>

int soma(int a, int b) {
	return a+b;
}

int main(){
	int (*ip)(int, int) = &soma;
	printf("%d",(*ip)(10, 10));
	printf("%d",soma(10, 10));
	return 0;
}

```

## Alocação dinâmica

Ponteiros fornecem o suporte necessário para executar alocação dinâmica, isto é: O programa consegue obter memória enquanto está em execução. Imagine que você quer criar uma array com o tamanho igual ao input do usuário. Como o programa precisa rodar para fazer scanf e como não é possivel criar variáveis durante a execução do programa, a não ser que usemos uma das 2 funções principais: malloc() ou calloc(), que estão em `<stdlib.h>`.

A alocação dinâmica em C basea-se nas funções malloc() e calloc() para alocar memória e free() para liberar memoria Alocada. Elas trabalham em conjunto e utilizam/dependem do "heap" (região de memória livre) para manter uma lista de armazenamento disponível. Enquanto malloc vai criar um único Bloco de armazenamento, calloc vai criar vários blocos. Imagine que a memória RAM é um retangulo e que ao consumir memoria preenchemos esse retangulo com quadrados. Ao usar malloc criariamos um único quadrado com tamanho X e ao usar calloc criariamos n quadrados com x/n de tamanho. Repare que o tamanho não muda, mas o metodo de alocação sim. Vejamos 2 exemplos:

```c
//Usando malloc()
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s = -1, i = 0;
    int *arr;
    printf("Diga o tamanho da array: ");
    scanf("%d", &s);

    arr = (int *)malloc(s * sizeof(int));
    //pense em 1 bloco com tamanho s vezes o tamanho de um int

    for (i = 0; i < s; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", arr + i);
    }

    for (i = 0; i < s; i++)
    {
        printf("arr[%d] = %d\t", i, *(arr + i));
    }
    free(arr);
    return 0;
}
```

```c
//usando calloc()

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s = -1, i = 0;
    int *arr;
    printf("Diga o tamanho da array: ");
    scanf("%d", &s);

    arr = (int *)calloc(s, sizeof(int));
    //pense em 's' blocos de tamanho de um int

    for (i = 0; i < s; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", arr + i);
    }

    for (i = 0; i < s; i++)
    {
        printf("arr[%d] = %d\t", i, *(arr + i));
    }
    free(arr);
    return 0;
}
```

## Estruturas (structs/structures):

Em C, uma estrutura é usada para criar objetos ou estruturas de dados customizadas. Em linguagens de programações modernas utiliza-se de POO (programação orientada à objetos). As variáveis dentro da estrutura são chamadas de elementos ou campos. Campos de uma estrutura também podem ser uma estrutura. Nesse caso se diz que as estruturas estão aninhadas. Para se referir ao valor de um campo de uma variável do "tipo" da struct, você usa o ponto (st.prop).

```c
#include<string.h>
#include<stdio.h>

struct Endereco{
    char estado[2];
    char cidade[50];
    char rua[50];
    int numero;
};


int main(){
    struct Endereco endereco1 = {0};

    strcpy(endereco1.estado, "RJ");
    strcpy(endereco1.cidade, "Alguma cidade aí");
    strcpy(endereco1.rua, "Alguma rua aí");
    endereco1.numero = 23;

    return 0;
}
```

### typedef:

No exemplo acima, criamos o objeto `endereco1` usando o tipo `struct Endereco`. Podemos dar um novo nome para esse tipo usando `typedef`.

```c
typedef struct{
    char estado[2];
    char cidade[50];
    char rua[50];
    int numero;
} Endereco;


int main(){
    Endereco endereco1 = {0};
    // ...
    return 0;
}
```

### Struct padding

C é uma linguagem que preza por eficiência e que é usada em projetos do mundo real, tipo, foguetes, satélites e etc. Muitos, muitos, muitos detalhes não expostos nessas anotações são levados em consideração na hora de escrever qualquer linha. Um desses detalhes é o struct padding.

Quando você cria uma struct, meḿoria é separada para cada campo. Entretando dependendo do processador e da arquitetura usada, o tamanho da struct pode ser maior. Se o processador é de 32bits, ele lê a cada ciclo/por vez 4 bytes e se o processador for de 64bits, ele lê a cada ciclo/por vez 8 bytes.

```c
struct student{
    char a; // tipo char tem tamanho 1 byte
    char b; // tipo char tem tamanho 1 byte
    int c; // tipo int tem tamanho 4 bytes
}, st1;
//O tamanho de st1 "teoricamente" seria de 6, porém dependendo do processador e da ordem das properties, o tamanho pode ser maior.

```

No caso do exemplo anterior, em um processador e 32bits ele "leria" 1 byte de "a" e de "b" e mais 2 bytes de "c", precisando de outro ciclo para ler os 2 bytes finais de "c". Repare que o segundo "ciclo" de leitura do processador foi ruim/ineficaz, sobrando 2 bytes de leitura.

Struct padding vai ser a funcionalidade automatica de obter o melhor modo de leitura possivel, usando todas as 8 ou 4 cargas de cada ciclo e tentando não dividir as variaveis/properties pela metade. Para que isso seja feito, o compilador automaticamente cria uma linhas vazias para ocupar espaço, entre outras estratégias, como usar diretivas ao pré-processador ([Macros](#macros-e-header-files)).

### Ponteiros de Structs

Ponteiros de uma struct passam apenas o endereço da estutura. São normalmente usados quando vc quer passar um objeto/instância de uma struct para uma função. Para acessar as props dessa struct utiliza-se da notação de seta (st->prop).

```c
#include <stdio.h>

typedef struct
{
    int TYPE;
    int operand1;
    int operand2;
} Operation;

int execute(Operation *op)
{
    switch (op->TYPE)
    {
    case 0:
        return op->operand1 + op->operand2;

    case 1:
        return op->operand1 * op->operand2;

    default:
        return 0;
    }
}

int main()
{
    Operation op = {0};

    op.operand1 = 7;
    op.operand2 = 3;
    op.TYPE = 1;

    printf("Resultado da operação: %d", execute(&op));

    return 0;
}
```

## Enumeradores (Enums):

O tipo "enum" é usado para criar uma enumeração, normalmente sendo usada para especificar todos os valores legais que uma variável pode ter, No exemplo anterior, com structs, ao invés de classificar o tipo de operação por números inteiros poderiamos usar enums:

```c
typedef enum{
    ADD = 0,
    MUL,
} OP_TYPE;

typedef struct{
    OP_TYPE TYPE;
    int operand1;
    int operand2;
} Operation;

// O resto do código é o msm
```

## Uniões (unions)

Em C uma "union" é uma posição de memória que é compartilhada por duas ou mais variáveis diferentes, geralmente de tipos diferentes e em momentos diferentes.

```c
typedef union{
    int i;
    float f;
} Uniao;

void doSomething(Uniao *un){
    un->f = 2.3;
}

int main(){
    Uniao un = {0};
    un.i = 10;
    doSomething(&un);
    return 0;
}
```

## Manipulação de arquivos

C não possue comandos de I/O por padrão. Para realizar alguma operação de input ou output é necessário importar bibliotecas, ou seja, existem diferentes formas de fazer a msm coisa. Para operações de input (I) e output(O) que involvem o terminal de comandos normalmente utiliza-se o `<stdio.h>`.

### Stream e arquivos

Um conceito meio abstrato e entender é o de stram. Basicamente o computador pode se comunicar com diversos equipamentos, através de diferentes canais, usando diferentes protocolos. Em outras palavras, um computador pode enviar ou receber dados do mouse, através do cabo usb, ou enviar informações pelo ar para uma empressora do outro lado da sala. Para que programadores consigam interagir com esses diferentes equipamentos sem precisar entender a metodologia de comunicação específica existe o conceito de stream: um tradutor universal.

Nessas anotações vamos nos restringir a como receber informações e enviar informações através de arquivos. Arquivos, no contexto de c e linux, vão desde documentos que estão armazenados no disco rigido até a representação virtual de uma impressora, sendo acessados/modificados pelo nosso programa (que existe na mermória RAM) através de uma stream específica o tipo de arquivo.

Quando você abre um arquivo, ele se associa/se liga com uma stream, que então "padroniza" o arquivo, e deixa ele "bonito", de modo que o programador/usuário consiga usar/modificar o arquivo. Existem duas formas de streams, ou seja, C pode receber/analisar/interagir com 2 tipos de input de arquivos:

- Texto: Uma stream de texto é uma sequência de caracteres onde, dependendo do dispositivo externo, talvez seja necessário coverter/traduzir alguma parte do input que esse dispositivo está mandando. Os dados são gravados no formato ASCII.

- Binário: Uma stream binária é uma sequência de bytes, de modo que o "conteúdo" original (que está no dispositivo original) é passado sem perda de integridade (não há conversão/tradução). Os dados são gravados no formato binary file (.bin)

### Modo de abertura

Para abrir um arquivo você precisa, primeiro, saber o que vai fazer com ele: vai escrever nele? Onde? No início ou no final? Se for em outro local (no meio por exemplo), como você vai chegar naquela posição específica?
Para restringir a imensa capacidade de programadores inexperientes de fazer merda, você deve escolher um modo de abertura: Só leitura (r), Só escrita (sobrescrita) (w), Só anexo (adiciona no final) (a) ou alguma combinação entre as 3 (w+, r+ e outras variações com um 'b' no final, para arquivos binários).

### Usando ponteiros

"Ponteiros" são a cola que une o sistema C com o I/O. Um ponteiro de arquivo é uma Variável ponteiro (que já vimos antes) do tipo FILE que é usada para ler e escrever arquivos. Através da função fopen() o C vai abrir/criar uma stream para uso e associa um arquivo a essa stream, retornando um ponteiro de arquivo. Dessa forma é possível alterar/manipular arquivos no C (através do ponteiro).

Em suma, vc declara um ponteiro do tipo `FILE`, chama a função `fopen()`, faz o que tem que fazer e então chama a função `fclose()`. Fechar a stream (equivalente à chamar fclose ou a liberar o ponteiro) é importante para: 1. salvar as modificações e 2. liberar a memória usada pela stream.

```c
// Exemplo: programa que lê um arquivo de texto e imprimi seu conteúdo na tela.

#include<stdio.h>
#include<stdlib.h>

void main(){

    FILE *arq;
    char linha[100];
    char *result;
    int i = 1;

    arq = fopen("abacate.txt", "rt");
    if (arq == NULL){
    	printf("Problemas em abrir o arquivo");
    	exit(1);
    }

    while (!feof(arq)){
    	result = fgets(linha,100,arq);
    	if (result){
    		printf("linha %d: %s", i, linha);
    	}
    	i++;
    }
    fclose(arq);

}
```

```c
// Programa que lê uma string e a grava num arquivo de texto.

#include<stdio.h>
#include<stdlib.h>

void main(void){
    FILE \*fp;
    char s[80];

    if((fp=fopen("abacate.txt", "a")) == NULL){
        printf("Arquivo não reconhecido.\n");
        exit(1);
    }

    printf("Escreva uma palavra: ");
    fscanf(stdin, "%s", s); // parecido com scanf, mas lê strings.
    fprintf(fp, "%s", s); //"printa" a string no arquivo (grava na memória).
    fprintf(stdout, "Você anexou '%s' ao arquivo.\n", s); //printa a string no console.
    fclose(fp);

}
```

## Conclusão

É basicamente isso. Como já deu para perceber essas anotações são mais voltadas para a sintaxe da linguagem doq principios de programação ou algo do tipo. Aprender C é a base para aprender C++. Além disso, do jeito q minhas anotações estão estruturadas, saber C é necessário para entender as anotações sobre data structs (necessário saber a sintaxe).
