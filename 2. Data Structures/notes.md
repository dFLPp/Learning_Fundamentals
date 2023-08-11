⚪ Considerações iniciais ⚪
Essas anotações são referentes as conceitos fundamentais/basicos sobre data structures.
Uma vez que você conseguiu o dominio sobre as funcionalidades básicas de uma linguagem de programação e já consegue resolver problemas sozinhos (desenvolveu a "visão computacional"), você está pronto para aprender sobre como os dados são guardados.
Nesse mundo tecnológico tudo são dados, seja de texto (encriptado ou não-encriptado) da nota fiscal de um super-mercado até uma imagem específica de um video pego em uma camera de segurança. As grandes companias e a tecnologia no geral precisa desenvolver métodos para obter, armazenar e acessar esses dados eficientemente.
Por exemplo, como um computador que tem não interface gŕafica vai mostrar ou armazenar imagens? Ou então, como eu consigo trocar a foto de perfil de um usuário (dentro milhões de usuarios) que já foi vista por milhares de pessoas?
Perguntas como essas trazem a tona Data Structures. Cada dado, cada informação que precisa ser armazenada, Deve ser armazena do melhor jeito possivel, ou seja, existem diferentes jeitos de se armazenar e Acessar diferentes tipos de dados.
Também não vamos esquecer que, só guardamos o que precisamos, e se precisamos de algo é porque vamos usar novamente, dessa forma, o ato de busca um dado específico dentre vários outros também é um fator relevante na hora de escolher um modo de arrumar os dados (ou seja, escolher a data struc [ds]).
Nessas anotações vou fazer a apresentação das data structs mais importantes e usadas em situações reais. Isso vai ser feito com a liguagem C. Disclaimer: Aprender data Structs pode ser feito com qualquer linguagem, pois está alheia as linguagens (funciona em qualquer lugar e é do mesmo jeito, mudando a implementação). Vou fazer C por que, além do nível de dificuldade elevado, o aprendizado "nas piores circunstâncias" torna os problemas médios e faceis, muito mais faceis.
Local útil para estudar: https://www.javatpoint.com/data-structure-tutorial

⚪ Estrutura e terminologia ⚪

Uma data structure é um ou vários algoritimos que emplementam o armazenamento os dados na memória (efetivamente guarda na memória). Esses varios algoritimos/modos de armazenar os dados são chamados de abstract data types (ADT) e, como os ADT == algoritimos, cada ADT tem um conjunto de regras/logica que permite o seu funcionamento.
É importante deixar claro que data structs estão completamente ligadas à algoritimos. Algoritimo é um conjunto de instruções finitas que pegam um input e transforma ele em um output desejado. Nesse aspecto se você trata os inputs como "raw data" e o output como os dados organizados em DS's, então existe algoritimo inerente/pertencente à Data structure.

Existem 2 tipos de DS's:
- Primitive: DS's primitivos são os data types primitivos, ou seja, int, char, float, etc.
- Non-primitive: É dividido em 2 tipos:
	- Lineares: armazenam os dados de maneira contígua na memória, ou seja, um elemento está conectado a um único outro elemento, em uma forma linear
	- Não lineares: Quando um elemento está conectado a outros 'n' elementos de uma maneira aleatória/não linear. Ex: trees, graphs.	
D's também podem ser classficadas como estáticas (o tamanho máximo é pre definido, antes do programa rodar), como as arrays/vectors e Dinâmicos (o tamanho máximo varia durante a execução do programa), como as linked list, queue e stack.

Como DS's são implementações de algoritimos, existem algumas funcionalidades/caracteristicas gerais que encontramos:
1. Searching (podemos procurar/verificar se um elemento existe/está contido na DS)
2. Sorting (podemos ordenar os elementos)
3. Insertion (podemos adicionar elementos)
4. Deletion (podemos retirar elementos)
5. Updation (podemos trocar um elemento por outro)
6. Merging (juntar duas ADT's (do mesmo tipo) em uma)


⚪ Asymptotic Analysis ⚪
Um jeito de saber qual DS é a melhor é ao analisar o seu consumo de tempo e seu consumo de espaço de memória. Imagine que você quer colocar um elemento no inicio de uma array. Você precisaria mexer/empurar todos os "n" elementos que já existem, dessa forma tendo uma complexidade definida por uma função f(n). É interranste usar as funções como base porque dessa forma podemos levar esse conceito de análise de gastos para outras áreas (sem ser necessáriamente programação).

No geral podemos analisar 3 casos:
O pior cenário (mais gasto) --> Big O Notation
O melhor cenário (menos gasto) --> Omega Notation
O cenário comum(gasto intermediário) --> Theta notation
Existe um conceito/base matemática por trás, porém ela é irrelevante. O mais importante é saber definir o Big O de uma data structure.
No geral, sempre que você vai comparar DS's, você testa o quanto elas gastam de tempo ao fazer a mesma atividade, sendo essas atividades as funções básicas de um algoritimo, ou seja, adicionar um elemento, remover um elemento, iterar, procurar, juntar duas ADT iguais e etc.

Comparação entre Arrays e Linked Lists
Time complexity:
	- acessar um valor
		array: O(1)
		linked list: O(n)
		
	- procurar/iterar até um valor
		array: O(n)
		linked list: O(n)
		
	- inserir um valor
		array: O(n)
		linked list: O(1)
		
	- deletar um valor
		array: O(n)
		linked list: O(1)
	
Space complexity:
	array: O(1)
	linked list: O(n)

Repare portanto que cada DS é boa/útil em certas circunstâncias, sendo necessário analisar o que você quer fazer, em que escala você quer fazer e o porque você quer fazer.


⚪ Infix, postfix e prefix ⚪
 São jeitos de Se escrever operações, na maioria matemáticas. São aplicações de stack para analise de expressões arimitéticas. Basicamente, quando você escreve (2+3)*5, primeiro a soma entre parenteses deve ser feita, ou seja, ela é adicionada a stack e a multiplicação só é feita quando a stack for esvaziada.
Estrutura de um "Infix": <operando><operator><operando>. Infix é a operação matematica "Normal" só que aplicada no compudador. Seguimos a ordem PEMDAS e usamos parenteses, chaves e colchetes para estrututar a ordem das operações.
No Prefix: <operator><operando><operando>. Ou seja, a operação infix "2+3" seria escrita como "+ 2 3", ou a operação "a + b*c" seria escrita como "+ a * bc" 
No postfix: <operando><operando><operator>. Ou seja, a operação infix "2+3" seria escrita como "2 3 +" ou a operação "a + b*c" seria escrita como "abc * +"
Do ponto de vista humano não faz sentido nenhum fazer essa conversão, entretanto os computadores entendem e funcionam melhor com essas abordagens alternativas (aparentemente).

Existem algoritimos que leem expressões em postfix ou prefix e que apartir dai calculam o resultado. A ideia básica para ambos os casos é, você cria uma stack e itera sobre uma string/expressão. Se o elem. for um número você coloca ele na stack, se for uma operação, você usa os dois ultimos(primeiros) elementos da stack, faz a operação em ordem correta (depende do tipo) e então faz o pop desses dois números.

Também existem algortimos que leem a expressão em infix e convertem para postfix e prefix, mudando a implementação dependendo do caso, mas no geral a ideia é: você cria uma stack e itera sobre a expressão. Se o elemento atual for um número você adiciona ele na string/resultado. Se o elemento for uma operação, ele vai para a stack e espera que o operando da direita(ou esquerda) apareça. Além disso é necessário iterar sobre toda a stack e analisar a precedencia do operador a ser "Pushado" e os operadores que já existem.




⚪ Queues ⚪
ADT/features:
	- First-in-firist-out (FIFO). Por exemplo uma fila. Se você chega primeiro e atendido e sai primmeiro. Diferente de stacks, onde você só pode retirar pelo mesma entrada que você entrou, em queues você pode sair por uma "entrada" diferente da que você entrou. 
	- Ou seja, as entradas/inserções (chamadas de "enqueues") são feitas na "tail"(rear) e a remoção (chamada de "dequeue") é feita na "head"(front).
	- Como pre-requisito, as implementações de queues devem ter time complexity de O(1)
	- Outro exemplo é uma impressora. Quando uma request para impressão é feita, a primeira é feita primeiro e as outras são colocadas em espera.
	- Outro exemplo é fazer o "agendamento" de comandos/processos.
	
Do mesmo jeito que stacks, queues são uma "metodologia", dessa forma existem diferentes formas de aplicar essa ideia. Vamos mostrar a implementação em array e a implementação em linked list.
Os codigos no geral são bastante alto explicativos então preste atenção e entenda a necessidade/motivo das abordagens usadas.

Array implementation:
Antes de qualquer coisa, existe um conceito chamadado de "circular array" onde ao chegar na ultima posição da array, voltamos ao incio desde que alguma das céculas estejam vazias. 
Isso será útil pois ao fazer o dequeue estariamos jogando uma posição da array fora, Agora podemos reutiliza-la ao verificar se (tail+1) % n == front e se for falso, fazemos rear = (rear+1) % n.
É claro que devemos fazer o dequeue de modo a usar a ideia array circular. É importante notar que a ideia de circular array, ou imaginar a array como um retangulo são só interpretações lógicas. Efetivamente/fisicamente as coisas são diferentes, mas podemos aplicar logicas diferentes para resolver problemas de maneiras diferentes.
##
#include <iostream>
#define SIZE 20
using namespace std;

class queue{
    private:
        int A[SIZE];
        int head, tail;
    
    public:
        void createQ(){
            head = -1;
            tail = -1;
        }
        
        bool isEmpty(){
            if(head == -1 && tail == -1) return true;
            else return false;
        }
        
        bool isFull(){
            //something cool, just shouting out.
            return (tail+1) % SIZE == head ? true : false;
        }
        
        void enQueue(int x){
            if(isFull()){
                cout << "Queue is full\n";
                return;
            }
            else if(isEmpty()){
                head++;
                tail++;
                A[tail] = x;
                return;
            }
            else{
                tail = (tail+1)%SIZE;
                A[tail] = x;
                return;
            }
            
        }
        
        void deQueue(){
            if(isEmpty()){
                cout << "Queue is alredy empty.\n";
                return;
            }
            else if(head == tail){
                head = tail = -1;
                return;
            }
            else{
                head = (head+1)%SIZE;
            }
            
        }
        
        void print(){
            //gambiarra para iterar sobre a circular array:
            cout << "Estado atual: ";
            int count = (tail - head + SIZE) % SIZE + 1;
            for(int i = 0; i < count; i++){
                int index = (head+i)%SIZE;
                cout << A[index] << " ";
            }
            cout<<"\n\n";
        }
        
};

int main(){
    queue Q;        Q.createQ();
    Q.enQueue(2);   Q.print();  
    Q.enQueue(3);   Q.print();  
    Q.enQueue(0);   Q.print();
    Q.deQueue();    Q.print();

    return 0;
}
##

A implementação utilizando linked list utiliza de outro pointer que ficará sempre no ultimo node adicionado. Dessa forma podemos deletar um node no inicio da lista com O(1) e mudar o pointer dele (head ou front) para o seu proximo e ao adicionar um elemento na queue, usamos o outro ponteiro (rear) para reajustar o "next" do agora penúltimo elemento.
##

	#include <stdio.h>
	#include <stdlib.h>

	struct node{
	    int data;
	    struct node* next;
	};

	struct node* front = NULL;
	struct node* rear = NULL;

	void enQueue(int x){
	    struct node* temp = (struct node*)malloc(sizeof(struct node*));
	    temp->data = x;
	    temp->next = NULL;
	    if(front == NULL && rear == NULL){
		front = temp;
		rear = temp;
	    }else{
		rear->next = temp;
		rear = temp;
	    }
	}

	void deQueue(){
	    struct node* temp = front;
	    if(front == NULL) return;
	    
	    if(front == rear){
		front = NULL;
		rear = NULL;
	    }else{
		front = front->next;
	    }
	    free(temp);
	}

	void print(){
	    struct node* temp = front;
	    while(temp->next != NULL){
		printf("%d -> ", temp->data);
		temp = temp->next;
	    }
	    printf("%d\n", temp->data);
	}


	int main(){
	    enQueue(2);
	    enQueue(3);
	    enQueue(-7);
	    print();
	    
	    deQueue();
	    print();
	    enQueue(0);
	    print();
	    return 0;
	}

##


⚪ Trees ⚪

Uma maneira não linear de armazenar dados que se relacionam de maneira hierárquica/ordenada. Por exemplo os empregados de uma empresa ordenado de acordo com seus cargos.
ADT: Coleção de nodes que interagem de maneira hierarquica. O node inicial é o chamado de "root" apartir deles são derivados outros nodes (tem um pointer para esses nodes) que são chamados de childs e assim sucessivamente.
Os childs de um child do root é chamado de grandchildren. Dois nodes na mesma "profundidade" são siblings. O node anterior a um node é seu parent.
Os ultimos nodes na sequencia/cadeia/branch (não tem childs) são chamados de leaf nodes.
Você só pode iterar/andar no sentido do root até uma leaf node.
Também é possivel imaginar uma tree rercursivamente. Onde o root (node inicial) tem como child sub-trees, que tem como child subtrees e etc.
Em qualquer tree com N nodes, exitem N-1 links entre nodes.
Uma tree onde todos os nodes tem dois childs é chamada de binary tree.
Deapth of X: é o numero de links usados para se chegar no node X, apartir do root.
Height of X: é o Maior número de links usados para chegar a um leaf node apartir do node X.
Tree é uma data struct versátil muito boa para armazenar dados de modo que a pesquisa/acesso a esses dados é dado de maneira eficiente.
Uma possivel estrutura de node de uma binary tree seria:

struct node{
  int data;
  node* leftChild;
  node* rightChild;
}
Os pointers de leaf nodes apontam/são NULL.
Como a implementação de trees são trabalhosas focaremos em demostrar as BST's, tipo mais comum e importante de tree

Em uma binary tree completa o número Maximo de nodes possiveis é 2^i onde i é o número de levels/profundidade da tree.
Um binary tree é "perfeita" se todos os nodes tem 2 childs exeto os nodes no ultimo level da tree, que seram leaf nodes. Nesse caso, o número maximo de nodes seria 2^(h+1) - 1 onde h = log((n+1) - 1) na base 2.

Height/altura de uma tree com 0 nodes é -1 e a height de uma tree com só um node é 0

Balenced binary tree é uma tree cujo a diferenaça entre a height do subtree esquerda e a subtree da direita (em módulo) não é maior 1
Quando se fala de balancear uma tree, fala-se sobre o processo de igualar o tamalho dos "galhos" de uma tree.
(Lembrando: height é o maior número de links que se percorre partindo do root até uma leaf node) 

Podemos implementar trees com:
  - Nodes criados dinamicamente (structs)
  - arrays (normalmente usada para criar "Heaps")


➼➼ Implementação de binary search em arrays:
Binary search é uma algoritimo usado em arrays que foram ordenadas para encontrar um número.
Imagine que exite 100 números de 1 à 100 em uma array. Para archar o número 99 ao invés de iterar por cada elemento e obter um big O(n) podemos usar binary search. Ela consiste em dividir o tamanho de procura pela metade até achar o elemento.
No exemplo, uma binary search iria achar o elemento do meio da array(50) e verificar se o número (99) é maior ou menor. Ele iria repetir esse processo até achar o número 99.

Lembre: Como pre-requesito a array deve estar ordenada (basta fazer um bubble sort)

##
	#include<stdio.h>
	int binarySearch(int A[], int n , int x){
	  int low = 0;
	  int high = n - 1;
	  
	  while(low <= high){
	    int mid =(low+high)/2;
	    if(x == A[mid]) return mid;
	    else if(x < A[mid]) high = mid - 1;
	    else low = mid + 1;
	  }
	  //se chegar aqui é pq não achou o número
	  return -1;
	}
	
	int bubble(int A[], int n){
	  int i, j, k;
	  for(i = 0; i < n; i++){
	    for(j = i + 1; j < n; j++){
	      if(A[j] < A[i]){
	        k = A[j];
	        A[j] = A[i];
	        A[i] = k;
	      }
	    }
	  }
	}
	
	int main(){
	  int A[] = {-6, 4, 7, 15, 5, 12, 10};
	  printf("Enter a number: ");
	  int x; scanf("%d", &x);
	  bubble(A, sizeof(A)/sizeof(A[0]));
	  int index = binarySearch(A, 6, x);
	  if(index != -1) printf("%d foi encontrado na posição %d", x, index);
	  else printf("%d não foi encontrado", x);
	  return 0;
	}
##
Outra utilidade da binary search é achar/contar quantas vezes um valor repetido aparece em uma dataset:
## Em C++
	#include<stdio.h>
	int binarySearch(int A[], int n , int x, bool searchFirst){
	  int low = 0;
	  int high = n - 1;
	  int result = -1;
	  
	  while(low <= high){
	    int mid =(low+high)/2;
	    if(x == A[mid]){
	      result = mid;
	      if(searchFirst){
		high = mid-1;
	      }else{
		low = mid+1;
	      }
	    }
	    else if(x < A[mid]) high = mid - 1;
	    else low = mid+1;
	  }
	  
	  return result;
	}

	int main(){
	  int A[] = {-6, 0, 2, 7, 7, 7, 7, 10, 10, 12, 12};
	  printf("Enter a number: ");
	  int x; scanf("%d", &x);
	  int firstIndex = binarySearch(A, sizeof(A)/sizeof(A[0]), x, true);
	  if(firstIndex != -1){
	    int lastIndex = binarySearch(A, sizeof(A)/sizeof(A[0]), x, false);
	    printf("%d foi encontrado %d vezes", x, lastIndex - firstIndex + 1);
	  }
	  
	  else printf("%d foi encontrado 0 vezes", x);
	  return 0;
	}
##



⚪ BST ⚪

BST ou binary search tree é uma binary tree especial. Nela todos os valores/tamanho de todos os nodes da subtree da esquerda devem ser menores que o valor do root e todos os nodes da subtree da direita devem ser maiores que o valor do root.
Ex:
    15		Recursivamente, as subtrees de uma BST também são BST's. Repare à esquerda o 10 (menor que 15) e a direita o 20 (maior que 15)
   /  \  	Repare na subtree da esquerda (trate 10 como root), a esquerda tem 8 (menor que 10) e a direita 12 (maior que 10)
 10   20	Repare a subtree da direita (trate 20 como root), a esquerda tem 17 (menor que 20) e a direita 25 (maior que 20)
/ \   / \
8 12 17  25

Seguindo esse padrão o Big O das operações de search, insert e delete seriam os menores possiveis, que seriam O(log(n)) (log na base 2). 
Para que O(log(n)) sempre seja verdade, precisamos deixar a BST "balanceada".

Suponha que um computador faz um milhão de comparações por segundo. Temos então que uma comparação demora 10⁻⁶ segundos.
Suponha que queremos fazer uma pesquisa em uma database (ou etc) e esses dados estão armazenados em arrays (ou algo que tenha O(n)) que tem 2³¹ arquivos. Demorariamos 10⁻⁶*2³¹ = 200 segundos para cada pesquisa.
Agora imagine que nos organizamos esses arquivos em um BST. Nesse cenário o tempo necessário seria 31*10⁻⁶ segundos.

Em suma, computacionalmente, trees, mais especificamente Binary trees, mas especificamente BST's são a melhor forma de armazenar dados que seram consultados.

Como o nome diz, BST são uma DS que também é um algoritimo, o binary search tree. Se a tree está balanceada e fazemos uma binary search tree nos vamos fazer o mesmo procedimento que em uma binary search normal, vamos ignorando/diminuindo o espaço de procura pela metade(cortar um dos 2 galhos da tree)(n, n/2, n/4, n/8, ...) até chegarmos no valor/node que queremos.
Ao fazer "Insert" e "Delete" a binary tree vai ficar desbalanceada. Precisamos rebalancea-la para que o BST não perca produtividade.

Para criar uma BST usamos o mesmo esquema de criar nodes, como fazemos em linked lists, ou seja, vão ser criadas dinamicamente na memoria e por consequencia seram armazenadas no Heap, só pondendo ser acessada através de pointers.

Primeiro criamos um pointer que apontará para o root node. Se esse pointer for nulo a tree estará vazia.
Também vamos aproveitar que BST's funcionam bem com recursividade.

## Em C++

	#include <iostream>
	using namespace std;

	struct BSTnode{
	    int data;
	    BSTnode* leftChild;
	    BSTnode* rightChild;
	};

	/*
	Poderiamos fazer: node* root = NULL; (root é global)
	Dessa forma não precisariamos passar ele nas funções.
	*/

	BSTnode* createNode(int x){
	    BSTnode* temp = new BSTnode();
	    temp->data = x;
	    temp->leftChild = temp->rightChild = NULL;
	    return temp;
	 }

	BSTnode* insert(BSTnode* rootPointer, int x){
	    if(rootPointer == NULL){
		rootPointer = createNode(x);
	    }
	    else if(x <= rootPointer->data){
		rootPointer->leftChild = insert(rootPointer->leftChild, x);
	    }
	    else{
		rootPointer->rightChild = insert(rootPointer->rightChild, x);
	    }
	    return rootPointer;
	}

	bool search(BSTnode* rootPointer, int x){
	    if(rootPointer == NULL) return false;
	    else if(rootPointer->data == x) return true;
	    else if(rootPointer->data <= x) return search(rootPointer->rightChild, x);
	    else return search(rootPointer->leftChild, x);
	}

	int main(){
	    int i;
	    //criando a tree vazia
	    BSTnode* rootPointer = NULL;
	    
	    //inserindo nodes
	    rootPointer = insert(rootPointer, 15);  rootPointer = insert(rootPointer, 10);
	    rootPointer = insert(rootPointer, 20);  rootPointer = insert(rootPointer, 25);
	    rootPointer = insert(rootPointer, 8);   rootPointer = insert(rootPointer, 12);
	    
	    //testando
	    cout << "Diga um número: "<< endl;
	    cin >> i;
	    if(search(rootPointer, i) == false) cout << "Número não encontrado" << endl;
	    else cout << "Número encontrado" << endl;
	    return 0;
	}


##


⚪ Binary tree traversal
"traversal" é o ato de passar por todos os nodes da tree uma única vez e conseguir acessar/computar seus dados (fazer o print de seu valor). Existem diferentes algoritimos e metodologias para fazer o traversal:
  - Metodologia Breadth-first ----> Algoritimo: Level-order (consiste em ler os nodes no mesmo nivel/depth antes de descer mais na tree, normalmente da esquerda para a direita)
  - Metodologia Depth-first -----> Algoritimos: Preorder (root,left,right) (DLR, recomendo ver um vídeo para entender, é bem simples porém muito chato de escrever isso. É o tipo de coisa que você deve lembrar, não tentar escrever), Inorder(left, root, right)(LDR), Postorder((right, left, root)(RLD). No geral, consiste em ler/acessar todos os child nodes (descer/até o fundo) para então ir para um sibling node.

Level-order:
Vamos utilizar queues para armazenar o node atual. Uma fez que fizermos o Enqueue do left e e right child do root, vamos printar seus valores, e fazer o enqueue de seus childs. Repare que, como estamos usando uma queue os nodes são "Enqueue-ados" em ordem lógica (é mais fácil vendo uma imagem, confia, dá uma olhada no video: https://www.youtube.com/watch?v=B31LgI4Y4DQ)
Sinta-se livre para revisar queues ao fazer uma do zero, mas aqui vamos utilizar o C++ STL que é um conjunto de libraries que tem todas as DS e seus principais methods. 
## Só a função em C++
//Suponha que fizermos #include<queue> e que a struct node foi declarada:

void levelOrder(node* rootPointer){
  if(rootPointer == NULL) return;
  queue<node*> Q;
  Q.push(rootPointer);
  while(!Q.empty()){
    node* current = Q.front();
    cout << current->data << " " << endl;
    if(current->leftChild != NULL) Q.push(current->leftChild);
    if(current->rightChild != NULL) Q.push(current->rightChild);
    Q.pop();
  }
}
//Time complexity: O(n) pois vamos passar pelos n nodes da tree exatamente uma vez
//Space complexity: Varia de acordo com o número de nodes colocados na queue => varia de acordo com a queue. No pior cenário: O(n)
##

Preorder, Inorder, Postorder: São jeitos diferentes de se iterar pela tree. Para não deixar esse arquivo muito grande, olhe o arquivo "codes" e vocẽ verá as funções.
OBS: Para provar que uma Binary Tree é uma BST basta verificar se a lista/array de números "printados" durante a inorder traversal é ordenada (do menor ao maior)

⚪ BST "delete" operation

Deletar um node em uma tree não é algo tão simples. Você não pode deletar qualquer node, se não um "ganho" inteiro pode cair. Além disso quando você deleta um node a tree resultante deve manter as propriedades e por consequencia ser uma BST.
Para deletar leaf nodes só precisamos desfazer o link entre nodes e liberar o node da memória. Para deletar um node que tem 1 child, basta refazer o link entre o node anterior ao que queremos deletar e ao seu child. Caso o node tenha mais que um child as coisas ficam mais complexas levando em consideração a necessidade de manter as propriedades de uma BST. 
Basicamente vamos escolher uma alternativa: Vamos tratar o node que queremos deletar com um root e analisar as subtree dele. Podemos então escolher o node com menor valor da right-subtree, copiar seu valor ao root da subtree e então iriamos recair no caso 2 (tem 1 child) ou caso 1 (não tem childs). Outra alternativa seria escolher o node com maior valor da left-subtree e então fazer o mesmo processo, recaindo em algum outro caso. (Repare que só exitem 3 casos porque se trata de um Binary tree) 

Código no outro arquivo.

⚪ Outras trees mais complexas ⚪

----------> AVL tree:
É uma BST balanceada. Para que a BST esteja balanceada é necessário que, para cada node da tree: -1 <= (height da left sub-tree) - (height da right sub-tree) <= 1
Procure por imagens. O nome dado a essa subtração é "Balance factor". Quando adicionamos ou deletamos um node a tree obviamente vai ser desbalanceada, sendo necessário fazer as tão faladas "AVL Rotations", que consistem em trocar a posição de certos nodes, dada certas condições, para que a BST fique balanceada e se torne uma AVL.
Primeiramente, você não precisa saber fazer, só precisa mostrar que conhece o nome e Segundo, não vou copiar e colar o código aqui por que isso não vai fazer você aprender e nem vai fazer isso ser útil.

----------> Heap:
Heap é uma data structure (e também parte da memória RAM) que é uma tree completa. Uma tree completa é uma tree onde todos os nodes, exeto os leaf nodes tem extamente 2 childs. Existem 2 tipos de Heaps: Min. Heap: Onde o valor no parent node deve ser menor ou igual ao valor dos seus childs; Max. Heap: Onde o valor do parent node dever ser maior ou igual aos valores dos seus childs.
Se você analizar bem, uma heap é "logicamente" a mesma coisa que uma BST, é uma binary tree com pre-requisitos. Uma vez que você entende a lógica por tras da definição, a implementação fica fácil (tal qual em BST)

----------> Trie:
Também conhecida como digital tree ou prefix tree é uma tree-based data structure que trabalha/iterage com caracteres. A ideia básica é que, com uma trie você consegue montar/pesquisar por palavras, uma vez que os nodes possuem os caracteres necessários para formar a palavra que você pesquisou. O root node é NULL e cada node pode ter no máximo 26 child nodes (número de letras no alfabeto). Tries podem ser utilizadas em corretores de texto, em Auto-complete operations (quando você escreve metade do comando e o VS code vem com a sugestão do que você quer) entre outras coisas. Tem um exemplo de trie no outro arquivo só de curiosidade.


⚪ Hashing/ Hash table ⚪

Hash table é uma data structure que funciona da seguinte forma: Você tem um conjunto de dados chamado de Keys. A cada key desse conjunto de dados é aplicado uma função ou processo chamado de Hash function e o resultado dessa função é que, cada key vai ser associada com um Value. Por exemplo: Se a key é seu email e a hash table de um site serve para te autenticar, então ao colocar seu email, ele vai estar associado a seus values, que podem ser nome de perfil, amigos, jogos que você possue, etc.
No geral, o resultado de uma hash function vai retornar um Index, e com esse index você consegue acessar o bucket (local) onde seus dados estão guardados.

Se a hash function for perfeita/não tiver erros então uma propriedade muito util aparecerá: O tempo necessário para acessar seu index, dada uma key, e constante, ou seja, Big O(1). Outra caracteristica da Hash table é que para cada key existe um único value/bucket correspondente.
Entretanto se a função for mal feita pode ocorrer um erro chamado de "Colision". Colision é quando colocando/inserindo duas keys diferentes você obtem o mesmo value.
Existem diversas interpretações/representações lógicas, mas você pode entender a Hash table em si como se fosse uma array de doubly linked lists e que ela é vista verticalmente. Do mesmo jeito existem diversas hash functions diferentes que podem ser usadas, uma das mais simples é h(x) = x % m. Você passa um número x é o index dele na hash table vai ser o resto da divisão de x por m (número de buckets/ número de doubly linked lists/ tamanho (número de linhas) da hash table).

Mais uma vez, existem diversos jeitos de fazer as coisas, mas um dos métodos mais simples de lidar com a "Colision" citada anteriormente é, passar esse elemento como o proximo node da linked list que já existe. Se você visse uma imagem seria melhor, entretanto você pode executar o código abaixo que vai te dar um boa noção/relembrar.

## Simple Hash table 

#include <iostream>
#include <list>
#include <stdlib.h>
#include <assert.h>

using namespace std;

class hashTable{
    private:
        int buckets; //número de linhas/espaços na hash table
        list<int>* table; // Uma linha da table, ou seja, uma doubly linked list já pronta
    
    public:
        //contructor
        //(OBS: Method especial usado para criar objetos pre configurados, deve ter mesmo nome que a classe e não retorna nada)
        hashTable(int b){
            buckets = b;
            table = new list<int>[buckets];
            //criando "b" linked lists (linhas da table) que juntas formam a hash table.
        }
        
        void insert(int d){
            //nossa hash function. "bucket" é o index onde o valor d ficará armazenado
            int bucket = d % buckets;
            //dentro da hash table, vá ate a linha "bucket" (index) e coloque o valor aí.
            table[bucket].push_back(d);
            /*
            O method "push_back" é bom conveniente pois, idependente se já existe número nesse index ou não, como é uma linked list
            ele vai colocar nesse index do mesmo jeito, mas tomando cuidado para manter a ordem. Essa ideia de usar linked lists serve 
            justamente para contornar o problema de "Colision"
            */
        }
        
        void print(){
            for(int i = 0; i < buckets; i++){
                cout << "| bucket/index " << i << " | ";
                for(auto j : table[i]){
                    //Vamos por partes:
                    /*
                    1. -- estamos printando o table[i], e isso uma linked list, seria bem "Chato" tem que iterar sobre uma linked list né...
                    então é por isso que usamos a "auto" keyword, ela serve para declarar uma variável (j) que é de uma data type complexo
                    
                    2. -- Já a parte ": table[i]" é uma nova funcionalidade do C++, "Range-based for loop", basicamente ao inves de dar um
                    limite númerico, tipo < 10, nos damos um intervalo de valores e então o for loop itera até os elementos desse intervalo acabarem
                    */
                    cout << "-> | " << j << " | ";
                }
                cout << endl;
            }
        }
    
};

int main(){
    //criando a hash table com 8 indexes/buckets
    hashTable ht(8);
    
    //usando uma das bibliotecas para gerar números aleatórios e inserir na tabela
    srand(2);
    for(int i = 0; i < 20; i++){
        ht.insert(rand() % 100);
    }
    
    ht.print();
    
    return 0;
}


##

Analizando o resultado do codigo acima percebe-se que a hash table usada é bastante ineficaz pois, o intuito de hash tables e fazer como que tenhamos cadeias/buckets curtos e todos preenchidos (no código existem buckets vazios e outros longos).
Em trabalhos/situações reais você sabe qual tipo de dado você está recebendo e dessa forma você pode tentar desenvolver hash table mais eficazes para esse tipo dado. Entram em jogo outros conceitos como dada analysis e etc.


⚪ Graphs ⚪

Graph é um modo não linear de armazenar os dados. Diferente das Binary trees, não existe nenhuma pre-condição para um graph. Pela definição lógica, um graph é o conjunto de V vertices(ou nodes) que são ligados por E edges(ou links). Matematicamente declaramos um graph G como sendo igual á (V, E) onde V = {V1, V2, ..., Vn} é um par Não-ordenado.
As edges de um graph podem ser direcionadas (de um vertice u à um vertice v) ou não-direcionadas. No primeiro caso um verice entre v1 e v2 é representado como (V1, V2) (par ordenado) e no segundo caso como {V1, V2} (usa-se chaves pois o par é Não-ordenado). Dessa forma E pode ser descrito como E = {{V1, V2}, {V2, V3}, ..., {Vn, Vw}}. Se as edges são direcionadas forma-se um Digraph.
Existem diversas aplicações para graphs, um exemplo é uma rede social, onde cada node é um usuário e os edges são os meios pelos quais um usuário se conecta com os outros. As internet também funciona dessa forma, na realidade, lembra de quando você estudou Algebra linear? Lembra do assunto "metodo de rankeamento do google, PageRank"? Então, Um graph é a representação que temos em questões desse tipo, normalmente cada node desse graph é uma pagina da internet e cada edge é direcionado à outra página. Surgem apartir daí os mais diversos problemas para se otimizar, por exemplo: Qual página recebe mais menções, qual página é a mais importante, qual página é a menos importante, qual página devo mostrar dada uma pesquisa aleatória, etc.

Existe também Weighted graphs, onde a importancia de cada edge é diferente. Por exemplo, se representarmos as pistas que ligam as cidades de um estado em graph não-direcionado, é incorreto dizer que todas as pistas são igualmente importantes. Repare que nesse graph os nodes seriam as cidades e os links as pistas ou seja, realmente são as Edges que possuem diferentes importancias. Em casos como esse atribuem-se valores ao edges (proporcianal à largura da pista, tráfego, importancia econômica, etc). Outras perguntas importantes também surgem, por exemplo qual o melhor caminho entra a cidade A e a cidade B? Qual custa menos? Qual o caminho mais rápido ?

Outros tipos de edges especiais são: Self loop (um node tem um link/edge que o leva para sí mesmo), Multiedge (existem mais que 1 edge entre dois mesmos nodes). Se um graph não tem nehum desses casos especiais, ele é considerado Normal. Em um graph normal e  direcionado, o número maximo de edges é n*(n-1) onde n é o número de nodes, e caso seja não-direcionado o número máximo é n*(n-1)/2.
Dependendo da razão entre número de nodes/ número de edges podemos classificar um graph como "Denso", ou "Esparçado".

Existem ainda o coneceito de: 
Walk: uma sequencia de nodes que nos leva, através das edges até um destino.
Path(simple): É uma Walk onde nenhum vertice e nenhum edge é repetido/revisidado durante o percurso.
Trail: É uma Walk onde nenhuma Edge é repetida.
Strongly conected: Se existe um Path de um node X para um node Y quaisquer
Cyclic graph: Existe um walk onde o destino final é o ponto de partida, sendo o ponto de partida o único node repetido. (Trees são Undirected Acyclic graphs)

Armazenando graphs:
Para implementar graphs podemos guardar em uma array os dados de cada node e em outra array as edges entre os nodes. Dada a definição de Edge, poderiamos criar:

struct edge{
  struct node* startVertex;
  struct node* endVertex;
  int weight;
}
// Onde "node" é uma struct que representa o dado que queremos guardar. Você pode trocar "struct node*" por um pointer de qualquer outro data type.
// A analise através de Big O mostra que essa forma não é a mais eficiente, mas ela existe.


Existem 2 formas principais/ideais de se armazenar/utilizar graphs:

1. Sequential representation (or, Adjacency matrix representation)
2. Linked list representation (or, Adjacency list representation)

Em 1. temos exatamente uma matrix de Algebra linear, só que agora aplicada na computação. Nesse caso iriamos ter uma array de tamanho X que conteria todos os nodes do graph. Criarimaos então uma Matriz de tamanho X por X onde os valores do elemento Aij = 1 se existe conexão entre node i e node j, e Aij = 0 se não existe conexão entre esses nodes. A grande vantagem desse método é que, dado o indice i de um node, na array de nodes, podemos checar Imediatamente na linha i, quais são os nodes que tem coxeção com o node de index i. A ideia por trás da DS "Hash table" é bem semenlhante a esse caso.
No caso de um Weighted graph, substituimos 1 pela weight do Edge e substituiomos todos os zeros por um valor muito grande (infinito ou etc). 
Reapare que nessa aplicação estamos gastando bastante memória, pois tem muitos espaços vazios. Em suma a maioria dos graphs são esparçados, o que significa que essa abordagem só deve ser usada se o graph for denso (a proporção de nodes e edges seja proxima de 1) ou que o número de edges (e por consequencia o número de nodes) seja pequeno.

Em 2. temos o melhor jeito de trabalhar com graphs, ao mesmo tempo que tem time complexity baixo, não consume tanta memória como o método anterior. Basicamente vamos usar uma abordagem de linked list para cada tipo de graph.
Caso ele seja não-direcionado e unweighted:
Para cada node, criamos uma linked list, onde o primeiro node é o node X e os nodes subsequentes são os nodes com o qual X tem conexão. Repetimos isso para todos os nodes.
Caso o graph se direcionado:
Para cada node X criamos uma linked list onde o primeiro node é o X e os nodes subsequentes são, ordenadamente as ligações de um node com o outro
Caso o graph seja weighted:
Basta criar mais um espaço no node para colocar o fator multiplicativo
Não preciso nem dizer que é impossivel descrever corretamente né... Se você quer entender as diferenças e poder aplicar, veja uma imagem ou um video sobre.

##Ex:

	#include <stdio.h>  
	#include <stdlib.h>  
	  
	/* structure to represent a node of adjacency list */  
	struct AdjNode {  
	    int dest;  
	    struct AdjNode* next;  
	};  
	  
	/* structure to represent an adjacency list */  
	struct AdjList {  
	    struct AdjNode* head;  
	};  
	  
	/* structure to represent the graph */   
	struct Graph {  
	    int V; /*number of vertices in the graph*/  
	    struct AdjList* array;  
	};  
	  
	  
	struct AdjNode* newAdjNode(int dest){  
	    struct AdjNode* newNode = (struct AdjNode*)malloc(sizeof(struct AdjNode));  
	    newNode->dest = dest;  
	    newNode->next = NULL;  
	    return newNode;  
	}  
	  
	struct Graph* createGraph(int V)  
	{  
	    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));  
	    graph->V = V;  
	    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));  
	  
	    /* Initialize each adjacency list as empty by making head as NULL */  
	    int i;  
	    for (i = 0; i < V; ++i)  
		graph->array[i].head = NULL;  
	    return graph;  
	}  
	  
	/* function to add an edge to an undirected graph */  
	void addEdge(struct Graph* graph, int src, int dest)  
	{  
	    /* Add an edge from src to dest. The node is added at the beginning */  
	    struct AdjNode* check = NULL;  
	    struct AdjNode* newNode = newAdjNode(dest);  
	  
	    if (graph->array[src].head == NULL) {  
		newNode->next = graph->array[src].head;  
		graph->array[src].head = newNode;  
	    }  
	    else {  
	  
		check = graph->array[src].head;  
		while (check->next != NULL) {  
		    check = check->next;  
		}  
		// graph->array[src].head = newNode;  
		check->next = newNode;  
	    }  
	  
	    /* Since graph is undirected, add an edge from dest to src also */  
	    newNode = newAdjNode(src);  
	    if (graph->array[dest].head == NULL) {  
		newNode->next = graph->array[dest].head;  
		graph->array[dest].head = newNode;  
	    }  
	    else {  
		check = graph->array[dest].head;  
		while (check->next != NULL) {  
		    check = check->next;  
		}  
		check->next = newNode;  
	    }  
	}  
	/* function to print the adjacency list representation of graph*/  
	void print(struct Graph* graph)  
	{  
	    int v;  
	    for (v = 0; v < graph->V; ++v) {  
		struct AdjNode* pCrawl = graph->array[v].head;  
		printf("\n The Adjacency list of vertex %d is: \n head ", v);  
		while (pCrawl) {  
		    printf("-> %d", pCrawl->dest);  
		    pCrawl = pCrawl->next;  
		}  
		printf("\n");  
	    }  
	}  
	  
	int main(){  
	  
	    int V = 4;  
	    struct Graph* g = createGraph(V);  
	    addEdge(g, 0, 1);  
	    addEdge(g, 0, 3);  
	    addEdge(g, 1, 2);  
	    addEdge(g, 1, 3);  
	    addEdge(g, 2, 4);  
	    addEdge(g, 2, 3);  
	    addEdge(g, 3, 4);  
	    print(g);  
	    return 0;  
	} 

##

⚪ Graph traversal:
Do mesmo jeito que trees existem diferentes metodologias e algoritimos para fazer o traversal de uma graph. Além disso exitem diversos problemas matemáticos interessantes como o "Dijkstra's Algorithm" que é utilizado para achar o menor path entre dois nodes.
Um exemplo de traversal pode ser encotrado no arquivo de exemplos, mas para não deixar as anotações muito tecnicas, encerro as anotações sobre graphs por aqui.


⚪ DS Complexas ⚪

Ainda existem muitas outras Data structures que não foram citadas/expostas. Elas podem ser totalmente diferentes/desconhecidas ou podem ser melhorias das Structures que você já conhece. O intuito dessas anotações é expor as principais/mais usadas. 
Não há necessidade de aprender o que é uma "Priority queue" ou como usar uma "B+ tree" se você não vai usar elas pra nada. Com o "arsenal" de conhecimento que você tem dessas anotações você já consegue combater todos os inimigos. 
Não recomendo você perder tempo/quebrar a cabeça tentando aprender coisas muito tecnicas/especificas porque:
1. Você nunca vai aprender tudo muito menos todas as structs, ou seja, isso só vai consumir seu tempo e de deixar cabisbaixo
2. Você não vai precisar delas. As tecnologias avançam e o mais eficiente é, as vezes, o mais simples. E além disso a intenet sempre irá existir. Se você vai entrar em uma empresa/cargo que diz Explicitamente que você precisa saber de algo (que você não sabe) basta pesquisar e aprender (entretando entenda que nesse caso vocẽ precisa aprender devido a uma necessidade profissional).

Se desapegue da necessidade de querer aprender tudo. Isso é inerente ao fato de que você não sabe/decidiu o que fazer da vida (e por consequencia tenta de especializar em tudo), entretando entenda que, isso só custa tempo e recurso e, no final das contas, você vai esquecer disso na proxima semana, então: "work smart not hard" pode ser transmitido a você como "study smart not hard".
