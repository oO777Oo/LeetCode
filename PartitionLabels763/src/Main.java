import java.util.*;

public class Main {
    // TODO Didn't pass a test case need to do some changes!
    public static List<Integer> partitionLabels(String S) {
        HashMap<Character, Integer[]> pars = new HashMap<>();
        char[] list = S.toCharArray();
        // For to determinate first and last index where char is meted.
        for (int i = 0; i < list.length; i++) {
            char key = list[i];
            if(pars.containsKey(key)) {
                Integer[] diapason = pars.get(key);
                diapason[1] = i;
                pars.put(key, diapason);
            } else {
                pars.put(key, new Integer[]{i,0});
            }
        }

        // Check from map chars which come between min .. max
        ArrayList<Integer[]> ans = new ArrayList<>();
        boolean start = false;
        for (Map.Entry<Character, Integer[]> pair: pars.entrySet()) {
            if (start) {
                Integer[] minMax = pair.getValue();
                boolean status = false;
                for (int i = 0; i < ans.size(); i ++) {
                    if (ans.get(i)[0] <= minMax[0] && ans.get(i)[1] >= minMax[1]) {
                        status = true;
                        break;
                    } else if(ans.get(i)[0] <= minMax[0] && minMax[0] <= ans.get(i)[1]) {
                        minMax[0] = ans.get(i)[0];
                        ans.set(i, new Integer[]{minMax[0], minMax[1]});
                        status = true;
                        break;
                    } else if(ans.get(i)[0] >= minMax[0] && ans.get(i)[0] <= minMax[1]) {
                        minMax[1] = ans.get(i)[1];
                        ans.set(i,new Integer[]{minMax[0], minMax[1]});
                        status = true;
                        break;
                    }
                }
                if(!status) {
                    ans.add(pair.getValue());
                }
            } else {
                ans.add(pair.getValue());
                start = true;
            }
        }

        // Calculated chars number in array
        List<Integer> arr = new ArrayList<>();
        for (int i = 0; i < ans.size(); i++) {
            if (i == 0) {
                arr.add(ans.get(i)[1] - ans.get(i)[0] + 1);
            } else if (i == ans.size() - 1) {
                arr.add(S.length() - ans.get(i)[0]);
            } else {
                int value = ans.get(i)[1] - ans.get(i - 1)[1];
                if (value <= 0) {
                    arr.add(1);
                } else {
                    arr.add(value);
                }
            }
        }
        return arr;
    }

    public static void main(String[] args) {
        String s = "ababcbacadefegdehijhklij";
        System.out.println(partitionLabels(s));
    }
}
