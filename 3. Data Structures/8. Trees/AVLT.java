//AVL tree
/*
É outro tipo de tree que realiza auto-balanceamento.
Assim com a Red-Black tree, n perca tempo tentando refazê-la.
Tentar entender é uma coisa, por mais q seja pouco, existe merito em tentar entender
Agora tentar recriar uma do zero, n existe vantagem. Use uma implementação pronta da linguagem q vc usa

Propriedades (constraints)
- Segue as regras de uma BST
- Para cada node, a diferença entre a altura de suas subtrees (left & right subtrees),
chamado de balance factor, deve ser ou -1 ou 0 ou 1 (at most one).
*/

class Node {
    int data;
    int height;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        this.height = 1;
    }
}

public class AVLT {
    private Node root;

    public void insert(int data) {
        root = insert(root, data);
    }

    private int height(Node node) {
        return (node != null) ? node.height : 0;
    }

    private int balanceFactor(Node node) {
        return (node != null) ? height(node.left) - height(node.right) : 0;
    }

    // repare a seguir que a implementação das rotações da AVL são mais "simples" doq as da Red-Black tree
    // O porque? Por que eu peguei um código simplificado. Não existe arvore mais fácil ou mais difícil de implementar, existe nível de abstração
    // Como eu estava entendendo 43% das operações de rotação na Red-Black tree, aqui eu peguei uma implementação onde eu entendo 44% doq está acontencendo
    

    private Node rightRotate(Node y) {
        Node x = y.left;
        Node T2 = x.right;

        x.right = y;
        y.left = T2;

        y.height = Math.max(height(y.left), height(y.right)) + 1;
        x.height = Math.max(height(x.left), height(x.right)) + 1;

        return x;
    }

    private Node leftRotate(Node x) {
        Node y = x.right;
        Node T2 = y.left;

        y.left = x;
        x.right = T2;

        x.height = Math.max(height(x.left), height(x.right)) + 1;
        y.height = Math.max(height(y.left), height(y.right)) + 1;

        return y;
    }

    private Node insert(Node node, int data) {
        if (node == null) {
            return new Node(data);
        }

        if (data < node.data) {
            node.left = insert(node.left, data);
        } else if (data > node.data) {
            node.right = insert(node.right, data);
        } else {
            return node; // Duplicate data not allowed
        }

        node.height = 1 + Math.max(height(node.left), height(node.right));

        int balance = balanceFactor(node);

        // Perform rotations to maintain balance
        if (balance > 1) {
            if (data < node.left.data) {
                return rightRotate(node);
            } else {
                node.left = leftRotate(node.left);
                return rightRotate(node);
            }
        }

        if (balance < -1) {
            if (data > node.right.data) {
                return leftRotate(node);
            } else {
                node.right = rightRotate(node.right);
                return leftRotate(node);
            }
        }

        return node;
    }

    public void delete(int data) {
        root = delete(root, data);
    }

    private Node delete(Node node, int data) {
        if (node == null) {
            return null;
        }

        if (data < node.data) {
            node.left = delete(node.left, data);
        } else if (data > node.data) {
            node.right = delete(node.right, data);
        } else {
            if (node.left == null || node.right == null) {
                Node temp = (node.left != null) ? node.left : node.right;
                if (temp == null) {
                    temp = node;
                    node = null;
                } else {
                    node = temp;
                }
            } else {
                Node temp = minValueNode(node.right);
                node.data = temp.data;
                node.right = delete(node.right, temp.data);
            }
        }

        if (node == null) {
            return null;
        }

        node.height = 1 + Math.max(height(node.left), height(node.right));

        int balance = balanceFactor(node);

        if (balance > 1) {
            if (balanceFactor(node.left) >= 0) {
                return rightRotate(node);
            } else {
                node.left = leftRotate(node.left);
                return rightRotate(node);
            }
        }

        if (balance < -1) {
            if (balanceFactor(node.right) <= 0) {
                return leftRotate(node);
            } else {
                node.right = rightRotate(node.right);
                return leftRotate(node);
            }
        }

        return node;
    }

    private Node minValueNode(Node node) {
        Node current = node;
        while (current.left != null) {
            current = current.left;
        }
        return current;
    }

    public boolean search(int data) {
        return search(root, data);
    }

    private boolean search(Node node, int data) {
        if (node == null) {
            return false;
        }

        if (data == node.data) {
            return true;
        } else if (data < node.data) {
            return search(node.left, data);
        } else {
            return search(node.right, data);
        }
    }

    public void inOrderTraversal() {
        inOrderTraversal(root);
    }

    private void inOrderTraversal(Node node) {
        if (node != null) {
            inOrderTraversal(node.left);
            System.out.print(node.data + " ");
            inOrderTraversal(node.right);
        }
    }

    public static void main(String[] args) {
        AVLTree avl = new AVLTree();

        avl.insert(10);
        avl.insert(5);
        avl.insert(15);
        avl.insert(3);
        avl.insert(7);

        System.out.println("In-order traversal of AVL tree:");
        avl.inOrderTraversal(); // Should print the tree in sorted order

        System.out.println("\nSearching for 5: " + avl.search(5)); // Should print true
        System.out.println("Searching for 20: " + avl.search(20)); // Should print false

        avl.delete(5);
        System.out.println("In-order traversal after deleting 5:");
        avl.inOrderTraversal(); // Should print the tree without 5
    }
}
