import javax.swing.*;
import java.util.Arrays;

public class Main {

    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        int pointerEnd = m + n - 1;
        int pointerStart = m - 1;
        int secondListPointer = n - 1;

        if (n == 0) {
            return;
        } else if(m == 0) {
            for (int i = 0; i < n; i++) {
                nums1[i] = nums2[i];
            }
            return;
        }

        while (pointerStart >= 0 || secondListPointer >= 0) {
            if (secondListPointer == - 1) {
                return;
            }
            if (pointerStart == -1) {
                while (pointerEnd >= 0) {
                    nums1[pointerEnd] = nums2[secondListPointer];
                    pointerEnd --;
                    secondListPointer--;
                }
                return;
            }
            if (nums1[pointerStart] >= nums2[secondListPointer]) {
                nums1[pointerEnd] = nums1[pointerStart];
                pointerStart--;
                pointerEnd--;
            } else  {
                nums1[pointerEnd] = nums2[secondListPointer];
                pointerEnd--;
                secondListPointer--;
            }

        }


    }

    public static void main(String[] args) {

        int[] nums1 = new int[]{2,0};
        merge(nums1, 1, new int[]{1}, 1);
        System.out.println(Arrays.toString(nums1));
    }
}
