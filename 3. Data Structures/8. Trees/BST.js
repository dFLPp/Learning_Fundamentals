// Binary search tree
// Uma árvore que só pode ter no máximo 2 filhos em cada nó E tem um critério de adição/organização dos nós:
// se o valor a ser adicionado é menor que o valor no nó atual (começa com o root), você tenta adicionar ele a esquerda, e se for maior, a direita
// você então repete a checagem no novo nó: o valor e maior ou menor? E então continua fazer a checagem, até que a condição seja admitida
// Meio que já fiz ela em C na implementação de Binary trees mas n custa nada fazer dnv
// Quando vc for deletar um node em uma BST existem 3 cenários:
/*
- o node é um leaf -> vc simplesmente iguala ele à null ou corta o ponteiro até ele
- o node tem 1 (um) child -> vc troca a posição do node com a do child (se o child for subroot ele traz consigo sua subtree)
- o node tem 2 (dois) childs -> na maioria das vezes basta vc substituir ele com o maior node da left subtree
essa operação de mudança/substituição é mais complexa e pode acarretar em outras substituições

De forma geral, se vc realizar muitas operações de deletar a BST vai acabar perdendo sua propriedade de ordenação.
Tipo, ela n perde a propriedade, mas vai lentamente virando uma espécie de linked list ou parecido com as arestas de um triangulo

Se você vai armazenar algum dado no formato de tree e sabe que vai precisar adicionar E remover muitas vezes
o ideal é vc escolher outro tipo de tree, a red black tree para ser mais exato.

*/

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

    delete(data) {
        this.root = this._deleteRec(this.root, data);
        //Em js é um padrão recorrente usar outros métodos (privados) da classe pra fazer recursão
    }
    
    _deleteRec(node, data) {
        if (node === null) {
            return node;
        }
    
        if (data < node.data) {
            node.leftChild = this._deleteRec(node.leftChild, data);
        } else if (data > node.data) {
            node.rightChild = this._deleteRec(node.rightChild, data);
        } else {
            if (node.leftChild === null) {
                return node.rightChild;
            } else if (node.rightChild === null) {
                return node.leftChild;
            }
    
            node.data = this._minValueNode(node.rightChild).data;
            node.rightChild = this._deleteRec(node.rightChild, node.data);
        }
    
        return node;
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

tree.delete(3);
/*
Primeiros vamos procurar/iterar até a achar o elemento de valor 3, començando pelo root (5).
como 3 é menor que 5 vamos "descer" recursivamente em root.left, que é 3;
Nesse momento caimos no else (achamos o elem pra deletar). Como 3 só tem um child (leftChild = 1) retornamos 1
Esse 1 retornado vai ser atribuido à root.left da chamada recursiva que vissemos.
Repare que esse 1 é, em realidade uma referencia ao node 1, ou seja, nada impede que, em outras situações, ele fosse o subroot de uma subtree
Nesse caso em especifico como ele é um leaf node o root vai ter "appendando" um único node.
Depois disso retornamos o node (que é root) e reatribuimos o root (atualizamos o root)
*/

tree.printInPreOrder();