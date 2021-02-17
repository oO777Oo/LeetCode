import java.util.*;

public class Main {

    public static List<Integer> partitionLabels(String S) {
        LinkedHashMap<Character, Integer[]> pars = new LinkedHashMap<>();
        char[] list = S.toCharArray();
        // For to determinate first and last index where char is meted.
        for (int i = 0; i < list.length; i++) {
            char key = list[i];
            if(pars.containsKey(key)) {
                Integer[] diapason = pars.get(key);
                diapason[1] = i;
                pars.put(key, diapason);
            } else {
                pars.put(key, new Integer[]{i,i});
            }
        }

        // Check from map chars which come between min .. max
        ArrayList<Integer[]> ans = new ArrayList<>();
        boolean start = false;
        for (Map.Entry<Character, Integer[]> pair: pars.entrySet()) {
            if (start) {
                Integer[] minMax = pair.getValue();
                boolean flag = false;
                for (int i = 0; i < ans.size(); i ++) {
                    int min = ans.get(i)[0];
                    int max = ans.get(i)[1];
                    if (min < minMax[0] && minMax[1] < max) {
                        flag = true;
                        break;
                    } else if (minMax[0] < min && minMax[1] > min && minMax[1] < max) {
                        ans.set(i, new Integer[]{minMax[0], max});
                        flag = true;
                        break;
                    } else if (min < minMax[0] && minMax[0] < max && max < minMax[1]) {
                        ans.set(i, new Integer[]{min, minMax[1]});
                        flag = true;
                        break;
                    } else if(minMax[0] < min && max < minMax[1]) {
                        ans.set(i, minMax);
                        flag = true;
                        break;
                    }
                }
                if(!flag) {
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
            int min = ans.get(i)[0];
            int max = ans.get(i)[1];
            arr.add(max + 1 - min);
        }
        return arr;
    }

    public static void main(String[] args) {
        String s = "caedbdedda";
        // 9,7,8
        System.out.println(partitionLabels(s));
    }
}
