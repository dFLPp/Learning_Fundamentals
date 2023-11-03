// Checa se string é palindrome (é igual a sua forma reversa)

public class isPalin {

    public static boolean isPalindrome(String str) {
        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            while (!Character.isLetterOrDigit(str.charAt(left)) && left < right) {
                left++;
            }
            while (!Character.isLetterOrDigit(str.charAt(right)) && left < right) {
                right--;
            }

            if (Character.toLowerCase(str.charAt(left)) != Character.toLowerCase(str.charAt(right))) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    public static void main(String[] args) {
        String str = "A man, a plan, a canal, Panama";
        if (isPalindrome(str)) {
            System.out.println("A string é um palíndromo.");
        } else {
            System.out.println("A string não é um palíndromo.");
        }
    }
}
