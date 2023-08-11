// Batch processing + buffering + queues
// Basicamente usando os conceitos acima queremos "reverter" uma string
// se o carac é minusculo vira maiusculo e vice-versa.
// A ideia de usar batching é que vc pode usar várias threads para aumentar a performance
// como n sei mexer com isso ainda vamos de basic

import java.util.Queue;
import java.util.LinkedList;

public class BBQ {
    public static void main(String[] args) {
        String input = "Neque PORRO QuiSquAm ESt qUi doLorem ipsUm quIa";
        int batchSize = 5;
        Queue<String> bufferQueue = new LinkedList<>();
        StringBuilder output = new StringBuilder();

        // batching + buffering
        for (int i = 0; i < input.length(); i += batchSize) {
            // para evitar acessar posição que n existe na string
            int endindex = Math.min(i + batchSize, input.length());
            String batch = input.substring(i, endindex);
            bufferQueue.offer(batch); // msm coisa que enqueue
        }

        // batching + processing
        while (!bufferQueue.isEmpty()) {
            String batch = bufferQueue.poll(); // msm que dequeue
            doTheDeed(batch, output);
        }

        System.out.println("Before: " + input);
        System.out.println("After: " + output.toString());

    }

    private static void doTheDeed(String batch, StringBuilder output) {
        for (char c : batch.toCharArray()) {
            if (Character.isUpperCase(c)) {
                c = Character.toLowerCase(c);
            } else if (Character.isLowerCase(c)) {
                // else if pq o caractere pode ser um número ou símbolo
                c = Character.toUpperCase(c);
            }
            output.append(c);
        }
    }

}
