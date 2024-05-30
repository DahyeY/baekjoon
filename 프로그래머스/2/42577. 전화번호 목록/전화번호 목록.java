import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        Set<String> set = new HashSet<>();

        for (String num : phone_book) {
            set.add(num);
        }

        for (String s : phone_book) {
            for (int j = 0; j < s.length(); j++) {
                if (set.contains(s.substring(0, j))) {
                    answer = false;
                    break;
                }
            }
        }

        return answer;
    }
}