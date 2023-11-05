//Red-black tree
/*
É uma BST que se auto-balanceia. Tipo, depois de operações de adição e remoção
um algoritimo interno roda, trocando/re-organizando os nodes da tree para que ela nunca perca a propriedade
Red-black trees são uma substituição válida à BST's se vc for realizar muitas operações de deleção
pois independente da quantidade o Big O da arvore sempre vai se manter em O(log(n))

Propriedades (constraints):
- Cada node ou é "black" ou é "red"
- O root sempre é "black"
- "red" nodes não podem ter childs que sejam "red" (entenda: um red node não pode ser pai de um red node, mas nada impede que seja "avo")
- para cada/qualquer node o número de passos que devemos dar desse node até uma de suas leafs é/deve ser igual ao número de black nodes
- além disso ele deve obdecer aquela regra de ordenação das BST's

Bom. Eu sei um pouco de matemática mas provar que isso é verdade é desnecessário, ou seja, nos simplesmente acreditamos que, seguindo as props, temos uma red-black tree
Só precisamos criar um algoritimo/tree que siga/confira todas as propriedades acima antes e depois de cada operação de inserção e delete

Só pra deixar claro (se bem que mais óbivo impossivel): eu n fiz esse código. Peguei uma implementação pronta.
Essa é também é uma forma válida de estudar: tentar fazer/implementar coisas simples e simplesmente olhar/contemplar/analisar as complicadas
Simples e objetivamente, não existe nenhum trabalho no mundo que nós, meros mortais vamos ser cobrados para fazer isso do zero. Não existe. Ponto.
Se vc for usar, usa uma versão pronta e mais detalhada. O proprio cpp tem no STL implementações desse tipo de tree
*/

#include <iostream>

//tipos de nodes
enum class Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node* parent;
    Node* left;
    Node* right;
};

class RedBlackTree {
private:
    Node* root;
    Node* nil;  // ao invés de apontar para null, aponta para um node sem valor

    /*
    Os proximos 2 métodos são funções utilitárias: algoritimos de rotação.
    Basicamente eles são usados para trocar a posição de um child com o seu parent, podendo ser o esquerdo ou o direto
    Dê uma olhada em imagens. O conceito e bem simples contudo no momento de codificar vc deve levar em consideração todos os casos
    */

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nil) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nil) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        if (x->right != nil) {
            x->right->parent = y;
        }
        x->parent = y->parent;
        if (y->parent == nil) {
            root = x;
        } else if (y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }
        x->right = y;
        y->parent = x;
    }

    // outra função auxiliar (que faz, algo...)
    void transplant(Node* u, Node* v) {
        if (u->parent == nil) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    //lembra da prop que o número de passos de qqer node até um leaf node tem que ser igual ao número de black nodes?
    //Então, insert e delete Fixup corrigem isso (eu acho)
    void insertFixup(Node* z) {
        while (z->parent->color == Color::RED) {
            if (z->parent == z->parent->parent->left) {
                Node* y = z->parent->parent->right;
                if (y->color == Color::RED) {
                    z->parent->color = Color::BLACK;
                    y->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    rightRotate(z->parent->parent);
                }
            } else {
                Node* y = z->parent->parent->left;
                if (y->color == Color::RED) {
                    z->parent->color = Color::BLACK;
                    y->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = Color::BLACK;
    }

    void deleteFixup(Node* x) {
        while (x != root && x->color == Color::BLACK) {
            if (x == x->parent->left) {
                Node* w = x->parent->right;
                if (w->color == Color::RED) {
                    w->color = Color::BLACK;
                    x->parent->color = Color::RED;
                    leftRotate(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == Color::BLACK && w->right->color == Color::BLACK) {
                    w->color = Color::RED;
                    x = x->parent;
                } else {
                    if (w->right->color == Color::BLACK) {
                        w->left->color = Color::BLACK;
                        w->color = Color::RED;
                        rightRotate(w);
                        w = x->parent->right;
                    }
                    w->color = x->parent->color;
                    x->parent->color = Color::BLACK;
                    w->right->color = Color::BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            } else {
                Node* w = x->parent->left;
                if (w->color == Color::RED) {
                    w->color = Color::BLACK;
                    x->parent->color = Color::RED;
                    rightRotate(x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == Color::BLACK && w->left->color == Color::BLACK) {
                    w->color = Color::RED;
                    x = x->parent;
                } else {
                    if (w->left->color == Color::BLACK) {
                        w->right->color = Color::BLACK;
                        w->color = Color::RED;
                        leftRotate(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = Color::BLACK;
                    w->left->color = Color::BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = Color::BLACK;
    }

    
    void deleteNode(Node* z) {
        Node* y = z;
        Node* x;
        Color yOriginalColor = y->color;

        if (z->left == nil) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == nil) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = minimum(z->right);
            yOriginalColor = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            } else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }

        if (yOriginalColor == Color::BLACK) {
            deleteFixup(x);
        }
        delete z;
    }

    Node* minimum(Node* node) {
        while (node->left != nil) {
            node = node->left;
        }
        return node;
    }

public:
    RedBlackTree() {
        nil = new Node{0, Color::BLACK, nullptr, nullptr, nullptr};
        root = nil;
    }

    // Public insert function
    void insert(int data) {
        Node* newNode = new Node{data, Color::RED, nil, nil, nil};
        Node* parent = nullptr;
        Node* current = root;

        while (current != nil) {
            parent = current;
            if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        newNode->parent = parent;
        if (parent == nil) {
            root = newNode;
        } else if (data < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        insertFixup(newNode);
    }

    // Public delete function
    void deleteNode(int data) {
        Node* z = search(root, data);
        if (z != nil) {
            deleteNode(z);
        }
    }

    Node* search(Node* node, int data) {
        if (node == nil || node->data == data) {
            return node;
        }

        if (data < node->data) {
            return search(node->left, data);
        } else {
            return search(node->right, data);
        }
    }

    // Display the tree using in-order traversal
    void inOrderTraversal(Node* node) {
        if (node != nil) {
            inOrderTraversal(node->left);
            std::cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    void display() {
        inOrderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    RedBlackTree rbt;

    rbt.insert(10);
    rbt.insert(5);
    rbt.insert(15);
    rbt.insert(3);
    rbt.insert(7);

    std::cout << "Red-Black Tree in-order traversal: ";
    rbt.display();

    rbt.deleteNode(5);

    std::cout << "Red-Black Tree after deleting 5: ";
    rbt.display();

    return 0;
}
