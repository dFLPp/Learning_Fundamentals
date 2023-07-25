# C - anotações

## Introdução

C é uma linguagem de programação compilada de propósito geral, estruturada, imperativa e procedural criada em 1972 por Dennis Ritchie na empresa AT&T Bell Labs para desenvolvimento do sistema operacional Unix.
Em 2022 fez 50 anos, sendo conhecida por ser a linguagem "mãe" de várias outras (python, rust, etc). Tem como característica a não existência de um garbage colector, sendo necessário fazer um controle de memória preciso.

## Workflow dos programas em C

1.  Programa escrito em C é passado para o **preprocessor** que aplica as diretivas que o programador especificar.
2.  O preprocessor expande o código escrito em C (0*source code*) e então manda o código para o **compiler**.
3.  O compiler transforma o source code em _assembly code_ e então manda ele para o **assembler**.
4.  O assembler transforma o codigo em _Object code_ então manda ele para o **linker**.
5.  O linker vai juntar o object code com as libraries e e outras funções e gera o código executvel (_.exe_).
6.  O .exe é carregado na memória pelo **loader** que então executa o programa.

## Estrutura de um programa em C

Um programa em C é constituído por:

- Cabeçalho, contendo diretivas ao compilador como: incluir bibiliotecas, declarar variáveis globais e constatantes e declarar rotinas (funções).
- Um bloco de intrução principal (função main) e outros blocos de rotinas (outras funções)
- comentários

Em C deve-se declarar variáveis antes de usa-las e explicitarseu tipo. Todos os statements (linhas de código) devem terminar com ";".

## Segmentos de dados

Todas as variáveis, funções e estruturas de dados definidas no C são armazenadas na memória, na maioria das vezes sendo na RAM, que possue 4 partes/áreas:

1. Data area: É área de "memoria permanente". Todas as static e external variables são armazenadas aí, mas só existem até o final da execução do programa.
2. Code area: É a parte da memória que só pode ser usada por pointers de funções. O tamanho dessa área é fixo.
3. Heap area: É a parte da memória que é acessada/usada durante a alocação dinâmica de memória, que é feita com malloc() e calloc(). O tamanho varia de acordo com a memória disponivel.

4. Stack area: Também chamada de "temporary memory area", é onde variaveis locais, constantes, funções, return de funções e parâmetros são armazenados. Os valores são excluidos assim que o programa sai do seu respectivo escopo.

## Indentificadores

São os nomes que você dá para as variáveis. Você não pode usar caracteres especiais nem palavras reservadas. Para saber o que pode e o que não pode olhe [esse](https://learn.microsoft.com/pt-br/cpp/c-language/c-identifiers) artigo da Microsoft.

## Tipos de dados

Em C em existem 5 data types Básicos que definem que tipo de valor que pode ser armazenado em uma variável:

- char: armazena carateres e srings.
- int: armazena números inteiros.
- float: representa números reais "Sem" precisão nas casas decimais.
- double: representa números reais "Com" precisão nas casas decimais.
- void: representa a falta de conteúdo de uma variável.

> Para os tipos de dados números é possivel usar algum dos modificadores a seguir para modificar o intervalo válido de valores aceitos pela variável: _signed_, _unsigned_, _long_ e _short_.

## Declaração de variáveis e constantes:

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

## Operadores:

OBS: não existem tipos booleanos em C (true ou false)
OBS: você pode garantir o tipo de um resultado a usar um "cast".
Ex: printf("%d/2 é: %f\n", i, (float) i/2);
Dessa forma o termo i/2 vai ser do tipo float. Repare que o placeholder utilizado foi o "%f".

-> De atribuição: =;

-> aritiméticos: ++, --, -, \*, /, %, +, -; (em ordem de precedência/prioridade decrescente)
ex: int a, b, c, i = 3; //a: ? b: ? c: ? i: 3
a = i++; //a: 3 b: ? c: ? i: 4
b = ++i; //a: 3 b: 5 c: ? i: 5
c = --i; //a: 3 b: 5 c: 4 i: 4

-> relacional-logico: !(negação), >, <, >=, <=, ==(igual lógico), !=(diferente logico) &&, ||;

-> bit a bit: existem, mas suponham que sejam irrelevantes.

-------->
Existem dois operadores que são usados para manipular ponteiros(pointers): & e \*.
Pointers são o indereço na memória de uma variável. Uma variável de ponteiro é uma variável especificamente declarada para guardar um ponteiro para seu tipo especificado.

Pointers são uteis porque com eles você pode se referenciar a um elemento de uma matriz, permite que funções alterem/modifiquem os parâmetros passados na chamada e ajudam na manipulação de linked lists e outros data types complexos.

& é usado para se referir ao ENDEREÇO de uma variável na memória. Por exmplo "m = &count;" pode ser lido como "m recebe o Endereço de count". O endereço de count é completamente diferente do Valor de count.

- é usado para se referir ao VALOR de uma variável, dado o seu endereço. Por exemplo "q= *m;" pode ser lido com "q recebe o Valor que está no endereço de m".
  Porém repare que, como o endereço de m é o endereço de count, então *m é na verdade o valor de count.
  ##Ex:
  #include<stdio.h>
  void main(void){
  int target, source;
  int _m; //mesmo que eu tenha colocado o "_", a variável "m" em sí ainda é declarada.
  source = 10;
  m = &source;
  target = \*m;
  printf("O target é: %d\n", target);
  printf("O endereço é %d\n", m);
  }

##

<--------

➼➼ Estruturas de controle de fluxo.
Existem 3.
São usados para controlar o fluxo de processamento do programa. Um expressão tipo: "x=5" torna-se um comando quando colocamos um ponto e vírgula (; age como "terminador de comandos).
As chaves {} são usadas para construir blocos de codigo de modo que, sintaticamente, "funde-se" todo o código desse bloco e executa ele como se fosse um só comando.

Antes de começar a ver esses comandos, deve ficar "claro" que as condições de ativação dos comandos não são "ideais".
O que isso quer dizer é: Ao invés de você ter uma condicional que vai retornar True, você vai ter uma condicional que vai ser "Não 0", ou seja, ao invés de escrever um código lógico, você vai ter que escrever condicionais baseadas em números.
Eles são:
-> Comandos de seleção
-> Comandos de repetição
-> Comandos de desvio

➼ Comandos de seleção (condicionais):
Servem para executar código baseado em uma seleção (são as famosas condicionais)
Existem 3 em C: If, switch, ternary operator 1. If: ##
if(<condição>){
<comando>
}
else if(<outra condição>){
<outro comando>
}
else{
<comando>
} ##
No comando "if", o primeiro <comando> é executado se a expressão em não zero (verdadeiro) e o else, se o contrário.
Um comando if pode ser "aninhado" em outro.
No C, o else se refere ao if mais próximo. Como isso pode ser confuso, escreva de um jeito claro.

    2. Switch
    ##
    	switch(<condição>){

    	case <valor inteiro 1>:
    		//repare na utilização de dois pontos (:)
    		<comando>
    		break; // necessário usar o break em cada case

    	case <valor inteiro 2>:
    		<comando>
    		break;

    	default:
    		<comando>
    		break;
    	}
    O switch é usado quanto existem muitas "possibilidades".
    O comando break e um comando de desvio, que faz a execução "pular" até o final do switch.
    ##

    3. Operador ternário
    Assim como no JS é ideal para fazer uma escolha condicional rápida, sendo útil, por exemplo, para atribuir valores a variáveis de acordo com um critério.
    ## estrutura básica
    	<expressão1> ? <expressão2> : <expressão3>
    ##
    ## Ex:
    	x = 10;
    	y = x>9 100 : 200;
    	// se x for maior que 9, y = 100 otherwise y = 200
    ##

➼ Comandos de repetição (loops):
Existem 3: while, do... while, for 1. while ##
while(expressão de controle, i <10, por exemplo){
<comando>
} ##
Normalmente utiliza-se uma variável de controle externa ao loop para que ele tenha um fim.
Checa a condição Antes de cada execução.
##Ex:
int contador = 1; //variável de "controle" externa
while (contador <= 100){
printf("%d\n", contador);
contador++;
} ##

    2. do ... while
    ##
    	do{
    	<comando>
    	} while (<expressão de controle>);
    ##
    O do...while funciona da mesma maneira que o while, a diferença é que ele checa a condição Depois de cada execução.
    ##Ex:
    	int contador = 1;
    	do{
    		printf("%d\n", contador)
    	} while (contador <= 100);
    ##


    3. for
    ##
    	for(<inicializa variavel de controle>,<condicional que mantém o loop>, <como passar para a proxima iteração>){
    		<comando>
    	}
    ##
    ##Ex:
    	for(contador = 1, contador <= 100, contador++){
    		printf("%d\n", contador);
    	}
    ##

➼ Comandos de desvio:
O C tem 4 comandos que realizam "desvio incodicional", ou seja, trocam em que lugar o programa está sendo executado.
Por exemplo, se você está dentro de um nested loop e já obteve o resultado que queria, pode usar algum desses comandos (dependendo da situação) e então sair desse loop.
Os comandos são: return (para funções), goto, break, continue.

1.  return:
    Quando dentro de uma função, é usado para retomar ao ponto em que a função foi chamada. Se a função tiver algum valor associado a ela, ele é retornado.
    A função para de executar tão logo encontre o primeiro return.

2.  goto:
    É usado em raras situações. Ele funciona da seguinte forma: Você deve criar um checkpoint chamado de rótulo que vai ser o local onde o programa vai voltar quando o "goto" for chamado.
    O rótulo (ou label) tem um nome e é seguido por dois pontos. Todo o código que deve ser executado depois de "carregar o checkpoint" deve estar indentado. Entenda que o "goto" não é um bloco de código. Ele simplismente vai redirecionar o "leitor" até o checkpoint e entõ seguir com o código, linha à linha.
    Com ja dito, não é recomendando usar o goto, porém uma das situações onde ele é util é quando queremos sair de um nested loop de uma vez só.
    ##Ex:

        #include <stdio.h>

        void main(void) {
           const int tentativas = 100;
           int i;
           double num, media, soma = 0.0;

           for (i = 1; i <= tentativas; ++i) {
              printf("%d. Diga um número: ", i);
              scanf("%lf", &num); //isso é um l. Ele vai pegar o número como float e vai converter para double

              if (num < 0.0) {
        	 goto teleport;
              }
              soma += num;
           }

        teleport:

    //repare que o "teleport" está no mesmo nível de indentação que o main, porém ainda Dentro do main
    media = soma / (i - 1);
    printf("A soma é = %.2f\n", soma);
    printf("A média é = %.2f", media);
    }

##

3. break
   Normalmente é usado para terminar um "case" em um comando switch ou para forçar a finalização de um loop antes que ele cheque a condição.
   De modo semelhante ao break existe a função exit() da biblioteca padrão provoca o término imediato do programa inteiro (do main).

4. Continue
   Serve para pular uma iteração espcífica sem sair do loop completamente.
   #include <stdio.h>
   void main(void){  
    char s[80], *str; //s[80] delcara uma string (vetor de caracteres) com 80 dígitos
   int space;
   printf("diga uma string: ");
   fgets(s, 80, stdin); // lê um input como string (bem parecido com o input do python)
   str = s;
   for (space = 0; *str; str++){
   if (\*str != 0){
   continue;
   }
   space++;
   }
   printf("%d espaços \n", space);
   }

➼ Functions:
Funções são conjuntos de comandos agrupados em um bloco e que são executados como um único grande comando. A função main (obviamente) é uma função.
Existem vários motivos para usar funções e etc...

Você pode fazer a declaração: return_type function_name( parameter list );
Você pode fazer a atribuição: return_type function_name( parameter list ){//faz abacate};
Você fazer a declaração e a atribuição ao mesmo tempo, o que é claramente melhor.

OBS: Quando você declara e atribue a função de modo separado, a linha que faz a declaração da função é chamada de protótipo de função.
A justificativa para ter que escrever um protótipo é que você garante que o tipo das variáveis não vai ser convertido erroneamente. Basicamente, por precausão.

Basicamente você sempre vai querer declarar um função de uma vez só (declaração e atribuição) e isso deve ser feito antes da função main().
##Ex:
#include <stdio.h>
//declarando função que retorna o tipo int e que tem nome "fat".
// Repare que é necessário dizer qual é o type de Cada parâmetro
int fat(int num){
if(num > 1){
return num\*fat(num - 1); // isso é uma recursão
} else{
return 1;
}
}

void main(){
int x, y;
x = 5;
y = fat(x);
printf("O fatorial de %d é %d", x, y);
}

##

Uma observação a ser feita é a respeito do void e do return.
Se você diz que o tipo de uma função é "int", então ela Pode retornar um número inteiro.
No caso da função main(), se você declara ela como int, você deve, no final, fazer um "return 0", indicando que a função ocorreu bem.

No caso de você void como o tipo da função, você não precisa/n não pode fazer o return pois void literalmente não é nada, então não faz sentido retornar o nada.

➼ funções pré-definidas:
São funções que vem "junto" do C quando você instala ele. Você pode baixar outras bibliotecas para poder usar as funções delas.
Não faz sentido ficar decorando cada uma. Algumas são mais usadas, outras não.
Para mais info: https://www.ibm.com/docs/en/i/7.4?topic=extensions-standard-c-library-functions-table-by-name

OBS: Para usar a função floor() (para achar a unidade, dezena e centena mais fácil) é necessário fazer o #include<math.h>

##Exemplo: minúsculas para maiúsculas

#include<stdio.h>
#include<ctype.h>
void main(void){

    char ch;
    printf("-----------------------------------------\n");
    printf("Digite algo || Digite um ponto para sair.\n");
    printf("-----------------------------------------\n");
    do{
    	ch = getchar(); //getchar serve para retornar cada tecla selecionada (no final retorna uma string).
    	if(islower(ch)){
    	    ch = toupper(ch);
    	}
    	putchar(ch); //putchar vai escrever caracteres. Nesse caso vai escrever uma string
    	//Repare que tanto putchar quanto getchar trabalham em torno de caracteres únicos, mas mesmo usando vários(strings) eles ainda funcionam em função do uso de matrizes(vetores)
    } while (ch!='.');

}

##

➼ Parâmetros:
OBS: parâmetro é uma variável genérica que é usada na função; Argumento é o valor passado para a função que será usado com parâmetro.

--> Em funções no geral:
Podem ser passados argumentos para funções de duas maneiras: 1. Chamada por valor:
É quando o argumento passado não é alterado pela função.
##Ex:
int sqr(int x){x = x*x; return (x);}
void main(){int t = 10; printf("a variável é %d e o resultado da função é %d", t, sqr(t))}
// teoricamente t não seria 10, seria 100, mas justamente pela "troca de valor" ocorrer dentro da função ela não é passada para a variável (argumento) real ## 2. Chamada por referência:
É quando o argumento passado É alterado pela função.
Justamente pelo fato de você não passar o argumento em si, e sim seu endereço na memória.
Dessa forma a função vai alterar o valor da variável através do endereço dela.
Como a função deve acessar a memória os parâmetros da função devem ser ponteiros (pointers) e os argumentos podem ser justamente os endereços.
Ou seja, quando for passar os parâmetros você usa o "&".
##Exemplo básico: 1.
#include <stdio.h>
void Zera(float a){a = 0;}
void main(){
float f;
f = 20.7;
Zera(f);
printf("%d", f); // O output ainda será 20.7 pois o parâmetro da função foi o VALOR de f e não seu endereço.
} 2.
#include <stdio.h>
void Zera(float *a){*a = 0;}
void main(){
float f;
f = 20.7;
Zera(&f);
printf("%d", f); // O output agora será 0 pois o parâmetro da função foi o ENDEREÇO de f e, dentro da função, alteramos seu valor.
} ##
##Exemplo pŕatico:
void swap(int *x, int *y){ //x e y são parâmetros
//O propósito dessa função é bem meh. Você poderia fazer manulmente, porém serve para exemplificar como a troca do valor dos argumentos ocorre
int temp;
temp = *x;
*x = *y;
\*y = temp;
}
void main(){
int i, j;
i = 10;
j = 20;
swap(&i, &j); // Os endereços de i e j são argumentos
} ##

    3. vetores/matrizes:
    	Quando você passa um vetor ou uma matriz como argumento de uma função, eles não vão ser influenciados em si, e sim o seu primeiro elemento.
    	Em outras palavras, quando você passar um vetor em função, você não está passando todo o vetor, está passando só o primeiro elemento. E o mesmo para matrizes.
    	Claro que é possivel iterar sobre um vetor dentro de uma função, mas,quando você usa ele como argumento, a função se referencia ao primeiro elemento.

--> Na função main

Há dois argumentos especiais que podem ser passados na função main:
Ambos são usados para "pegar"/"guardar" o que você escreve no terminal (enquanto o programa está rodando)
1.argc
Contém o número de argumentos/coisas que você escreve na linha de comando. Você deve separar cada argumento por um espaço ou por um Tab. Deve ser iniciado como "int".
NO mínimo argc é 1 porque o nome do arquivo é considerado um argumento.
2.argv
É um ponteiro para uma matriz de ponteiros para caracteres. No bom português, é um indice para cada caractere em uma string (que é um vetor). Deve ser inciado como "char".
basicamente "vetores" podem ser considerados/tratados como sendo uma "matriz".

##Ex:
#include<stdio.h>
#include<stdlib.h>
void main(int argc, char \*argv[]){ // O [] indica que vários argumentos (indeterminado) podem ser escritos
if(argc != 2){
printf("Você não escreveu nada\n");
exit(1);
}
printf("Essa foi a primeira coisa que você escreveu no terminal %s\n ", argv[1]);
}

##

➼ Recursividade:
Ocorre quando uma função chama a sí mesmo dentro dela.
Em um dos exemplos acima (sobre farorial) você conseguirá perceber o uso de recursividade.
Claro que a chamada recursiva deve acontecer de um modo especial, evitando a execução infinita.
Recursão gasta muita mémoria e com C é uma linguagem complicada, onde você tem que administrar a memória de maneira muito específica, você deve usar de maneira consisa e direcionada.
Vejamos o exemplo do calculo do fatorial (dessa forma usando protótipos de função, para mais "segurança"):

##

#include<stdio.h>

long Fat(long n); //Esse é o protótipo da função.
// long é um data type para números grandes.
//Você poderia escrever "long int", por exemplo.
void main(){
int num;
long result;
printf("Diga um número: ");
scanf("%d", &num);
result = Fat(num);
printf("O fatorial de %d é %ld", num, result);
}
long Fat(long n){ //essa é a atribuição/criação propria da função.
if (n==0){
return 1;
} else{
return n \* Fat(n-1);
}
}

##

➼ Macros do pré-processador:
Esse tópico é sobre instruções que você pode passar para o compilador de modo a "personalizar" a criação do executável.

- #define é usado basicamente para criar constantes "globais". Mas

- #include diz ao compliador que arquivo/bibilioteca abrir (possibilitando usar as funções desses arquivos)

- #if, #else, #elif e #endif são condicionais destinadas diretamente ao compilador. Só podem funcionar quando usam Constantes para fazer a lógica.
  ##Ex:
  #include<stdio.h>
  #define MAX 100
  void main(){
  #if MAX > 99 //está usando a constante MAX para fazer a lógica
  printf("Compilando algo grande\n");
  #else //repare que não estamos usando nem chaves nem dois pontos
  printf("Compilando algo pequeno\n");
  #endif //precisa do endif para fechar o #if statement
  }

  ##

- #undef é o constrário de define, servindo para "desativar" variáveis/macros criados com o define.
  ##Ex:
  #define LEN 100
  #define WIDTH 100
  char array[LEN][WIDTH];
  #undef LEN
  #undef WIDTH
  //apartir daqui LEN e WIDTH não estão definidos
  ##

➼➼➼ Matrizes e Strings

➼➼ Matrizes:
Uma matriz é uma coleção de variáveis do mesmo tipo que são referenciadas por um nome em comum e que são acessadas por um indice.
Em C matrizes são variáveis em posições contiguas na memória (variáveis "alinhadas" fisicamente)
Todo primeiro elemento de uma matriz tem indice 0.

➼ matrizes unidimensionais (também chamadas de vetores ou arrays):

## Exemplo & estrutura:

##

    #include <stdio.h>
    void main(){
    	int x[100]; //declarando uma Matriz unidimensional com 100 espaços/elementos
    		    //Por padrão cada elemento é void, já que só declaramos a variavel

    	int *m, *n; //criando pointers para poder se referir a elementos em específico.
    	m = &x[2];  //é através dessa notação que acessamos um termo de uma array.
    	n = &x[3];
    	//Perceba cuidadosamente: Primeiro criamos dois Pointers com o asterisco *, ou seja, m e n servem especificamente para receber endereços.
    	//Depois disso, através do &, atribuimos o endereço de elementos do vetor as variáveis m e n. Dessa forma *m e *n se referem ao valor desses elementos.
    	//Perceba que fazer *m e *n na DECLARAÇÃO faz com que as variáveis sejam pointers desde nascença, e fazer *m e *n no PRINTF só mostra o valor no enderço de m e n
    	//Cuidado, isso é relativamente simples porém confuso. Aloque bastante antenção nesse tópico porque é a essencia de "matrizes".
    		//1.m e n são declaradas como pointers(endereço inicial = nulo) -->
    		//2.recebem endereços de elementos de matriz (assumem esses endereços) -->
    		//3.retornam o valor desse endereço(do elemento da matriz);

    	int t;
    	for (t=0; t<100; t++){
    		x[t] = t; //defindo o valor de cada elemento do vetor via um loop.
    		printf("t vale %d\n", t);
    	}

    	printf("O valor no index 2 é: %d\n", *m);
    	printf("O valor no index 3 é: %d\n", *n);
    	printf("O endereço do index 2 é: %p\n", m);
    	printf("O endereço do index 3 é: %p\n", n);
    }

##

##

Basicamente, se no javaScript para você referir ao elemento de indice 7 em uma array você usaria: "let x = array[7];" Em C você tem que fazer "int \*x; x = &array[7];"
Simples e literalmente, basta se acostumar/memorizar.

➼ Matriz bidimensional
São matrizes propriamente. Você sua a notação: x[linhas][colunas]; e para se referir a um elemento usa: x[2][3] para o termo na linha 2 e na coluna 3, por exemplo.
A primeira linha e a primeira coluna não são 1, e sim 0. Por exemplo, as colunas não são: 1 2 3 4, são: 0 1 2 3; e o mesmo para linhas.
Dessa forma o elemento x[0][0] é o primero na matriz x.

##Ex & estrutura
#include<stdio.h>
void main(){
int t, i, num[3][4];
for(t = 0; t < 3; t++){
for(i = 0; i < 4; ++i){
num[t][i] = (t\*4)+i+1;
printf("Elemento [%d][%d] --> valor:%3d\n", t, i, num[t][i]);
}
}
}

##

### Ex com código assustadoramente grande, porém simples. Recomendo ler em um compilador.

### //O editor de texto deixa o codigo parecendo algo mais dificl do que realmente é.

###

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define TURMAS 3 //constante
#define ALUNOS 30 //constante
int nota[TURMAS][ALUNOS]; //variável global

void enterNotas(void){
int t,i;
for(t=0; t<TURMAS; t++){
printf("\nTurma # %d\n", t+1);
for(i=0; i<ALUNOS; ++i){
nota[t][i] = getNotas(i);
}
}
}

int getNotas(int num){
char s[80];
printf("Diga a nota do aluno %d\n", num+1);
gets(s);
return(atoi(s));
}

void dispNotas(int g[][ALUNOS]){
int t, i;
for(t=0; t<TURMAS; t++){
printf("Turma # %d\n", t+1);
for(i=0; i<ALUNOS; ++i){
printf("Aluno #%d e %d\n", i+1, g[t][i]);
}
}
}

void main(){
char ch, str[80];
for(;;){
do{
printf("Use 'E' para Entrar notas\n");
printf("Use 'M' para Mostrar notas\n");
printf("Use 'S' para Sair\n");
gets(str);
ch = toupper(\*str);
} while(ch != 'E' && ch != 'M' && ch != 'S');
switch(ch){
case 'E':
enterNotas();
break;
case 'M':
dispNotas(nota);
break;
case 'S':
exit(0);
}
}
}

###

###

###

------> Matrizes multidemensionais: Existem mas praticamente não são usadas.
➼ Inicialização de matrizes: É possível dar valores para a uma matriz no momento da declaração. Basta seguir a notação usada no exemplo:

##

int sqrs[10][2] = {
1,1,
2,4,
3,9,
4,16,
5,25,
6,36,
7,49,
8,64,
9,81,
10,100
}

##

➼➼ Strings:
Strings em C consistem em matrizes unidimensionais (vetores ou arrays) de caracteres e que é terminada por nulo "\0".
Os vetores do "tipo" strings devem ser declarados como "char".
Pelo fato do das strings terminarem em \0 sempre é nessário criar string com um espaço a mais.
Ex: para criar um string com 10 caracteres você precisaria declarar "char str[11]" (um a mais).
Algumas funções para manupulação de strings presentes em <string.h>: - strcpy(s1, s2) -> copia a string s2 em s1 - strcat(s1, s2) -> concatena s2 em s1 - strlen(s1) -> retorna o tamanho da string s1

É possivel criar uma matriz de strings str[x][y] onde x seria o número de strings diferentes e y-1 seria o tamanho que cada string poderia ter.
OBS: Como strings são matrizes unidimensionais, tudo que se aplicava/se usava antes se mantem. válido.

##Exemplo que eu não sei o que faz:

#include<stdio.h>
#define MAX 100
#define LEN 80
char text[MAX][LEN];

void main(){
register int, i, j;
printf("Aperte enter sem digitar nada para sair.\n");
for(t=0; t<MAX; t++){
printf("%d", t);
fgets(text[t]); //text[t][0] seria a mesma coisa;
if(!\*text[t]){
break;
}
for(i=0; i<t; i++){
for()j=0; text[i][j]; j++){
putchar(text[i][j]);
}
putchar("\n");
}
}

}

##

➼➼ Ponteiros (pointers):

Ponteiros são uma das especialidades de C. Eles permitem que funções modifiquem seus argumentos além de que suportam as rotinas de alocação dinâmica e podem aumentar a eficiência do programa.
Entretando usar ponteiros aumenta a complexidade do problema, podendo fazer erros surgirem.
Um ponteiro é uma variável que contém um endereço de memória. Esse endereço normalmente é a posição de outra variável na memória.
Ou seja o valor que essa variável (chamada de ponteiro) contém é justamente um endereço de memória (normalmente um código binário).

Se uma variável vai ser um ponteiro você precisa declarar ela com *. Por exemplo:
int *m; E apartir de então os valores que m pode possuir são os endereços de outras variáveis.
Para atribuir um endereço para esse ponteiro basta ter outra variável (int a = 10;) e fazer:
m = &a; Onde "&" diz qual é o endereço na memória da variável "a".
Ex: Se a variável "m" contém o endereço da variável "cont", então se "p = \*m;" significa que p vai ter valor igual ao valor que está no endereço de m, ou seja, p = count;

É importante perceber que o \* tem funções diferentes. Ele serve para declarar uma variável como pointer e também serve para resgatar o valor de um endereço.

##exemplo rápido
void main(){
int x;
int *p1, *p2;
p1 = &x;
p2 = p1; // agora p1 e p2 apontam para x
print("%p",p2) //escreve o endereço de x e não seu valor
//repare que usamos %p para substituir p2 (pointer).
}

##

Normalmente um ponteiro inteiro (p1 e p2 do exemplo anterior) ocupam 2 bytes de memória e uma variável do tipo float ocupa 8 bytes.

Se você declara um ponteiro (int \*x;) e tenta usar ele sem atribuir um valor, você pode quebrar seu OS.
Basicamente, como um pointer está diretamente ligado à espaços na memória, se você usa esse ponteiro sem dizer qual parte da memória(endereço) você quer, o compilador vai pegar uma parte aleatória, e por consequência por gerar um efeito dominó que travaria o PC.

O recomendado é que você inicialize um ponteiro como 0 (por mais que não garanta segurança). Ex: int *p = NULL; int x = 10; int *p = &x;

Dangling Pointers: São ponteiros que estão apontando para um indereço de memória inválido. Por exemplo, se um ponteiro está apontando para uma variável dentro do escopo, quando o código sair do escopo a variável vai ser deletada e o ponteiro vai apontar para um endereço inválido (ele Não é redirecionado para o NULL, sendo necessário fazer isso "manualmente").

-------->
➼ Pilhas/Stacks:
São estruturas de dados do tipo LIFO (last-in first-out), onde o último elemento a ser inserido, será o primeiro a ser retirado. Assim, uma pilha permite acesso a apenas um item por vez - o último a inserido. Para processar o penúltimo item inserido, deve-se remover o último e assim sucessivamente.
Uma analogia seria com uma pilha de pratos onde o primeiro prato (valor) a ser colocado em uma mesa (vetor ou linked list) será o ultimo a ser retirado, se outros pratos forem colocados em cima dele (depois do primeiro).
Para criar pilhas em C usa-se das funções push() para colocar valores na pilha e pop() para retirar valores, ambas estão em <stdlib.h>
Uma pilha é basicamente uma lista, ou seja, uma pilha é um vetor, basicamente.

##Exemplo:

##

    #include <stdio.h>
    #include<stdlib.h>

    struct Pilha {
    	int topo; /* vai guardar a posição do elemento no topo */
    	int capa;
    	float *pElem;

    };

    void criarPilha( struct Pilha *p, int c){
       p->topo = -1; //passada uma struct do tipo Pilha. && Por padrão, a ultima posição SEMPRE é -1.
       p->capa = c; //usa-se "->" para se referir a uma propriedade dessa struct. "capa" é o tamanho da stack, passado na função como "c"
       p->pElem = (float*) malloc(c*sizeof(float)); //vai alocar/criar memória para a Stack/pilha de acordo com o tamanho maximo dela
    }
    int empty(struct Pilha *p){
       if( p->topo == -1 )
          return 1; //se o primeiro elemento é -1 significa que ele também é o ultimo, logo a pilha está vazia
       else
          return 0;
    }
    int full(struct Pilha *p){
    	if (p->topo == p->capa - 1)
    		return 1; //se o "index" do ultimo elemento é igual ao tamanho definido para a pilha, então ela está cheia.
    	else
    		return 0;
    }

    void add(struct Pilha *p, float value){
    	p->topo++; //aumenta o "index" do value antes de mesmo de atribuir algo à essa posição
    	p->pElem[p->topo] = value; //value vai ser o valor do elemento da stack cujo index é igual ao "topo" atual.

    }

    float pop(struct Pilha *p){
       float aux = p->pElem[p->topo]; //salva o valor "mais alto" na stack
       p->topo--; //"diminue o indice" (aparentemente é o suficiente para desvincular/retirar o valor)
       return aux; //retorna o valor do "topo antigo"

    }
    float lastElem(struct Pilha *p){
       return p->pElem [p->topo]; //simplismente retorna o "valor mais alto" na stack
    }

    int main(){
    	struct Pilha pilha1;
    	int size, fluxo;
    	float value;

    	printf( "\nQual o tamanho da pilha? ");
    	scanf( "%d", &size);

    	criarPilha (&pilha1, size); //lebre de que, quando se passa uma struct deve-se usar o seu endereço(&)

    	while(1){
    	//loop infinito
    		printf("\n1- Empilhar (push)\n");
    		printf("2- Desempilhar (Pop)\n");
    		printf("3- Mostrar o topo\n");
    		printf("4- sair\n");
    		printf("\n-> ");
    		scanf("%d", &fluxo);

    		switch (fluxo){
    			case 1: //push
    				if(full(&pilha1) == 1)
    					printf("\nSua pilha está cheia.\n");
    				else {
    					printf("\nValor para adicionar: ");
    					scanf("%f", &value);
    					add(&pilha1, value);
    				}
    				break;

    			case 2: //pop
    				if(empty(&pilha1) == 1)
    					printf( "\nSua pilha já está vazia\n");
    				else{
    					value = pop(&pilha1);
    					printf ("\n%.2f foi removido da pilha\n", value);
    				}
    				break;

    			case 3: // mostrar o topo
    				if (empty(&pilha1) == 1)
    					printf( "\nVocê ainda não adicionou nada!\n" );
    				else {
    					value = lastElem(&pilha1);
    					printf("\nO valor no topo da stack é: %.2f\n", value);
    				}
    				break;
    			case 4:
    				exit(0); //sai do programa, logo sai do loop infinito

    			default:
    			    printf("\nOpção inválida\n");
    		}
    	}
    }

##

##

<--------

➼ Ponteiros e matrizes:

C fornece dois métodos para acessar elementos de matrizes:
-> aritimética de ponteiros: Mais rapida. Consiste em usar atribuir um pointer a uma matriz.
Ele vai se referir ao primeiro elemento dessa matriz. Apartir daí, para se referir a outros
elementos em outras posições basta somar um inteiro até o index desse elemento.
Ex:

##

char str[80], _p1;
p1 = str; //o ponteiro se refere ao primeir o elemento de uma matriz
printf("%d", _(p1+4)); // vai printar o 5 elemento pois \*(p1+4) se refere ao 5 index.

##

-> indexação de matrizes: é basicamente usar colchetes e o index do elemento.
No caso do exemplo anterior, fariamos printf("%d", str[4]);

Ponteiros também podem ser organizados em matrizes, ou seja, pode existir uma matriz de ponteiros.
Ex: int *x[10]; Para criar a matriz com espaço para 10 pointers
x[2] = &var; Para dar ao pointer de index 3 o endereço da variável "var"
*x[2]; Para encontrar o valor de "var";

Exemplo:

##

void someInfo (int num){
static char \*err[] = {
"Atribuindo 'Manualmente' os valores da matriz\n",
"Cada string é um elemento da matriz\n",
"E a matriz 'err' possue ponteios para cada string\n"
};
printf("%s", err[num]);
}
Por exemplo, se eu chamar someInfo(2) a função vai printar a terceira string.

##

➼ Ponteiros (pointers) e funções:
Você já viu que um ponteiro pode armazenar o endereço de memória de uma variável, mas e quanto armazenar o de uma função? As funções, assim como as variáveis Possuem endereço na memória (stack e code area).
Para obter o endereço de uma função precisamos criar um pointer na mesma estrutura da função que queremos e então igualar ele à função original.
##Ex:
float (\*fp) (int , int); // Declaration of a function pointer.  
 float func( int , int ); // Declaration of function.  
 fp = func; // Assigning address of func to the fp pointer.

##

##Exemplo prático:
#include <stdio.h>  
 int add(int a,int b){  
 int c=a+b;  
 return c;  
 }
int main(){  
 int a,b;  
 int (*ip)(int,int); //repare na estrutura/sintaxe: (*ip)
int result;  
 printf("Enter the values of a and b : ");  
 scanf("%d %d",&a,&b);  
 ip=add; //ip é igual ao Nome (tecnicamente, o endereço) da função.
result=(*ip)(a,b); //e o valor de ip é a função em si. Pense que (*ip) é substituido por "add"
printf("Value after addition is : %d",result);  
 return 0;  
 }

##

➼➼ Alocação dinâmica
Ponteiros fornecem o suporte necessário para executar alocação dinâmica, isto é: O programa consegue obter memória enquanto está em execução.
Imagine que você quer criar uma array com o tamanho igual a resposta do usuário. Como o programa precisa rodar para fazer scanf, não vai ser possivel criar a array, ou seja, alocar memoria na execução do programa. Para que isso possa ocorrer, precisamos alocar a memória dinâmicamente ao usar uma das 3 funções principais:
malloc(), calloc(), free(); Essa funções estão em <stdlib.h>
A alocação dinâmica em C basea-se nas funções malloc() e calloc () para alocar memória e free() para liberar memoria Alocada. Elas trabalham em conjunto e utilizam/dependem do "heap" (região de memória livre) para manter uma lista de armazenamento disponível.
Enquanto malloc vai criar um único Bloco de armazenamento, calloc vai criar vários blocos. Imagine que a memória RAM é um retangulo e que ao consumir memoria preenchemos esse retangulo com quadrados.
Ao usar malloc criariamos um único quadrado com tamanho X e ao usar calloc criariamos n quadrados com x/n de tamanho. Repare que o tamanho não muda, mas o metodo de alocação sim.
Sintaxe do malloc(): ptr=(cast-type*)malloc(byte-size);
Sintaxe do calloc(): ptr=(cast-type*)calloc(number, byte-size);
Sintaxe do free(): free(ptr)

Vejamos dois exemplos, um usando malloc() e outro usando calloc():

##

##

//////Usando malloc()
#include<stdio.h>
#include<stdlib.h>
int main(){
int n, i, _memoria, soma = 0;
printf("Diga quantos elementos sua array vai ter: ");  
 scanf("%d",&n);  
 memoria=(int_)malloc(n*sizeof(int)); //estamos alocando valores inteiros por isso o (int*) é necessario
//dentro do malloc estamos criando um único bloco com o tamanho em bytes ao equivalente à n vezes o tamnho de um inteiro.

    if(memoria==NULL){
        printf("Quando não é possivel armazenar o retorno é NULL");
        exit(0);
    }

    printf("diga os elementos da array: ");
    for(i=0; i<n; i++){
    scanf("%d",  memoria+i);
    soma += *(memoria+i);
    }
    printf("\nA soma dos elementos é: %d", soma);
    free(memoria);

return 0;
}

//////Usando calloc()
#include<stdio.h>
#include<stdlib.h>
int main(){
int n, i, _memoria, soma = 0;
printf("Diga quantos elementos sua array vai ter: ");  
 scanf("%d",&n);  
 memoria=(int_)calloc(n, sizeof(int)); //estamos alocando valores inteiros por isso o (int\*) é necessario
//dentro do malloc estamos criando um único bloco com o tamanho em bytes ao equivalente à n vezes o tamnho de um inteiro.

    if(memoria==NULL){
        printf("Quando não é possivel armazenar o retorno é NULL");
        exit(0);
    }

    printf("diga os elementos da array: ");
    for(i=0; i<n; i++){
    scanf("%d",  memoria+i);
    soma += *(memoria+i);
    }
    printf("\nA soma dos elementos é: %d", soma);
    free(memoria);

return 0;
}

##

##

➼ Estruturas (structs/structures):
Em C uma estrutura é como se fosse uma constructor function do JavaScript ou uma classe do python. Você declara variáveis/características que um elemento dessa struc teria e então cria um variável seguindo esse "blueprint". As variáveis dentro da estrutura são chamadas de elementos ou campos.
Depois que você cria a struct, para criar uma variável desse tipo você precisa usa: "struct <nome da struct> <variavel>"
Campos de uma estrutura também podem ser uma estrutura. Nesse caso se diz que as estruturas estão aninhadas.
Para se referir ao valor de um campo de uma variável do "tipo" da struct, você usa o ponto, patricamente igual ao que ocorre em JS.
Ex: Se o campo "campo1" é inteiro fazemos simplismente e1.campo1 = 12;
Ex2: Se o campo "campo2" é uma string precisamos usar a função strcpy, que fica em <string.h>
strcpy(e1.campo2, "Transmitndo essa string para o campo2");

##Exemplo da aplicação de estruturas:

#include<string.h>
#include<stdio.h>

void main(){
// Criação de uma struct
struct endereco{
char rua[40];
int numero;
char bairro[20];
char cidade[20];
char estado[3];
char cep[10];
}; //poderia declarar variável desse "tipo" aqui, nessa linha.
//criação de uma variavel que é do "tipo" "endereco"
struct endereco variavel1;
//atribuindo valores para cada campo:
variavel1.numero = 666;
strcpy(variavel1.rua, "Fim da rua");
strcpy(variavel1.bairro, "Fim do mundo");
strcpy(variavel1.estado, "ZE");
strcpy(variavel1.cep, "14444-144");
printf("O seu endereço é:\n");
printf("Rua: %s, número: %d\n", variavel1.rua, variavel1.numero);
printf("No estado %s com o CEP: %s\n", variavel1.estado, variavel1.cep);
printf("...");
}

##

➼ typedef.
O C permite que sejam definidos explicitamente novos nomes aos tipos de dado ao usar a keywork "typedef". Normalmente utiliza-se typedef para trocar o nome de um data type já existente, aumentando a portabilidade do código. O formato geral é: typedef <tipo ja existente> <novoNome>; Ex: typedef float real. Agora eu posso usar "real" no lugar de float. Ex: real x;

typedef pode ser útil para simplificar a declaração de variáveis de estrutura. Ex:

##

//Normalmente:
struct mystruct{
unsigned x;
float f;
};
struct mystruct s; //declaração

    //Com typedef:
    struct mystruct{
    	unsigned x;
    	float f;
    };
    typedef struct mystruct estrutura1;
    estrutura1 w; //declaração.
    //"struct mystruct" foi trocado por "estrutura1"

##

Também é possivel criar matrizes e vetores de estruturas (onde todos os elementos são variáveis do tipo "estrutura" (é literalmente uma "lista de dicionários", falando em python)
Para manipular os dados de um vetor desse tipo, você precisa especificar o index com "[]" e o campo com ".".

## Exemplo expositivo:

struct teste{
char x;
int y;
flaot z;
char s[10];
}
struct teste v1;

struct teste vetor[100]; //cria a variável "vetor" (matriz unidimensional) com elementos da struct "teste"
strcpy(vetor[0].s,"Abacate"); //O primeiro elemento do vetor, no campo s, vai ter "Abacate".

//Structs como argumento de função

func1(v1.x); //passa o valor do caractere x;
func1(v1.s[2]); //passa o valor do caractere de s[2];

func1(&v1.x); //passa o endereço do caractere x;
func1(&v1.s[2]); //passa o endereço do caractere de s[2];

##

➼ Struct padding:
Quando você cria uma struct, meḿoria é separada para cada campo. Entretando dependendo do processador e da arquitetura usada, o tamanho da struct pode ser maior.
Se o processador é de 32bits, ele lê a cada ciclo/por vez 4 bytes e se o processador for de 64bits, ele lê a cada ciclo/por vez 8 bytes. Veja o exemplo:

##

    struct student{
      char a; // tipo char tem tamanho 1 byte
      char b; // tipo char tem tamanho 1 byte
      int c; // tipo int tem tamanho 4 bytes
    }, st1;
    //O tamanho de st1 "teoricamente" seria de 6, porém dependendo do processador e da ordem das properties, o tamanho pode ser maior.

##

No caso do exemplo anterior, em um processador e 32bits ele "leria" os 1 bytes de "a" e de "b" e mais 2 bytes de "c", precisando de outro ciclo para ler os 2 bytes finais de "c".
Repare que o segundo "ciclo" de leitura do processador foi ruim/ineficaz, sobrando 2 bytes de leitura.
Struct padding vai ser a funcionalidade automatica de obter o melhor modo de leitura possivel, usando todas as 8 ou 4 cargas de cada ciclo e tentando não dividir as variaveis/properties pela metade. Para que isso seja feito, o compilador automaticamente cria uma linhas vazias para ocupar espaço.
Em projeto real/serio (tipo, fazer um satelite), cada byte precisa ser economizado e são detalhes como esse que dão liberdade ao programador. BTW, se você quiser evitar o struct padding, você pode usar a deritiva "#pragma pack(1)" no início do código, porém não use, você não precisa.

--------------->
➼ Ponteiros e Structs
Ponteiros para uma estrutura passam para funções apenas o endereço da estutura.
Uma das vantagem é que usando ponteiros você, através da função, alterar o valor de um campo da struct.
Para criar/passar um ponteiro que se refere a TODA a struct, para dentro de uma função você faz: "void funcao(struct <NomeStruct> \*x);" Onde x é o ponteiro para a struct <NomeStruct>.
Esse ponteiro se refere a TDOA struct. Para fazer ele se referir apenas a um campo, usa-se a setinha: printf("%d", x->campo1); Dessa forma "x->campo1" é o valor atual desse campo.

##Exemplo um pouco mais complexo:

#include <dos.h> // aparentamente não vem instalado
#include <stdio.h>
#include <stdlib.h>

struct tempo{
int horas;
int minutos;
int segundos;
};

void mostrarH(struct tempo \*t){
//Esse é o "jeito"/nomeclatura usada para usar um ponteiro da struct "tempo" em uma função.
//Dessa forma a variável/pointer t vai apontar para a struct "tempo" e pode alterar os valores que o campo dela tem.

printf("%02d: ", t->horas);
printf("%02d: ", t->minutos);
printf("%02d \n", t->segundos);

//repare no código: t->horas. Esse é o jeito/modo de, utilizando um ponteiro que se refere a TODA a struct, fazer o ponteiro se referir especificamente a um campo, usando a setinha "->"
};

void atualizarH(struct tempo \*t){
t->segundos++;
if(t->segundos==60){
t->segundos = 0;
t->minutos++;
}
if(t->minutos==60){
t->minutos = 0;
t->horas++;
}
if(t->horas==1){
t->horas = 0;
printf("Parabéns, você ficou 1h com o programa aberto =|");
exit(0);
}
}

void main(){
int i;
struct tempo sysTime; //Como eu declarei a struct "fora" de qualquer coisa, ela é meio que global.
sysTime.segundos=0;
sysTime.minutos=0;
sysTime.horas=0;
for(i=0; i<60; i++){
atualizarH(&sysTime);
mostrarH(&sysTime);
}
}

##

<---------------

➼ Enumeradores:
O tipo "enum" é usado para criar uma enumeração, um conjunto de constantes inteiras que especifica todos os valores legais que uma variável desse tipo pode ter.
É mais fácil ver do que, tipo, ler? Ex:

##

    enum diaSemana{
    	domingo = 1, //Por padrão, se você não define um valor, ele começa com zero
    	segunda, // tratará segunda como 2
    	terça, // tratará segunda como 3
    	quarta, // tratará segunda como 4
    	quinta, // tratará segunda como 5
    	sexta, // tratará segunda como 6
    	sabado // tratará segunda como 7

    }
    // Para criar uma variável que é desse tipo você faz:

    diaSemana dia1, dia2, dia3;
    dia1 = sabado;
    dia2 = segunda;
    dia 3 = quarta;

##

O ponto chave para o entendimento de uma enumeração é que cada símbolo (cada linha/valor) representa um valor inteiro, dessa forma eles podem ser usados em qualquer lugar que um inteiro seria usado.
O proximo valor de um símbolo é igual ao antigo + 1. Ex:

##

    enum a{
    	z, //tratará com 0
    	d, //tratará com 1
    	b = 100, //tratará com 100
    	z, //tratará com 101
    	w  //tratará com 102
    }
    a abacate;
    abacate = b;
    //OBS: talvez o local de maior utilidade de enums seja no switch. Para cada "case" você pode ter um "simbolo" enum.
    switch (abacate){
    	case d
    		printf("nah...");
    		break;

    	case b:
    		printf("ABACATE");
    		break;

    	default:
    		printf("...");
    		break;
    }

##

➼ Uniões:
Em C uma "union" é uma posição de memória que é compartilhada por duas ou mais variáveis diferentes, geralmente de tipos diferentes e em momentos diferentes.
Você declara unions quase igual a como você declara structs. Ex:

##

    //declaração/criação de uma union:
    union primeiroUM{
    	int i,
    	char ch;
    };
    // Declarando uma variável que participa/realiza essa union:
    union primeiroUM variavel1;

    //Acessando/alterando valores dessa variável:
    variavel.i = 10;

    //atribuindo valores a union através de uma função (bem parecido com o que fazemos em structs:
    void func1(union primeiroUM *un){
    	un->i = 12;
    }

##

Quando uma union é criada o compilador criar uma variável grande o suficiente para comportar o maior tipo de variável da únion.
No caso do exemplo anterior, criaria uma variavel com 2 bytes de tamanho (que é o tamanho de um int)
Basicamente o inteiro (int) é armazenado em 2 bytes e caractere (char) fica em 1 desses 2 bytes, "se alternado".
Usar union pode ajudar na produção de código independente da máquina (portável)

➼➼ Manipulação de arquivos.

C não possue comandos de I/O. Para realizar alguma operação de input ou output é necessário importar uma biblioteca e isso permite que diferentes formas de resolver um problema existam.
A biblioteca padrão do C que disponibiliza todas as funcionalidades em repeito à I/O é a <stdio.h>

➼ Stream e arquivos:

O sistema de I/O do C provê um nível de abstração aos programadores, deixando as coisas mais fáceis.
Essa "abstração" é chamada de stream e o dispositivo real é chamado de arquivo.
C pode trabalhar com diversos dispositivos, sejam terminais, acionadores de disco, etc.
Embora esses dispositivos sejam diferentes, o "sistema de arquivos com buffer" do C transforma esses diferentes dispostivos (fontes de input) em algo generalizado chamado de stream.

Ou seja, o sistema de arquivos do C se conecta com dispositivos e cria uma abordagem "generalista", de modo que consiguamos usar/mexer no dispositivo independente de qual ele seja (porque o C vai criar um padrão chamado de stream).

--->> Strema em C
Entenda stream como um meio termo: Um "Interpretador" entre a máquina/dispositivo externo com o C/sistema.

Outro modo de interpretar (é importante você pegar a ideia) é que streams é uma sequência de dados que mapeia e organiza input E output.
Ou seja, existem diversos tipos de input e o stream basicamente vai converter esses inputs em algo "padrão"/universal.

Quando você abre um arquivo, ele se associa/se liga com uma stream, que então "padroniza" o arquivo, e deixa ele "bonito", de modo que o programador/usuário consiga usar/modificar o arquivo.

Existem duas formas de streams, ou seja, C pode receber/analisar/interagir com 2 tipos de input de arquivos:
-> texto;
-> binário;

1. Uma stream de texto é uma sequência de caracteres onde, dependendo do dispositivo externo, talvez seja necessário coverter/traduzir alguma parte do input que esse dispositivo está mandando.

2. Uma stream binária é uma sequência de bytes, de modo que o "conteúdo" original (que está no dispositivo original) é passado sem perda de integridade (não há conversão/tradução)

--->> Arquivos em C
Em C (e no linux) um "arquivo" pode ser qualquer coisa, desde uma foto até uma impressora.
É associada uma stream a tipos de arquivo, de modo que a abertura do arquivo seja feita do modo específico que é necessário.

Cada stream possue uma estrutura de controle de arquivo que, básicamente, é um editor de texto e descreve tudo o que é feito.
Dessa forma, cada byte de um arquivo possue um endereço único que é o deslocamento realitvo ao início do arquivo.

➼ Arquivo texto x arquivo binário

É possivel gravar dados no formato de caracter(no C é ASCII) ou em binário (binary file).
Existem rotinas/funções para manipulação de arquivos "texto" e de manipulação de arquivos "binários".

"Ponteiros" são a cola que une o sistema C com o I/O.
Um "ponteiro de arquivo" é um ponteiro para informações que definem um arquivo, incluindo nome, status, etc.
Um ponteiro de arquivo é uma Variável ponteiro (que já vimos antes) do tipo FILE, usada para ler e escrever arquivos.

Através da função fopen(), o C vai abrir/criar uma stream para uso e associa um arquivo a essa stream, retornando um ponteiro de arquivo.
Dessa forma é possível alterar/manipular arquivos no C.

Para abrir um arquivo em C fazemos:
FILE _fopen(const char_ <path até o arquivo>, const char\* <modo>);
Onde <modo> é uma das possiveis operações que você pode fazer com o arquivo.
Por exemplo, se você quer Abrir um "arquivo de texto para leitura"(não pode ser alterado) deve-se usar o modo "r".
Para Criar um "arquivo de texto para leitura/escrita" usa-se "w+" e para abri-lo "r+"
Para criar um "arquvio binário para leitura/escrita" usa-se "w+b" e para abir-lo "r+b"

Para anexar/adicionar conteúdo no Final de um arquivo(anexar) usa-se "a" para arquivos de texto e "a+b" para arquivos binários.

##Ex:
FILE \*fp; //declaração de um "ponteiro de arquivo"
if((fp=fopen("teste", "w"))== NULL){
printf("Arquivo não pode ser aberto =(\n");
exit(1);
}

##

A função fclose() fecha uma stream que foi aberta pelo fopen(). Se tiver algum dado não salvo (algum dado permanece no buffer), fclose primeiro salva e então fecha.
Para fechar uma arquivo usa-se:
int fclose("FILE \*fp");
Onde "fp" é o "ponteiro de arquivo" criado/declarado/devolvido pela função fopen().
Se fclose() vale 0, então o fechamento ocorreu bem. Qualquer outro valor é erro.

No C existe a função fputc() para escrever caracteres e fgetc() para ler caracteres.
OBS: também existem funções que recebem e escrevem strings: fputs() e fgets()
Protótipo de utilização:

##

//Em ambos os casos *fp é o ponteiro de arquivo para um arquivo.
//Ou seja fp = fopen("arquivo", "modo");
int fputc(int ch, FILE *fp);
int fgetc(FILE \*fp);

##

## Exemplo de progrma que lê o nome do arquivo e mostra na tela.

##

    #include<stdio.h>
    #include<stdlib.h>

    void main(int argc, char *argv[]){ //recebe o nome do arquivo com um parâmetro do programa. Esse código é "padrão", copie e cole para ter essa funcionalidade
    	FILE *fp;
    	char ch;
    	if(argc != 2){ //Basciamente, argc é 2 se o nome do arquivo for válido e quando o programa está rodando, ou seja, "se o nome do arquivo não existir..."
    		printf("Seu arquivo não tem nome...\nComo isso é um arquivo então??\n");
    		exit(1);
    	}
    	if((fp = fopen(argv[1], "r")) == NULL){ //Estamos definindo/criando o "ponteiro de arquivo" (fp) dentro do if, e ele se refere ao primeiro elemento de argv, ou seja, o nome do arquivo.
    		printf("O nome do arquivo é considerado inexistente, logo --> :(\n");
    		exit(1);
    	}
    	ch = getc(fp); //vai ler um caractere de fp. Mas fp é um ponteiro de arquivo do arquivo atual, ou seja, vai ler um caractere do nome do arquivo.
    	while (ch!=EOF){ //Estamos fazendo um loop por uma sequencia de caracteres (o nome do arquivo). EOF representa o final do arquivo, ou seja: "enquanto não final de arquivo..."
    		putchar(ch); //imprime o Caractere atual na tela
    		ch = getc(fp); //O caractere muda e passa a ser o proximo. Ou seja, ele começa com a primeira letra do nome do arquivo e vai assim, até o nome acabar
    	}
    	fclose(fp); //importante fechar o arquivo. Otherwise você bloqueia memória para sempre.
    }

##

##

## Exemplo: programa que lê um arquivo texto e imprimi seu conteúdo na tela.

##

//execute esse código em um compilador local (vs code) e crie um arquivo chamado "abacate.txt" no diretório onde o programa está..

#include<stdio.h>
#include<stdlib.h>

void main(){

    FILE *arq;
    char linha[100];
    char *result;
    int i;

    arq = fopen("abacate.txt", "rt");
    if (arq == NULL){
    	printf("Problemas em abrir o arquivo");
    	exit(1);
    }
    i = 1;
    while (!feof(arq)){
    	result = fgets(linha,100,arq);
    	if (result){
    		printf("linha %d: %s", i, linha);
    	}
    	i++;
    }
    fclose(arq);

}

##

##

##Exemplo: Programa que lê uma string, grava/salva ela no disco, e depois lê o arquivo

##

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
fscanf(stdin, "%s", s); // é a mesma coisa que scanf, porém com strings. Lê do teclado.
fprintf(fp, "%s", s); //grava/anexa a string "capturada" no arquivo passado para fp.
fprintf(stdout, "Você anexou '%s' ao arquivo.\n", s);
fclose(fp);
//Nesse momento fp não aponta para nenhum arquivo, pois foi fechada a stream com fclose
if((fp=fopen("abacate.txt", "r")) == NULL){
printf("Arquivo não pode ser lido.\n");
exit(1);
}
//Aqui o fp já aponta novamente para um arquivo, pois a stream foi aberta dentro do "if"
fscanf(fp, "%s", s); //ao invés de ler do terminal, lê do proprio arquivo que fp aponta
fprintf(stdout, "Esse é o arquivo final: '%s'.\n", s); //imprime o conteúdo não no arquivo, mas sim no terminal.
}

##

##