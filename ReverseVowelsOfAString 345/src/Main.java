import java.util.HashMap;

public class Main {

    public static String reverseVowels(String s) {
        char[] vowels = {'e', 'E', 'u', 'U', 'i', 'I', 'o', 'O', 'a', 'A'};
        int pointerLeft = 0;
        int pointerRight = s.length() - 1;
        char[] sList = s.toCharArray();

        boolean flagLeft = false;
        boolean flagRight = false;

        while (pointerLeft < pointerRight) {
            for (int i = 0; i < vowels.length; i++) {
                if (sList[pointerLeft] == vowels[i]) {
                    flagLeft = true;
                }
                if (sList[pointerRight] == vowels[i]) {
                   flagRight = true;
                }
            }

            if (!flagLeft) {
                pointerLeft ++;
            }
            if (!flagRight) {
                pointerRight --;
            }

            if (flagLeft && flagRight) {
                swapChar(sList, pointerLeft, pointerRight);
                flagLeft = false;
                flagRight = false;
                pointerLeft++;
                pointerRight--;
            }
        }
        return String.valueOf(sList);
    }

    private static void swapChar(char[] list, int firstItem, int secondItem) {
        char intermediate = list[secondItem];
        list[secondItem] = list[firstItem];
        list[firstItem] = intermediate;
    }


    public static void main(String[] args) {
        System.out.println(reverseVowels("hello"));
    }
}
