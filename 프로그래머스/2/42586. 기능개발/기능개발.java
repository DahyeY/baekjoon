import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        Queue<Integer> q = new LinkedList<Integer>();
        Queue<Integer> workDays = new LinkedList<Integer>();
        List<Integer> list = new ArrayList<Integer>();

        for(int i = 0; i<progresses.length; i++){
            workDays.add((int)Math.ceil((100-progresses[i])/(double)speeds[i]));
        }
        
        while(workDays.peek() != null) {
            int cnt = 1;
            int n = workDays.peek();
            workDays.remove();
            
            while (workDays.peek() != null && workDays.peek() <= n) {
                cnt++;
                workDays.remove();
            }
            list.add(cnt);
        }
        
        System.out.println(list);

        
        int[] answer = new int[list.size()];
        for(int i = 0; i<answer.length; i++){
            answer[i] = list.get(i);
        }
        return answer;
    }
}

