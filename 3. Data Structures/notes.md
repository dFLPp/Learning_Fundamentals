
⚪ BST ⚪

BST ou binary search tree é uma binary tree especial. Nela todos os valores/tamanho de todos os nodes da subtree da esquerda devem ser menores que o valor do root e todos os nodes da subtree da direita devem ser maiores que o valor do root.
Ex:
15 Recursivamente, as subtrees de uma BST também são BST's. Repare à esquerda o 10 (menor que 15) e a direita o 20 (maior que 15)
/ \ Repare na subtree da esquerda (trate 10 como root), a esquerda tem 8 (menor que 10) e a direita 12 (maior que 10)
10 20 Repare a subtree da direita (trate 20 como root), a esquerda tem 17 (menor que 20) e a direita 25 (maior que 20)
/ \ / \
8 12 17 25

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
node\* current = Q.front();
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


⚪ Graphs ⚪

Graph é um modo não linear de armazenar os dados. Diferente das Binary trees, não existe nenhuma pre-condição para um graph. Pela definição lógica, um graph é o conjunto de V vertices(ou nodes) que são ligados por E edges(ou links). Matematicamente declaramos um graph G como sendo igual á (V, E) onde V = {V1, V2, ..., Vn} é um par Não-ordenado.
As edges de um graph podem ser direcionadas (de um vertice u à um vertice v) ou não-direcionadas. No primeiro caso um verice entre v1 e v2 é representado como (V1, V2) (par ordenado) e no segundo caso como {V1, V2} (usa-se chaves pois o par é Não-ordenado). Dessa forma E pode ser descrito como E = {{V1, V2}, {V2, V3}, ..., {Vn, Vw}}. Se as edges são direcionadas forma-se um Digraph.
Existem diversas aplicações para graphs, um exemplo é uma rede social, onde cada node é um usuário e os edges são os meios pelos quais um usuário se conecta com os outros. As internet também funciona dessa forma, na realidade, lembra de quando você estudou Algebra linear? Lembra do assunto "metodo de rankeamento do google, PageRank"? Então, Um graph é a representação que temos em questões desse tipo, normalmente cada node desse graph é uma pagina da internet e cada edge é direcionado à outra página. Surgem apartir daí os mais diversos problemas para se otimizar, por exemplo: Qual página recebe mais menções, qual página é a mais importante, qual página é a menos importante, qual página devo mostrar dada uma pesquisa aleatória, etc.

Existe também Weighted graphs, onde a importancia de cada edge é diferente. Por exemplo, se representarmos as pistas que ligam as cidades de um estado em graph não-direcionado, é incorreto dizer que todas as pistas são igualmente importantes. Repare que nesse graph os nodes seriam as cidades e os links as pistas ou seja, realmente são as Edges que possuem diferentes importancias. Em casos como esse atribuem-se valores ao edges (proporcianal à largura da pista, tráfego, importancia econômica, etc). Outras perguntas importantes também surgem, por exemplo qual o melhor caminho entra a cidade A e a cidade B? Qual custa menos? Qual o caminho mais rápido ?

Outros tipos de edges especiais são: Self loop (um node tem um link/edge que o leva para sí mesmo), Multiedge (existem mais que 1 edge entre dois mesmos nodes). Se um graph não tem nehum desses casos especiais, ele é considerado Normal. Em um graph normal e direcionado, o número maximo de edges é n*(n-1) onde n é o número de nodes, e caso seja não-direcionado o número máximo é n*(n-1)/2.
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
// Onde "node" é uma struct que representa o dado que queremos guardar. Você pode trocar "struct node\*" por um pointer de qualquer outro data type.
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
