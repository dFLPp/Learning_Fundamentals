// Skip List

/*
 * ATENÇÃO
 * Diferentemente dos outros arquivos, esse, "SL.java", não foi feito 95-100% por mim (usei o chatGPT)
 * Skip lists são estruturas de dados complexas mas q eu decidi deixar aqui porque o nome dela é parecido (é tudo lista)
 * Fique à vontade para pesquisar mais a fundo, mas esse código é mais pra mim que estou escrevendo doq pra vc q está lendo
 * BTW, se vc quer uma forma eficaz de aprender algo, faça uma pesquisa profunda e tente explicar esse assunto para alguem
 * Idealmente para diferente pessoas com diferentes níveis de conhecimento sobre o o tema (pesquisa tbm sobre a taxonomia de bloom)
*/

import java.util.Random;

class Node {
    int value;
    Node right, down;

    public Node(int value) {
        this.value = value;
        this.right = null;
        this.down = null;
    }
}

public class SL {
    private Node head;
    private int maxLevel;
    private Random random;

    public SL() {
        this.head = new Node(Integer.MIN_VALUE);
        this.maxLevel = 1;
        this.random = new Random();
    }

    private int getMultilevelPromotion() {
        int level = 1;
        while (random.nextDouble() < 0.5) {
            level++;
        }
        return level;
    }

    public void insert(int value) {
        int newLevels = getMultilevelPromotion();
        if (newLevels > maxLevel) {
            for (int i = maxLevel + 1; i <= newLevels; i++) {
                Node newHead = new Node(Integer.MIN_VALUE);
                newHead.down = head;
                head = newHead;
            }
            maxLevel = newLevels;
        }

        Node newNode = new Node(value);
        Node current = head;
        for (int i = maxLevel; i >= 1; i--) {
            while (current.right != null && current.right.value < value) {
                current = current.right;
            }
            if (i <= newLevels) {
                newNode.right = current.right;
                current.right = newNode;
                newNode = newNode.down;
            }
            current = current.down;
        }
    }

    public void printSL() {
        Node current = head;
        while (current != null) {
            Node node = current;
            while (node != null) {
                System.out.print(node.value + " -> ");
                node = node.right;
            }
            System.out.println("null");
            current = current.down;
        }
    }

    // Rest of the methods remain the same

    public static void main(String[] args) {
        SL SL = new SL();
        SL.insert(3);
        SL.insert(7);
        SL.insert(5);
        SL.insert(9);

        SL.printSL();
    }
}
