// Transposta de uma matriz

public class rotMat {

    public static int[][] rotateMatrix(int[][] matrix) {
        int n = matrix.length;

        for (int i = 0; i < n; i++) {
            if (matrix[i].length != n) {
                throw new RuntimeException("Matriz deve ser quadrada");
            }
        }

        int[][] rotated = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rotated[j][n - 1 - i] = matrix[i][j];
            }
        }

        return rotated;
    }

    public static void printMatrix(int[][] matrix) {
        for (int[] row : matrix) {
            for (int num : row) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[][] matrix = {
                { 1, 2, 3 },
                { 4, 5, 6 },
                { 7, 8, 9 }
        };
        try {
            int[][] rotatedMatrix = rotateMatrix(matrix);
            printMatrix(rotatedMatrix);
        } catch (RuntimeException e) {
            System.out.println(e.getMessage());
        }

    }
}