// Binary search tree
// Uma árvore que só pode ter no máximo 2 filhos para cada nó E tem um critério de adição/organização dos nós:
// se o valor a ser adicionado é menor que o valor no nó atual (começa com o root), você tenta adicionar ele a esquerda, e se for maior, a direita
// você então repete a checagem no novo nó: o valor e maior ou menor? E então continua fazer a checagem, até que a condição seja admitida
// Meio que já fiz ela em C na implementação de Binary trees mas n custa nada fazer dnv

class Node {
    constructor(data) {
        this.data = data; //deve ser int
        this.leftChild = null;
        this.rightChild = null;
    }
}

class BST {
    constructor() {
        this.root = null;
    }

    addNode(data) {
        this.root = this.insert(this.root, data);
    }

    insert(root, data) {
        if (root === null) {
            return new Node(data);
        }

        if (data < root.data) {
            root.leftChild = this.insert(root.leftChild, data);
        } else if (data > root.data) {
            root.rightChild = this.insert(root.rightChild, data);
        }

        return root;
    }

    printInPreOrder(){
        if (this.root) {
            this.preOrderLogic(this.root);
        } else {
            console.log("Tree is empty");
        }
    }

    preOrderLogic(root){
        console.log(root.data);
        if(root.leftChild) this.preOrderLogic(root.leftChild);
        if(root.rightChild) this.preOrderLogic(root.rightChild);
    }
}

let tree = new BST();
tree.addNode(5);
tree.addNode(3);
tree.addNode(1);


/*
tree.addNode(5); -> tree.root = null, logo caimos no primeiro if do insert e root = Node(5)
5

tree.addNode(3); -> tree.root = Node(5), logo caimos no if onde data < root.data
                 -> o novo root agora é tree.root.leftChild, que é null, logo caimos no primeiro if, retonamos Node(3) e root.leftChild = Node(3)
                 -> agora nos "copiamos por cima" do root anterior a nova árvore (pra isso que o return root do final serve, para atualizar o this.root na função addNode)
 5
3


tree.addNode(1); -> tree.root = Node(5), logo caimos no if onde data < root.data 
                 -> o novo root agora é tree.root.leftChild, que é Node(3), logo caimos no segundo if
                 -> o novo root agora é tree.root.leftChild.leftChild, que é null, logo caimos no primeiro if e retornamos Node(1)
                 -> atribuimos  tree.root.leftChild.leftChild à Node(1) e as chamadas recursivas começam a se fechar
                 -> sobreescrevemos o antigo root com o novo/atualizado
  5
 3
1   
*/

tree.printInPreOrder();
/*
printa root depois leftChild, depois rightChild, usando recursão
*/