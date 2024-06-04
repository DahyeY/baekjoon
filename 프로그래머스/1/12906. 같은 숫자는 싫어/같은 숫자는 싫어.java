import java.util.*;

public class Solution {
    public int[] solution(int[] arr) {

        Queue<Integer> queue = new LinkedList<Integer>();

        int n = -1;
        for (int num : arr) {
            if (n == num) continue;
            else {
                n = num;
                queue.add(num);
            }
        }

        int[] answer = new int[queue.size()];

        for (int i = 0; i < answer.length; i++) {
            answer[i] = queue.remove();
        }


        return answer;
    }
}