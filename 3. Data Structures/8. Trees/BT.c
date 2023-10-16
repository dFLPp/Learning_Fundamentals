// binary tree

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Tree Tree;

struct Node {
    int data;
    Node* leftChild;
    Node* rightChild;
};

struct Tree {
    Node* root;
};

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

// Função para inserir um nó em uma árvore, atenção:

/*
Estamos usando de recursão para inserir os elementos ao mesmo tempo que escolhemos um critério.
Usamos recursão porque, para cada adição que fizermos, aos adições posteriores deverão ser feitas mais no "fundo" da arvoré.
Assim nos temos que nos preocupar com iterar até o local onde é possivel adicionar um node.

Sabendo disso, precisamos também definir um critério para inserir o elemento: na direita ou na esquerda? O local é importante.
O critério usado aqui é usado comumente em BST's: os nodes com menores valores são colocados à esquerda e os com maiores valores a direita.

Outra observação importante é conceito de sub-trees. A medida que iteramos (escolhemos se vamos para a esquerda ou direita) nos saimos do node atual (o root)
e chegamos a outro node. A sacada é que, esse novo node também pode ser considerado como root para todos os outros nodes abaixo dele. 
Esse é o truque de recursividade usado em praticamente todos os tipos de árvores: O conceito de subtree.
*/
void insertNode(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else if (data < (*root)->data) {
        insertNode(&(*root)->leftChild, data);
    } else if (data > (*root)->data) {
        insertNode(&(*root)->rightChild, data);
    }
}

// Função para imprimir a árvore em ordem (in-order)
/*
Existem 3 formas de iterar por uma árvore: pre-order, in-order e pos-order.
na pre-order primeiro vc printa os valores nessa ordem root->left->right
na in-order primeiro vc printa os valores nessa ordem left->root->right
na pos-order primeiro vc printa os valores nessa ordem left->right->root
*/
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->leftChild);
        printf("%d ", root->data);
        inOrderTraversal(root->rightChild);
    }
}

void initTree(Tree* tree) {
    tree->root = NULL;
}

int main() {
    Tree tree;
    initTree(&tree);

    // Inserindo nós na árvore - passo a passo:

    insertNode(&tree.root, 5);
    // root é null, logo root = node(5)

    //5

    insertNode(&tree.root, 3);
    //root não é null e data(=3) é menor que root(=5), logo repetimos para root->leftChild, que será o root para sua subtree
    //o root (root->leftChild) é null, logo root = node(3)

    //   5
    //  3

    insertNode(&tree.root, 7);
    //root n é null e data(=3) é maior que root(=5), logo repetimos para root->rightChild, msm esquema
    //o root é null, logo root = node(7)

    //   5
    //  3 7

    insertNode(&tree.root, 2);
    // root n é null e data é menor que root
    // root n é null e data é menor que root
    // root é null, logo root = node(2)

    //   5
    //  3 7
    // 2

    insertNode(&tree.root, 4);
    // root n é null e data é menor que root
    // root n é null e data é maior que root
    // root é null, logo root = node(4)

    //   5
    //  3 7
    // 2 4


    printf("Árvore em ordem (in-order): ");
    inOrderTraversal(tree.root);
    printf("\n");

    /*
      5 - root
     3 7 - pseudo root
    2 4 - leafs (n tem childs)

    logo print(root->leftChild) vai passar de 5 para 3 e de 3 para 2. Como 2 é um leaf n é subtree, logo 2 é printado
    como a iteração é in-oder, depois de printar o da esquerda, é printado o root, ou seja, nos "subimos" uma linha, para voltar para o 3, que é pseudo root, é printar ele
    por ultimo printa o 4, que o right child.
    Depois de ter terminado com essa subtree, subimos mais uma linha, agora, pritnado 5 e por fim 7
    Ou sejam o resultado é 2, 3, 4, 5, 7
    */
    


    return 0;
}
